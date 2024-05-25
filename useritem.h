#ifndef USERITEM_H
#define USERITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMouseEvent>
namespace Ui {
class UserItem;
}

class UserItem : public QWidget
{
    Q_OBJECT

public:
    int m_id;
    QString m_names;
    explicit UserItem(QWidget *parent = nullptr,int x = 200,int y = 40);
    ~UserItem();
    void addUserItem(QString,QString);
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            // 处理鼠标左键按下事件
            Q_EMIT SIG_Chat(m_id);
        }
        QWidget::mousePressEvent(event);
    }
    QString name() const;

private:
    Ui::UserItem *ui;
    int m_width;
    int m_height;
    QPushButton * m_pbIcon;
    QLabel *m_name;
    QLabel *m_content;
    QVBoxLayout *m_layout;
    QHBoxLayout *m_layout_h;
signals:
    void SIG_Chat(int);
};

#endif // USERITEM_H
