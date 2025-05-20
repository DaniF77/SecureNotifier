QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# Подключение драйвера для PostgreSQL (если используешь)
# Для работы с PostgreSQL нужно будет также убедиться, что у тебя установлен драйвер QPSQL.
# Если нужно, добавь его в проект:
# DEFINES += QT_USE_QPSQL

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
