#ifndef TRAYMESSAGEQUEUE_H
#define TRAYMESSAGEQUEUE_H

#include <QSystemTrayIcon>
#include <QQueue>
#include <QTimer>

struct Message {
    QString title;
    QString text;
    QSystemTrayIcon::MessageIcon icon;
    int delay;

    Message(QString t, QString txt, QSystemTrayIcon::MessageIcon i, int d)
        : title(t), text(txt), icon(i), delay(d) {}
};

class TrayMessageQueue : public QObject {
    Q_OBJECT

public:
    TrayMessageQueue(QSystemTrayIcon* tray, int defaultDelay = 3000);
    void addMessage(QString title, QString text, QSystemTrayIcon::MessageIcon icon, int delay = 0);
     ~TrayMessageQueue();

private slots:
    void showNextMessage();

private:
    QSystemTrayIcon* trayIcon;
    QQueue<Message> queue;
    QTimer* timer;
    int defaultDelay;
    bool trayAvailable() const;
};

#endif // TRAYMESSAGEQUEUE_H
