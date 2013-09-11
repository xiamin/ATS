/*
 * osa_log.h
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

#ifndef OSA_LOG_H_
#define OSA_LOG_H_

#include <stdio.h>
#include "osa_types.h"

#ifndef OSA_DISABLE_LOG

#define osa_log_fatal(fmt, msg...) do { \
    printf("[FATAL]"fmt, ##msg); \
    exit(-1); \
}while(0)

#define osa_log_error(fmt, msg...) do { \
    printf("[ERROR]"fmt, ##msg); \
}while(0)

#define osa_log_warn(fmt, msg...) do { \
    printf("[WARN]"fmt, ##msg); \
}while(0)

#define osa_log_info(fmt, msg...) do { \
    printf("[INFO]"fmt, ##msg); \
}while(0)

#else

#define osa_log_fatal(fmt, msg...)
#define osa_log_error(fmt, msg...)
#define osa_log_warn(fmt, msg...)
#define osa_log_info(fmt, msg...)

#endif


#ifdef OSA_DISABLE_LOG
#define OSA_DISALBE_DEBUG
#endif

#ifndef OSA_DISALBE_DEBUG
#define osa_log_debug(fmt, msg...) do { \
    printf("[DEBUG]<%s, %d>"fmt, __FILE__, __LINE__, ##msg); \
}while (0)

#else

static osa_inline osa_log_debug(fmt, msg){}
#endif


#endif /* OSA_LOG_H_ */
