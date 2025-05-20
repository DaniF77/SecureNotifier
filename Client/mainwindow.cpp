#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QTextEdit>
#include <QScreen>
#include <QDebug>
#include <QUdpSocket>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Загружаем плагины (если нужно)
    QCoreApplication::addLibraryPath("/usr/lib/x86_64-linux-gnu/qt5/plugins");

    // Создаём UDP сокет
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4, 12345, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::readMessage);

    // Указатель на QTextEdit из UI
    messageDisplay = ui->messageDisplay;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readMessage()
{
    QByteArray data;
    data.resize(udpSocket->pendingDatagramSize());
    udpSocket->readDatagram(data.data(), data.size());

    QString message = QString::fromUtf8(data);

    // Показываем всплывающее уведомление
    showPopup(message);

    // Добавляем в поле
    messageDisplay->append(message);

    qDebug() << "Message received: " << message;
}

void MainWindow::showPopup(const QString &message)
{
    // Создаем QLabel для отображения сообщения
    QLabel *popup = new QLabel(message, this);

    // Применяем стиль: пожирненный шрифт, увеличенный размер, фоновый цвет и цвет текста
    popup->setStyleSheet("QLabel { "
                         "background-color: #333; "
                         "color: white; "
                         "padding: 12px; "
                         "border-radius: 10px; "
                         "font-weight: bold; "
                         "font-size: 16px; "
                         "}");
    popup->setWindowFlags(Qt::ToolTip); // Для отображения как ToolTip
    popup->adjustSize();

    // Получаем главный экран
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    // Позиционируем в правом нижнем углу
    int x = screenGeometry.width() - popup->width();  // Справа
    int y = screenGeometry.height() - popup->height(); // Снизу

    // Небольшой отступ
    int offsetX = 20;
    int offsetY = 20;

    popup->move(screenGeometry.topLeft() + QPoint(x - offsetX, y - offsetY));
    popup->show();

    // Убираем через 2 секунды
    QTimer::singleShot(2000, popup, &QWidget::deleteLater);
}
