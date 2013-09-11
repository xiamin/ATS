/*
 * osa_dir.c
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

#include <dirent.h>
#include "osa_debug.h"
#include "osa_error.h"
#include "osa_types.h"
#include "osa_log.h"
#include "osa_dir.h"

struct _OSA_DIR
{
    DIR *dir;
};

struct _OSA_DIRENT
{
    struct dirent *dent;
};

OSA_API osa_err_t osa_dir_make(const char *dpath, osa_uint32_t flags)
{
    OSA_ASSERT(dpath != OSA_NULL);

    if (!mkdir(dpath, flags))
    {
        osa_log_error("failed to make directory : %s!\n", dpath);
        return OSA_ERR_ERR;
    }
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_dir_remove(const char *dpath)
{
    OSA_ASSERT(dpath != OSA_NULL);

    if (!rmdir(dpath))
    {
        osa_log_error("failed to remove directory :%s\n", dpath);
        return OSA_ERR_ERR;
    }
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_dir_open(osa_dir_t *dir, const char *dpath, osa_uint32_t flags)
{
    OSA_ASSERT(dpath != OSA_NULL);

    dir->dir = opendir(dpath);
    if (OSA_NULL == dir->dir)
    {
        osa_log_error("failed to open directory : %s\n", dpath);
        return OSA_ERR_ERR;
    }
    return OSA_ERR_ERR;
}

OSA_API osa_err_t osa_dir_close(osa_dir_t *dir)
{
    if (dir->dir)
    {
        closedir(dir->dir);
    }
    dir->dir = OSA_NULL;
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_dir_read(osa_dir_t *dir, osa_dirent_t *out_dent)
{
    if (dir->dir == OSA_NULL)
    {
        osa_log_error("please open directory first\n");
        return OSA_ERR_ERR;
    }
    out_dent->dent = readdir(dir->dir);
    if (out_dent->dent == OSA_NULL)
    {
        osa_log_error("failed to read directory!\n");
        return OSA_ERR_ERR;
    }
    return OSA_ERR_OK;
}
