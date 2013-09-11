/*
 * osa_list.h
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

#ifndef OSA_LIST_H_
#define OSA_LIST_H_

#include "osa_types.h"

/**
 * @addtogroup osa
 */
/*@{*/


typedef struct _LIST_NODE
{
    struct _LIST_NODE *prev;                          /**< point to prev node. */
    struct _LIST_NODE *next;                          /**< point to next node. */
}
osa_list_t;

/**
 * initialize a list
 * @param l list to be initialized
 */
static osa_inline void osa_list_init(osa_list_t *l)
{
    l->next = l->prev = l;
}

/**
 * insert a node after a list
 * @param l list to insert it
 * @param n new node to be inserted
 */
static osa_inline void osa_list_insert_after(osa_list_t *l, osa_list_t *n)
{
    l->next->prev = n;
    n->next = l->next;

    l->next = n;
    n->prev = l;
}

/**
 * insert a node before a list
 * @param n new node to be inserted
 * @param l list to insert it
 */
static osa_inline void osa_list_insert_before(osa_list_t *l, osa_list_t *n)
{
    l->prev->next = n;
    n->prev = l->prev;

    l->prev = n;
    n->next = l;
}

/**
 * remove node from list.
 * @param n the node to remove from the list.
 */
static osa_inline void osa_list_remove(osa_list_t *n)
{
    n->next->prev = n->prev;
    n->prev->next = n->next;

    n->next = n->prev = n;
}

/**
 * tests whether a list is empty
 * @param l the list to test.
 */
static osa_inline int osa_list_isempty(const osa_list_t *l)
{
    return l->next == l;
}

/**
 * get the struct for this entry
 * @param node the entry point
 * @param type the type of structure
 * @param member the name of list in structure
 */
#define osa_list_entry(node, type, member) \
    ((type *)((char *)(node) - (unsigned long)(&((type *)0)->member)))

/*@}*/


/**
 * foreach call for list
 * @param node the entry point
 * @param hook hook call
 * @param ctx context
 */
static osa_inline void osa_list_foreach(osa_list_t *node, void (*hook)(void *param), void *ctx)
{
    osa_list_t *n = node->next;
    for (; n != node; n=n->next)
        hook(ctx);
}


#endif /* OSA_LIST_H_ */
