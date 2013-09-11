PROJECT_OUT            :=$(PROJECT_TOP_DIR)/out
PROJECT_VERSION        :=1.1.1
PROJECT_BUILD_ID       :=1234
PROJECT_BUILD_TYPE     :=debug
PROJECT_MODULE_OWNER   :=hello

CROSS_COMPILE          :=

AR                         :=$(AR)
CC                         :=$(CC)
CPP                        :=$(CC) -E
CXX                        :=$(CXX)
LD                         :=$(CXX)
SIZE                       :=$(CROSS_COMPILE)size
OBJDUMP                    :=$(CROSS_COMPILE)objdump
NM                         :=$(CROSS_COMPILE)nm
READELF                    :=$(CROSS_COMPILE)readelf