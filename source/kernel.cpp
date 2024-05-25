#include "kernel.h"

Kernel::Kernel(QObject *parent)
    : QObject{parent}
{
    setProtocolMap();
    m_window = new MainWindow;
    connect(m_window,SIGNAL(SIG_login(QString,QString)),this,SLOT(slot_login(QString,QString)));
    connect(m_window,SIGNAL(SIG_register()),this,SLOT(slot_register()));
    //connect(m_window,SIGNAL(SIG_LoginHide()),this,SLOT(slot_LoginHide()));
    m_reg = new Regiser(nullptr,m_window->m_width,m_window->m_height);
    connect(m_reg,SIGNAL(SIG_RegisterConfirm(QString,QString,QString)),this,SLOT(slot_registerConfirm(QString,QString,QString)));
    connect(m_reg,SIGNAL(SIG_RegisterHide()),this,SLOT(slot_RegisterHide()));
    m_pltWidth  =400;
    m_pltHeight =200;
    m_plt = new UserPlatfrom(nullptr,m_pltWidth,m_pltHeight);
    connect(m_plt,SIGNAL(SIG_addFriend()),this,SLOT(slot_addFriend()));
    connect(m_plt,SIGNAL(SIG_CloseWindow()),this,SLOT(slot_CloseWindow()));
    m_window->show();
    m_pMediator=new INetTcpMediator();
    connect(m_pMediator,SIGNAL(SIG_ReadyData(char*,int,QAbstractSocket*)),this,SLOT(slot_ReadyData(char*,int,QAbstractSocket*)));
    m_pMediator->OpenNet();
}

Kernel::~Kernel()
{
    for(auto ite = m_mapIdToChatdlg.begin();ite!=m_mapIdToChatdlg.end();)
    {
        ChatDialog* chat = *ite;
        if(chat)
        {
            chat->hide();
            delete chat;
            chat=nullptr;
        }
        ite = m_mapIdToChatdlg.erase(ite);
    }
    m_mapIdToChatdlg.clear();
    for(auto ite=m_mapIdToUserItem.begin();ite!=m_mapIdToUserItem.end();)
    {
        UserItem*item=*ite;
        if(item)
        {
            item->hide();
            delete item;
            item=nullptr;
        }
        //从map中移除节点
        ite=m_mapIdToUserItem.erase(ite);
    }
    m_mapIdToUserItem.clear();
    if(m_pMediator)
    {
        m_pMediator->CloseNet();
        delete m_pMediator;
        m_pMediator = nullptr;
    }
    if(m_window)
    {
        delete m_window;
        m_window = nullptr;
    }
    if(m_pMediator)
    {
        delete m_pMediator;
        m_pMediator=nullptr;
    }
    if(m_reg)
    {
        delete m_reg;
        m_reg = nullptr;
    }
}

void Kernel::setProtocolMap()
{
    qDebug()<<__func__;
    //数组初始化为0
    memset(m_mapPackTypeToFun,0,sizeof(m_mapPackTypeToFun));
    //绑定协议头和处理函数
    m_mapPackTypeToFun[_DEF_TCP_REGISTER_RS-_DEF_PROTOCOL_BASE-1]               =&Kernel::dealRegisterRs;
    m_mapPackTypeToFun[_DEF_TCP_LOGIN_RS-_DEF_PROTOCOL_BASE-1]                  =&Kernel::dealLoginRs;
    m_mapPackTypeToFun[_DEF_TCP_FRIEND_INFO-_DEF_PROTOCOL_BASE-1]               =&Kernel::dealFriendInfo;
    m_mapPackTypeToFun[_DEF_TCP_CHAT_RQ-_DEF_PROTOCOL_BASE-1]                   =&Kernel::dealChatRq;
    m_mapPackTypeToFun[_DEF_TCP_CHAT_RS-_DEF_PROTOCOL_BASE-1]                   =&Kernel::dealChatRs;
    m_mapPackTypeToFun[_DEF_TCP_ADD_FRIEND_RQ-_DEF_PROTOCOL_BASE-1]             =&Kernel::dealAddFriendRq;
    m_mapPackTypeToFun[_DEF_TCP_ADD_FRIEND_RS-_DEF_PROTOCOL_BASE-1]             =&Kernel::dealAddFriendRs;
    m_mapPackTypeToFun[_DEF_TCP_OFFLINE_RQ-_DEF_PROTOCOL_BASE-1]                =&Kernel::dealTcpOfflineRq;

}

