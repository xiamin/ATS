/*
 * osa_msg.h
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

#ifndef OSA_IOCHANNEL_H_
#define OSA_IOCHANNEL_H_

#include "osa_types.h"
#include "osa_error.h"

typedef enum
{
    OSA_IOCH_INITIALIZED = 0x01,
    OSA_IOCH_OPENED = 0x02,
    OSA_IOCH_LOCKED = 0x04,
}osa_ioch_flag_t;

typedef struct _OSA_IO_CHANNEL
{
    osa_fd_t fd;
    osa_uint32_t flags;
}
osa_ioch_t;

#define _IOCH_IS_INITIALIZED(ioch)   ((ioch)->flags & OSA_IOCH_INITIALIZED)
#define _IOCH_IS_OPENED(ioch)   ((ioch)->flags & OSA_IOCH_OPENED)
#define _IOCH_IS_LOCKED(ioch)   ((ioch)->flags & OSA_IOCH_LOCKED)

/**
 * initialize I/O channel
 * @param ioch I/O channel object
 * @param fd file descriptor bind with io channel
 * @param flags flags
 * @return error code 
 */
OSA_API osa_err_t osa_ioch_init(osa_ioch_t *ioch, osa_fd_t fd, osa_ioch_flag_t flags);

/**
 * Finalize I/O channel
 * @param ioch I/O channel object
 */
OSA_API void osa_ioch_fini(osa_ioch_t *ioch);

/**
 * open I/O channel
 * @param ioch I/O channel object
 * @return error code
 */
OSA_API osa_err_t osa_ioch_open(osa_ioch_t *ioch);

/**
 * close I/O object
 * @param ioch I/O channel object
 * @return error code
 */
OSA_API osa_err_t osa_ioch_close(osa_ioch_t *ioch);

/**
 * bind I/O channel with new file descriptor
 * @param ioch I/O channel object
 * @param new_fd new file descriptor
 * @return error code
 */
OSA_API osa_err_t osa_ioch_bind(osa_ioch_t *ioch, osa_fd_t new_fd);

typedef enum
{
    OSA_IOCH_CMD_LOCK=0,        // lock I/O channel
    OSA_IOCH_CMD_UNLOCK,        // unlock I/O channel

    _IOCH_CMD_MAX,
}osa_ioch_cmd_t;

/**
 * control I/O channel
 * @param ioch I/O channel object
 * @return error code 
 */
OSA_API osa_err_t osa_ioch_ctrl(osa_ioch_t *ioch, osa_ioch_cmd_t cmd);

#endif /* OSA_MSG_H_ */
