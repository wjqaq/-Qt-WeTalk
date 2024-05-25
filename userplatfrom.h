#ifndef USERPLATFROM_H
#define USERPLATFROM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QDebug>
#include <QMenu>
#include <QCloseEvent>
#include "useritem.h"
namespace Ui {
class UserPlatfrom;
}

class UserPlatfrom : public QWidget
{
    Q_OBJECT

public:
    void closeEvent(QCloseEvent *event) override
    {
        Q_EMIT  SIG_CloseWindow();
        event->ignore();
    }
    explicit UserPlatfrom(QWidget *parent = nullptr,int x=400,int y=200);
    ~UserPlatfrom();
    void addUserItem(UserItem*,QString,QString);
    void updateUserItem(UserItem*,QString,QString);

private:
    Ui::UserPlatfrom *ui;
    int m_width;
    int m_height;
    int m_h;
    QLabel* m_lab;
    QLabel* m_msg;
    QVBoxLayout* m_layout;
    QVBoxLayout* m_layouts;
    QHBoxLayout* m_layout_h1;
    QHBoxLayout* m_layout_h2;
    QScrollArea* m_scare;
    QPushButton* m_pbAdd;
    QPushButton* m_pbSerch;
    QPushButton* m_pbWeTalk;
    QPushButton* m_pbBook;
    QPushButton* m_pbLook;
    QPushButton* m_pbMe;
    QSpacerItem *m_sp;
    QWidget* m_widget;
    UserItem* m_item;
    QMenu* m_meu;
private slots:
    void slot_m_pbAddClicked();
    void slot_clickMenu(QAction *action);
signals:
    void SIG_addFriend();
    void SIG_CloseWindow();
};

#endif // USERPLATFROM_H
