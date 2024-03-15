#ifndef _COMMON_H_
#define _COMMON_H_

/*登陆账户：客户端->服务器*/
#define INPUT_ACCOUNT 10
/*账户登陆成功：服务器->客户端*/
#define ACCOUNT_INPUT_SUCCESS 100
/*账户登陆失败,账号或密码错误：服务器->客户端*/
#define ACCOUNT_INPUT_FAIL 101
/*账户登陆失败,未知原因：服务器->客户端*/
#define ACCOUNT_INPUT_FAIL_UNKNOW 102

/*客户端发送接收套接字：客户端->服务器*/
#define CLIENT_RECVFD 103

/*发送好友的相关信息：服务器->客户端*/
#define SERVICE_SEND_FRIEND_INFO 11

/*删除好友：客户端->服务器*/
#define DELETE_FRIEND 12
/*删除好友成功：服务器->客户端*/
#define DELETE_FRIEND_SUCCESS 120
/*删除好友失败：服务器->客户端*/
#define DELETE_FRIEND_FAIL 121

/*注册账户：客户端->服务器*/
#define CREATE_ACCOUNT 20
/*ID存在：服务器->客户端*/
#define ID_EXIST 200

/*账户创建成功：服务器->客户端*/
#define ACCOUNT_CREAT_SUCCESS 201
/*账户创建失败：服务器->客户端*/
#define ACCOUNT_CREAT_FAIL 202

/*发送消息：客户端->服务器*/
#define MESSAGE_CLI_TO_SER 30
/*发送消息成功：服务器->客户端*/
#define MESSAGE_CLI_TO_SER_SUCC 300
/*发送消息失败：服务器->客户端*/
#define MESSAGE_CLI_TO_SER_FAIL 301

/*发送消息：服务器->客户端*/
#define MESSAGE_SER_TO_CLI 31
/*发送消息成功：客户端->服务器*/
#define MESSAGE_SER_TO_CLI_SUCC 310
/*发送消息失败：客户端->服务器*/
#define MESSAGE_SER_TO_CLI_FAIL 311

/*根据ID搜索联系人*/
#define CONTACTS_SEARCH_BY_ID 40
/*搜索成功*/
#define CONTACTS_SEARCH_SUCCESS 401
/*搜索失败--查无此人*/
#define CONTACTS_SEARCH_NO_FIND 402
/*搜索失败--原因未知*/
#define CONTACTS_SEARCH_UNKNOW 403

/*发送好友申请*/
#define CONTACTS_SEARCH_ADD_FRIEND 41
/*发送好友申请成功*/
#define CONTACTS_SEARCH_ADD_FRIEND_SUCCESS 411
/*发送好友申请失败*/
#define CONTACTS_SEARCH_ADD_FRIEND_FAIL 412
/*已给对方发过好友申请*/
#define CONTACTS_SEARCH_ADD_FRIEND_ALREADY 413
/*对方好友申请过多，至多10条*/
#define CONTACTS_SEARCH_ADD_FRIEND_FULL 414

/*同意好友申请*/
#define CONTACTS_AGREE_FRIEND_APPLY 415
/*拒绝好友申请*/
#define CONTACTS_REFUSE_FRIEND_APPLY 416

/*发送好友申请的相关信息：服务器->客户端*/
#define SERVICE_SEND_FRIEND_APPLY 42
/*好友申请相关的信息发送成功：客户端->服务器*/
#define SERVICE_SEND_FRIEND_INFO_SUCCESS 421
/*好友申请相关的信息发送失败：客户端->服务器*/
#define SERVICE_SEND_FRIEND_INFO_FAIL 422

typedef struct{
    char name[32];      //昵称
    char id[32];        //账号
    char remark[32];    //备注
    char flag[255];     //个性签名
    char news[25][255]; //消息
}FRIEND_INFO;

#endif