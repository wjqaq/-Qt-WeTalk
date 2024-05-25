#include "useritem.h"
#include "ui_useritem.h"


QString UserItem::name() const
{
    return m_names;
}

UserItem::UserItem(QWidget *parent,int x,int y)
    : QWidget(parent)
    , ui(new Ui::UserItem),m_width(x),m_height(y)
{
    setFixedSize(m_width,m_height);
    ui->setupUi(this);
    m_pbIcon = new QPushButton;
    m_name = new QLabel;
    m_content = new QLabel;
    m_layout = new QVBoxLayout;
    m_layout_h = new QHBoxLayout;

    m_pbIcon->setMaximumSize(m_height,m_height);
    m_name->setMinimumSize(m_width-m_height,m_height/2);
    m_content->setMinimumSize(m_width-m_height,m_height/2);
    m_layout->addWidget(m_name);
    m_layout->addWidget(m_content);
    m_layout_h->addWidget(m_pbIcon);
    m_layout_h->addLayout(m_layout);
    this->setLayout(m_layout_h);
}

UserItem::~UserItem()
{
    delete ui;
    if(m_pbIcon)
    {
        delete m_pbIcon;
        m_pbIcon = nullptr;
    }
    if(m_name)
    {
        delete m_name;
        m_name = nullptr;
    }
    if(m_content)
    {
        delete m_content;
        m_content = nullptr;
    }
}

void UserItem::addUserItem(QString name, QString content)
{
    m_names=name;
    m_name->setText(name);
    m_content->setText(content);

}
