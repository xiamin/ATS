/*
 * osa_dir.h
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

#ifndef OSA_DIR_H_
#define OSA_DIR_H_

#include "osa_types.h"

typedef struct _OSA_DIR     osa_dir_t;
typedef struct _OSA_DIRENT  osa_dirent_t;

/**
 * make directory
 * @param dpath directory path
 * @param flags flags
 * @return error code 
 */
OSA_API osa_err_t osa_dir_make(const char *dpath, osa_uint32_t flags);

/**
 * remove directory
 * @param dpath directory path
 * @return error code
 */
OSA_API osa_err_t osa_dir_remove(const char *dpath);

/**
 * open directory
 * @param dir directory object
 * @param dpath directory path
 * @param flags flags
 * @return error code 
 */
OSA_API osa_err_t osa_dir_open(osa_dir_t *dir, const char *dpath, osa_uint32_t flags);

/**
 * close directory
 * @param dir directory object
 * @return error code
 */
OSA_API osa_err_t osa_dir_close(osa_dir_t *dir);

/**
 * read directory
 * @param dir directory object
 * @param [out] out_dent output directory entry
 * @return error code
 */
OSA_API osa_err_t osa_dir_read(osa_dir_t *dir, osa_dirent_t *out_dent);

#endif /* OSA_DIR_H_ */
