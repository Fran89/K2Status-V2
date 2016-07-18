/****************************************************************************
** Meta object code from reading C++ file 'stninfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/stninfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stninfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StaInfo_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StaInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StaInfo_t qt_meta_stringdata_StaInfo = {
    {
QT_MOC_LITERAL(0, 0, 7) // "StaInfo"

    },
    "StaInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StaInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void StaInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject StaInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StaInfo.data,
      qt_meta_data_StaInfo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StaInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StaInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StaInfo.stringdata0))
        return static_cast<void*>(const_cast< StaInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int StaInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_StnInfo_t {
    QByteArrayData data[26];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StnInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StnInfo_t qt_meta_stringdata_StnInfo = {
    {
QT_MOC_LITERAL(0, 0, 7), // "StnInfo"
QT_MOC_LITERAL(1, 8, 15), // "stationsUpdated"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "stationAdded"
QT_MOC_LITERAL(4, 38, 7), // "QMutex*"
QT_MOC_LITERAL(5, 46, 13), // "stationLogEvt"
QT_MOC_LITERAL(6, 60, 13), // "stationXmlEvt"
QT_MOC_LITERAL(7, 74, 12), // "debugMessage"
QT_MOC_LITERAL(8, 87, 13), // "statusMessage"
QT_MOC_LITERAL(9, 101, 12), // "stationIndex"
QT_MOC_LITERAL(10, 114, 8), // "StaInfo*"
QT_MOC_LITERAL(11, 123, 14), // "K2INFO_HEADER*"
QT_MOC_LITERAL(12, 138, 6), // "header"
QT_MOC_LITERAL(13, 145, 11), // "QDomElement"
QT_MOC_LITERAL(14, 157, 7), // "station"
QT_MOC_LITERAL(15, 165, 7), // "network"
QT_MOC_LITERAL(16, 173, 15), // "recieveK2Status"
QT_MOC_LITERAL(17, 189, 12), // "STATUS_INFO*"
QT_MOC_LITERAL(18, 202, 6), // "status"
QT_MOC_LITERAL(19, 209, 5), // "mutex"
QT_MOC_LITERAL(20, 215, 16), // "recieveK2Status2"
QT_MOC_LITERAL(21, 232, 17), // "EXT2_STATUS_INFO*"
QT_MOC_LITERAL(22, 250, 7), // "status2"
QT_MOC_LITERAL(23, 258, 16), // "recieveK2HeaderS"
QT_MOC_LITERAL(24, 275, 10), // "K2_HEADER*"
QT_MOC_LITERAL(25, 286, 9) // "infheader"

    },
    "StnInfo\0stationsUpdated\0\0stationAdded\0"
    "QMutex*\0stationLogEvt\0stationXmlEvt\0"
    "debugMessage\0statusMessage\0stationIndex\0"
    "StaInfo*\0K2INFO_HEADER*\0header\0"
    "QDomElement\0station\0network\0recieveK2Status\0"
    "STATUS_INFO*\0status\0mutex\0recieveK2Status2\0"
    "EXT2_STATUS_INFO*\0status2\0recieveK2HeaderS\0"
    "K2_HEADER*\0infheader"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StnInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       5,    2,   78,    2, 0x06 /* Public */,
       6,    1,   83,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,
       8,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   92,    2, 0x0a /* Public */,
       9,    1,   95,    2, 0x0a /* Public */,
       9,    2,   98,    2, 0x0a /* Public */,
      16,    3,  103,    2, 0x0a /* Public */,
      20,    3,  110,    2, 0x0a /* Public */,
      23,    3,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    0x80000000 | 10, 0x80000000 | 11,   12,
    0x80000000 | 10, 0x80000000 | 13,   14,
    0x80000000 | 10, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 17, 0x80000000 | 4,   12,   18,   19,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 21, 0x80000000 | 4,   12,   22,   19,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 24, 0x80000000 | 4,   12,   25,   19,

       0        // eod
};

void StnInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StnInfo *_t = static_cast<StnInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stationsUpdated(); break;
        case 1: _t->stationAdded((*reinterpret_cast< QMutex*(*)>(_a[1]))); break;
        case 2: _t->stationLogEvt((*reinterpret_cast< QMutex*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->stationXmlEvt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->debugMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->statusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: { StaInfo* _r = _t->stationIndex((*reinterpret_cast< K2INFO_HEADER*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< StaInfo**>(_a[0]) = _r; }  break;
        case 7: { StaInfo* _r = _t->stationIndex((*reinterpret_cast< QDomElement(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< StaInfo**>(_a[0]) = _r; }  break;
        case 8: { StaInfo* _r = _t->stationIndex((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< StaInfo**>(_a[0]) = _r; }  break;
        case 9: _t->recieveK2Status((*reinterpret_cast< K2INFO_HEADER*(*)>(_a[1])),(*reinterpret_cast< STATUS_INFO*(*)>(_a[2])),(*reinterpret_cast< QMutex*(*)>(_a[3]))); break;
        case 10: _t->recieveK2Status2((*reinterpret_cast< K2INFO_HEADER*(*)>(_a[1])),(*reinterpret_cast< EXT2_STATUS_INFO*(*)>(_a[2])),(*reinterpret_cast< QMutex*(*)>(_a[3]))); break;
        case 11: _t->recieveK2HeaderS((*reinterpret_cast< K2INFO_HEADER*(*)>(_a[1])),(*reinterpret_cast< K2_HEADER*(*)>(_a[2])),(*reinterpret_cast< QMutex*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StnInfo::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StnInfo::stationsUpdated)) {
                *result = 0;
            }
        }
        {
            typedef void (StnInfo::*_t)(QMutex * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StnInfo::stationAdded)) {
                *result = 1;
            }
        }
        {
            typedef void (StnInfo::*_t)(QMutex * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StnInfo::stationLogEvt)) {
                *result = 2;
            }
        }
        {
            typedef void (StnInfo::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StnInfo::stationXmlEvt)) {
                *result = 3;
            }
        }
        {
            typedef void (StnInfo::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StnInfo::debugMessage)) {
                *result = 4;
            }
        }
        {
            typedef void (StnInfo::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StnInfo::statusMessage)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject StnInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StnInfo.data,
      qt_meta_data_StnInfo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StnInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StnInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StnInfo.stringdata0))
        return static_cast<void*>(const_cast< StnInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int StnInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void StnInfo::stationsUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void StnInfo::stationAdded(QMutex * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StnInfo::stationLogEvt(QMutex * _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void StnInfo::stationXmlEvt(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void StnInfo::debugMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void StnInfo::statusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
