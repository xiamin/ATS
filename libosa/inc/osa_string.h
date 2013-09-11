/*
 * osa_string.h
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

#ifndef OSA_STRING_H_
#define OSA_STRING_H_

#include "osa_types.h"


typedef struct _OSA_STRING
{
    char        *str;
    osa_size_t  len;
}
osa_string_t;


/**
 * set string value
 * @param string string object
 * @param c_strs c string
 */
OSA_API static inline void osa_string_set(osa_string_t *string, const char *c_strs)
{
    string->len = strlen(c_strs);
    string->str = c_strs;
}

/**
 * is string empty
 * @param string string object
 * @return boolean value
 */
OSA_API static inline osa_bool_t osa_string_is_empty(osa_string_t *string)
{
    return (string->str == NULL)? OSA_TRUE: OSA_FALSE;
}

/**
 * get c string by string object
 * @param string string object
 * @return c string pointer
 */
OSA_API static inline char *osa_string_2_cstr(osa_string_t *string)
{
    return string->str;
}

#endif /* OSA_STRING_H_ */
