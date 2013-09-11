/*
 * osa_file.c
 * osa_file.c
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
 
#include <sys/stat.h>
#include "osa_file.h"
#include "osa_error.h"
#include "osa_debug.h"
#include "osa_log.h"


OSA_API osa_err_t osa_file_open(osa_file_t *file, const char *fpath, const char *mode)
{
    OSA_ASSERT(fpath != OSA_NULL);
    
    struct stat statbuf;
    strncpy(file->fpath, fpath, OSA_PATH_MAX);
    file->fp = fopen(fpath, mode);
    if (OSA_NULL == file->fp)
    {
        osa_log_error("failed to open file!\n");
        return OSA_ERR_FOPEN;
    }
    fstat(fileno(file->fp), &statbuf);
    if (statbuf.st_mode & S_IFREG)
    {
        file->fsize = statbuf.st_size;
    }
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_file_close(osa_file_t *file)
{
    if (file->fp)
    {
        fclose(file->fp);
    }
    file->fp = OSA_NULL;
    file->fsize = 0;
    return OSA_ERR_OK;
}

OSA_API osa_size_t osa_file_read(osa_file_t *file, void *out_buf, osa_size_t size)
{
    if (OSA_NULL == file->fp)
    {
        osa_log_error("please open file first!\n");
        return 0;
    }
    return (osa_size_t)fread(out_buf, size, 1, file->fp);
}

OSA_API osa_size_t osa_file_write(osa_file_t *file, void *buf, osa_size_t size)
{
    if (OSA_NULL == file->fp)
    {
        osa_log_error("please open file first!\n");
        return 0;
    }
    return (osa_size_t)fwrite(buf, size, 1, file->fp);
}


OSA_API osa_size_t osa_file_get_size(osa_file_t *file)
{
    return file->fsize;
}

OSA_API char *osa_file_get_name(osa_file_t *file)
{
    return file->fpath;
}

OSA_API osa_err_t osa_file_unlink(const char *fpath)
{
    OSA_ASSERT(fpath != OSA_NULL);

    if (0 != unlink(fpath))
    {
        return OSA_ERR_ERR;
    }
    return OSA_ERR_OK;
}
