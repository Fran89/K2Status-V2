/****************************************************************************
** Meta object code from reading C++ file 'ewmessagemgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ewmessagemgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ewmessagemgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EWMessageMgr_t {
    QByteArrayData data[10];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EWMessageMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EWMessageMgr_t qt_meta_stringdata_EWMessageMgr = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EWMessageMgr"
QT_MOC_LITERAL(1, 13, 14), // "exportK2Status"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "K2INFO_HEADER*"
QT_MOC_LITERAL(4, 44, 12), // "STATUS_INFO*"
QT_MOC_LITERAL(5, 57, 7), // "QMutex*"
QT_MOC_LITERAL(6, 65, 15), // "exportK2Status2"
QT_MOC_LITERAL(7, 81, 17), // "EXT2_STATUS_INFO*"
QT_MOC_LITERAL(8, 99, 15), // "exportK2HeaderS"
QT_MOC_LITERAL(9, 115, 10) // "K2_HEADER*"

    },
    "EWMessageMgr\0exportK2Status\0\0"
    "K2INFO_HEADER*\0STATUS_INFO*\0QMutex*\0"
    "exportK2Status2\0EXT2_STATUS_INFO*\0"
    "exportK2HeaderS\0K2_HEADER*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EWMessageMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       6,    3,   36,    2, 0x06 /* Public */,
       8,    3,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 5,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 7, 0x80000000 | 5,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9, 0x80000000 | 5,    2,    2,    2,

       0        // eod
};

void EWMessageMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EWMessageMgr *_t = static_cast<EWMessageMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exportK2Status((*reinterpret_cast< K2INFO_HEADER*(*)>(_a[1])),(*reinterpret_cast< STATUS_INFO*(*)>(_a[2])),(*reinterpret_cast< QMutex*(*)>(_a[3]))); break;
        case 1: _t->exportK2Status2((*reinterpret_cast< K2INFO_HEADER*(*)>(_a[1])),(*reinterpret_cast< EXT2_STATUS_INFO*(*)>(_a[2])),(*reinterpret_cast< QMutex*(*)>(_a[3]))); break;
        case 2: _t->exportK2HeaderS((*reinterpret_cast< K2INFO_HEADER*(*)>(_a[1])),(*reinterpret_cast< K2_HEADER*(*)>(_a[2])),(*reinterpret_cast< QMutex*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EWMessageMgr::*_t)(K2INFO_HEADER * , STATUS_INFO * , QMutex * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EWMessageMgr::exportK2Status)) {
                *result = 0;
            }
        }
        {
            typedef void (EWMessageMgr::*_t)(K2INFO_HEADER * , EXT2_STATUS_INFO * , QMutex * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EWMessageMgr::exportK2Status2)) {
                *result = 1;
            }
        }
        {
            typedef void (EWMessageMgr::*_t)(K2INFO_HEADER * , K2_HEADER * , QMutex * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EWMessageMgr::exportK2HeaderS)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject EWMessageMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EWMessageMgr.data,
      qt_meta_data_EWMessageMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EWMessageMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EWMessageMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EWMessageMgr.stringdata0))
        return static_cast<void*>(const_cast< EWMessageMgr*>(this));
    return QObject::qt_metacast(_clname);
}

int EWMessageMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void EWMessageMgr::exportK2Status(K2INFO_HEADER * _t1, STATUS_INFO * _t2, QMutex * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EWMessageMgr::exportK2Status2(K2INFO_HEADER * _t1, EXT2_STATUS_INFO * _t2, QMutex * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EWMessageMgr::exportK2HeaderS(K2INFO_HEADER * _t1, K2_HEADER * _t2, QMutex * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
