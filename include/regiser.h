#ifndef REGISER_H
#define REGISER_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QCloseEvent>
namespace Ui {
class Regiser;
}

class Regiser : public QWidget
{
    Q_OBJECT

public:
    explicit Regiser(QWidget *parent = nullptr,int x=400,int y=200);
    ~Regiser();
public:
    QLineEdit * m_leName;
    QLineEdit * m_leCount;
    QLineEdit * m_lePasswd;
private:
    Ui::Regiser *ui;
    QLabel *m_lab;
    QCheckBox *m_ckPro;
    QPushButton * m_pbRegister;
    QVBoxLayout *m_layout;
    QSpacerItem *m_sp;
    int m_width;
    int m_height;
    void closeEvent(QCloseEvent *event) override
    {
        Q_EMIT  SIG_RegisterHide();
        event->ignore();
    }
private slots:
    void slot_pbRegister();
signals:
    void SIG_RegisterConfirm(QString ,QString ,QString);
    void SIG_RegisterHide();
};

#endif // REGISER_H
