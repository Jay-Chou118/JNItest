LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := MyLibrary

 #添加头文件查找路径
 LOCAL_C_INCLUDES += \
#      $(LOCAL_PATH)/curl/curl.h
     $(LOCAL_PATH)/curl

# 定义源代码文件路径
LOCAL_SRC_FILES := \
    native-lib.cpp \


LOCAL_LDFLAGS := -llog -lc++ -std=c++17 -lz



include $(BUILD_STATIC_LIBRARY)

APP_STL := c++_shared

APP_ABI := arm64-v8a

APP_PLATFORM := android-30

