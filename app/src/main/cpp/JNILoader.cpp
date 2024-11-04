#include "com_example_testjni_JNILoader.h"
#include <string>

#ifdef __cplusplus
extern "C"{
#endif

    jstring JNICALL Java_com_example_testjni_JNILoader_GetNativeString
(JNIEnv *env, jobject obj)
{
    std::string labelString = "Hello native c++ from wolong";

    return env->NewStringUTF(labelString.c_str());

}
#ifdef __cplusplus
}
#endif
