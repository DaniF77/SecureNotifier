#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Вывод доступных драйверов
    qDebug() << "Доступные драйверы:" << QSqlDatabase::drivers();

    // Инициализация UDP сокета
    udpSocket = new QUdpSocket(this);

    // Подключение кнопки
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendMessage);

    // Настройка подключения к БД
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("secure_notifier_db");
    db.setUserName("postgres");
    db.setPassword("1");

    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка БД", "Не удалось подключиться к базе данных:\n" + db.lastError().text());
        qDebug() << "Ошибка подключения к БД:" << db.lastError().text();
    } else {
        qDebug() << "Подключено к БД:" << db.databaseName();

        // Проверка существования таблицы logs
        QSqlQuery checkTableQuery;
        if (!checkTableQuery.exec("SELECT EXISTS (SELECT FROM pg_tables WHERE tablename = 'logs')")) {
            qDebug() << "Ошибка проверки таблицы:" << checkTableQuery.lastError().text();
        } else if (checkTableQuery.next() && !checkTableQuery.value(0).toBool()) {
            qDebug() << "Таблица 'logs' не найдена. Создаю...";
            QSqlQuery createQuery;
            if (!createQuery.exec(
                    "CREATE TABLE logs ("
                    "id SERIAL PRIMARY KEY,"
                    "message TEXT NOT NULL,"
                    "timestamp TIMESTAMP NOT NULL DEFAULT NOW()"
                    ")"
                    )) {
                qDebug() << "Ошибка создания таблицы:" << createQuery.lastError().text();
            } else {
                qDebug() << "Таблица 'logs' успешно создана";
            }
        }

        // Простой проверочный запрос
        QSqlQuery checkQuery;
        if (!checkQuery.exec("SELECT 1")) {
            qDebug() << "Ошибка проверочного запроса:" << checkQuery.lastError().text();
        } else {
            qDebug() << "Проверочный запрос успешен";
        }
    }
}

void MainWindow::sendMessage()
{
    QString message = ui->messageLineEdit->text();
    if (message.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Сообщение не может быть пустым");
        return;
    }

    QByteArray data = message.toUtf8();
    qint64 sent = udpSocket->writeDatagram(data, QHostAddress::Broadcast, 12345);

    if (sent == -1) {
        QMessageBox::warning(this, "Ошибка", "Ошибка отправки: " + udpSocket->errorString());
    } else {
        logEvent(message);
        ui->messageLineEdit->clear();
        qDebug() << "Отправлено:" << message;
    }
}

void MainWindow::logEvent(const QString &message)
{
    QSqlQuery query;

    QString msgCopy = message;
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    // Экранируем апострофы
    msgCopy.replace("'", "''");

    // Формируем SQL-запрос
    QString queryString = QString("INSERT INTO logs (message, timestamp) VALUES ('%1', '%2')").arg(msgCopy, timestamp);

    if (!query.exec(queryString)) {
        QString errorText = query.lastError().text();
        qDebug() << "Ошибка SQL:" << queryString;
        qDebug() << "Ошибка БД:" << errorText;
        QMessageBox::warning(this, "Ошибка БД", "Ошибка записи в журнал:\n" + errorText);
    } else {
        qDebug() << "Запись добавлена в журнал";

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
