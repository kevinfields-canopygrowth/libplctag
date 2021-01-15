/***************************************************************************
 *   Copyright (C) 2020 by Kyle Hayes                                      *
 *   Author Kyle Hayes  kyle.hayes@gmail.com                               *
 *                                                                         *
 * This software is available under either the Mozilla Public License      *
 * version 2.0 or the GNU LGPL version 2 (or later) license, whichever     *
 * you choose.                                                             *
 *                                                                         *
 * MPL 2.0:                                                                *
 *                                                                         *
 *   This Source Code Form is subject to the terms of the Mozilla Public   *
 *   License, v. 2.0. If a copy of the MPL was not distributed with this   *
 *   file, You can obtain one at http://mozilla.org/MPL/2.0/.              *
 *                                                                         *
 *                                                                         *
 * LGPL 2:                                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

 #pragma once

#include <stdint.h>

#define PCCC_CMD_OK ((uint8_t)(0x40))
#define PCCC_TYPED_CMD ((uint8_t)(0x0F))



// #define LIBPLCTAG_VENDOR_ID ((uint16_t)0xF33D)      /* no idea what this needs to be */
// #define LIBPLCTAG_VENDOR_SN ((uint32_t)0x21504345)  /* the string !PCE */


typedef enum { PCCC_FILE_UNKNOWN        = 0x00, /* UNKNOWN! */
               PCCC_FILE_ASCII          = 0x8e,
               PCCC_FILE_BCD            = 0x8f,
               PCCC_FILE_BIT            = 0x85,
               PCCC_FILE_BLOCK_TRANSFER = 0x00, /* UNKNOWN! */
               PCCC_FILE_CONTROL        = 0x88,
               PCCC_FILE_COUNTER        = 0x87,
               PCCC_FILE_FLOAT          = 0x8a,
               PCCC_FILE_INPUT          = 0x8c,
               PCCC_FILE_INT            = 0x89,
               PCCC_FILE_LONG_INT       = 0x91,
               PCCC_FILE_MESSAGE        = 0x92,
               PCCC_FILE_OUTPUT         = 0x8b,
               PCCC_FILE_PID            = 0x93,
               PCCC_FILE_SFC            = 0x00, /* UNKNOWN! */
               PCCC_FILE_STATUS         = 0x84,
               PCCC_FILE_STRING         = 0x8d,
               PCCC_FILE_TIMER          = 0x86
             } df1_file_t;

extern int df1_parse_logical_address(const char *name, df1_file_t *file_type, int *file_num, int *elem_num, int *sub_elem_num);
extern int df1_element_size(df1_file_t file_type);
extern const char *df1_decode_error(uint8_t *data, int capacity);

