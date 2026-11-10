"""Check the AS21 Markdown subset. Read-only; explicit file paths only.

Uses standard-library scalar parsing, not a general YAML parser or SSAT validator.
"""
import argparse
from datetime import date
import json
from pathlib import Path
import re

REQUIRED = (
    'ssat_md', 'id', 'id_status', 'title', 'description', 'doc_class', 'doc_type',
    'status', 'iteration', 'document_version', 'owner', 'owner_status',
    'classification', 'language', 'created_date', 'updated_date',
)


def scalar(value):
    """Project front matter permits one-line scalars only."""
    if value.startswith('"'):
        result = json.loads(value)
        if not isinstance(result, str):
            raise ValueError('需要字符串')
        return result
    if value.startswith("'"):
        if not re.fullmatch(r"'(?:[^']|'')*'", value):
            raise ValueError('单引号未正确闭合')
        return value[1:-1].replace("''", "'")
    value = value.split(' #', 1)[0].strip()
    if not value or value[0] in '[{|>&*!' or value in ('null', '~'):
        raise ValueError('仅支持非空的单行标量')
    return value


def check_text(text):
    """Return (one-based line number, message) pairs; never change the input."""
    lines = text.lstrip('\ufeff').splitlines()
    errors = []
    if not lines or lines[0] != '---':
        return [(1, '缺少 YAML 元数据头（首行应为 ---）')]
    try:
        end = lines.index('---', 1)
    except ValueError:
        return [(1, '元数据头未闭合')]

    meta, locations = {}, {}
    for index in range(1, end):
        line = lines[index]
        if not line.strip() or line.lstrip().startswith('#'):
            continue
        match = re.fullmatch(r'([a-z][a-z0-9_]*)\s*:\s*(.+)', line)
        if not match:
            errors.append((index + 1, '元数据应为 key: value，不能嵌套或换行'))
            continue
        key, raw = match.groups()
        if key in meta:
            errors.append((index + 1, f'元数据字段重复：{key}'))
            continue
        try:
            value = scalar(raw)
            if not value.strip():
                raise ValueError('字段不能为空')
            meta[key] = value
            locations[key] = index + 1
        except ValueError as exc:
            errors.append((index + 1, f'{key}：{exc}'))

    for key in REQUIRED:
        if not meta.get(key):
            errors.append((1, f'缺少必填字段：{key}'))
    enums = {
        'doc_class': {'controlled', 'working', 'template'},
        'doc_type': {'spec', 'test_report', 'guide', 'note'},
        'status': {'draft', 'review', 'approved', 'obsolete'},
        'id_status': {'proposed', 'assigned'},
        'owner_status': {'unconfirmed', 'confirmed'},
    }
    for key, choices in enums.items():
        if key in meta and meta[key] not in choices:
            errors.append((locations.get(key, 1), f'{key} 不在项目约定范围：{", ".join(sorted(choices))}'))
    if 'ssat_md' in meta and meta['ssat_md'] != '2.0.0':
        errors.append((locations['ssat_md'], '本项目沿用的 ssat_md 标记应为 2.0.0'))
    if 'iteration' in meta and not re.fullmatch(r'[1-9][0-9]*', meta['iteration']):
        errors.append((locations['iteration'], 'iteration 应为正整数'))
    if 'document_version' in meta and not re.fullmatch(r'\d+\.\d+\.\d+(?:[-+][A-Za-z0-9.-]+)?', meta['document_version']):
        errors.append((locations['document_version'], 'document_version 应采用三段版本号，例如 1.0.0'))
    dates = {}
    for key in ('created_date', 'updated_date'):
        if key in meta:
            try:
                if not re.fullmatch(r'\d{4}-\d{2}-\d{2}', meta[key]):
                    raise ValueError()
                dates[key] = date.fromisoformat(meta[key])
            except ValueError:
                errors.append((locations[key], f'{key} 应为有效的 YYYY-MM-DD 日期'))
    if len(dates) == 2 and dates['updated_date'] < dates['created_date']:
        errors.append((locations['updated_date'], '更新日期不能早于创建日期'))
    if meta.get('id') == 'TBD' and meta.get('id_status') != 'proposed':
        errors.append((locations.get('id_status', 1), '未分配编号应使用 id_status: proposed'))
    if meta.get('owner') == 'TBD' and meta.get('owner_status') != 'unconfirmed':
        errors.append((locations.get('owner_status', 1), '未确认负责人应使用 owner_status: unconfirmed'))
    if meta.get('status') == 'approved':
        for key in ('id', 'owner', 'classification'):
            if meta.get(key) in (None, '', 'TBD'):
                errors.append((locations.get(key, 1), f'已批准文档不能保留未确认的 {key}'))
        if meta.get('id_status') != 'assigned' or meta.get('owner_status') != 'confirmed':
            errors.append((locations.get('status', 1), '已批准文档的编号和负责人必须已确认'))

    titles, numbers, last, figure_ids = [], set(), {}, set()
    active_section = ()
    figure_number = 0
    fence = None
    previous = ''
    for index in range(end + 1, len(lines)):
        line = lines[index]
        marker = re.match(r'^ {0,3}(`{3,}|~{3,})(.*)$', line)
        if fence:
            if marker and marker[1][0] == fence['char'] and len(marker[1]) >= fence['length'] and not marker[2].strip():
                if fence['language'] == 'mermaid':
                    body = '\n'.join(fence['body'])
                    ids = re.findall(r'^\s*%%\s*ssat:figure_id=(\S+)\s*$', body, re.M)
                    if not re.search(r'^\s*%%\s*ssat:role=formal\s*$', body, re.M):
                        errors.append((fence['line'], 'Mermaid 缺少 %% ssat:role=formal'))
                    if len(ids) != 1 or not re.fullmatch(r'FIG_[A-Z0-9_]+', ids[0]):
                        errors.append((fence['line'], 'Mermaid 需要一个 FIG_ 开头的大写 figure_id'))
                    elif ids[0] in figure_ids:
                        errors.append((fence['line'], f'图 ID 重复：{ids[0]}'))
                    else:
                        figure_ids.add(ids[0])
                    if not re.fullmatch(r'\*\*图 \d+｜.+\*\*', fence['previous']):
                        errors.append((fence['line'], 'Mermaid 前应有 **图 N｜图题**'))
                fence = None
                previous = line.strip()
            else:
                fence['body'].append(line)
            continue
        if marker:
            fence = {'char': marker[1][0], 'length': len(marker[1]),
                     'language': marker[2].strip(), 'line': index + 1,
                     'body': [], 'previous': previous}
            continue
        caption = re.fullmatch(r'\*\*图 (\d+)｜.+\*\*', line.strip())
        if caption:
            figure_number += 1
            if int(caption[1]) != figure_number:
                errors.append((index + 1, f'图编号应连续，此处应为图 {figure_number}'))
        heading = re.match(r'^(#{1,6})\s+(.+?)\s*#*\s*$', line)
        if heading:
            level, title = len(heading[1]), heading[2]
            if level == 1:
                titles.append((index + 1, title))
            number = re.match(r'^(\d+(?:\.\d+)*)(?:[.、])?\s+\S', title)
            if number and level > 1:
                parts = tuple(int(item) for item in number[1].split('.'))
                parent = parts[:-1]
                if len(parts) != level - 1:
                    errors.append((index + 1, '标题层级与编号深度不一致'))
                if parent and parent not in numbers:
                    errors.append((index + 1, '编号缺少对应父章节'))
                elif parent and active_section[:len(parent)] != parent:
                    errors.append((index + 1, '子章节不属于当前父章节'))
                expected = last.get(parent, 0) + 1
                if parts[-1] != expected:
                    errors.append((index + 1, f'章节编号不连续：{number[1]}，本级应为 {expected}'))
                last[parent] = parts[-1]
                numbers.add(parts)
                active_section = parts
        if line.strip():
            previous = line.strip()
    if fence:
        errors.append((fence['line'], '代码围栏未闭合'))
    if len(titles) != 1:
        errors.append((end + 2, '正文应且仅应有一个一级标题'))
    elif titles[0][1] != meta.get('title'):
        errors.append((titles[0][0], '一级标题与元数据 title 不一致'))
    return errors


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('files', nargs='+', type=Path, help='本次需要检查的 Markdown 文件，不递归扫描')
    args = parser.parse_args()
    failed = False
    for path in args.files:
        try:
            errors = check_text(path.read_text(encoding='utf-8-sig'))
        except (OSError, UnicodeError) as exc:
            errors = [(1, f'无法读取 UTF-8 文档：{exc}')]
        if errors:
            failed = True
            for line, message in errors:
                print(f'{path}:{line}: {message}')
        else:
            print(f'PASS: {path}')
    return int(failed)


if __name__ == '__main__':
    raise SystemExit(main())
