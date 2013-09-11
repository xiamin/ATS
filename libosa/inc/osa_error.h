/*
 * osa_error.h
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

#ifndef OSA_ERROR_H_
#define OSA_ERROR_H_

#include "osa_types.h"
#include "osa_log.h"

typedef signed int osa_err_t;


#define     OSA_ERR_OK          0
#define     OSA_ERR_ERR         -1
#define     OSA_ERR_NOMEM       -2
#define     OSA_ERR_FOPEN       -3
#define     OSA_ERR_SOCKET      -4


#define OSA_RETURN_IF_FAIL(condition)   do { \
    if (!(condition)) { \
        osa_log_error("<%s, %s, %n>Check failed!\n", __FILE__, __func__, __LINE__); \
        return; \
    } \
}while(0)

#define OSA_RETURN_VAL_IF_FAIL(condition, retval)   do { \
    if (!(condition)) { \
        osa_log_error("<%s, %s, %n>Check failed!\n", __FILE__, __func__, __LINE__); \
        return retval;  \
    } \
}while(0)


#endif /* OSA_ERROR_H_ */
