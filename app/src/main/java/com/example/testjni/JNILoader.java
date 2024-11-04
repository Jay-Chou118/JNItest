package com.example.testjni;

public class JNILoader {

    public native String GetNativeString();

    static {
        System.loadLibrary("JNILoader");
    }

}
