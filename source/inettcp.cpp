#include "inettcp.h"
INetTcp::INetTcp(INetMediator* pMediator):m_isStop(false)
{
    m_pMediator = pMediator;
}

INetTcp::~INetTcp()
{

}
bool INetTcp::InitNet()
{
    socket.connectToHost(QString(_IP), _PORT);
    if (!socket.waitForConnected(3000))
    {
        qDebug() << "Error: Connection timed out!";
        return false;
    }
    qDebug() << "Connected to server.";
    bt.clear();
    connect(&socket, &QTcpSocket::readyRead, this, &INetTcp::RecvData);
    //connect(&que,&QQueue<QByteArray>::isEmpty,this, &INetTcp::do_work);
    // 设置定时器间隔，单位为毫秒
    connect(&timer, &QTimer::timeout, this, &INetTcp::do_work);
    timer.start(100); // 1000毫秒 = 1秒
    return true;
}

bool INetTcp::SendData(char *sendData, int nLen, QAbstractSocket* lSend)
{
    qDebug()<<__func__;
    if (!sendData || nLen <= 0)
    {
        qDebug() << "senddata parameter error: " << socket.errorString();
        return false;
    }
    QByteArray blockSize(reinterpret_cast<const char*>(&nLen), sizeof(nLen));
    qint64  nSendNum = 0;
    if (socket.state() == QAbstractSocket::ConnectedState)
    {
        qDebug()<<blockSize.data();
        nSendNum = socket.write(blockSize,sizeof(int));
        qDebug()<<nSendNum;
        if (nSendNum == -1)
        {
            qDebug()<<"send data data error"<<socket.errorString();
            return false;
        }
        nSendNum = socket.write(sendData,nLen);
        if (nSendNum == -1)
        {
            qDebug()<<"send data data error"<<socket.errorString();
            return false;
        }
    }
    qDebug()<<nSendNum;
    qDebug()<<"send success\n";
    return true;
}

void INetTcp::UnInitNet()
{
    m_isStop=true;
    socket.disconnectFromHost();
}

void INetTcp::RecvData()
{
    //qDebug()<<__func__;
    bt.append(socket.readAll());
    if(bt.size() >= sizeof(int))
    {
        int size;
        memcpy(&size, bt.data(), sizeof(int));  // 使用memcpy将前四个字节转换为int值
        if(bt.size()>=size+sizeof(int))
        {
            bt.remove(0,sizeof(int));
            QByteArray tmp = bt.left(size);
            que.push_back(tmp);
            bt.remove(0,size);
        }
    }
}


void INetTcp::do_work()
{
    while(!que.empty())
    {
        //qDebug()<<__func__;
        qDebug()<<que.size();
        QByteArray tmp = que.front();
        que.pop_front();
        m_pMediator->DealData(tmp.data(), tmp.size(), &socket);
    }
    Q_EMIT socket.readyRead();
}



