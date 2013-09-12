/*
 * dummy_test.c
 *
 * Copyright (C) TuoAn
 *
 */
 
 
#include "test.h"
#include "test_data.h"
#include "cat.h"
#include "log.h"


#define     TEST_DEFAULT_PRIORITY       100


CAT_TestResult  dummyTestStart(CAT_TestCase *testCase);       // 开始测试
void            dummySuccessCall(void *data);                 // 测试成功后调用
void            dummyFailedCall(void *data);                  // 测试失败后调用


static CAT_TestPoint   dummyTestPoint = 
{
    .name       = "dummyTest",
    .priority   = TEST_DEFAULT_PRIORITY,
    .result     = CAT_TEST_FAILED,
    .startTest  = dummyTestStart,
    .stopTest   = NULL,
    .successFunc= dummySuccessCall,
    .failedFunc = dummyFailedCall,
};


CAT_TestResult  dummyTestStart(CAT_TestCase *testCase)
{
    CAT_LogInfo("start test dummy module!\n");
    
    return CAT_TEST_FAILED;
}


void            dummySuccessCall(void *data)
{
    CAT_LogInfo("dummy test success call!\n");
    
}


void            dummyFailedCall(void *data)
{
    CAT_LogInfo("dummy test failed call!\n");
    
}


CAT_TestPoint   *dummyGetTPObj()
{
    return &dummyTestPoint;
}

