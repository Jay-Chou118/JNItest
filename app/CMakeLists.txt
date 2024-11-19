# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see GitHub - android/ndk-samples: Android NDK samples with Android Studio.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name.
project(jnitestdemo)
# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建并命名一个共享库
add_library(native-lib SHARED ${CMAKE_SOURCE_DIR}/src/main/cpp/native-lib.cpp)
include_directories (${CMAKE_SOURCE_DIR}/src/main/cpp/include/openssl)
#include_directories((${CMAKE_SOURCE_DIR}/src/main/cpp/include/zlib)
#find_library(openssl ${CMAKE_SOURCE_DIR}/src/main/cpp/include/openssl)
find_library( # Sets the name of the path variable.
        log-lib
        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )


target_include_directories(native-lib PRIVATE src/main/cpp/native-lib.cpp)


add_library(curl SHARED IMPORTED)
set_target_properties(curl PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libcurl.so
         )


target_link_libraries(
        native-lib
        curl

#        ${SSL_LIBRARY}
        ${log-lib}

)



