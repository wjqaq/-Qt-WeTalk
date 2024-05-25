#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QTextEdit>
#include <QTextBrowser>
#include <QTime>
#include <QScrollArea>
#include <QListWidget>
#include <QCloseEvent>
#include <QResizeEvent>
#include "chatcontent.h"
namespace Ui {
class ChatDialog;
}

class ChatDialog : public QWidget
{
    Q_OBJECT

public:
    void closeEvent(QCloseEvent *event) override
    {
        Q_EMIT  SIG_ChatDialogHide(m_id);
        event->ignore();
    }
    void resizeEvent(QResizeEvent *event) override
    {
        setMinimumSize(0, 0);
        setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
        m_width = width();
        m_height = height();
    }
    int m_id;
    QString m_name;
    bool is_left;
    explicit ChatDialog(QWidget *parent = nullptr,int x=400,int y=200);
    ~ChatDialog();
    void setTitle(QString);
    //把聊天内容显示在窗口上
    void setContent(QString content,QString name,int id,bool type);

private:
    Ui::ChatDialog *ui;
    QLabel *m_lab;//聊天框名称
    QPushButton *m_pbBack;//回退
    QPushButton *m_pbChatInfo;//聊天信息
    QPushButton *m_pbChatBtoVoice;//聊天转语音选项|语音转聊天选项
    QTextEdit   *m_teChatBtoVoice;//聊天或者语音输入
    QTextBrowser*m_tbChat;//显示聊天内容
    QListWidget *m_lwChat;//显示聊天内容
    QScrollArea *m_scChat;//显示聊天内容
    QWidget     *m_wgChat;//显示聊天内容
    QVBoxLayout *m_lyShow;//显示聊天内容
    QVBoxLayout *m_lyShowall;//显示聊天内容
    QSpacerItem *m_sp;
    QPushButton *m_pbEmoji;//表情
    QPushButton *m_pbMore;//更多
    QPushButton *m_pbPic;//相册
    QPushButton *m_pbImg;//拍摄
    QPushButton *m_pbLocal;//位置
    QPushButton *m_pbSound;//语音输入
    QPushButton *m_pbCol;//我的搜藏
    QPushButton *m_pbida;//我的名片
    QPushButton *m_pbFile;//文件
    QPushButton *m_pbMusic;//音乐

    QHBoxLayout* m_lytitle;//上面
    QHBoxLayout* m_lyChat;//下面
    QVBoxLayout* m_lyAll;//整体
    //QScrollArea* m_scChat;//聊天内容
    int m_width;
    int m_height;
    bool isShow;
signals:
    void SIG_ChatDialogHide(int);
private slots:
    void slot_TeHasChanged();
    void slot_pbAddClicked();

signals:
    void SIG_sendMsg(int,QString);

};

#endif // CHATDIALOG_H
