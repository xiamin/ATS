/*
 * cat_test.h
 *
 * Copyright (C) TuoAn
 *
 */
 
#include "test.h"
#include "test_xml.h"
#include "test_data.h"
#include "log.h"

#include "test_table.h"

#include "tinyxml.h"

#ifdef __cplusplus
extern "C" {
#endif



// 解析云台配置
static osa_err_t    _ParsePtz(TiXmlElement *root);

// 解析网络配置
static osa_err_t    _ParseNetwork(TiXmlElement *root);

// dummy
static osa_err_t    _ParseDummy(TiXmlElement *root);


osa_err_t   XML_ParseAll(const char *file)
{
    osa_err_t   err;
    
    TiXmlDocument   *doc = new TiXmlDocument(file);
    if (doc->LoadFile() != true)
    {
        CAT_LogError("Failed to load templete file : %s\n", file);
        
        return OSA_ERR_ERR;
    }

    TiXmlElement    *root = doc->RootElement();
    if (!root)
    {
        CAT_LogError("Unable to get xml root : %s!\n", file);

        return OSA_ERR_ERR;
    }

#if 0
    err = _ParsePtz(root);
    if (err != OSA_ERR_OK)
    {
        goto err;
    }

    //err = _ParseNetwork(root);
    //if (err != OSA_ERR_OK)
    //{
     //   goto err;
    //}
#endif

    err = _ParseDummy(root);
    if (err != OSA_ERR_OK)
    {
        goto err;
    }

    return OSA_ERR_OK;


err:
    return OSA_ERR_ERR;
    
}


void    *XML_GetTestPointRoot(void *xmlRoot, char *name)
{
    TiXmlElement    *tmp = ((TiXmlElement *)xmlRoot)->FirstChildElement("test_point");
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


static osa_err_t   _ParsePtz(TiXmlElement *root)
{

    TEST_Ptz    ptzTP;
    
    
    TiXmlElement    *ptzRoot = (TiXmlElement *)XML_GetTestPointRoot((void *)root, PTZ_NODE_NAME);
    
}



static osa_err_t    _ParseDummy(TiXmlElement *root)
{

    osa_uint32_t    i;
    CAT_TestPoint   *p = NULL;

    osa_size_t  sz = sizeof(g_testPointTable)/sizeof(g_testPointTable[0]);

    for (i=0; i<sz; i++)
    {
        if (!strcmp(g_testPointTable[i].name, "DummyTest"))
        {
            p = g_testPointTable[i].getTestPoint();

            CAT_TestCaseSet(&p->testCase, 0, 0, NULL);

            CAT_TestPointRegister(p);
            break;
        }
    }

    return OSA_ERR_OK;
}


#ifdef __cplusplus
}
#endif
