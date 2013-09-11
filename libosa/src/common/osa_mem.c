/*
 * osa_mem.c
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

#include "osa_mem.h"
#include "osa_error.h"
#include "osa_debug.h"
#include "osa_log.h"

OSA_API osa_pointer_t _MEM_ALLOC(osa_size_t size,
                                 char *file, char *func, osa_uint32_t line)
{
    OSA_ASSERT(size > 0);

    osa_pointer_t p = (osa_pointer_t)malloc(size);
    if (!p)
    {
        osa_log_error("failed to allocate memory!\n");
        return OSA_NULL;
    }
    osa_mem_zero(p, size);
    return p;
}

OSA_API osa_pointer_t _MEM_REALLOC(osa_pointer_t old_mem, osa_size_t new_size,
                                   char *file, char *func, osa_uint32_t line)
{
    OSA_ASSERT(new_size > 0);

    osa_pointer_t p = (osa_pointer_t)realloc(old_mem, new_size);
    if (!p)
    {
        osa_log_error("failed to re-allocate memory!\n");
        return OSA_NULL;
    }
    osa_mem_zero(p, new_size);
    return p;
}
