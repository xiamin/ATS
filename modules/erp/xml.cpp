/*
 * xml.cpp
 *
 * Copyright (C) TuoAn
 *
 */


#include "tinyxml.h"
#include "conf.h"
#include "conf_data.h"
#include "module.h"
#include "log.h"

#ifdef __cplusplus
extern "C" {
#endif

TiXmlElement *XML_TestModuleRoot(TiXmlElement *root);

void XML_TestModuleRead(CAT_Conf *cf, CONF_Test *out_data)
{
    TiXmlElement    *root       = NULL;
    TiXmlElement    *moduleRoot = NULL;
    TiXmlElement    *node       = NULL;
    bool            ret         = false;
    
    TiXmlDocument   doc(cf->file);
    
    ret = doc.LoadFile();
    if (ret != true)
    {
        CAT_LogError("Failed to load file: %s\n", cf->file);
        goto err;
    }
    
    root = doc.RootElement();
    if (NULL == root)
    {
        CAT_LogError("Failed to get the root of file: %s\n", cf->file);
        goto err;
    }
    
    moduleRoot = XML_TestModuleRoot(root);
    if (NULL == moduleRoot)
    {
        CAT_LogError("Failed to get module root : test\n");
        goto err;
    }
    
    strncpy(out_data->name, "test", OSA_NAME_MAX-1);
    
    node = moduleRoot->FirstChildElement("state");
    if (NULL == node)
    {
        CAT_LogError("Node not found: state!\n");
        goto err;
    }
    if (!strcmp(node->FirstChild()->Value(), "on"))
    {
        out_data->state = CAT_MODULE_ON;
    }
    else
    {
        out_data->state = CAT_MODULE_OFF;
    }
    
    node = moduleRoot->FirstChildElement("test_templete");
    if (NULL == node)
    {
        CAT_LogError("Node not found: test_templete!\n");
        goto err;
    }
    strncpy(out_data->testTemplete, node->FirstChild()->Value(), OSA_NAME_MAX-1);
    return;
    
err:
    return;
}

TiXmlElement *XML_TestModuleRoot(TiXmlElement *root)
{
    TiXmlElement    *tmp = root->FirstChildElement("module");
    TiXmlAttribute  *attr = NULL;
    while (tmp)
    {
        attr = tmp->FirstAttribute();
        if (!strcmp(attr->Value(), "test"))
        {
            return tmp;
        }
        tmp = tmp->NextSiblingElement("module");
    }
    
    return NULL;
}

#ifdef __cplusplus
}
#endif