void Kernel::registerHide()
{
    m_reg->m_leName->setText("");
    m_reg->m_leCount->setText("");
    m_reg->m_lePasswd->setText("");
    m_reg->hide();
    m_window->m_leCount->setText("");
    m_window->m_lePasswd->setText("");
    m_window->show();
}

void Kernel::loginHide()
{
    m_plt->hide();
    m_window->m_leCount->setText("");
    m_window->m_lePasswd->setText("");
    m_window->show();
}

void Kernel::closePrgm()
{
    exit(0);
}

void Kernel::dealRegisterRs(char *recvData, int nLen, QAbstractSocket *lFrom)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_TCP_REGISTER_RS *rs=(_STRU_TCP_REGISTER_RS*)recvData;

    //2.根据注册结果显示提示信息
    if(rs->result==register_success)
    {
        QMessageBox::about(m_reg,"提示","注册成功");
        registerHide();
    }
    else if(rs->result==register_count_used)
    {
        QMessageBox::about(m_reg,"提示","账号已存在");
    }
    else if(rs->result==register_name_used)
    {
        QMessageBox::about(m_reg,"提示","昵称已存在");
    }
    else if(rs->result==register_name_illegal)
    {
        QMessageBox::about(m_reg,"提示","昵称非法");
    }
    else if(rs->result==register_count_illegal)
    {
        QMessageBox::about(m_reg,"提示","账号非法");
    }
    else if(rs->result==register_passwd_illegal)
    {
        QMessageBox::about(m_reg,"提示","密码非法");
    }
}

void Kernel::dealLoginRs(char *recvData, int nLen, QAbstractSocket *lFrom)
{
    qDebug()<<__func__;
    //取出协议头
    _STRU_TCP_LOGIN_RS *rs = (_STRU_TCP_LOGIN_RS *)recvData;
    //2.根据登录结果显示提示信息
    if(rs->result==login_success)
    {
        m_window->m_leCount->setText("");
        m_window->m_lePasswd->setText("");
        m_id = rs->userId;
        m_window->hide();
        m_plt->show();
    }
    else if(rs->result==login_no_count)
    {
        QMessageBox::about(m_plt,"提示","账号不存在");
    }
    else if(rs->result==login_passwd_error)
    {
        QMessageBox::about(m_plt,"提示","密码错误");
    }
    else if(rs->result==login_count_illegal)
    {
        QMessageBox::about(m_plt,"提示","账号非法");
    }
    else if(rs->result==login_passwd_illegal)
    {
        QMessageBox::about(m_plt,"提示","密码非法");
    }

}

void Kernel::dealFriendInfo(char *recvData, int nLen, QAbstractSocket *lFrom)
{
    qDebug()<<__func__;
    //取出协议头
    _STRU_TCP_FRIEND_INFO *rq = (_STRU_TCP_FRIEND_INFO*)recvData;
    //1.判断userItem是否为自己
    qDebug()<<rq->userId<<" "<<m_id;
    if(rq->userId == m_id)
    {
        //判断是否存在，若存在更新信息
        if(m_mapIdToUserItem.count(rq->userId)>0)
        {
            UserItem* item = m_mapIdToUserItem[rq->userId];
            m_plt->updateUserItem(item,rq->name,nullptr);
        }
        //不存在，new一个自己的userItem
        else
        {
            UserItem* item = new UserItem(nullptr,m_pltWidth-35,m_pltWidth/7);
            item->m_id = rq->userId;
            m_name = rq->name;
            connect(item,SIGNAL(SIG_Chat(int)),this,SLOT(slot_Chat(int)));
            m_plt->addUserItem(item,rq->name,nullptr);
            m_mapIdToUserItem[rq->userId]=item;
            ChatDialog* dia = new ChatDialog;
            connect(dia,SIGNAL(SIG_sendMsg(int,QString)),this,SLOT(slot_sendMsg(int,QString)));
            connect(dia,SIGNAL(SIG_ChatDialogHide(int)),this,SLOT(slot_ChatDialogHide(int)));
            dia->setTitle(rq->name);
            dia->m_id = rq->userId;
            dia->m_name = rq->name;
            m_mapIdToChatdlg[rq->userId]=dia;
        }
        //QThread::sleep(50);
    }
    //2.好友
    else
    {
        //判断是否存在，若存在更新信息
        if(m_mapIdToUserItem.count(rq->userId)>0)
        {
            UserItem* item = m_mapIdToUserItem[rq->userId];
            m_plt->updateUserItem(item,rq->name,nullptr);
        }
        //不存在，new一个自己的userItem
        else
        {
            UserItem* item = new UserItem(nullptr,m_pltWidth-35,m_pltWidth/7);
            item->m_id = rq->userId;
            connect(item,SIGNAL(SIG_Chat(int)),this,SLOT(slot_Chat(int)));
            m_plt->addUserItem(item,rq->name,nullptr);
            m_mapIdToUserItem[rq->userId]=item;
            ChatDialog* dia = new ChatDialog;
            connect(dia,SIGNAL(SIG_sendMsg(int,QString)),this,SLOT(slot_sendMsg(int,QString)));
            connect(dia,SIGNAL(SIG_ChatDialogHide(int)),this,SLOT(slot_ChatDialogHide(int)));
            dia->m_id = rq->userId;
            dia->m_name = rq->name;
            dia->setTitle(rq->name);
            m_mapIdToChatdlg[rq->userId]=dia;
        }
    }
}

