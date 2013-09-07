/*
 * cat_test.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CAT_TEST_H_
#define CAT_TEST_H_

#include "osa.h"

typedef struct _CAT_TEST_INTERFACE
{
    char            name[OSA_NAME_MAX];         // 测试名称
    osa_bool_t      result;                     // 测试结果

    osa_uint8_t     (*init)();                  // 初始化测试
    void            (*exit)();                  // 退出测试
    osa_uint8_t     (*start)();                 // 开始测试
    void            (*stop)();                  // 停止测试
}CAT_Test;

osa_uint8_t CAT_TestInit();
void        CAT_TestExit();
osa_uint8_t CAT_TestStart();
void        CAT_TestStop();


#endif /* CAT_TEST_H_ */
