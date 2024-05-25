#include "chatcontent.h"
#include "ui_chatcontent.h"

ChatContent::ChatContent(QWidget *parent,int x,int y)
    : QWidget(parent)
    , ui(new Ui::ChatContent),m_width(x),m_height(m_width/8)
{
    ui->setupUi(this);
    this->resize(m_width,m_height);
    m_labContent = new QLabel;
    m_pbHead = new QPushButton;
    m_labName = new QLabel;
    m_lyContent = new QVBoxLayout;
    m_ly = new QVBoxLayout;
    m_lyAll = new QVBoxLayout;
    m_lyHead = new QHBoxLayout;
    m_labContent->setStyleSheet("QLabel { background-color: white; border: none; }");
    m_labName->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    m_labContent->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    m_labName->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    m_labContent->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_pbHead->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_labName->setMinimumSize(m_width - 50,m_width/20);
    m_labName->setMaximumSize(m_width - 50,m_width/20);
    m_pbHead->setMaximumSize(m_width/10,m_width/10);
    m_pbHead->setMinimumSize(m_width/10,m_width/10);
    m_sp = new QSpacerItem(m_width/10, m_width/10, QSizePolicy::Minimum, QSizePolicy::Expanding);


}

ChatContent::~ChatContent()
{
    delete ui;
}

void ChatContent::setContent(QString icon, QString name, QString content,int type)
{
    qDebug()<<__func__;
    this->resize(m_width,m_height);
    m_pbHead->setFixedSize(m_width / 10, m_width / 10);
    m_pbHead->setIcon(QIcon(":/headimg/27.png"));
    m_labName->setText(name);
    m_ly->addWidget(m_pbHead);
   // m_ly->addItem(m_sp);
    // 创建一个 QTextDocument 来格式化文本
    QStringList lst;
    QString tmp;
    QString str;
    lst = content.split("\n");
    int index = 0;
    int times = 0;
    while (!lst.empty())
    {
        QString line = lst.first();
        lst.pop_front();
        index=0;
        str="";
        while(index<line.size())
        {
            int nextIndex = qMin(40, line.size());
            str += line.mid(index,nextIndex)+"\n";
            times++;
            index+=nextIndex;
        }
        tmp.append(str);
    }
    qDebug()<<times<<" "<<m_height;
    this->resize(m_width,m_height+times* 15);
    // 将格式化后的文本设置给 QLabel

    if(!type)
    {
        m_lyContent->addWidget(m_labName);
        m_lyContent->addWidget(m_labContent);
        m_lyHead->addItem(m_ly);
        m_lyHead->addItem(m_lyContent);
        m_lyAll->setAlignment(Qt::AlignLeft|Qt::AlignTop);
        m_labName->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    }
    else
    {
        //m_lyContent->addWidget(m_labName);
        m_lyContent->addWidget(m_labContent);
        m_lyHead->addItem(m_lyContent);
        m_lyHead->addItem(m_ly);
        m_lyAll->setAlignment(Qt::AlignRight|Qt::AlignTop);
        //m_labName->setAlignment(Qt::AlignRight|Qt::AlignTop);
    }
    m_labContent->setText(tmp);
    m_lyAll->addItem(m_lyHead);
    this->setLayout(m_lyAll);
}
