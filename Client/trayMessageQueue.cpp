#include "trayMessageQueue.h"
#include <QDebug>
#include <QMessageBox>

TrayMessageQueue::TrayMessageQueue(QSystemTrayIcon* tray, int defaultDelay)
    : trayIcon(tray), defaultDelay(defaultDelay)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TrayMessageQueue::showNextMessage);
}

TrayMessageQueue::~TrayMessageQueue()
{
    // Добавлен пустой деструктор, чтобы избежать ошибки линковки
}

void TrayMessageQueue::addMessage(QString title, QString text, QSystemTrayIcon::MessageIcon icon, int delay)
{
    delay = (delay == 0) ? defaultDelay : delay;
    queue.enqueue(Message(title, text, icon, delay));

    if (!timer->isActive()) {
        showNextMessage(); // Запускаем показ сообщений
    }
}

void TrayMessageQueue::showNextMessage()
{
    if (queue.isEmpty()) {
        return;
    }

    Message msg = queue.dequeue();

    if (trayAvailable()) {
        trayIcon->showMessage(msg.title, msg.text, msg.icon, msg.delay);
    } else {
        // fallback: popup окно
        QMessageBox::information(nullptr, msg.title, msg.text);
    }

    // запускаем таймер только если есть ещё сообщения
    if (!queue.isEmpty()) {
        timer->start(msg.delay + 500); // небольшой буфер между сообщениями
    }
}

bool TrayMessageQueue::trayAvailable() const
{
    return QSystemTrayIcon::isSystemTrayAvailable() && trayIcon->isVisible();
}
