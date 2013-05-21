#include    "com_example_p2plive_MainActivity.h"
#include    "hello/main.h"
JNIEXPORT jint JNICALL Java_com_example_p2plive_MainActivity_startHttpServer
(JNIEnv * env, jobject obj, jint listenport)
{
   int rt = startHttpServer(listenport);
   return rt;
}
