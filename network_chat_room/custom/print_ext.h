#ifndef __PRINT_EXT_H__
#define __PRINT_EXT_H__

#include "custom.h"

#define DEBUG_PRINT

/**
 * 无输出
 */
#define NO_PRINT(fmt, args...)  do {} while(0)


#ifdef DEBUG_PRINT

/**
 * 普通打印 - 打印普通显示信息
 */
#define PRINT(fmt, args...) \
        do { \
            char pthreadName[64] = {0}; \
            prctl(PR_GET_NAME, (unsigned long)pthreadName, 0, 0, 0); \
            printf("[PRINT][%s][%s-%s:%d] " fmt, pthreadName, __FILE__, __FUNCTION__, __LINE__, ##args); \
        } while(0)

/**
 * 黄色打印 - 带行号, 用于调试信息打印
 */
#define DEBUG(fmt, args...) \
        do { \
            char pthreadName[64] = {0}; \
            prctl(PR_GET_NAME, (unsigned long)pthreadName, 0, 0, 0); \
            printf("\033[33m[DEBUG][%s][%s-%s:%d] " fmt "\033[0m", pthreadName, __FILE__, __FUNCTION__, __LINE__, ##args); \
        } while(0)

/**
 * 红色打印 - 带行号, 用于错误处理
 */
#define ERROR(fmt, args...) \
        do { \
            char pthreadName[64] = {0}; \
            prctl(PR_GET_NAME, (unsigned long)pthreadName, 0, 0, 0); \
            printf("\033[31m[ERROR][%s][%s-%s:%d] " fmt "\033[0m", pthreadName, __FILE__, __FUNCTION__, __LINE__, ##args); \
        } while(0)

#else

/**
 * 普通输出 - 关闭
 */
#define PRINT(fmt, args...)  do {} while(0)

/**
 * 关闭黄色打印
 */
#define DEBUG(fmt, args...)  do {} while(0) 

/**
 * 红色输出 - 保持
 */
#define ERROR(fmt, args...) \
        do { \
            char pthreadName[64] = {0}; \
            prctl(PR_GET_NAME, (unsigned long)pthreadName, 0, 0, 0); \
            printf("\033[31m[ERROR][%s][%s-%s:%d] " fmt "\033[0m", pthreadName, __FILE__, __FUNCTION__, __LINE__, ##args); \
        } while(0)

#endif  

#endif /* __PRINT_EXT_H__ */