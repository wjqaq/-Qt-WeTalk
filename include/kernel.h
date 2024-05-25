#ifndef KERNEL_H
#define KERNEL_H

#include <QObject>
#include <QMessageBox>
#include <QInputDialog>
#include "mainwindow.h"
#include "inet.h"
#include "inetmediator.h"
#include "inettcp.h"
#include "inettcpmediator.h"
#include "regiser.h"
#include "userplatfrom.h"
#include "chatdialog.h"
class Kernel;
typedef void (Kernel::*pFun)(char* recvData, int nLen, QAbstractSocket* lFrom);
class Kernel : public QObject
{
    Q_OBJECT
public:
    explicit Kernel(QObject *parent = nullptr);
    ~Kernel();
    //初始化协议头数组
    void setProtocolMap();
    //注册成功后隐藏注册界面，显示登录界面
    void registerHide();
    void loginHide();
    void closePrgm();
private:
    int m_pltWidth;
    int m_pltHeight;
    int m_id;
    QString m_name;
    MainWindow* m_window;
    INetMediator *m_pMediator;
    Regiser * m_reg;
    UserPlatfrom* m_plt;
    //保存tcp协议好友id和useritem
    QMap<int,UserItem*>m_mapIdToUserItem;
    //保存id和chatdialog
    QMap<int,ChatDialog*>m_mapIdToChatdlg;
    //定义函数指针数组
    pFun m_mapPackTypeToFun[_DEF_PROTOCOL_COUNT];
    //处理注册回复
    void dealRegisterRs(char* recvData, int nLen, QAbstractSocket* lFrom);
    //处理登录回复
    void dealLoginRs(char* recvData, int nLen, QAbstractSocket* lFrom);
    //登录时处理好友信息
    void dealFriendInfo(char* recvData, int nLen, QAbstractSocket* lFrom);
    //处理聊天请求tcp
    void dealChatRq(char* recvData,int nLen,QAbstractSocket* lFrom);
    //处理聊天回复tcp
    void dealChatRs(char* recvData,int nLen,QAbstractSocket* lFrom);
    //处理添加好友请求
    void dealAddFriendRq(char* recvData,int nLen,QAbstractSocket* lFrom);
    //处理添加好友回复
    void dealAddFriendRs(char* recvData,int nLen,QAbstractSocket* lFrom);
    //处理好友下线
    void dealTcpOfflineRq(char *recvData, int nLen, QAbstractSocket* lFrom);
signals:
private slots:
    void slot_ReadyData(char*, int, QAbstractSocket*);
    void slot_login(QString,QString);
    void slot_register();
    void slot_registerConfirm(QString ,QString ,QString);
    void slot_RegisterHide();
    void slot_sendMsg(int,QString);
    void slot_ChatDialogHide(int);
    //void slot_LoginHide();
    void slot_CloseWindow();
    void slot_Chat(int);
    void slot_addFriend();
};

#endif // KERNEL_H
