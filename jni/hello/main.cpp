/*
 * ============================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/15/13 10:31:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#ifndef     _HELLO_HEAER_
#define     _HELLO_HEAER_
#define P2PLIVE_PATH  "/data/data/com.example.p2plive/lib/libtest.so"
#include    <unistd.h>
#include    <errno.h>
#include    <stdlib.h>
#include    <stdio.h>

#define LOG_TAG "TestLib" //自定义的变量，相当于logcat函数中的tag
#undef LOG
#include <android/log.h>   //#include <utils/Log.h>//在源码环境中，头文件的路径不同
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)  

#include    <android/log.h>
int startHttpServer(int listenPort)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        exit(-1);
    }
    else if (pid == 0)
    {
        int p2pfd = 30;
        int httpfd = 40;
        int socketP2pused = p2pfd;                                             
        int socketHttpused = httpfd;                                           
        char socketp2pused[10];                                                
        bzero(socketp2pused, sizeof(socketp2pused));                           
        sprintf(socketp2pused, "%d", socketP2pused);                           

        char sockethttpused[10];                                               
        bzero(sockethttpused, sizeof(sockethttpused));                         
        sprintf(sockethttpused, "%d", socketHttpused);                         

        if (execlp(P2PLIVE_PATH, P2PLIVE_PATH, socketp2pused, sockethttpused, (char*) 0) < 0)
        {
            perror("execlp error, exit");
            exit(-1);
        }
    }
    else
    {
        LOGD("Hello LIB!\n");//将会输出“TestLib” “Hello LIB！”
        //__android_log_write(ANDROID_LOG_DEBUG,"Tag"," This is a Debug Info");
        sleep(1000000);
    }
}
#endif
