#ifndef INETTCPMEDIATOR_H
#define INETTCPMEDIATOR_H

#include <QObject>
#include "inetmediator.h"

class INetTcpMediator : public INetMediator
{
    Q_OBJECT
public:
    INetTcpMediator();
    virtual ~INetTcpMediator();
public:
    //初始化网络
    virtual bool OpenNet();
    //发送数据(UDP是ip地址--ulong，TCP是socket--uint)
    virtual bool SendData(char* sendData, int nLen, QAbstractSocket* lSend);
    //数据处理
    virtual void DealData(char* recvData, int nLen, QAbstractSocket* lFrom);
    //关闭网络
    virtual void CloseNet();

};

#endif // INETTCPMEDIATOR_H
