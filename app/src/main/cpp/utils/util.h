#ifndef ANDROIDSAFEDEMO_PASCUTIL_H
#define ANDROIDSAFEDEMO_PASCUTIL_H

#include <android/log.h>
#include <jni.h>
#include <string>
#include <unistd.h>

#define  LOG_TAG    "utils_ffmpeg"
#ifdef LOG_FLAG
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#else
#define  LOGI(...)
#endif

#endif //ANDROIDSAFEDEMO_PASCUTIL_H
