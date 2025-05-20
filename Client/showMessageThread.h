#ifndef SHOWMESSAGETHREAD_H
#define SHOWMESSAGETHREAD_H

#include <QThread>
#include <QSystemTrayIcon>
#include <queue>

#include "message.h"

class ShowMessageThread : public QThread
{
    Q_OBJECT

public:
    ShowMessageThread(std::queue<Message>* messageQueue)
        : messageQueue(messageQueue) {}

signals:
    void showMessageInMainThread(QString title, QString text, QSystemTrayIcon::MessageIcon icon, int delay);
    void clearTrayMessage();

protected:
    void run() override {
        while (true) {
            if (!messageQueue->empty()) {
                Message message = messageQueue->front();
                messageQueue->pop();

                emit showMessageInMainThread(message.title, message.text, message.icon, static_cast<int>(message.delay));
                msleep(message.delay);

                if (messageQueue->empty()) {
                    emit clearTrayMessage();
                }
            } else {
                msleep(100);  // не грузим CPU
            }
        }
    }

private:
    std::queue<Message>* messageQueue;
};

#endif // SHOWMESSAGETHREAD_H
