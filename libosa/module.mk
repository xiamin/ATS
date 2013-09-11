### module.mk

LOCAL_PATH             :=$(call MyDir)

LOCAL_MODULE           :=libosa
LOCAL_MODULE_OWNER     :=osa

common_srcs:=src/common/osa_iochannel.c \
			src/common/osa_mem.c
			
linux_srcs:=src/linux/osa_dir.c \
			src/linux/osa_dll.c \
			src/linux/osa_file.c \
			src/linux/osa_rand.c \
			src/linux/osa_socket.c
			
win_srcs:=src/win32/osa_dir.c

LOCAL_SRC_FILES        :=$(common_srcs) $(linux_srcs)

#LOCAL_CORSS_COMPILE   :=
#LOCAL_AR              :=$(LOCAL_CROSS_COMPILE)ar
#LOCAL_CC              :=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CPP             :=$(LOCAL_CROSS_COMPILE)gcc
#LOCAL_CXX             :=$(LOCAL_CROSS_COMPILE)g++
#LOCAL_LD              :=$(LOCAL_CC)

LOCAL_INCLUDE_DIRS     :=$(LOCAL_PATH)/inc
LOCAL_LIBRARY_DIRS     :=

LOCAL_EXPORT_HEADER_TO	 :=osa_include
LOCAL_EXPORT_HEADER_DIRS :=$(LOCAL_PATH)/inc

LOCAL_STATIC_LIBRARIES :=
LOCAL_SHARED_LIBRARIES :=

LOCAL_ARLIBS           :=
LOCAL_LDLIBS           :=ldl

LOCAL_CFLAGS           :=
LOCAL_CXXFLAGS         :=
LOCAL_LDFLAGS          :=

#include $(BUILD_HOST_EXECUTABLE)
include $(BUILD_HOST_STATIC_LIBRARY)
#include $(BUILD_HOST_SHARED_LIBRARY)

#include $(BUILD_TARGET_EXECUTABLE)
#include $(BUILD_TARGET_STATIC_LIBRARY)
#include $(BUILD_TARGET_SHARED_LIBRARY)

#include $(CLEAR_VARS)
