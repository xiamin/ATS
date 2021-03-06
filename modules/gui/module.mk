### module.mk

LOCAL_PATH             :=$(call MyDir)

LOCAL_MODULE           :=libgui
LOCAL_MODULE_OWNER     :=

gtk_srcs:=gtk2/gtk2.c
qt_srcs:=qt4/qt4.c

LOCAL_SRC_FILES        :=gui_module.c $(gtk_srcs)

#LOCAL_CORSS_COMPILE   :=
#LOCAL_AR              :=$(LOCAL_CROSS_COMPILE)ar
#LOCAL_CC              :=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CPP             :=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CXX             :=$(LOCAL_CROSS_COMPILE)g++
#LOCAL_LD              :=$(LOCAL_CC)

LOCAL_INCLUDE_DIRS     :=$(PROJECT_TOP_DIR)/include osa_include tinyxml_include 
LOCAL_LIBRARY_DIRS     :=

LOCAL_EXPORT_HEADER_TO	 :=
LOCAL_EXPORT_HEADER_DIRS :=

LOCAL_STATIC_LIBRARIES :=liblog
LOCAL_SHARED_LIBRARIES :=

LOCAL_ARLIBS           :=


LOCAL_LDLIBS           :=

		
#gtk_cflags:=-D_REENTRANT -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/directfb -I/usr/include/libpng12  

gtk_cflags:=`pkg-config --cflags gtk+-2.0`
LOCAL_CFLAGS           :=$(gtk_cflags)
LOCAL_CXXFLAGS         :=
LOCAL_LDFLAGS          :=


#include $(BUILD_HOST_EXECUTABLE)
include $(BUILD_HOST_STATIC_LIBRARY)
#include $(BUILD_HOST_SHARED_LIBRARY)

#include $(BUILD_TARGET_EXECUTABLE)
#include $(BUILD_TARGET_STATIC_LIBRARY)
#include $(BUILD_TARGET_SHARED_LIBRARY)

#include $(CLEAR_VARS)
