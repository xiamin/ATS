/*
 * cat_test.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CAT_TEST_H_
#define CAT_TEST_H_


#include "osa.h"
#include "cat.h"
#include "report.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef enum
{
    CAT_TEST_SUCCESS = 0,
    CAT_TEST_FAILED = -1,
}CAT_TestResult;


// 测试用例
struct _CAT_TEST_CASE
{
    osa_uint32_t        caseNum;                // 测试用例数量
    osa_uint32_t        caseSize;               // 每个测试用例大小
    void                *privData;              // 测试用例数据地址
};


// 设置测试用例
void            CAT_TestCaseSet(CAT_TestCase *self, osa_uint32_t num, osa_uint32_t size, void *priv);


// 测试点
struct _CAT_TEST_POINT
{
    char            *name;                      // 测试点名字
    osa_uint32_t    priority;                   // 测试优先级，数字越小优先级越大
    CAT_TestCase    testCase;                   // 测试用例
    CAT_TestResult  result;                     // 测试结果
    
    osa_list_t      list;                       // 链表
    
    CAT_TestResult  (*startTest)(CAT_TestCase *testCase);       // 开始测试
    void            (*stopTest)();                              // 停止测试, 现在没有使用
    void            (*successFunc)(CAT_TestPoint *self);                 // 测试成功后调用
    void            (*failedFunc)(CAT_TestPoint *self);                  // 测试失败后调用

    CAT_Report      *report;                    // 报告
};


CAT_TestPoint   *CAT_TestPointFind(const char *name);
osa_err_t       CAT_TestPointRegister(CAT_TestPoint *self);
osa_err_t       CAT_TestPointUnregister(CAT_TestPoint *self);

// 新建一个测试
CAT_TestPoint   *CAT_TestPointNew(const char *name);
void            CAT_TestPointDelete(CAT_TestPoint *self);

osa_err_t       CAT_TestModuleInit();
void            CAT_TestModuleExit();

// 解析测试模块文件
osa_err_t       CAT_TestParseTemplete(const char *file);

// 开始所有的测试
osa_err_t       CAT_TestStartAll();

// 释放测试中申请的资源
void            CAT_TestReleaseResource();



#ifdef __cplusplus
}
#endif

#endif /* CAT_TEST_H_ */
