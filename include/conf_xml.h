/*
 * conf_xml.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CONF_XML_H_
#define CONF_XML_H_

#include "conf.h"
#include "conf_data.h"


#ifdef __cplusplus
extern "C" {
#endif


void *XML_GetModuleRoot(void *root, char *name);

void XML_TestModuleRead(ATS_Conf *cf, CONF_Test *out_data);
void XML_GuiModuleRead(ATS_Conf *cf, CONF_Gui *out_data);
void XML_LogModuleRead(ATS_Conf *cf, CONF_Log *out_data);
void XML_ReportModuleRead(ATS_Conf *cf, CONF_Report *out_data);
void XML_ErpModuleRead(ATS_Conf *cf, CONF_Erp *out_data);


#ifdef __cplusplus
}
#endif

#endif /* CONF_XML_H_ */
