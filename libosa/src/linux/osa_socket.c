/*
 * osa_socket.c
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

#include <sys/un.h>
#include <linux/in.h>
#include <sys/socket.h>

#include "osa_socket.h"
#include "osa_types.h"
#include "osa_error.h"
#include "osa_debug.h"
#include "osa_log.h"
#include "osa_mem.h"

#define OSA_LINK_MAX    5

OSA_API osa_err_t osa_unsock_init(osa_unsock_t *sock, const char *local_spath)
{
    OSA_ASSERT(local_spath != OSA_NULL);

    strncpy(sock->local_addr.spath, local_spath, OSA_PATH_MAX);
    sock->sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock->sfd <= 0)
    {
        osa_log_error("failed to initialize socket\n");
        return OSA_ERR_SOCKET;
    }

    struct sockaddr_un my_addr;
    osa_mem_zero(&my_addr, sizeof(struct sockaddr_un));
    my_addr.sun_family = AF_UNIX;
    strcpy(my_addr.sun_path, local_spath);

    if (bind(sock->sfd, &my_addr, sizeof(struct sockaddr_un)) < 0)
    {
        osa_log_error("failed to bind Unix socket : %s\n", local_spath);
        return OSA_ERR_SOCKET;
    }

    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_unsock_fini(osa_unsock_t *sock)
{
    if (sock->sfd > 0)
    {
        close(sock->sfd);
    }
    sock->sfd = -1;
    return OSA_ERR_OK;
}

OSA_API void osa_unsock_set_dest_addr(osa_unsock_t *sock, const char *remote_spath)
{
    OSA_ASSERT(remote_spath != OSA_NULL);

    strncpy(sock->remote_addr.spath, remote_spath, OSA_PATH_MAX);
}

OSA_API char *osa_unsock_get_dest_addr(osa_unsock_t *sock)
{
    return sock->remote_addr.spath;
}

OSA_API osa_err_t osa_unsock_send(osa_unsock_t *sock, char *buf, osa_size_t size)
{
    OSA_ASSERT(sock->sfd > 0);

    struct sockaddr_un remote_addr;
    osa_mem_zero(&remote_addr, sizeof(struct sockaddr_un));
    remote_addr.sun_family = AF_UNIX;
    strcpy(remote_addr.sun_path, sock->remote_addr.spath);

    osa_size_t sz = sendto(sock->sfd, buf, size, 0, &remote_addr, sizeof(remote_addr));
    if (sz != size)
    {
        osa_log_warn("%d bytes data sent\n", sz);
    }
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_unsock_recv(osa_unsock_t *sock, char *out_buf, osa_size_t size)
{
    OSA_ASSERT(sock->sfd > 0);

    struct sockaddr_un remote_addr;
    osa_mem_zero(&remote_addr, sizeof(struct sockaddr_un));

    osa_size_t sz = recvfrom(sock->sfd, out_buf, size, 0, &remote_addr, sizeof(remote_addr));
    if (sz != size)
    {
        osa_log_warn("%d bytes data sent\n", sz);
    }
    strncpy(sock->remote_addr.spath, remote_addr.sun_path, OSA_PATH_MAX);
    return OSA_ERR_OK;
}


OSA_API osa_err_t osa_insock_client_init(osa_insock_t *sock, const char *server_ip, osa_uint32_t server_port)
{
    OSA_ASSERT(server_ip != OSA_NULL);
    OSA_ASSERT(server_port > 0);

    struct sockaddr_in server_addr;
    osa_mem_zero(&server_addr, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);
    bzero( &(server_addr.sin_zero), 8 );

    sock->sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock->sfd <= 0)
    {
        osa_log_error("failed to initialize Internet socket\n");
        return OSA_ERR_SOCKET;
    }

    if (connect(sock->sfd, &server_addr, sizeof(struct sockaddr)) < 0)
    {
        osa_log_error("failed to connect to server: %s, %d\n", server_ip, server_port);
        return OSA_ERR_SOCKET;
    }
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_insock_client_fini(osa_insock_t *sock)
{
    if (sock->sfd)
    {
        close(sock->sfd);
    }
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_insock_server_init(osa_insock_t *sock, osa_uint32_t port)
{
    OSA_ASSERT(port > 0);

    struct sockaddr_in server_addr;
    osa_uint32_t val = 1;
    osa_mem_zero(&server_addr, sizeof(struct sockaddr_in));

    sock->sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock->sfd <= 0)
    {
        osa_log_error("failed to initialize Internet socket\n");
        return OSA_ERR_SOCKET;
    }
    setsockopt(sock->sfd, SOL_SOCKET, SO_REUSEADDR, (char *) &val, sizeof (val));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero( &(server_addr.sin_zero), 8 );
    if(bind(sock->sfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        osa_log_error("failed to bind Internet socket\n");
        return OSA_ERR_SOCKET;
    }
    if (listen(sock->sfd, OSA_LINK_MAX) < 0)
    {
        osa_log_error("failed to listen socket\n");
        return OSA_ERR_SOCKET;
    }
    return OSA_ERR_OK;
}

OSA_API osa_err_t osa_insock_server_fini(osa_insock_t *sock)
{
    if (sock->sfd)
    {
        close(sock->sfd);
    }
    sock->sfd = -1;
    return OSA_ERR_OK;
}

OSA_API osa_fd_t osa_insock_server_accept(osa_insock_t *sock)
{
    OSA_ASSERT(sock->sfd > 0);

    struct sockaddr_in client_addr;
    osa_mem_zero(&client_addr, sizeof(struct sockaddr_in));

    osa_fd_t new_fd = accept(sock->sfd, &client_addr, sizeof(struct sockaddr_in));
    if (new_fd < 0)
    {
        osa_log_error("failed to accept: %s\n", new_fd);
        return -1;
    }
    strncpy(sock->client_addr.ip, inet_ntoa(client_addr.sin_addr), OSA_NAME_MAX);
    sock->client_addr.port = ntohl(client_addr.sin_port);
    return new_fd;
}

OSA_API osa_size_t osa_insock_send(osa_insock_t *sock, const char *buf, osa_size_t size)
{
    OSA_ASSERT(sock->sfd > 0);

    osa_size_t sz = send(sock->sfd, buf, size, MSG_NOSIGNAL);
    if (sz != size)
    {
        osa_log_warn("%d bytes sent\n", sz);
    }
    return OSA_ERR_OK;
}

OSA_API osa_size_t osa_insock_recv(osa_insock_t *sock, char *out_buf, osa_size_t size)
{
    OSA_ASSERT(out_buf != OSA_NULL);

    osa_size_t sz = recv(sock->sfd, out_buf, size, MSG_NOSIGNAL);
    if (sz != size)
    {
        osa_log_warn("%d bytes received\n", sz);
    }
    return OSA_ERR_OK;
}

