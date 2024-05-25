#include "regiser.h"
#include "ui_regiser.h"
#include <QMessageBox>
Regiser::Regiser(QWidget *parent,int x,int y)
    : QWidget(parent)
    , ui(new Ui::Regiser),m_width(x),m_height(y)
{
    ui->setupUi(this);
    setWindowTitle("WeTalk:注册");
    m_layout = new QVBoxLayout();
    m_lab = new QLabel("账号密码注册");
    m_leName = new QLineEdit();
    m_leName->setPlaceholderText(("输入昵称"));
    m_leCount = new QLineEdit();
    m_leCount->setPlaceholderText(("输入WeTalk账号"));
    m_lePasswd = new QLineEdit();
    m_lePasswd->setPlaceholderText(("输入WeTalk密码"));
    m_ckPro = new QCheckBox("已阅读并同意服务协议和WeTalk隐私保护指引");
    m_pbRegister = new QPushButton("注册");
    connect(m_pbRegister,SIGNAL(clicked()),this,SLOT(slot_pbRegister()));

    m_lab->setAlignment(Qt::AlignCenter);
    m_lab->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_leCount->setAlignment(Qt::AlignCenter); // 将文本居中显示
    m_leCount->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_leName->setAlignment(Qt::AlignCenter); // 将文本居中显示
    m_leName->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_leCount->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 10px; padding: 2px; }");
    m_lePasswd->setAlignment(Qt::AlignCenter); // 将文本居中显示
    m_lePasswd->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_lePasswd->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 10px; padding: 2px; }");

    m_ckPro->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_pbRegister->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_pbRegister->setStyleSheet("QPushButton { border: 1px solid gray; border-radius: 10px; padding: 2px; }"
                           "QPushButton:pressed { background-color: lightgray; }");

    // 设置窗口大小
#ifdef Q_OS_WIN
    m_lab->setMaximumSize(m_width-20,50);
    m_lab->setMinimumSize(m_width-20,30);
    m_leName->setMaximumSize(m_width-20,50);
    m_leName->setMinimumSize(m_width-20,30);
    m_leCount->setMaximumSize(m_width-20,50);
    m_leCount->setMinimumSize(m_width-20,30);
    m_lePasswd->setMaximumSize(m_width-20,50);
    m_lePasswd->setMinimumSize(m_width-20,30);
    m_ckPro->setMaximumSize(m_width-20,50);
    m_ckPro->setMinimumSize(m_width-20,30);
    m_pbRegister->setMaximumSize(m_width-20,50);
    m_pbRegister->setMinimumSize(m_width-20,30);
#endif
#ifdef  Q_OS_ANDROID
    m_lab->setMaximumSize(m_width-20,200);
    m_lab->setMinimumSize(m_width-20,280);
    m_leName->setMaximumSize(m_width-20,80);
    m_leName->setMinimumSize(m_width-20,50);
    m_leCount->setMaximumSize(m_width-20,80);
    m_leCount->setMinimumSize(m_width-20,50);
    m_lePasswd->setMaximumSize(m_width-20,80);
    m_lePasswd->setMinimumSize(m_width-20,50);
    m_ckPro->setMaximumSize(m_width-20,80);
    m_ckPro->setMinimumSize(m_width-20,50);
    m_pbRegister->setMaximumSize(m_width-20,80);
    m_pbRegister->setMinimumSize(m_width-20,50);

#endif
    m_sp = new QSpacerItem(m_width/8, m_width/8, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_layout->addWidget(m_lab);
    m_layout->addWidget(m_leName);
    m_layout->addWidget(m_leCount);
    m_layout->addWidget(m_lePasswd);
    m_layout->addWidget(m_ckPro);
    m_layout->addWidget(m_pbRegister);
    m_layout->setAlignment(Qt::AlignCenter|Qt::AlignTop);
    this->setLayout(m_layout);
}

Regiser::~Regiser()
{
    if(m_lab)
    {
        delete m_lab;
        m_lab=nullptr;
    }
    if(m_leName)
    {
        delete m_leName;
        m_leName=nullptr;
    }
    if(m_leCount)
    {
        delete m_leCount;
        m_leCount=nullptr;
    }
    if(m_lePasswd)
    {
        delete m_lePasswd;
        m_lePasswd=nullptr;
    }
    if(m_ckPro)
    {
        delete m_ckPro;
        m_ckPro=nullptr;
    }
    if(m_pbRegister)
    {
        delete m_pbRegister;
        m_pbRegister=nullptr;
    }
    delete ui;
}

void Regiser::slot_pbRegister()
{
    qDebug()<<__func__;
    QString name = this->m_leName->text();
    QString count = this->m_leCount->text();
    QString passwd = this->m_lePasswd->text();
    QString tmp=name;
    bool is_ck = this->m_ckPro->isChecked();
    if(!is_ck)
    {
        QMessageBox::about(this,"提示","请同意协议");
        return;
    }
    if(tmp.remove(" ").isEmpty()||name.isEmpty())
    {
        QMessageBox::about(this,"提示","昵称不能为空");
        return;
    }
    tmp=count;
    if(tmp.remove(" ").isEmpty()||count.isEmpty())
    {
        QMessageBox::about(this,"提示","账号不能为空");
        return;
    }
    tmp=passwd;
    if(tmp.remove(" ").isEmpty()||passwd.isEmpty())
    {
        QMessageBox::about(this,"提示","密码不能为空");
        return;
    }
    if(name.size()>20)
    {
        QMessageBox::about(this,"提示","昵称过长");
        return;
    }
    if(count.size()>13||count.size()<6)
    {
        QMessageBox::about(this,"提示","账号长度为(6~13位)");
        return;
    }
    if(passwd.size()>13||passwd.size()<6)
    {
        QMessageBox::about(this,"提示","密码长度为(6~13位)");
        return;
    }
    QRegularExpression regex("[^a-zA-Z0-9.]");  // 匹配非大小写字母和句点（.）
    QRegularExpressionMatchIterator matchIterator = regex.globalMatch(passwd);
    if(matchIterator.hasNext())
    {
        QMessageBox::about(this,"提示","密码必须由大小写字母数字和.组成");
        return;
    }
    Q_EMIT SIG_RegisterConfirm(name,count,passwd);

}
