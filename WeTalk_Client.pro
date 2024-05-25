QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT += network
SOURCES += \
    chatcontent.cpp \
    chatdialog.cpp \
    inetmediator.cpp \
    inettcp.cpp \
    inettcpmediator.cpp \
    kernel.cpp \
    main.cpp \
    mainwindow.cpp \
    regiser.cpp \
    useritem.cpp \
    userplatfrom.cpp

HEADERS += \
    chatcontent.h \
    chatdialog.h \
    config.h \
    inet.h \
    inetmediator.h \
    inettcp.h \
    inettcpmediator.h \
    kernel.h \
    mainwindow.h \
    regiser.h \
    useritem.h \
    userplatfrom.h

FORMS += \
    chatcontent.ui \
    chatdialog.ui \
    mainwindow.ui \
    regiser.ui \
    useritem.ui \
    userplatfrom.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}
