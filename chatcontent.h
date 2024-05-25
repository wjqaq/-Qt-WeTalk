#ifndef CHATCONTENT_H
#define CHATCONTENT_H

#include <QWidget>
#include <QTextBrowser>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
namespace Ui {
class ChatContent;
}

class ChatContent : public QWidget
{
    Q_OBJECT

public:
    explicit ChatContent(QWidget *parent = nullptr,int x=400,int y=200);
    ~ChatContent();
    void setContent(QString, QString, QString, int type);
private:
    Ui::ChatContent *ui;
    QLabel * m_labContent;
    QPushButton * m_pbHead;
    QLabel * m_labName;
    QVBoxLayout *m_lyContent;
    QVBoxLayout *m_ly;
    QVBoxLayout *m_lyAll;
    QHBoxLayout *m_lyHead;
    QSpacerItem *m_sp;
    int m_width;
    int m_height;
};

#endif // CHATCONTENT_H
