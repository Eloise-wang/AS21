/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 *
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with
 * the terms contained in the written license agreement between you and ArcCore,
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as
 * published by the Free Software Foundation and appearing in the file
 * LICENSE.GPL included in the packaging of this file or here
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/

/* AS21 uses the default linker .bss/.data sections for these Com objects.
 * Repeated inclusion is intentional; consume each marker without an include guard.
 * Only the four markers present in this imported Com are supported. */
#if defined(COM_START_SEC_VAR_CLEARED_UNSPECIFIED)
#undef COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined(COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
#undef COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined(COM_START_SEC_VAR_INIT_UNSPECIFIED)
#undef COM_START_SEC_VAR_INIT_UNSPECIFIED
#elif defined(COM_STOP_SEC_VAR_INIT_UNSPECIFIED)
#undef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
#else
#error Unsupported_Com_memory_section
#endif
