target_link_directories(testndk1 PUBLIC mylib
        ${CMAKE_SOURCE_DIR}/mylib/build/)
# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${JNI}
        # List libraries link to the target library
        android
        mylib
        log)