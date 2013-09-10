/*
 * cat_report.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef CAT_REPORT_H_
#define CAT_REPORT_H_

#include "osa.h"

typedef struct _CAT_REPORT_INTERFACE
{

}CAT_Report;


osa_err_t   CAT_ReportModuleInit();
void        CAT_ReportModuleExit();

#endif /* CAT_REPORT_H_ */
