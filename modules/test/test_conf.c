/*
 * test_conf.c
 *
 * Copyright (C) TuoAn
 *
 */


#include "conf_cmd.h"
#include "conf.h"
#include "osa.h"

#include "tinyxml.h"


static osa_err_t   _getInfo(CAT_Conf *cf, CONF_Test *out_data);
static osa_err_t   _setInfo(CAT_Conf *cf, CONF_Test *data);


osa_err_t   testModuleGet(CAT_Conf *cf, osa_uint32_t cmd, void *out_data)
{
    CONF_Test   *p = (CONF_Test *)out_data;
    osa_err_t   err = OSA_ERR_ERR;
    
    switch (cmd)
    {
        case CMD_TEST_GET_INFO:
        {
            err = _getInfo(cf, out_data);
            break;
        }
        default:
        {
            CAT_LogError("Unknown command: %d\n", cmd);
            break;
        }
    }
    
    return err;
}

osa_err_t   testModuleSet(CAT_Conf *cf, osa_uint32_t cmd, void *data)
{
    CONF_Test   *p = (CONF_Test *)data;
    osa_err_t   err = OSA_ERR_ERR;

    switch (cmd)
    {
        case CMD_TEST_SET_INFO:
        {
            err = _setInfo(cf, data);
            break;
        }
        default:
        {
            CAT_LogError("Unknown command: %d\n", cmd);
            break;
        }
    }
    
    return err;
}

static osa_err_t   _getInfo(CAT_Conf *cf, CONF_Test *out_data)
{
    TiXmlDocument   doc(osa_file_get_name(&cf->file));
    doc.LoadFile();
    
    TiXmlElement    *root = NULL, *testModuleRoot = NULL, *node = NULL;
    
    root = doc->RootElement();
    testModuleRoot = root->FirstChildElement("module");
    
    node = testModuleRoot->FirstChildElement("name");
    strncpy(out_data->name, node->FirstNode()->Value(), OSA_NAME_MAX-1);
    
    node = testModuleRoot->FirstChildElement("state");
    if (!strcmp(node->FirstNode()->Value(), "ON"))
    {
        out_data->state = CAT_MODULE_ON;
    }
    else
    {
        out_data->state = CAT_MODULE_OFF;
    }
    
    node = testModuleRoot->FirstChildElement("test_templete");
    strncpy(out_data->testTemplete, node->FirstNode()->Value(), OSA_NAME_MAX-1);
    
    return OSA_ERR_OK;
}


static osa_err_t   _setInfo(CAT_Conf *cf, CONF_Test *data)
{
    TiXmlDocument   doc(osa_file_get_name(&cf->file));
    doc.LoadFile();
    
    TiXmlElement    *root = NULL, *testModuleRoot = NULL, *node = NULL;
    
    root = doc->RootElement();
    testModuleRoot = root->FirstChildElement("module");
    
    node = testModuleRoot->FirstChildElement("name");
    strncpy(out_data->name, node->FirstNode()->Value(), OSA_NAME_MAX-1);
    
    node = testModuleRoot->FirstChildElement("state");
    if (!strcmp(node->FirstNode()->Value(), "ON"))
    {
        out_data->state = CAT_MODULE_ON;
    }
    else
    {
        out_data->state = CAT_MODULE_OFF;
    }
    
    node = testModuleRoot->FirstChildElement("test_templete");
    strncpy(out_data->testTemplete, node->FirstNode()->Value(), OSA_NAME_MAX-1);
    
    return OSA_ERR_OK;
}

CAT_ModuleConf  testModuleConf =
{
    .name   = "test",
    .state  = CAT_MODULE_ON,
    .get    = testModuleGet,
    .set    = testModuleSet,
};
