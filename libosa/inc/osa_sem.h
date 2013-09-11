/*
 * osa_sem.h
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

#ifndef OSA_SEM_H_
#define OSA_SEM_H_

#include "osa_types.h"

typedef struct _OSA_SEM     osa_sem_t;

OSA_API void osa_sem_init(osa_sem_t *sem, osa_uint32_t value);
OSA_API osa_sem_t *osa_sem_new(osa_uint32_t value);
OSA_API void osa_sem_delete(osa_sem_t *sem);

#endif /* OSA_SEM_H_ */
