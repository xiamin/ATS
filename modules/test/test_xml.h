/*
 * test_xml.h
 *
 * Copyright (C) TuoAn
 *
 */
 
#ifndef TEST_XML_H__
#define TEST_XML_H__


#include "osa.h"
#include "test_data.h"


#ifdef __cplusplus
extern "C" {
#endif



// 解析配置中的测试点
osa_err_t   XML_ParseAll(const char *file);

// 获取测试点根节点
void        *XML_GetTestPointRoot(void *xmlRoot, char *name);


#ifdef __cplusplus
}
#endif


#endif
