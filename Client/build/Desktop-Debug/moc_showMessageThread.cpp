/****************************************************************************
** Meta object code from reading C++ file 'showMessageThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../showMessageThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showMessageThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShowMessageThread_t {
    QByteArrayData data[9];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowMessageThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowMessageThread_t qt_meta_stringdata_ShowMessageThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ShowMessageThread"
QT_MOC_LITERAL(1, 18, 23), // "showMessageInMainThread"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 5), // "title"
QT_MOC_LITERAL(4, 49, 4), // "text"
QT_MOC_LITERAL(5, 54, 28), // "QSystemTrayIcon::MessageIcon"
QT_MOC_LITERAL(6, 83, 4), // "icon"
QT_MOC_LITERAL(7, 88, 5), // "delay"
QT_MOC_LITERAL(8, 94, 16) // "clearTrayMessage"

    },
    "ShowMessageThread\0showMessageInMainThread\0"
    "\0title\0text\0QSystemTrayIcon::MessageIcon\0"
    "icon\0delay\0clearTrayMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowMessageThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,
       8,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 5, QMetaType::Int,    3,    4,    6,    7,
    QMetaType::Void,

       0        // eod
};

void ShowMessageThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShowMessageThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showMessageInMainThread((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QSystemTrayIcon::MessageIcon(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->clearTrayMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShowMessageThread::*)(QString , QString , QSystemTrayIcon::MessageIcon , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShowMessageThread::showMessageInMainThread)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ShowMessageThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShowMessageThread::clearTrayMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ShowMessageThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_ShowMessageThread.data,
    qt_meta_data_ShowMessageThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ShowMessageThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowMessageThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShowMessageThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ShowMessageThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ShowMessageThread::showMessageInMainThread(QString _t1, QString _t2, QSystemTrayIcon::MessageIcon _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ShowMessageThread::clearTrayMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
