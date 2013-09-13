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


struct _ATS_MEMORY_POOL
{
    osa_list_t      list;           // 内存池链表
    
    osa_size_t      size;           // 内存池大小
    void            *addr;          // 内存池地址
};


ATS_MemPool *ATS_MemPoolNew();
void        ATS_MemPoolDelete();


osa_err_t   ATS_MemPoolModuleInit();
void        ATS_MemPoolModuleExit();


void        *ATS_MemAlloc(osa_size_t size);
void        ATS_MemFree(void *ptr);


#endif