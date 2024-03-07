/****************************************************************************
** Meta object code from reading C++ file 'natsclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../natsclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'natsclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Nats__Subscription_t {
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Nats__Subscription_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Nats__Subscription_t qt_meta_stringdata_Nats__Subscription = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Nats::Subscription"
QT_MOC_LITERAL(1, 19, 8), // "received"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "Nats::Subscription\0received\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Nats__Subscription[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void Nats::Subscription::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Subscription *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->received(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Subscription::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Subscription::received)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Nats::Subscription::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Nats__Subscription.data,
    qt_meta_data_Nats__Subscription,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Nats::Subscription::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Nats::Subscription::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Nats__Subscription.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Nats::Subscription::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Nats::Subscription::received()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Nats__Client_t {
    QByteArrayData data[14];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Nats__Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Nats__Client_t qt_meta_stringdata_Nats__Client = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Nats::Client"
QT_MOC_LITERAL(1, 13, 9), // "connected"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "error"
QT_MOC_LITERAL(4, 30, 12), // "disconnected"
QT_MOC_LITERAL(5, 43, 7), // "connect"
QT_MOC_LITERAL(6, 51, 4), // "host"
QT_MOC_LITERAL(7, 56, 4), // "port"
QT_MOC_LITERAL(8, 61, 21), // "Nats::ConnectCallback"
QT_MOC_LITERAL(9, 83, 8), // "callback"
QT_MOC_LITERAL(10, 92, 13), // "Nats::Options"
QT_MOC_LITERAL(11, 106, 7), // "options"
QT_MOC_LITERAL(12, 114, 10), // "disconnect"
QT_MOC_LITERAL(13, 125, 11) // "connectSync"

    },
    "Nats::Client\0connected\0\0error\0"
    "disconnected\0connect\0host\0port\0"
    "Nats::ConnectCallback\0callback\0"
    "Nats::Options\0options\0disconnect\0"
    "connectSync"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Nats__Client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,
       4,    0,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   89,    2, 0x0a /* Public */,
       5,    2,   96,    2, 0x2a /* Public | MethodCloned */,
       5,    1,  101,    2, 0x2a /* Public | MethodCloned */,
       5,    0,  104,    2, 0x2a /* Public | MethodCloned */,
       5,    4,  105,    2, 0x0a /* Public */,
       5,    3,  114,    2, 0x2a /* Public | MethodCloned */,
      12,    0,  121,    2, 0x0a /* Public */,
      13,    2,  122,    2, 0x0a /* Public */,
      13,    1,  127,    2, 0x2a /* Public | MethodCloned */,
      13,    0,  130,    2, 0x2a /* Public | MethodCloned */,
      13,    3,  131,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, 0x80000000 | 8,    6,    7,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    6,    7,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, 0x80000000 | 10, 0x80000000 | 8,    6,    7,   11,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, 0x80000000 | 10,    6,    7,   11,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::UShort,    6,    7,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString, QMetaType::UShort, 0x80000000 | 10,    6,    7,   11,

       0        // eod
};

void Nats::Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->disconnected(); break;
        case 3: _t->connect((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< Nats::ConnectCallback(*)>(_a[3]))); break;
        case 4: _t->connect((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 5: _t->connect((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->connect(); break;
        case 7: _t->connect((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< const Nats::Options(*)>(_a[3])),(*reinterpret_cast< Nats::ConnectCallback(*)>(_a[4]))); break;
        case 8: _t->connect((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< const Nats::Options(*)>(_a[3]))); break;
        case 9: _t->disconnect(); break;
        case 10: { bool _r = _t->connectSync((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->connectSync((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->connectSync();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->connectSync((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< const Nats::Options(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::error)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::disconnected)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Nats::Client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Nats__Client.data,
    qt_meta_data_Nats__Client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Nats::Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Nats::Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Nats__Client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Nats::Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Nats::Client::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Nats::Client::error(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Nats::Client::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
