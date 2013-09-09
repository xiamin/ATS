/*
 * module.h
 *
 * Copyright (C) TuoAn
 *
 */

#ifndef MODULE_H_
#define MODULE_H_

#include "osa.h"

typedef struct _CAT_MODULE
{
    char            name[OSA_NAME_MAX];
    osa_uint8_t     state;
}CAT_Module;


#endif /* MODULE_H_ */
