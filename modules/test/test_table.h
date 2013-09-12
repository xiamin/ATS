/*
 * test_api.h
 *
 * Copyright (C) TuoAn
 *
 */

 
#ifndef TEST_TABLE_H_
#define TEST_TABLE_H_


#include "config.h"


#ifdef __cplusplus
extern "C" {
#endif


CAT_TestPoint   *dummyGetTPObj();


typedef struct _SLOT
{
    char            *name;                      // 名字
    CAT_TestPoint   *(*getTestPoint)();          // 测试点结构体
}TEST_NameSlot;


#define NAME_SLOT(name, slot)   {name, slot}


// 系统中支持的测试表
TEST_NameSlot    g_testPointTable[] =
{
#ifdef CAT_USING_VERSION_TEST
    NAME_SLOT("VersionTest", testGetTPObj),
#endif

#ifdef CAT_USING_DUMMY_TEST
    NAME_SLOT("DummyTest", dummyGetTPObj),
#endif
};



#ifdef __cplusplus
}
#endif

#endif
