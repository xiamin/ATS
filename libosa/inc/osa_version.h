/*
 * osa_version.h
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

#ifndef OSA_VERSION_H_
#define OSA_VERSION_H_

#define OSA_MAJOR       0
#define OSA_MINOR       0
#define OSA_MICRO       1

#define OSA_VERSION_ID     (OSA_MAJOR*100)+(OSA_MINOR)*10+(OSA_MICRO)

#define OSA_VERSION(major, minor, micro)    ((major)*100) + ((minor)*10) + ((micro)*1)


#endif /* OSA_VERSION_H_ */
