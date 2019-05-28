//
// Created by 黄志艺(EX-HUANGZHIYI001) on 2019-05-27.
//

#ifndef TEST_T_H
#define TEST_T_H
extern "C" {
#include <jni.h>

JNIEXPORT jstring JNICALL stringFromJNI(JNIEnv *env, jobject thiz);

JNIEXPORT jstring JNICALL urlprotocolinfo(JNIEnv *env, jobject thiz);

JNIEXPORT jstring JNICALL avformatinfo(JNIEnv *env, jobject thiz);

JNIEXPORT jstring JNICALL avcodecinfo(JNIEnv *env, jobject thiz);

JNIEXPORT jstring JNICALL avfilterinfo(JNIEnv *env, jobject thiz);

};

#endif //TEST_T_H
