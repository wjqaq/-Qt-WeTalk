#ifndef INETMEDIATOR_H
#define INETMEDIATOR_H

#include <QObject>
#include <QAbstractSocket>
class INet;
class INetMediator : public QObject
{
    Q_OBJECT
public:
    INetMediator();
    virtual ~INetMediator();
public:
    //初始化网络
    virtual bool OpenNet() = 0;
    //发送数据(UDP是ip地址--ulong，TCP是socket--uint)
    virtual bool SendData(char* sendData, int nLen, QAbstractSocket* lSend) = 0;
    //数据处理
    virtual void DealData(char* recvData, int nLen, QAbstractSocket* lFrom) = 0;
    //关闭网络
    virtual void CloseNet() = 0;
protected:
    INet* m_pNet;
signals:
    //把收到数据传给kernel
    void SIG_ReadyData(char*,int,QAbstractSocket*);
};

#endif // INETMEDIATOR_H
