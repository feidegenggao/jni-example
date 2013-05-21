LOCAL_PATH :=$(call my-dir)
include $(CLEAR_VARS)


define all-cpp-files-under
$(patsubst ./%,%, \
  $(shell cd $(LOCAL_PATH) ; \
          find $(1) -name "*.cpp" -and -not -name ".*") \
 )
endef

define all-subdir-cpp-files
$(call all-cpp-files-under,.)
endef


define all-c-files-under
$(patsubst ./%,%, \
  $(shell cd $(LOCAL_PATH) ; \
          find $(1) -name "*.c" -and -not -name ".*") \
 )
endef

define all-subdir-c-files
$(call all-c-files-under,.)
endef

LOCAL_SRC_FILES := $(call all-subdir-cpp-files)
LOCAL_SRC_FILES += $(call all-subdir-c-files)


$(warning src $(LOCAL_SRC_FILES))
				   
				  
LOCAL_C_INCLUDES :=$(LOCAL_PATH)/\
	$(LOCAL_PATH)/hello \
	$(JNI_H_INCLUDE)

#LOCAL_C_INCLUDES += system/core/include/cutils
#LOCAL_SHARED_LIBRARIES += libcutil
LOCAL_SHARED_LIBRARIES += libsupc++
#LOCAL_LDLIBS = -L$(SYSROOT)/usr/lib -llog

LOCAL_LDLIBS :=  -llog

LOCAL_CXX_FLAGS :=-g2 -O0 -DDEBUG -Wall -Werror -frtti
LOCAL_CPP_FLAGS :=-g2 -O0 -DDEBUG -Wall -Werror -frtti



LOCAL_PRELINK_MODULE := false
LOCAL_MODULE = Main
#LOCAL_CFLAGS := -DPAGE_SIZE=2048
LOCAL_EXECUTABLES := test.so

#include $(BUILD_EXECUTABLE)
include  $(BUILD_SHARED_LIBRARY)
