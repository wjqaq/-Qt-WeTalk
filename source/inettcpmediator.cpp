#include "inettcpmediator.h"
#include "inettcp.h"
INetTcpMediator::INetTcpMediator()
{
    m_pNet = new INetTcp(this);
}

INetTcpMediator::~INetTcpMediator()
{
    if (m_pNet)
    {
        delete m_pNet;
        m_pNet = nullptr;
    }
}

bool INetTcpMediator::OpenNet()
{
    return m_pNet->InitNet();
}

bool INetTcpMediator::SendData(char *sendData, int nLen, QAbstractSocket* lSend)
{
    return m_pNet->SendData(sendData,nLen,lSend);
}

void INetTcpMediator::DealData(char *recvData, int nLen, QAbstractSocket* lFrom)
{
    Q_EMIT SIG_ReadyData(recvData,nLen,lFrom);
}

void INetTcpMediator::CloseNet()
{
    m_pNet->UnInitNet();
}
