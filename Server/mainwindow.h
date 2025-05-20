#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sendMessage();  // Только отправка

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    QSqlDatabase db;
    void logEvent(const QString &message);
};

#endif // MAINWINDOW_H
