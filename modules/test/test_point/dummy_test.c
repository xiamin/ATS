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


ATS_TestResult  dummyTestStart(ATS_TestCaseBox *testCase);       // 开始测试
void            dummySuccessCall(ATS_TestPoint *self);                 // 测试成功后调用
void            dummyFailedCall(ATS_TestPoint *self);                  // 测试失败后调用


static ATS_TestPoint   dummyTestPoint = 
{
    .name       = "dummyTest",
    .priority   = TEST_DEFAULT_PRIORITY,
    .result     = ATS_TEST_FAILED,
    .startTest  = dummyTestStart,
    .stopTest   = NULL,
    .successFunc= dummySuccessCall,
    .failedFunc = dummyFailedCall,
};


ATS_TestResult  dummyTestStart(ATS_TestCaseBox *testCase)
{
    ATS_LogInfo("start test dummy module!\n");
    
    return ATS_TEST_FAILED;
}


void            dummySuccessCall(ATS_TestPoint *self)
{
    ATS_LogInfo("dummy test success call!\n");
    
}


void            dummyFailedCall(ATS_TestPoint *self)
{
    ATS_LogInfo("dummy test failed call!\n");
    
}


ATS_TestPoint   *dummyGetTPObj()
{
    return &dummyTestPoint;
}