void Kernel::dealChatRq(char *recvData, int nLen, QAbstractSocket *lFrom)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_TCP_CHAT_RQ *rq=( _STRU_TCP_CHAT_RQ *)recvData;
    //2.找到聊天窗口
    if(m_mapIdToChatdlg.count(rq->friendId)>0)
    {
        //把聊天窗口设置到窗口上
        ChatDialog*chat=m_mapIdToChatdlg[rq->friendId];
        if(rq->userId == m_id)
        {
            //chat->setContent(rq->content,rq->friendId,true);
            return ;
        }
        chat=m_mapIdToChatdlg[rq->userId];
        chat->is_left=true;
        chat->setContent(rq->content,chat->m_name,rq->userId,false);
        //显示聊天窗口
        //chat->show();
    }
}

void Kernel::dealChatRs(char *recvData, int nLen, QAbstractSocket *lFrom)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_TCP_CHAT_RS *rs=( _STRU_TCP_CHAT_RS *)recvData;
    //2.找到聊天窗口
    if(m_mapIdToChatdlg.count(rs->userId)>0)
    {
        //把好友设置到窗口上
        ChatDialog*chat=m_mapIdToChatdlg[rs->userId];
        //chat->setContent(QString("好友[%1]不在线").arg(chat->getName()));
        //显示聊天窗口
        chat->show();
    }
}

void Kernel::dealAddFriendRq(char *recvData, int nLen, QAbstractSocket *lFrom)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_TCP_ADD_FRIEND_RQ *rq=(_STRU_TCP_ADD_FRIEND_RQ *)recvData;
    _STRU_TCP_ADD_FRIEND_RS rs;
    //2.弹出提示框，询问用户是否同意添加好友
    if(QMessageBox::Yes==QMessageBox::question(m_plt,"提示",QString("用户[%1]请求添加好友").arg(rq->username)))
    {
        rs.result=add_friend_aggree;
        rs.friendId=m_id;
        strcpy(rs.friendname,rq->friendname);
        rs.userId=rq->userId;
    }
    else
    {
        rs.result=add_friend_disaggree;
        strcpy(rs.friendname,rq->friendname);
        rs.userId=rq->userId;
    }
    m_pMediator->SendData((char*)&rs,sizeof(rs),nullptr);
}

void Kernel::dealAddFriendRs(char *recvData, int nLen, QAbstractSocket *lFrom)
{

    qDebug()<<__func__;
    //1.拆包
    _STRU_TCP_ADD_FRIEND_RS *rs=(_STRU_TCP_ADD_FRIEND_RS *)recvData;
    //2.根据用户添加结果
    if(rs->result==add_friend_no_user)
    {
        QMessageBox::about(m_plt,"提示",QString("用户[%1]不存在").arg(rs->friendname));
    }else if(rs->result==add_friend_offline)
    {
        QMessageBox::about(m_plt,"提示",QString("用户[%1]不在线").arg(rs->friendname));
    }
    else if(rs->result==add_friend_disaggree)
    {
        QMessageBox::about(m_plt,"提示",QString("用户[%1]拒绝").arg(rs->friendname));
    }else if(rs->result==add_friend_aggree)
    {
        QMessageBox::about(m_plt,"提示",QString("用户[%1]同意").arg(rs->friendname));
    }
}

void Kernel::dealTcpOfflineRq(char *recvData, int nLen, QAbstractSocket *lFrom)
{
    qDebug()<<__func__;
}

