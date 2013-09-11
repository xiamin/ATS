### module.mk

LOCAL_PATH	        :=$(call MyDir)

LOCAL_MODULE		:=libfunc_a
LOCAL_MODULE_OWNER	:=user_lib

LOCAL_SRC_FILES		:=a.c

#LOCAL_CORSS_COMPILE	:=

#LOCAL_AR		:=$(LOCAL_CROSS_COMPILE)ar
#LOCAL_CC		:=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CPP		:=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CXX		:=$(LOCAL_CROSS_COMPILE)g++
#LOCAL_LD		:=$(LOCAL_CC)

LOCAL_INCLUDE_DIRS	:=$(TEST_TOP_DIR)/include 
LOCAL_LIBRARY_DIRS	:=

LOCAL_EXPORT_HEADER_TO  :=my_a
LOCAL_EXPORT_HEADER_DIRS:=$(LOCAL_PATH)/inc

LOCAL_STATIC_LIBRARIES	:=
LOCAL_SHARED_LIBRARIES	:=

LOCAL_LDLIBS		:=

LOCAL_ARFLAGS		:=
LOCAL_CFLAGS		:=
LOCAL_CPPFLAGS		:=
LOCAL_CXXFLAGS		:=
LOCAL_LDFLAGS		:=

LOCAL_PRE_DEPENDENTS	:=
LOCAL_POST_DEPENDENTS	:=

##主机可执行文件
#include $(BUILD_HOST_EXECUTABLE)
##主机静态库
include $(BUILD_HOST_STATIC_LIBRARY)
##主机动态库
#include $(BUILD_HOST_SHARED_LIBRARY)

##目标机可执行文件
#include $(BUILD_TARGET_EXECUTABLE)
##目标机静态库
#include $(BUILD_TARGET_STATIC_LIBRARY)
##目标机动态库
#include $(BUILD_TARGET_SHARED_LIBRARY)

##重置LOCAL_变量
#include $(CLEAR_VARS)
