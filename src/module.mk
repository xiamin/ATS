### module.mk

LOCAL_PATH             :=$(call MyDir)

LOCAL_MODULE           :=main
LOCAL_MODULE_OWNER     :=

LOCAL_SRC_FILES        :=conf.c module.c conf_xml.cpp ats_main.c

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

LOCAL_STATIC_LIBRARIES :=libtest libtinyxml libgui libreport  liberp
LOCAL_SHARED_LIBRARIES :=

LOCAL_ARLIBS           :=
LOCAL_LDLIBS           :=ldl

LOCAL_CFLAGS           :=-fno-builtin -DATS_CONFIG_FILE=\"$(PROJECT_TOP_DIR)/conf/CAT.xml\"
LOCAL_CXXFLAGS         :=

gtk_ldflags:=`pkg-config --libs gtk+-2.0`

LOCAL_LDFLAGS          :=$(gtk_ldflags)

include $(BUILD_HOST_EXECUTABLE)
#include $(BUILD_HOST_STATIC_LIBRARY)
#include $(BUILD_HOST_SHARED_LIBRARY)
