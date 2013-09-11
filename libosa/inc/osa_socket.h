/*
 * osa_socket.h
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

#ifndef OSA_SOCKET_H_
#define OSA_SOCKET_H_

#include "osa_types.h"
#include "osa_stddef.h"
#include "osa_error.h"

/** Unix/local socket */
typedef struct _OSA_UNIX_SOCKET_ADDR
{
    char    spath[OSA_PATH_MAX];
}
osa_unsock_addr_t;

typedef struct
{
    osa_fd_t    sfd;
    osa_unsock_addr_t local_addr;
    osa_unsock_addr_t remote_addr;
}
osa_unsock_t;

/**
 * initialize Unix socket
 * @param sock socket object
 * @param local_spath local socket path
 * @return error code
 */
OSA_API osa_err_t osa_unsock_init(osa_unsock_t *sock, const char *local_spath);

/**
 * Finalize Unix socket
 * @param sock socket object
 * @return error code
 */
OSA_API osa_err_t osa_unsock_fini(osa_unsock_t *sock);

/**
 * set the destination of socket
 * @param sock socket object
 * @param remote_spath remote socket path
 * @return error code
 */
OSA_API void osa_unsock_set_dest_addr(osa_unsock_t *sock, const char *remote_spath);

/**
 * get the destination of socket
 * @param sock socket object
 * @return socket path
 */
OSA_API char *osa_unsock_get_dest_addr(osa_unsock_t *sock);

/**
 * send data to destination
 * @param sock socket object
 * @param buf data to be sent
 * @param size size of data
 * @return error code
 */
OSA_API osa_err_t osa_unsock_send(osa_unsock_t *sock, char *buf, osa_size_t size);

/**
 * receive data from destination
 * @param sock socket object
 * @param [out] out_buf output buffer
 * @param size size of data
 * @param [out] out_addr output address
 * @return error code
 */
OSA_API osa_err_t osa_unsock_recv(osa_unsock_t *sock, char *out_buf, osa_size_t size);


/** Internet socket */
typedef struct _OSA_INET_SOCKET_ADDR
{
    char    ip[OSA_NAME_MAX];
    osa_uint32_t    port;
}
osa_insock_addr_t;

typedef struct _OSA_INET_SOCKET
{
    osa_fd_t sfd;
    osa_insock_addr_t client_addr;
    osa_insock_addr_t server_addr;
}osa_insock_t;

/**
 * initialize client socket
 * @param sock socket object
 * @param server_ip ip of server
 * @param server_port port of server
 * @return error code
 */
OSA_API osa_err_t osa_insock_client_init(osa_insock_t *sock, const char *server_ip, osa_uint32_t server_port);

/**
 * Finalize client socket
 * @param sock socket object
 * @return error code
 */
OSA_API osa_err_t osa_insock_client_fini(osa_insock_t *sock);

/**
 * initialize server socket
 * @param sock socket object
 * @param port port of server
 * @return error code
 */
OSA_API osa_err_t osa_insock_server_init(osa_insock_t *sock, osa_uint32_t port);

/**
 * Finalize server socket
 * @param sock socket object
 * @return error code
 */
OSA_API osa_err_t osa_insock_server_fini(osa_insock_t *sock);

/**
 * server socket accept
 * @param sock socket object
 * @return new socket file descriptor
 */
OSA_API osa_fd_t osa_insock_server_accept(osa_insock_t *sock);

/**
 * send data
 * @param sock socket object
 * @param buf data to be send
 * @param size size of data
 * @return size of sending
 */
OSA_API osa_size_t osa_insock_send(osa_insock_t *sock, const char *buf, osa_size_t size);

/**
 * receive data
 * @param sock socket object
 * @param [out] out_buf output buffer
 * @param size size of data
 * @return size of receiving
 */
OSA_API osa_size_t osa_insock_recv(osa_insock_t *sock, char *out_buf, osa_size_t size);

#endif /* OSA_SOCKET_H_ */
