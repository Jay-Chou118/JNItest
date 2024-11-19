#include <jni.h>
#include <string>
#include <iostream>
#include <android/log.h>
#include "include/curl/curl.h"

// 定义LOGI宏
#define LOG_TAG "MiChatCurlExample"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

static std::string curlGet(const char* url) {
    CURL *curl;
    CURLcode res;
    std::string response;
    LOGI("RRRR1111111111");
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    LOGI("RRRR21111111111");
    if (curl) {
        LOGI("RRRR31111111111");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);//设定为不验证证书和HOST
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
        curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            LOGI("RRRR Curl res: %s", curl_easy_strerror(res));
            response = "curl_easy_perform() failed: " + std::string(curl_easy_strerror(res));
        } else {
            LOGI("RRRR Curl response: %s", response.c_str());
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    // 打印response到Logcat
    LOGI("RRRR Curl response: %s", response.c_str());

    return response;
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnitestdemo_MainActivity_Java_1com_1example_1jnitestdemo_1NativeLib_1stringFromJNI(JNIEnv* env, jobject /* this */, jstring url) {
    const char *c_url = env->GetStringUTFChars(url, nullptr);
    std::string response = curlGet(c_url);
    env->ReleaseStringUTFChars(url, c_url);
    return env->NewStringUTF(response.c_str());
}