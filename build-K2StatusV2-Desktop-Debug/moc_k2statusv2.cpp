/****************************************************************************
** Meta object code from reading C++ file 'k2statusv2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/k2statusv2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'k2statusv2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_K2StatusV2_t {
    QByteArrayData data[16];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_K2StatusV2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_K2StatusV2_t qt_meta_stringdata_K2StatusV2 = {
    {
QT_MOC_LITERAL(0, 0, 10), // "K2StatusV2"
QT_MOC_LITERAL(1, 11, 9), // "sendDebug"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "sendStation"
QT_MOC_LITERAL(4, 34, 17), // "showStatusMessage"
QT_MOC_LITERAL(5, 52, 7), // "message"
QT_MOC_LITERAL(6, 60, 20), // "appendToDebugBrowser"
QT_MOC_LITERAL(7, 81, 11), // "resizeTable"
QT_MOC_LITERAL(8, 93, 11), // "DebugToggle"
QT_MOC_LITERAL(9, 105, 10), // "addStation"
QT_MOC_LITERAL(10, 116, 10), // "connectUDP"
QT_MOC_LITERAL(11, 127, 13), // "disconnectUDP"
QT_MOC_LITERAL(12, 141, 7), // "nothing"
QT_MOC_LITERAL(13, 149, 9), // "onClicked"
QT_MOC_LITERAL(14, 159, 4), // "volt"
QT_MOC_LITERAL(15, 164, 4) // "temp"

    },
    "K2StatusV2\0sendDebug\0\0sendStation\0"
    "showStatusMessage\0message\0"
    "appendToDebugBrowser\0resizeTable\0"
    "DebugToggle\0addStation\0connectUDP\0"
    "disconnectUDP\0nothing\0onClicked\0volt\0"
    "temp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_K2StatusV2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   85,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    1,   97,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void K2StatusV2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        K2StatusV2 *_t = static_cast<K2StatusV2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDebug((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sendStation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->showStatusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->appendToDebugBrowser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->resizeTable(); break;
        case 5: _t->DebugToggle(); break;
        case 6: _t->addStation(); break;
        case 7: _t->connectUDP(); break;
        case 8: _t->disconnectUDP(); break;
        case 9: _t->nothing(); break;
        case 10: _t->onClicked((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 11: _t->volt(); break;
        case 12: _t->temp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (K2StatusV2::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&K2StatusV2::sendDebug)) {
                *result = 0;
            }
        }
        {
            typedef void (K2StatusV2::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&K2StatusV2::sendStation)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject K2StatusV2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_K2StatusV2.data,
      qt_meta_data_K2StatusV2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *K2StatusV2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *K2StatusV2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_K2StatusV2.stringdata0))
        return static_cast<void*>(const_cast< K2StatusV2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int K2StatusV2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void K2StatusV2::sendDebug(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void K2StatusV2::sendStation(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
