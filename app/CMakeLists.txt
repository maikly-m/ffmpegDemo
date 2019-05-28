cmake_minimum_required(VERSION 3.4.1)

find_library(
        log-lib
        log)

file(GLOB _SRC "${CMAKE_SOURCE_DIR}/src/main/cpp/*.cpp")

set(distribution_DIR ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI})

add_library(avutil
        SHARED
        IMPORTED)
set_target_properties(avutil
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/libavutil.so)

add_library(swresample
        SHARED
        IMPORTED)
set_target_properties(swresample
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/libswresample.so)

add_library(avcodec
        SHARED
        IMPORTED)
set_target_properties(avcodec
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/libavcodec.so)

add_library(avfilter
        SHARED
        IMPORTED)
set_target_properties(avfilter
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/libavfilter.so)

add_library(swscale
        SHARED
        IMPORTED)
set_target_properties(swscale
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/libswscale.so)

add_library(fdk-aac
        SHARED
        IMPORTED)
set_target_properties(fdk-aac
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/libfdk-aac.so)

add_library(avformat
        SHARED
        IMPORTED)
set_target_properties(avformat
        PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/libavformat.so)

add_library(native
            SHARED
            ${_SRC}
            )

target_include_directories(native
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/include
        )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

target_link_libraries(native
        swresample avcodec avfilter
        swscale fdk-aac avformat avutil
        ${log-lib}
        )
