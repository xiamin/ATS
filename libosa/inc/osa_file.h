/*
 * osa_file.h
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

#ifndef OSA_FILE_H_
#define OSA_FILE_H_

#include <stdio.h>

#include "osa_types.h"
#include "osa_stddef.h"
#include "osa_error.h"

#define OSA_FMODE_RDONLY    "r"
#define OSA_FMODE_WRONLY    "w"
#define OSA_FMODE_RDWR      "w+"
#define OSA_FMODE_APPEND    "a"


typedef struct _OSA_FILE
{
    char        fpath[OSA_PATH_MAX];
    FILE        *fp;
    osa_size_t  fsize;
}osa_file_t;



/**
 * file open
 * @param file file object
 * @param fpath file path
 * @param mode file mode
 * @return error code
 */
OSA_API osa_err_t osa_file_open(osa_file_t *file, const char *fpath, const char *mode);

/**
 * file close
 * @param file file object
 * @return error code
 */
OSA_API osa_err_t osa_file_close(osa_file_t *file);

/**
 * file read
 * @param file file object
 * @param [out] out_buf output buffer
 * @param size size for reading
 * @return real size of reading
 */
OSA_API osa_size_t osa_file_read(osa_file_t *file, void *out_buf, osa_size_t size);

/**
 * file write
 * @param file file object
 * @param buf buffer
 * @param size size for writing
 * @return real size of writing
 */
OSA_API osa_size_t osa_file_write(osa_file_t *file, void *buf, osa_size_t size);

/**
 * get file size
 * @param file file object
 * @return size of file
 */
OSA_API osa_size_t osa_file_get_size(osa_file_t *file);

/**
 * get file name
 * @param file file object
 * @return file name
 */
OSA_API char *osa_file_get_name(osa_file_t *file);

/**
 * unlink file
 * @param fpath file path
 * @return error code
 */
OSA_API osa_err_t osa_file_unlink(const char *fpath);

#endif /* OSA_FILE_H_ */
