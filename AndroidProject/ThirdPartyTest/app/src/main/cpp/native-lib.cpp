#include <jni.h>
#include <string>
//#include "zlib.h"
//#include "openssl/crypto.h"
//#include "curl/curl.h"
#include "png.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_thirdpartytest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
//    return env->NewStringUTF(zlibVersion());
//    return env->NewStringUTF(OpenSSL_version(OPENSSL_VERSION));
//    return env->NewStringUTF(curl_version());
      png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
      return env->NewStringUTF(hello.c_str());
}