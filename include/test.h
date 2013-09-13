/*
 * cat_test.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef ATS_TEST_H_
#define ATS_TEST_H_


#include "osa.h"
#include "ats.h"
#include "report.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef enum
{
    ATS_TEST_SUCCESS = 0,
    ATS_TEST_FAILED = -1,
}ATS_TestResult;


// 测试用例容器
struct _ATS_TEST_CASE_BOX
{
    osa_uint32_t        caseNum;                // 测试用例数量
    osa_uint32_t        caseSize;               // 每个测试用例大小
    void                *privData;              // 测试用例数据地址
};


// 把测试用例集和用例容器盒子关联. 
// 注意：关联意味着privData只是指向，不申请内存，请不要使用栈上的数据,否则可能出现未知错误
void            ATS_TestCaseBoxAssociate(ATS_TestCaseBox *self, osa_uint32_t num, osa_uint32_t size, void *priv);


// 测试点
struct _ATS_TEST_POINT
{
    char            *name;                      // 测试点名字
    osa_uint32_t    priority;                   // 测试优先级，数字越小优先级越大
    ATS_TestCaseBox testCaseBox;                // 测试用例容器
    ATS_TestResult  result;                     // 测试结果
    
    osa_list_t      list;                       // 链表
    
    ATS_TestResult  (*startTest)(void *testCase);               // 开始测试
    void            (*stopTest)();                              // 停止测试, 现在没有使用
    void            (*successFunc)(ATS_TestPoint *self);        // 测试成功后调用
    void            (*failedFunc)(ATS_TestPoint *self);         // 测试失败后调用

    ATS_Report      *report;                    // 报告
};


ATS_TestPoint   *ATS_TestPointFind(const char *name);
osa_err_t       ATS_TestPointRegister(ATS_TestPoint *self);
osa_err_t       ATS_TestPointUnregister(ATS_TestPoint *self);

// 新建一个测试
ATS_TestPoint   *ATS_TestPointNew(const char *name);
void            ATS_TestPointDelete(ATS_TestPoint *self);

osa_err_t       ATS_TestModuleInit();
void            ATS_TestModuleExit();

// 解析测试模块文件
osa_err_t       ATS_TestParseTemplete(const char *file);

// 开始所有的测试
osa_err_t       ATS_TestStartAll();

// 释放测试中申请的资源
void            ATS_TestReleaseResource();



#ifdef __cplusplus
}
#endif

#endif /* ATS_TEST_H_ */
