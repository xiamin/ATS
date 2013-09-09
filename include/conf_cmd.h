/*
 * conf_cmd.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CONF_CMD_H_
#define CONF_CMD_H_

#include "osa.h"


#define TEST_MODULE_NAME    "test"

enum
{
    CMD_TEST_MIN = 0,
	CMD_TEST_GET_INFO = CMD_TEST_MIN,
	CMD_TEST_SET_INFO,
	CMD_TEST_MAX,
};

typedef struct
{
    char            name[OSA_NAME_MAX];	
    osa_uint8_t     state;
	char			testTemplete[OSA_NAME_MAX];
}CONF_Test;


#define REPORT_MODULE_NAME    "report"

enum
{
    CMD_REPORT_MIN = 100,
	CMD_REPORT_GET_INFO = CMD_REPORT_MIN,
	CMD_REPORT_SET_INFO,
	CMD_REPORT_MAX,
};

typedef struct
{
    char        	name[OSA_NAME_MAX];         // 报告输出文件，可以为STDOUT
	osa_uint8_t		state;
	char			output[OSA_NAME_MAX];
}CONF_Report;


#define ERP_MODULE_NAME     "erp"

enum
{
    CMD_ERP_MIN = 200,
	CMD_ERP_GET_INFO = CMD_ERP_MIN,
	CMD_ERP_SET_INFO,
	CMD_ERP_MAX,
};

typedef struct
{
	char			name[OSA_NAME_MAX];
	osa_uint8_t		state;
	char			serverAddr[OSA_NAME_MAX];
}CONF_Erp;


#define GUI_MODULE_NAME     "gui"

enum
{
    CMD_GUI_MIN = 300,
	CMD_GUI_GET_INFO = CMD_GUI_MIN,
	CMD_GUI_SET_INFO,
	CMD_GUI_MAX,
};

typedef struct
{

}CONF_Gui;



#endif /* CONF_CMD_H_ */
