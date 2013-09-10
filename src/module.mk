### module.mk

LOCAL_PATH             :=$(call my-dir)

LOCAL_MODULE           :=libsrc
LOCAL_MODULE_OWNER     :=

LOCAL_SRC_FILES        :=conf.c module.c conf_xml.cpp

#LOCAL_CORSS_COMPILE   :=
#LOCAL_AR              :=$(LOCAL_CROSS_COMPILE)ar
#LOCAL_CC              :=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CPP             :=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CXX             :=$(LOCAL_CROSS_COMPILE)g++
#LOCAL_LD              :=$(LOCAL_CC)

LOCAL_INCLUDE_DIRS     :=$(PROJECT_TOP_DIR)/include osa_include  tinyxml_include
LOCAL_LIBRARY_DIRS     :=

LOCAL_EXPORT_HEADER_TO	 :=
LOCAL_EXPORT_HEADER_DIRS :=

LOCAL_STATIC_LIBRARIES :=
LOCAL_SHARED    _LIBRARIES :=

LOCAL_ARLIBS           :=
LOCAL_LDLIBS           :=

LOCAL_CFLAGS           :=-fno-builtin -DTIXML_USE_STL
LOCAL_CXXFLAGS         :=
LOCAL_LDFLAGS          :=

#include $(BUILD_HOST_EXECUTABLE)
include $(BUILD_HOST_STATIC_LIBRARY)
#include $(BUILD_HOST_SHARED_LIBRARY)

#include $(BUILD_TARGET_EXECUTABLE)
#include $(BUILD_TARGET_STATIC_LIBRARY)
#include $(BUILD_TARGET_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE           :=main
LOCAL_MODULE_OWNER     :=

LOCAL_SRC_FILES        :=cat_main.c
LOCAL_INCLUDE_DIRS     :=$(PROJECT_TOP_DIR)/include osa_include

gtk_libs:=lpthread \
        lgtk-x11-2.0 \
        lgdk-x11-2.0 \
        latk-1.0 \
        lgio-2.0 \
        lpangoft2-1.0 \
        lgdk_pixbuf-2.0 \
        lm \
        lpangocairo-1.0 \
        lcairo \
        lpango-1.0 \
        lfreetype \
        lfontconfig \
        lgobject-2.0 \
        lgmodule-2.0 \
        lgthread-2.0 \
        lrt \
        lglib-2.0

LOCAL_LDLIBS:=$(gtk_libs)
LOCAL_STATIC_LIBRARIES :=liblog libtest libtinyxml libgui libsrc libreport

include $(BUILD_HOST_EXECUTABLE)
