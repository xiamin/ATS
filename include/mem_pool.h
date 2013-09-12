/*
 * mem.h
 *
 * Copyright (C) TuoAn
 *
 */
 
 
#ifndef MEM_POOL_H_
#define MEM_POOL_H_


#include "osa.h"
#include "cat.h"


struct _CAT_MEMORY_POOL
{
    osa_list_t      list;           // 内存池链表
    
    osa_size_t      size;           // 内存池大小
    void            *addr;          // 内存池地址
};


CAT_MemPool *CAT_MemPoolNew();
void        CAT_MemPoolDelete();


osa_err_t   CAT_MemPoolModuleInit();
void        CAT_MemPoolModuleExit();


void        *CAT_MemAlloc(osa_size_t size);
void        CAT_MemFree(void *ptr);


#endif