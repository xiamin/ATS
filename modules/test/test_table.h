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


ATS_TestPoint   *dummyGetTPObj();


typedef struct _SLOT
{
    char            *name;                      // 名字
    ATS_TestPoint   *(*getTestPoint)();          // 测试点结构体
}TEST_NameSlot;


#define NAME_SLOT(name, slot)   {name, slot}


// 系统中支持的测试表
TEST_NameSlot    g_testPointTable[] =
{
#ifdef ATS_USING_VERSION_TEST
    NAME_SLOT("VersionTest", testGetTPObj),
#endif

#ifdef ATS_USING_DUMMY_TEST
    NAME_SLOT("DummyTest", dummyGetTPObj),
#endif
};

#define TEST_POINT_ELE_NUM      (sizeof(g_testPointTable)/sizeof(g_testPointTable[0]))



static inline ATS_TestPoint   *TEST_GetSlotTestPoint(const char *name)
{
    osa_uint32_t i;
    for (i=0; i<TEST_POINT_ELE_NUM; i++)
    {
        if (!(strcmp(g_testPointTable[i].name, name)))
            return g_testPointTable[i].getTestPoint();
    }
}



#ifdef __cplusplus
}
#endif

#endif
