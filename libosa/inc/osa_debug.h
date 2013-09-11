/*
 * osa_debug.h
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

#ifndef OSA_DEBUG_H_
#define OSA_DEBUG_H_

#include "osa_log.h"

#ifndef OSA_DISABLE_DEBUG
#define OSA_ASSERT(condition)   do { \
    if (!(condition)) { \
        printf("Assert failed: (%s)[%s, %s, %d]\n", #condition, __FILE__, __func__, __LINE__); \
        getchar(); \
        exit(-1); \
    } \
}while(0)
#define OSA_DEBUG(fmt, args...)   osa_log_debug(fmt, ##args)
#else
#define OSA_ASSERT(condition)
#define OSA_DEBUG(fmt, args...)
#endif

#endif /* OSA_DEBUG_H_ */
