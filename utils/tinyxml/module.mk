### module.mk

LOCAL_PATH             :=$(call my-dir)

LOCAL_MODULE           :=libtinyxml
LOCAL_MODULE_OWNER     :=

tinyxml_srcs:=tinystr.cpp \
			tinyxml.cpp \
			tinyxmlerror.cpp \
			tinyxmlparser.cpp

LOCAL_SRC_FILES        :=$(tinyxml_srcs)

#LOCAL_CORSS_COMPILE   :=
#LOCAL_AR              :=$(LOCAL_CROSS_COMPILE)ar
#LOCAL_CC              :=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CPP             :=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CXX             :=$(LOCAL_CROSS_COMPILE)g++
#LOCAL_LD              :=$(LOCAL_CC)

LOCAL_INCLUDE_DIRS     :=
LOCAL_LIBRARY_DIRS     :=

LOCAL_EXPORT_HEADER_TO	 :=tinyxml_include
LOCAL_EXPORT_HEADER_DIRS :=$(LOCAL_PATH)

LOCAL_STATIC_LIBRARIES :=
LOCAL_SHARED_LIBRARIES :=

LOCAL_ARLIBS           :=
LOCAL_LDLIBS           :=

LOCAL_CFLAGS           :=-DTIXML_USE_STL
LOCAL_CXXFLAGS         :=
LOCAL_LDFLAGS          :=

#include $(BUILD_HOST_EXECUTABLE)
include $(BUILD_HOST_STATIC_LIBRARY)
#include $(BUILD_HOST_SHARED_LIBRARY)

#include $(BUILD_TARGET_EXECUTABLE)
#include $(BUILD_TARGET_STATIC_LIBRARY)
#include $(BUILD_TARGET_SHARED_LIBRARY)

#include $(CLEAR_VARS)
