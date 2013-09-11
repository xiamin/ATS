/*
 * osa_i18n.h
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

#ifndef OSA_I18N_H_
#define OSA_I18N_H_

#include <libintl.h>
#include <string.h>

#define  _(string) gettext (string)
#define N_(string) (string)
#define C_(context,string) g_dpgettext (NULL, context "\004" string, strlen (context) + 1)
#define NC_(context, string) (string)

#endif /* OSA_I18N_H_ */
