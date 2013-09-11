/*
 * osa_rand.c
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

#include <time.h>
#include <stdlib.h>
#include "osa_rand.h"
#include "osa_types.h"
#include "osa_error.h"


OSA_API osa_int32_t osa_random_gen_int32(osa_int32_t min, osa_int32_t max)
{
    struct timeval tpstart;
    osa_int32_t r;

    gettimeofday(&tpstart, OSA_NULL);
    srand(tpstart.tv_usec);

    r = (rand()/(RAND_MAX + 1.0));

    return min + (osa_uint32_t )(r*(max - min));
}

OSA_API osa_double_t osa_random_gen_double(osa_double_t min, osa_double_t max)
{
    struct timeval tpstart;
    osa_double_t r;

    gettimeofday(&tpstart, OSA_NULL);
    srand(tpstart.tv_usec);

    r = (rand()/(RAND_MAX + 1.0));

    return min + (osa_double_t )(r*(max - min));
}
