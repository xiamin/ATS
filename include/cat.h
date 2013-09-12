/*
 * cat.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CAT_H_
#define CAT_H_

#ifndef CAT_CONFIG_FILE
#define CAT_CONFIG_FILE     "/etc/cat/CAT.xml"
#endif


typedef struct _CAT_MODULE_CONF     CAT_ModuleConf;
typedef struct _CAT_CONF            CAT_Conf;
typedef struct _CAT_MODULE          CAT_Module;
typedef struct _CAT_TEST_POINT      CAT_TestPoint;
typedef struct _CAT_TEST_CASE       CAT_TestCase;
typedef struct _CAT_MEMORY_POOL     CAT_MemPool;


extern CAT_Conf  *g_conf;


#endif /* CAT_H_ */
