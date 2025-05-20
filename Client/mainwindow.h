#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QDateTime>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QTextEdit>
#include "trayMessageQueue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showPopup(const QString &message);

private slots:
    void readMessage();  // Слот для чтения сообщений

private:
    Ui::MainWindow *ui;

    QUdpSocket *udpSocket;
    QSqlDatabase db;
    QSystemTrayIcon *trayIcon;

    QTextEdit *messageDisplay;  // Виджет для отображения сообщений
    TrayMessageQueue *messageQueue;  // Очередь сообщений для отображения

};

#endif // MAINWINDOW_H
