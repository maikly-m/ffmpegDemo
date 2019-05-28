package com.example.test

/**
 * Created by ex-huangzhiyi001 on 2019-05-28.
 * jni 调用
 */
class JniUtils private constructor(){
    private object Holder { val INSTANCE = JniUtils () }

    companion object {
        val instance: JniUtils by lazy { Holder.INSTANCE }
        init {
            System.loadLibrary("native")
        }
    }

    external fun stringFromJNI(): String
    external fun urlProtocolInfo(): String
}
