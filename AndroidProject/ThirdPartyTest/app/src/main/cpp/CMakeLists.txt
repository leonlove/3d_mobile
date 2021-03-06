# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("thirdpartytest")

#设置so库路径
set(my_lib_path ${CMAKE_SOURCE_DIR}/../../../libs)

INCLUDE_DIRECTORIES(${my_lib_path}/include)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

#将第三方库作为动态库引用 #指定第三方库的绝对路径
add_library(myzlib SHARED IMPORTED)
set_target_properties(myzlib PROPERTIES IMPORTED_LOCATION ${my_lib_path}/${ANDROID_ABI}/libz.so)

#add_library(openssl-crypto SHARED IMPORTED)
#set_target_properties(openssl-crypto PROPERTIES IMPORTED_LOCATION ${my_lib_path}/${ANDROID_ABI}/libcrypto.so)
#
#add_library(openssl-ssl SHARED IMPORTED)
#set_target_properties(openssl-ssl PROPERTIES IMPORTED_LOCATION ${my_lib_path}/${ANDROID_ABI}/libssl.so)

#add_library(curl SHARED IMPORTED)
#set_target_properties(curl PROPERTIES IMPORTED_LOCATION ${my_lib_path}/${ANDROID_ABI}/libcurl.so)

add_library(png SHARED IMPORTED)
set_target_properties(png PROPERTIES IMPORTED_LOCATION ${my_lib_path}/${ANDROID_ABI}/libpng.so)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib
#                       openssl-crypto
#                       openssl-ssl
#                       curl
                       png
                       myzlib
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )