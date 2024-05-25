#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QScreen>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("WeTalk");
    m_layout = new QVBoxLayout();
    m_lab = new QLabel("登录");
    m_leCount = new QLineEdit();
    m_leCount->setPlaceholderText(("输入WeTalk账号"));
    m_lePasswd = new QLineEdit();
    m_lePasswd->setPlaceholderText(("输入WeTalk密码"));
    m_ckPro = new QCheckBox("已阅读并同意服务协议和WeTalk隐私保护指引");
    m_pbLog = new QPushButton("登录");
    connect(m_pbLog,SIGNAL(clicked()),this,SLOT(slot_pblogClicked()));

    m_layouts =new QHBoxLayout();
    m_pbPhone = new QPushButton("手机号登录");
    m_pbOther = new QPushButton("其他方式登录");
    m_pbRegister = new QPushButton("注册");
    connect(m_pbRegister,SIGNAL(clicked()),this,SLOT(slot_pbRegClicked()));
    m_pbMore = new QPushButton("更多");


    m_lab->setAlignment(Qt::AlignCenter);
    m_lab->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_leCount->setAlignment(Qt::AlignCenter); // 将文本居中显示
    m_leCount->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_leCount->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 10px; padding: 2px; }");
    m_lePasswd->setAlignment(Qt::AlignCenter); // 将文本居中显示
    m_lePasswd->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_lePasswd->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 10px; padding: 2px; }");

    m_ckPro->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_pbLog->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_pbLog->setStyleSheet("QPushButton { border: 1px solid gray; border-radius: 10px; padding: 2px; }"
                           "QPushButton:pressed { background-color: lightgray; }");

    m_pbPhone->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_pbPhone->setStyleSheet("QPushButton { border: 2px solid gray; border-radius: 20px; padding: 4px; background-color: lightblue; }"
                             "QPushButton:pressed { background-color: lightgray; }");
    m_pbOther->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_pbOther->setStyleSheet("QPushButton { border: 2px solid gray; border-radius: 20px; padding: 4px; background-color: lightblue; }"
                             "QPushButton:pressed { background-color: lightgray; }");
    m_pbRegister->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_pbRegister->setStyleSheet("QPushButton { border: 2px solid gray; border-radius: 20px; padding: 4px; background-color: lightblue; }"
                                "QPushButton:pressed { background-color: lightgray; }");
    m_pbMore->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    m_pbMore->setStyleSheet("QPushButton { border: 2px solid gray; border-radius: 20px; padding: 4px; background-color: lightblue; }"
                            "QPushButton:pressed { background-color: lightgray; }");

    QGuiApplication *guiApp = static_cast<QGuiApplication *>(QApplication::instance());
    QList lst = guiApp->screens();
    QSize screenSize=QSize();
    for(auto s:lst)
    {
        if (s->size().width() > screenSize.width() && s->size().height() > screenSize.height())
        {
            screenSize = s->size();
            break;
        }
    }

    // 设置窗口大小
#ifdef Q_OS_WIN
    setMinimumSize(screenSize/4);
    setMaximumSize(screenSize/4);
    resize(screenSize);
    m_width = screenSize.width()/4;
    m_height = screenSize.height()/4;
    m_lab->setMaximumSize(m_width-20,50);
    m_lab->setMinimumSize(m_width-20,30);
    m_leCount->setMaximumSize(m_width-20,50);
    m_leCount->setMinimumSize(m_width-20,30);
    m_lePasswd->setMaximumSize(m_width-20,50);
    m_lePasswd->setMinimumSize(m_width-20,30);
    m_ckPro->setMaximumSize(m_width-20,50);
    m_ckPro->setMinimumSize(m_width-20,30);
    m_pbLog->setMaximumSize(m_width-20,50);
    m_pbLog->setMinimumSize(m_width-20,30);

    m_pbPhone->setMaximumSize(m_width/8,m_width/8);
    m_pbPhone->setMinimumSize(m_width/8,m_width/8);
    m_pbOther->setMaximumSize(m_width/8,m_width/8);
    m_pbOther->setMinimumSize(m_width/8,m_width/8);
    m_pbRegister->setMaximumSize(m_width/8,m_width/8);
    m_pbRegister->setMinimumSize(m_width/8,m_width/8);
    m_pbMore->setMaximumSize(m_width/8,m_width/8);
    m_pbMore->setMinimumSize(m_width/8,m_width/8);
#endif
    qDebug()<<screenSize;
#ifdef  Q_OS_ANDROID
    setMinimumSize(screenSize);
    setMaximumSize(screenSize);
    resize(screenSize);
    m_width = screenSize.width();
    m_height = screenSize.height();
    m_lab->setMaximumSize(m_width-20,200);
    m_lab->setMinimumSize(m_width-20,280);
    m_leCount->setMaximumSize(m_width-20,80);
    m_leCount->setMinimumSize(m_width-20,50);
    m_lePasswd->setMaximumSize(m_width-20,80);
    m_lePasswd->setMinimumSize(m_width-20,50);
    m_ckPro->setMaximumSize(m_width-20,80);
    m_ckPro->setMinimumSize(m_width-20,50);
    m_pbLog->setMaximumSize(m_width-20,80);
    m_pbLog->setMinimumSize(m_width-20,50);

    m_pbPhone->setMaximumSize(m_width/8,m_width/8);
    m_pbPhone->setMinimumSize(m_width/8,m_width/8);
    m_pbOther->setMaximumSize(m_width/8,m_width/8);
    m_pbOther->setMinimumSize(m_width/8,m_width/8);
    m_pbRegister->setMaximumSize(m_width/8,m_width/8);
    m_pbRegister->setMinimumSize(m_width/8,m_width/8);
    m_pbMore->setMaximumSize(m_width/8,m_width/8);
    m_pbMore->setMinimumSize(m_width/8,m_width/8);
#endif

    m_sp = new QSpacerItem(m_width/8, m_width/8, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_layout->addWidget(m_lab);
    m_layout->addWidget(m_leCount);
    m_layout->addWidget(m_lePasswd);
    m_layout->addWidget(m_ckPro);
    m_layout->addWidget(m_pbLog);
    m_layout->setAlignment(Qt::AlignCenter|Qt::AlignTop);

    m_layouts->addWidget(m_pbPhone);
    m_layouts->addItem(m_sp);
    m_layouts->addWidget(m_pbOther);
    m_layouts->addItem(m_sp);
    m_layouts->addWidget(m_pbRegister);
    m_layouts->addItem(m_sp);
    m_layouts->addWidget(m_pbMore);
    m_layouts->setAlignment(Qt::AlignCenter|Qt::AlignBottom);
    m_layout->addItem(m_sp);
    m_layout->addLayout(m_layouts);
    centralWidget()->setLayout(m_layout);

}

MainWindow::~MainWindow()
{
    if(m_lab)
    {
        delete m_lab;
        m_lab = nullptr;
    }
    if(m_leCount)
    {
        delete m_leCount;
        m_leCount = nullptr;
    }
    if(m_lePasswd)
    {
        delete m_lePasswd;
        m_lePasswd = nullptr;
    }
    if(m_layout)
    {
        delete m_layout;
        m_layout = nullptr;
    }
    if(m_layouts)
    {
        delete m_layouts;
        m_layouts = nullptr;
    }
    if(m_pbMore)
    {
        delete m_pbMore;
        m_pbMore = nullptr;
    }
    if(m_pbOther)
    {
        delete m_pbOther;
        m_pbOther = nullptr;
    }
    if(m_pbPhone)
    {
        delete m_pbPhone;
        m_pbPhone = nullptr;
    }
    if(m_pbRegister)
    {
        delete m_pbRegister;
        m_pbRegister = nullptr;
    }
    if(m_sp)
    {
        delete m_sp;
        m_sp = nullptr;
    }
    delete ui;
}

void MainWindow::slot_pblogClicked()
{
    //qDebug()<<__func__;
    bool is_ck = m_ckPro->isChecked();
    QString count = m_leCount->text();
    QString passwd = m_lePasswd->text();
    QString tmp=count;
    if(!is_ck)
    {
        QMessageBox::about(this,"提示","请同意协议");
        return;
    }
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
    Q_EMIT SIG_login(count,passwd);
}

void MainWindow::slot_pbRegClicked()
{
    qDebug()<<__func__;
    Q_EMIT SIG_register();
}


