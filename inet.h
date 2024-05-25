#ifndef INET_H
#define INET_H

#include <QAbstractSocket>
#include <QObject>
#include "config.h"
class INetMediator;
class INet:public QObject
{
    Q_OBJECT
public:
    INet(){};
    virtual ~INet(){};
public:
    //初始化网络
    virtual bool InitNet() = 0;
    //发送数据(UDP是ip地址--ulong，TCP是socket--uint)
    virtual bool SendData(char* sendData, int nLen, QAbstractSocket* lSend) = 0;
    //关闭网络
    virtual void UnInitNet() = 0;
    //接收数据
    virtual void RecvData() = 0;
    INetMediator * m_pMediator;
};

#endif // INET_H
