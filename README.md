# SecureNotifier

## Описание (Русский)

**SecureNotifier** — это кроссплатформенное клиент-серверное приложение для отправки и получения тревожных сообщений в локальной сети.

- **Сервер** позволяет отправлять тревожные сообщения по UDP всем клиентам в сети и сохраняет каждое сообщение в базе данных PostgreSQL для ведения журнала.
- **Клиент** принимает сообщения от сервера, отображает их в виде всплывающих уведомлений (popup) и выводит в основном окне программы.

### Особенности

- Кроссплатформенность: работает на Windows и Linux.
- Использует Qt (C++) для интерфейса и сетевого взаимодействия.
- Сервер логирует все сообщения в PostgreSQL.
- Простая настройка и запуск.

### Запуск

1. Установите Qt 5.x и PostgreSQL.
2. Соберите проект с помощью Qt Creator или qmake/Makefile.
3. Настройте параметры подключения к базе данных в сервере (файл [`mainwindow.cpp`](mainwindow.cpp)).
4. Запустите сервер и клиент на нужных машинах в одной локальной сети.

---

## Description (English)

**SecureNotifier** is a cross-platform client-server application for sending and receiving alert messages over a local network.

- The **server** can send alert messages via UDP to all clients in the network and logs each message to a PostgreSQL database.
- The **client** receives messages from the server, displays them as popup notifications, and shows them in the main window.

### Features

- Cross-platform: works on Windows and Linux.
- Uses Qt (C++) for UI and networking.
- Server logs all messages to PostgreSQL.
- Easy setup and usage.

### Getting Started

1. Install Qt 5.x and PostgreSQL.
2. Build the project using Qt Creator or qmake/Makefile.
3. Configure database connection parameters in the server ([`mainwindow.cpp`](mainwindow.cpp)).
4. Run the server and client on the desired machines within the same local network.
