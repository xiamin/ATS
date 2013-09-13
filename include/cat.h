/*
 * cat.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef ATS_H_
#define ATS_H_

#ifndef ATS_CONFIG_FILE
#define ATS_CONFIG_FILE     "/etc/cat/CAT.xml"
#endif


typedef struct _ATS_MODULE_CONF     ATS_ModuleConf;
typedef struct _ATS_CONF            ATS_Conf;
typedef struct _ATS_MODULE          ATS_Module;
typedef struct _ATS_TEST_POINT      ATS_TestPoint;
typedef struct _ATS_TEST_CASE_BOX   ATS_TestCaseBox;
typedef struct _ATS_MEMORY_POOL     ATS_MemPool;


extern ATS_Conf  *g_conf;


#endif /* ATS_H_ */