void Kernel::slot_ReadyData(char* sendData, int nLen, QAbstractSocket* lSend)
{
    qDebug()<<__func__;
    //取出协议头
    PackType type=*(int*)sendData;
    //根据协议头走到不同的处理流程
    //计算数组下标
    int index = type-_DEF_PROTOCOL_BASE-1;
    qDebug()<<type;
    //校验是否越界
    if(0<=index&&index<_DEF_PROTOCOL_COUNT)
    {
        pFun pf=m_mapPackTypeToFun[index];
        if(pf)
        {
            (this->*pf)(sendData,nLen,lSend);
        }
        else
        {
            qDebug()<<"no this function's type "<<type;
        }
    }
    else
    {
        qDebug()<<"no this type:"<<type;
    }
}



void Kernel::slot_login(QString count, QString passwd)
{
    qDebug()<<__func__;
    //1.封装协议
    _STRU_TCP_LOGIN_RQ rq;
    strcpy(rq.count,count.toUtf8().toStdString().c_str());
    strcpy(rq.passwd,passwd.toUtf8().toStdString().c_str());
    //2.发送给服务器
    m_pMediator->SendData((char*)&rq,sizeof(rq),nullptr);
}

void Kernel::slot_register()
{
    qDebug()<<__func__;
    m_window->hide();
    m_reg->show();
}

void Kernel::slot_registerConfirm(QString name,QString count,QString passwd)
{
    qDebug()<<__func__;
    //1.封装协议
    _STRU_TCP_REGISTER_RQ rq;
    strcpy(rq.name,name.toUtf8().toStdString().c_str());
    strcpy(rq.count,count.toUtf8().toStdString().c_str());
    strcpy(rq.passwd,passwd.toUtf8().toStdString().c_str());
    //2.发送给服务器
    m_pMediator->SendData((char*)&rq,sizeof(rq),nullptr);
}

void Kernel::slot_RegisterHide()
{
    registerHide();
}

void Kernel::slot_sendMsg(int id,QString text)
{
    qDebug()<<__func__;
    _STRU_TCP_CHAT_RQ rq;
    if(m_mapIdToChatdlg.count(id)>0)
    {
        ChatDialog* chat = m_mapIdToChatdlg[id];
        chat->setContent(text,m_name,m_id,true);
    }
    strcpy(rq.content,text.toStdString().c_str());
    rq.userId=m_id;
    rq.friendId=id;
    m_pMediator->SendData((char*)&rq,sizeof(rq),nullptr);
}

void Kernel::slot_ChatDialogHide(int id)
{
    qDebug()<<__func__;
    if(m_mapIdToChatdlg.count(id)>0)
    {
        ChatDialog* chat = m_mapIdToChatdlg[id];
        chat->hide();
        m_plt->show();
    }
}

void Kernel::slot_CloseWindow()
{
    qDebug()<<__func__;
    struct _STRU_TCP_OFFLINE_RQ tcpRq;
    tcpRq.userId=m_id;
    m_pMediator->SendData((char*)&tcpRq,sizeof(tcpRq),nullptr);
    closePrgm();
}

void Kernel::slot_Chat(int m_id)
{
    m_plt->hide();
    if(m_mapIdToChatdlg.count(m_id)>0)
    {
        ChatDialog* dia = m_mapIdToChatdlg[m_id];
        dia->show();
    }
}

void Kernel::slot_addFriend()
{
    qDebug()<<__func__;    //1.弹出窗口，提示用户输入好友信息，（只支持昵称）
    QString name = QInputDialog::getText(m_plt,"提示","请输入待加好友昵称");
    //2.校验是否合法
    QString nameTmp=name;
    if(name.isEmpty()||nameTmp.remove(" ").isEmpty())
    {
        QMessageBox::about(m_plt,"提示","名字不能为空");
        return;
    }
    //3.判断是不是自己的
    if(name==m_name)
    {
        QMessageBox::about(m_plt,"提示","不能添加自己");
        return;
    }
    //4.判断是不是自己的好友
    for(auto ite = m_mapIdToUserItem.begin();ite!=m_mapIdToUserItem.end();ite++)
    {
        UserItem* item=*ite;
        if(item->name()==name)
        {
            QMessageBox::about(m_plt,"提示","好友已存在");
            return ;
        }

    }
    //5.给服务端发送添加好友请求
    _STRU_TCP_ADD_FRIEND_RQ rq;
    strcpy(rq.friendname,name.toUtf8().toStdString().c_str());
    strcpy(rq.username,m_name.toUtf8().toStdString().c_str());
    rq.userId=m_id;
    m_pMediator->SendData((char*)&rq,sizeof(rq),nullptr);
}

// void Kernel::slot_LoginHide()
// {
//     loginHide();
// }
