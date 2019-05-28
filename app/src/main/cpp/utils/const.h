
#ifndef ANDROIDSAFEDEMO_CONSTANT_H
#define ANDROIDSAFEDEMO_CONSTANT_H

// lib使用的class
const char *const CLASS_NAME_NATIVE = "com/example/test/JniUtils";


const char *const messageDigestClassName = "java/security/MessageDigest";
const char *const getInstanceMethod = "getInstance";
const char *const getInstanceMethodSig = "(Ljava/lang/String;)Ljava/security/MessageDigest;";
const char *const updateMethod = "update";
const char *const updateMethodSig = "([B)V";

const char *const digestMethod = "digest";
const char *const digestMethodSig = "()[B";

const char *const stringClass = "java/lang/String";

const char *const getBytesMethod = "getBytes";
const char *const getBytesMethodSig = "()[B";

const char *const bytesToHexMethod = "bytesToHex";
const char *const bytesToHexMethodSig = "([B)Ljava/lang/String;";

const char * const onFinishPwdMethod="onFinishPwd";
const char * const onFinishPwdMethodSig="(Ljava/lang/String;Z)V";


#endif //ANDROIDSAFEDEMO_CONSTANT_H
