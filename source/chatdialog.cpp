#include "chatdialog.h"
#include "ui_chatdialog.h"
#include <QMessageBox>
ChatDialog::ChatDialog(QWidget *parent,int x,int y)
    : QWidget(parent)
    , ui(new Ui::ChatDialog),m_width(x),m_height(y)
{
    ui->setupUi(this);
    this->setWindowTitle("WeTalk");
    m_lab = new QLabel;//聊天框名称
    m_pbBack = new QPushButton;//回退
    m_pbChatInfo = new QPushButton;//聊天信息
    m_pbChatBtoVoice = new QPushButton;//聊天转语音选项|语音转聊天选项
    m_teChatBtoVoice = new QTextEdit;//聊天或者语音输入
    connect(m_teChatBtoVoice,SIGNAL(textChanged()),this,SLOT(slot_TeHasChanged()));
    m_lyShowall = new QVBoxLayout;
    m_tbChat = new QTextBrowser;//显示聊天内容
    m_scChat = new QScrollArea;//显示聊天内容
    m_lwChat = new QListWidget;
    m_wgChat = new QWidget;//显示聊天内容
    m_lyShow = new QVBoxLayout;//显示聊天内容
    m_pbEmoji = new QPushButton("emoji");//表情
    m_pbMore = new QPushButton("+");//更多
    isShow = true;
    connect(m_pbMore,SIGNAL(clicked()),this,SLOT(slot_pbAddClicked()));
    m_lytitle = new QHBoxLayout;//上面
    m_lyChat = new QHBoxLayout;//下面
    m_lyAll = new QVBoxLayout;//整体
    m_lab->setAlignment(Qt::AlignCenter);
    m_lab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_scChat->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_pbChatBtoVoice->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_pbChatBtoVoice->setStyleSheet("QPushButton { border: 2px solid gray; border-radius: 20px; padding: 4px; background-color: lightblue; }"
                           "QPushButton:pressed { background-color: lightgray; }");
    m_pbEmoji->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_pbEmoji->setStyleSheet("QPushButton { border: 2px solid gray; border-radius: 20px; padding: 4px; background-color: lightblue; }"
                                    "QPushButton:pressed { background-color: lightgray; }");
    m_pbMore->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_pbMore->setStyleSheet("QPushButton { border: 2px solid gray; border-radius: 20px; padding: 4px; background-color: lightblue; }"
                                    "QPushButton:pressed { background-color: lightgray; }");
#ifdef Q_OS_WIN
    m_height *=4;
    QSize size(m_width,m_height);
    this->setFixedSize(size);
    //m_scChat->setMaximumSize(m_width - 20, m_height * 0.8);
    m_scChat->setFixedSize(m_width - 20, m_height * 0.8);
    m_wgChat->setFixedWidth(m_width - 50);
    m_wgChat->setFixedHeight(0);
   // m_wgChat->setMaximumWidth(m_width - 50);
   // m_wgChat->setFixedHeight(0);
    m_lab->setFixedSize(m_width-120,20);
   // m_lab->setMinimumSize(m_width-120,20);
    m_pbBack->setFixedSize(m_width/10,m_width/10);
   // m_pbBack->setMinimumSize(m_width/10,m_width/10);
    m_pbChatInfo->setFixedSize(m_width/10,m_width/10);
  //  m_pbChatInfo->setMinimumSize(m_width/10,m_width/10);
    m_pbChatBtoVoice->setFixedSize(m_width/10,m_width/10);
  //  m_pbChatBtoVoice->setMinimumSize(m_width/10,m_width/10);
    m_teChatBtoVoice->setFixedSize(m_width - m_width/10*4,m_width/10);
  //  m_teChatBtoVoice->setMinimumSize(m_width - m_width/10*4,m_width/10);
    m_pbEmoji->setFixedSize(m_width/10,m_width/10);
  //  m_pbEmoji->setMinimumSize(m_width/10,m_width/10);
    m_pbMore->setFixedSize(m_width/10,m_width/10);
   // m_pbMore->setMinimumSize(m_width/10,m_width/10);
#endif
#ifdef  Q_OS_ANDROID
    m_scChat->setMaximumSize(m_width - 20, m_height * 0.8*4);
    m_scChat->setMinimumSize(m_width - 20, m_height * 0.8*4);
    m_lab->setMaximumSize(m_width-120,20);
    m_lab->setMinimumSize(m_width-120,20);
    m_pbBack->setMaximumSize(m_width/10,m_width/10);
    m_pbBack->setMinimumSize(m_width/10,m_width/10);
    m_pbChatInfo->setMaximumSize(m_width/10,m_width/10);
    m_pbChatInfo->setMinimumSize(m_width/10,m_width/10);
    m_pbChatBtoVoice->setMaximumSize(m_width/10,m_width/10);
    m_pbChatBtoVoice->setMinimumSize(m_width/10,m_width/10);
    m_teChatBtoVoice->setMaximumSize(m_width - m_width/10*4,m_width/10);
    m_teChatBtoVoice->setMinimumSize(m_width - m_width/10*4,m_width/10);
    m_pbEmoji->setMaximumSize(m_width/10,m_width/10);
    m_pbEmoji->setMinimumSize(m_width/10,m_width/10);
    m_pbMore->setMaximumSize(m_width/10,m_width/10);
    m_pbMore->setMinimumSize(m_width/10,m_width/10);
#endif
    m_sp = new QSpacerItem(m_width/8, m_width/8, QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_lytitle->addWidget(m_pbBack);
    m_lytitle->addWidget(m_lab);
    m_lytitle->addWidget(m_pbChatInfo);
    m_lyChat->addWidget(m_pbChatBtoVoice);
    m_lyChat->addWidget(m_teChatBtoVoice);
    m_lyChat->addWidget(m_pbEmoji);
    m_lyChat->addWidget(m_pbMore);
    m_lyAll->addLayout(m_lytitle);
    m_lyAll->addWidget(m_scChat);
    m_lyAll->addLayout(m_lyChat);
    this->setLayout(m_lyAll);
}

ChatDialog::~ChatDialog()
{
    if(m_sp)
    {
        delete m_sp;
        m_sp = nullptr;
    }
    if(m_lab)
    {
        delete m_lab;
        m_lab = nullptr;
    }
    if(m_pbBack)
    {
        delete m_pbBack;
        m_pbBack = nullptr;
    }
    if(m_pbEmoji)
    {
        delete m_pbEmoji;
        m_pbEmoji = nullptr;
    }
    if(m_pbChatInfo)
    {
        delete m_pbChatInfo;
        m_pbChatInfo = nullptr;
    }
    if(m_pbChatBtoVoice)
    {
        delete m_pbChatBtoVoice;
        m_pbChatBtoVoice = nullptr;
    }
    if(m_teChatBtoVoice)
    {
        delete m_teChatBtoVoice;
        m_teChatBtoVoice = nullptr;
    }
    if(m_scChat)
    {
        delete m_scChat;
        m_scChat = nullptr;
    }
    if(m_lwChat)
    {
        delete m_lwChat;
        m_lwChat = nullptr;
    }
    if(m_pbMore)
    {
        delete m_pbMore;
        m_pbMore = nullptr;
    }
    if(m_lytitle)
    {
        delete m_lytitle;
        m_lytitle = nullptr;
    }
    if(m_lyChat)
    {
        delete m_lyChat;
        m_lyChat = nullptr;
    }
    if(m_lyAll)
    {
        delete m_lyAll;
        m_lyAll = nullptr;
    }
    if(m_wgChat)
    {
        delete m_wgChat;
        m_wgChat = nullptr;
    }
    if(m_lyShow)
    {
        delete m_lyShow;
        m_lyShow = nullptr;
    }
    delete ui;
}

void ChatDialog::setTitle(QString title)
{
    m_lab->setText(title);
}
void ChatDialog::setContent(QString content,QString name,int id,bool type)
{
    qDebug()<<__func__;
    ChatContent* con = new ChatContent;
    con->setContent(nullptr,name,content,type);
    m_lyShow->addWidget(con);
    qDebug()<<m_wgChat->height();
    qDebug()<<con->height();
   // m_lyShow->addItem(m_sp);
    m_wgChat->setFixedSize(m_wgChat->width(),m_wgChat->height()+con->height());
    m_wgChat->setLayout(m_lyShow);
    if(!type)
    {
        m_scChat->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    }
    else
    {
        m_scChat->setAlignment(Qt::AlignRight|Qt::AlignTop);
    }
    m_scChat->setWidget(m_wgChat);

}

void ChatDialog::slot_TeHasChanged()
{
    QString text = m_teChatBtoVoice->toPlainText();
    if(text.isEmpty())
    {
        m_pbMore->setText("+");
        isShow = true;
    }
    else
    {
        m_pbMore->setText("发送");
        isShow = false;
    }
}

void ChatDialog::slot_pbAddClicked()
{
    if(!isShow)
    {
        QString text = m_teChatBtoVoice->toPlainText();
        m_teChatBtoVoice->setPlainText("");
        Q_EMIT SIG_sendMsg(m_id,text);
    }
    else
    {

    }
}
