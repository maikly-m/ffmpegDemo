#include "jniLoad.h"
#include "utils/util.h"
#include "utils/const.h"
#include "test.h"

__attribute__((visibility ("default")))
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void * /*reserved*/) {
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) == JNI_OK) {
        RegisterNativeMethods(env);
    }
    // release 版本反调试
#ifdef RELEASE
    be_attached_check();
#endif
    return JNI_VERSION_1_6;
}


__attribute__((visibility ("default")))
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void * /*reserved*/) {
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) == JNI_OK) {
        UnregisterNativeMethods(env, CLASS_NAME_NATIVE);

    }

}

//注册本地方法
jint RegisterNativeMethods(JNIEnv *env) {
    const int count = 2;
    const JNINativeMethod methods[count] =
            {
                    {"stringFromJNI", "()Ljava/lang/String;", (void *) stringFromJNI},
                    {"urlProtocolInfo", "()Ljava/lang/String;", (void *) urlprotocolinfo},
            };
    int ret = RegisterNativeMethods(env, CLASS_NAME_NATIVE,
                                    methods, count);
    LOGI("RegisterNativeMethods ret : %d", ret);
    return 0;
}

jint RegisterNativeMethods(JNIEnv *env, const char *className, const JNINativeMethod *methods,
                           int numMethods) {
    jint result = JNI_ERR;
    if (jclass clazz = env->FindClass(className)) {
        result = env->RegisterNatives(clazz, methods, numMethods);
        env->DeleteLocalRef(clazz);
    }
    return result;
}

jint UnregisterNativeMethods(JNIEnv *env, const char *className) {
    jint result = JNI_ERR;
    if (jclass clazz = env->FindClass(className)) {
        result = env->UnregisterNatives(clazz);
        env->DeleteLocalRef(clazz);
    }
    return result;
}