/*
 * osa_dll.h
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

#ifndef OSA_DLL_H_
#define OSA_DLL_H_

#include <dlfcn.h>
#include "osa_types.h"
#include "osa_error.h"

typedef struct _OSA_DLL     osa_dll_t;

/**
 * dll bind flags
 */
#define OSA_DBIND_LAZY      RTLD_LAZY
#define OSA_DBIND_LOCAL     RTLD_LOCAL

/**
 * load dynamic library
 * @param dll dll object
 * @param dllpath path of dll
 * @param flags dll bind flags
 * @return error code
 */
OSA_API osa_err_t osa_dll_load(osa_dll_t *dll, const char *dllpath, osa_uint32_t flags);

/**
 * unload dynamic library
 * @param dll dll object
 * @return error code
 */
OSA_API osa_err_t osa_dll_unload(osa_dll_t *dll);

/**
 * find symbol from dll
 * @param dll dll object
 * @param symbol symbol
 * @return if found, return pointer point to the symbol.
 */
OSA_API osa_pointer_t osa_dll_sym(osa_dll_t *dll, const char *symbol);


#endif /* OSA_DLL_H_ */
