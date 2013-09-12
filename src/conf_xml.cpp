/*
 * conf_xml.cpp
 *
 * Copyright (C) TuoAn
 *
 */


#include "conf_xml.h"
#include "tinyxml.h"
#include "log.h"
#include "module.h"

#ifdef __cplusplus
extern "C" {
#endif


void XML_ReportModuleRead(CAT_Conf *cf, CONF_Report *out_data)
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

    moduleRoot = (TiXmlElement *)XML_GetModuleRoot((void *)root, "report");
    if (NULL == moduleRoot)
    {
        CAT_LogError("Failed to get module root : report\n");
        goto err;
    }

    strncpy(out_data->name, "report", OSA_NAME_MAX-1);

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


err:
    return;
}


TiXmlElement *XML_LogModuleRoot(TiXmlElement *root);

void XML_LogModuleRead(CAT_Conf *cf, CONF_Log *out_data)
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

    moduleRoot = (TiXmlElement *)XML_GetModuleRoot((void *)root, "log");
    if (NULL == moduleRoot)
    {
        CAT_LogError("Failed to get module root : log\n");
        goto err;
    }

    // 模块名字
    strncpy(out_data->name, "log", OSA_NAME_MAX-1);

    // 模块状态
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

    // 日志等级
    node = moduleRoot->FirstChildElement("level");
    if (NULL == node)
    {
        CAT_LogError("Node not found: level!\n");
        goto err;
    }
    out_data->level = atoi(node->FirstChild()->Value());

    // 日志输出文件
    node = moduleRoot->FirstChildElement("file");
    if (NULL == node)
    {
        CAT_LogError("Node not found: file!\n");
        goto err;
    }
    strncpy(out_data->logFile, node->FirstChild()->Value(), OSA_NAME_MAX-1);


    return;

err:
    return;
}


void XML_GuiModuleRead(CAT_Conf *cf, CONF_Gui *out_data)
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

    moduleRoot = (TiXmlElement *)XML_GetModuleRoot((void *)root, "gui");
    if (NULL == moduleRoot)
    {
        CAT_LogError("Failed to get the module root of file: %s\n", cf->file);
        goto err;
    }

    strncpy(out_data->name, "gui", OSA_NAME_MAX-1);

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

    return;

err:
    return;
}


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

    moduleRoot = (TiXmlElement *)XML_GetModuleRoot((void *)root, "test");
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

    node = moduleRoot->FirstChildElement("templete");
    if (NULL == node)
    {
        CAT_LogError("Node not found: templete!\n");
        goto err;
    }
    strncpy(out_data->testTemplete, node->FirstChild()->Value(), OSA_NAME_MAX-1);
    return;

err:
    return;
}


void *XML_GetModuleRoot(void *root, char *name)
{
    TiXmlElement    *tmp = ((TiXmlElement *)root)->FirstChildElement("module");
    TiXmlAttribute  *attr = NULL;
    while (tmp)
    {
        attr = tmp->FirstAttribute();
        if (!strcmp(attr->Value(), name))
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
