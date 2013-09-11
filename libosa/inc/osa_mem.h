/*
 * osa_mem.h
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

#ifndef OSA_MEM_H_
#define OSA_MEM_H_

#include <stdio.h>
#include "osa_types.h"


OSA_API osa_pointer_t _MEM_ALLOC(osa_size_t size,
                                 char *file, char *func, osa_uint32_t line);
OSA_API osa_pointer_t _MEM_REALLOC(osa_pointer_t old_mem, osa_size_t new_size,
                                   char *file, char *func, osa_uint32_t line);

#define osa_mem_alloc(size)     _MEM_ALLOC(size, __FILE__, __func__, __LINE__)
#define osa_mem_realloc(old_mem, new_size)  _MEM_REALLOC(old_mem, new_size, __FILE__, __func__, __LINE__)
#define osa_mem_zero(addr, size)    memset(addr, 0, size)
#define osa_mem_free(mem)           free(mem)


#endif /* OSA_MEM_H_ */
