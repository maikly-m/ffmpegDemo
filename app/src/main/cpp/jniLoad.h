#ifndef LIBMATCH_JNILOAD_H
#define LIBMATCH_JNILOAD_H

#include <jni.h>

jint RegisterNativeMethods(JNIEnv *env);
jint UnregisterNativeMethods(JNIEnv *env, const char *className);
jint RegisterNativeMethods(JNIEnv* env, const char* className, const JNINativeMethod* methods, int numMethods);

#endif //LIBMATCH_JNILOAD_H
