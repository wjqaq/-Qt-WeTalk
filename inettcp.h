#ifndef INETTCP_H
#define INETTCP_H
#include "inet.h"
#include "inettcpmediator.h"
#include <QTcpSocket>
#include <QThread>
#include <QQueue>
#include <QTimer>
class INetTcp:public INet
{
public:
    INetTcp(INetMediator* pMediator);
    virtual ~INetTcp();
public:
    //初始化网络
    virtual bool InitNet();
    //发送数据(UDP是ip地址--ulong，TCP是socket--uint)
    virtual bool SendData(char* sendData, int nLen, QAbstractSocket* lSend);
    //关闭网络
    virtual void UnInitNet();
    //接收数据
    virtual void RecvData();
private:
    QTcpSocket socket;
    QThread thread;
    bool m_isStop;
    QQueue<QByteArray>que;
    QByteArray bt;
    QTimer timer;
private slots:
    void do_work();
};

#endif // INETTCP_H
