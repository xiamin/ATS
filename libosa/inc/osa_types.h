/*
 * osa_types.h
 *
 *      Author: kunta 
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#ifndef OSA_TYPES_H_
#define OSA_TYPES_H_

#include "osa_error.h"

typedef char    osa_char_t;
typedef char    osa_int8_t;
typedef short   osa_int16_t;
typedef int     osa_int32_t;
typedef long    osa_int64_t;

typedef unsigned char   osa_uint8_t;
typedef unsigned short  osa_uint16_t;
typedef unsigned int    osa_uint32_t;
typedef unsigned long   osa_uint64_t;

typedef double          osa_double_t;

typedef unsigned int    osa_base_t;

typedef osa_base_t      osa_fd_t;
typedef osa_base_t      osa_size_t;
typedef osa_base_t      osa_bool_t;
typedef void *          osa_pointer_t;

#ifndef OSA_TRUE
#define OSA_TRUE    1
#endif
#ifndef OSA_FALSE
#define OSA_FALSE   0
#endif

#ifndef NULL
    #ifdef __cplusplus
        #define NULL        (0L)
    #else /* !__cplusplus */
        #define NULL        ((void*) 0)
    #endif /* !__cplusplus */
#endif

#ifndef OSA_NULL
#define OSA_NULL   NULL
#endif

#ifndef OSA_API
#define OSA_API
#endif

#ifndef osa_inline
#define osa_inline  inline
#endif


#endif /* OSA_TYPES_H_ */
