#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QSpacerItem>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class Kernel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int m_width;//获取屏幕宽高
    int m_height;
public:
    QLineEdit * m_leCount;
    QLineEdit * m_lePasswd;
private:
    Ui::MainWindow *ui;


    //登录界面
    QLabel *m_lab;
    QCheckBox *m_ckPro;
    QPushButton * m_pbLog;
    QVBoxLayout *m_layout;

    QSpacerItem *m_sp;
    //其他选项
    QPushButton * m_pbPhone;
    QPushButton * m_pbOther;
    QPushButton * m_pbRegister;
    QPushButton * m_pbMore;
    QHBoxLayout *m_layouts;
private slots:
    void slot_pblogClicked();
    void slot_pbRegClicked();
signals:
    void SIG_login(QString,QString);
    void SIG_register();
};
#endif // MAINWINDOW_H
