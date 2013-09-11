/*
 * osa_dll.c
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

#include "osa_dll.h"
#include "osa_stddef.h"
#include "osa_error.h"
#include "osa_debug.h"
#include "osa_log.h"

struct _OSA_DLL
{
    char dname[OSA_NAME_MAX];
    osa_pointer_t dhandler;
};

OSA_API osa_err_t osa_dll_load(osa_dll_t *dll, const char *dllpath, osa_uint32_t flags)
{
    OSA_ASSERT(dllpath != OSA_NULL);

    strncpy(dll->dname, dllpath, OSA_PATH_MAX);
    dll->dhandler = dlopen(dllpath, flags);
    if (dll->dhandler == OSA_NULL)
    {
        osa_log_error("failed to load dll: %s\n", dllpath);
        return OSA_ERR_ERR;
    }
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_dll_unload(osa_dll_t *dll)
{
    if (dll->dhandler != OSA_NULL)
    {
        dlclose(dll->dhandler);
    }
    dll->dhandler = OSA_NULL;
    return OSA_ERR_OK;
}

OSA_API osa_pointer_t osa_dll_sym(osa_dll_t *dll, const char *symbol)
{
    OSA_ASSERT(symbol != OSA_NULL);

    osa_pointer_t p = OSA_NULL;
    if (OSA_NULL != dll->dhandler)
    {
        p = dlsym(dll->dhandler, symbol);
        if (OSA_NULL == p)
        {
            osa_log_error("failed to find symbol: %s\n", symbol);
            return OSA_NULL;
        }
        return p;
    }
    return OSA_NULL;
}
