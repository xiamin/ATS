/*
 * cat_test.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CAT_TEST_H_
#define CAT_TEST_H_


#include "osa.h"


typedef enum
{
    CAT_TEST_SUCCESS = 0,
    CAT_TEST_FAILED = -1,
}CAT_TestResult;


// 测试点
typedef struct _CAT_TEST_POINT
{
    char            name[OSA_NAME_MAX];         // 测试点名字
    osa_uint32_t    priority;                   // 测试优先级，数字越小优先级越大
    void            *param;                     // 测试参数
    CAT_TestResult  result;                     // 测试结果
    
    osa_list_t      list;                       // 链表
    
    osa_uint32_t    (*start)(void *param);      // 开始测试
    void            (*stop)();                  // 停止测试, 现在没有使用
}CAT_TestPoint;


CAT_TestPoint   *CAT_TestPointFind(const char *name);
osa_err_t       CAT_TestPointRegister(CAT_TestPoint *self);
osa_err_t       CAT_TestPointUnregister(CAT_TestPoint *self);

// 新建一个测试
CAT_TestPoint   *CAT_TestPointNew(const char *name);
void            CAT_TestPointDelete(CAT_TestPoint *self);

osa_err_t   CAT_TestModuleInit();
void        CAT_TestModuleExit();

// 解析测试模块文件
osa_err_t   CAT_TestParseTemplete(const char *file);

// 开始所有的测试
osa_err_t   CAT_TestStartAll();

// 释放测试中申请的资源
void        CAT_TestReleaseResource();

#endif /* CAT_TEST_H_ */
