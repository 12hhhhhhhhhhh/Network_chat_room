#ifndef _COMMON_H_
#define _COMMON_H_

/*登陆账户*/
#define INPUT_ACCOUNT 10

/*账户登陆成功*/
#define ACCOUNT_INPUT_SUCCESS 11

/*账户登陆失败,账号或密码错误*/
#define ACCOUNT_INPUT_FAIL 12

/*账户登陆失败,未知原因*/
#define ACCOUNT_INPUT_FAIL_UNKNOW 13

/*发送好友信息*/
#define SERVICE_SEND_FRIEND_INFO 110


/*注册账户*/
#define CREATE_ACCOUNT 20

/*ID存在*/
#define ID_EXIST 21

/*账户创建成功*/
#define ACCOUNT_CREAT_SUCCESS 22

/*账户创建失败*/
#define ACCOUNT_CREAT_FAIL 23

typedef struct{
    char name[32];      //昵称
    char id[32];        //账号
    char remark[32];    //备注
    char flag[255];     //个性签名
    char news[25][255]; //消息
}FRIEND_INFO;

#endif