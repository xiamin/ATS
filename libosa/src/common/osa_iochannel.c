/*
 * osa_iochannel.c
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


#include "osa_iochannel.h"
#include "osa_types.h"
#include "osa_error.h"
#include "osa_log.h"
#include "osa_debug.h"

OSA_API osa_err_t osa_ioch_init(osa_ioch_t *ioch, osa_fd_t fd, osa_ioch_flag_t flags)
{
    OSA_ASSERT(fd >= 0);
    ioch->fd = fd;
    ioch->flags |= OSA_IOCH_INITIALIZED;
    return OSA_ERR_OK;
}

OSA_API void osa_ioch_fini(osa_ioch_t *ioch)
{
    ioch->fd = -1;
    ioch->flags = 0;
}

OSA_API osa_err_t osa_ioch_open(osa_ioch_t *ioch)
{
    if (_IOCH_IS_LOCKED(ioch))
    {
        osa_log_warn("I/O channel locked, please unlock first!\n");
        return OSA_ERR_ERR;
    }
    if (ioch->fd < 0)
    {
        osa_log_error("please bind FD with I/O channel first!\n");
        return OSA_ERR_ERR;
    }
    ioch->flags |= OSA_IOCH_OPENED;
    osa_ioch_ctrl(ioch, OSA_IOCH_CMD_LOCK);

    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_ioch_close(osa_ioch_t *ioch)
{
    if (_IOCH_IS_LOCKED(ioch))
    {
        osa_log_warn("I/O channel locked, please unlock first!\n");
        return OSA_ERR_ERR;
    }
    ioch->fd = -1;
    ioch->flags &= ~OSA_IOCH_OPENED;
    osa_ioch_ctrl(ioch, OSA_IOCH_CMD_UNLOCK);

    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_ioch_bind(osa_ioch_t *ioch, osa_fd_t new_fd)
{
    if (_IOCH_IS_LOCKED(ioch))
    {
        osa_log_warn("I/O channel locked, please unlock first!\n");
        return OSA_ERR_ERR;
    }
    ioch->fd = new_fd;
    ioch->flags = OSA_IOCH_INITIALIZED | OSA_IOCH_OPENED;
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_ioch_ctrl(osa_ioch_t *ioch, osa_ioch_cmd_t cmd)
{
    if (_IOCH_IS_LOCKED(ioch))
    {
        osa_log_warn("I/O channel locked, please unlock first!\n");
        return OSA_ERR_ERR;
    }
    switch (cmd)
    {
    case OSA_IOCH_CMD_LOCK:
        ioch->flags |= OSA_IOCH_LOCKED;
        break;
    case OSA_IOCH_CMD_UNLOCK:
        ioch->flags &= ~OSA_IOCH_LOCKED;
        break;
    default:
        osa_log_error("unknown I/O contorl command: %d\n", cmd);
        break;
    }
    return OSA_ERR_OK;
}

