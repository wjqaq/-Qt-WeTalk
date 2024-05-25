#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <string.h>
#define _IP     ("192.168.1.21")
#define _PORT   (8080)

typedef int PackType;
//协议数量
#define _DEF_PROTOCOL_COUNT (1024)
//定义协议头
#define _DEF_PROTOCOL_BASE  (1000)
//TCP：
//注册请求
#define _DEF_TCP_REGISTER_RQ    (_DEF_PROTOCOL_BASE+1)
//注册回复
#define _DEF_TCP_REGISTER_RS    (_DEF_PROTOCOL_BASE+2)
//登录请求
#define _DEF_TCP_LOGIN_RQ       (_DEF_PROTOCOL_BASE+3)
//登录回复
#define _DEF_TCP_LOGIN_RS       (_DEF_PROTOCOL_BASE+4)
//好友信息
#define _DEF_TCP_FRIEND_INFO    (_DEF_PROTOCOL_BASE+5)
//聊天请求
#define _DEF_TCP_CHAT_RQ        (_DEF_PROTOCOL_BASE+6)
//聊天回复
#define _DEF_TCP_CHAT_RS        (_DEF_PROTOCOL_BASE+7)
//添加好友请求
#define _DEF_TCP_ADD_FRIEND_RQ  (_DEF_PROTOCOL_BASE+8)
//添加好友回复
#define _DEF_TCP_ADD_FRIEND_RS  (_DEF_PROTOCOL_BASE+9)
//下线请求
#define _DEF_TCP_OFFLINE_RQ     (_DEF_PROTOCOL_BASE+10)

#define _DEF_LENGTH  (2048)
//注册结果
#define register_success        (0)
#define register_count_used     (1)
#define register_name_used      (2)
#define register_name_illegal   (3)
#define register_count_illegal  (4)
#define register_passwd_illegal (5)
//登录结果
#define login_success           (0)
#define login_no_count          (1)
#define login_passwd_error      (2)
#define login_count_illegal     (3)
#define login_passwd_illegal    (4)
//状态
#define status_online           (0)
#define status_offline          (1)
//聊天结果
#define send_success            (0)
#define send_fail               (1)
//添加好友结果
#define add_friend_no_user      (0)
#define add_friend_offline      (1)
#define add_friend_aggree       (2)
#define add_friend_disaggree    (3)
//发送文件结果
#define send_file_offline       (0)
#define send_file_disaggree     (1)
#define send_file_success       (2)
//TCP ：结构体
//注册请求:协议头、昵称、账号、密码
typedef struct _STRU_TCP_REGISTER_RQ
{
    _STRU_TCP_REGISTER_RQ():type(_DEF_TCP_REGISTER_RQ)
    {
        memset(name,0,_DEF_LENGTH);
        memset(count,0,_DEF_LENGTH);
        memset(passwd,0,_DEF_LENGTH);
    }

    PackType type;
    char name[_DEF_LENGTH];
    char count[_DEF_LENGTH];
    char passwd[_DEF_LENGTH];
}_STRU_TCP_REGISTER_RQ;

//注册回复：协议头、注册结果（注册成功、账号已被注册、昵称已被使用）
typedef struct _STRU_TCP_REGISTER_RS
{
    _STRU_TCP_REGISTER_RS():type(_DEF_TCP_REGISTER_RS),result(register_name_used)
    {

    }
    PackType type;
    int result;
}_STRU_TCP_REGISTER_RS;

//登录请求：协议头、账号、密码
typedef struct _STRU_TCP_LOGIN_RQ
{
    _STRU_TCP_LOGIN_RQ():type(_DEF_TCP_LOGIN_RQ)
    {
        memset(count,0,_DEF_LENGTH);
        memset(passwd,0,_DEF_LENGTH);
    }

    PackType type;
    char count[_DEF_LENGTH];
    char passwd[_DEF_LENGTH];
}_STRU_TCP_LOGIN_RQ;
//登录回复：协议头、登录结果（登录成功，账号没注册，密码错误）
typedef struct _STRU_TCP_LOGIN_RS
{
    _STRU_TCP_LOGIN_RS():type(_DEF_TCP_LOGIN_RS),result(login_no_count),userId(0)
    {

    }
    PackType type;
    int result;
    int userId;
}_STRU_TCP_LOGIN_RS;

//好友信息：协议头、id、昵称、头像id、签名、状态
typedef struct _STRU_TCP_FRIEND_INFO
{
    _STRU_TCP_FRIEND_INFO():type(_DEF_TCP_FRIEND_INFO),userId(0),status(status_offline)
    {
        memset(name,0,_DEF_LENGTH);
        memset(feeling,0,_DEF_LENGTH);
    }
    PackType type;
    int userId;
    int iconId;
    int status;
    char name[_DEF_LENGTH];
    char feeling[_DEF_LENGTH];

}_STRU_TCP_FRIEND_INFO;

//聊天请求：协议头、聊天内容、好友id、自己的id
typedef struct _STRU_TCP_CHAT_RQ
{
    _STRU_TCP_CHAT_RQ():type(_DEF_TCP_CHAT_RQ),userId(0),friendId(0)
    {
        memset(content,0,_DEF_LENGTH);
    }
    PackType type;
    int userId;
    int friendId;
    char content[_DEF_LENGTH];

}_STRU_TCP_CHAT_RQ;
//聊天回复：协议头、聊天结果
typedef struct _STRU_TCP_CHAT_RS
{
    _STRU_TCP_CHAT_RS():type(_DEF_TCP_CHAT_RS),result(send_fail),userId(0)
    {

    }
    PackType type;
    int result;
    int userId;
}_STRU_TCP_CHAT_RS;
//添加好友请求：协议头、好友昵称、自己的id、自己的昵称
typedef struct _STRU_TCP_ADD_FRIEND_RQ
{
    _STRU_TCP_ADD_FRIEND_RQ():type(_DEF_TCP_ADD_FRIEND_RQ),userId(0)
    {
        memset(friendname,0,_DEF_LENGTH);
        memset(username,0,_DEF_LENGTH);
    }
    PackType type;
    int userId;
    char friendname[_DEF_LENGTH];
    char username[_DEF_LENGTH];

}_STRU_TCP_ADD_FRIEND_RQ;
//添加好友回复：协议头、添加结果（好友不存在、好友不在线、好友同意、好友拒绝)、好友昵称、自己id、好友id
typedef struct _STRU_TCP_ADD_FRIEND_RS
{
    _STRU_TCP_ADD_FRIEND_RS():type(_DEF_TCP_ADD_FRIEND_RS),userId(0),friendId(0),result(add_friend_no_user)
    {
        memset(friendname,0,_DEF_LENGTH);
    }
    PackType type;
    int userId;
    int friendId;
    int result;
    char friendname[_DEF_LENGTH];
}_STRU_TCP_ADD_FRIEND_RS;
//下线请求：协议头、自己的id
typedef struct _STRU_TCP_OFFLINE_RQ
{
    _STRU_TCP_OFFLINE_RQ():type(_DEF_TCP_OFFLINE_RQ),userId(0)
    {

    }
    PackType type;
    int userId;
}_STRU_TCP_OFFLINE_RQ;
#endif // CONFIG_H

