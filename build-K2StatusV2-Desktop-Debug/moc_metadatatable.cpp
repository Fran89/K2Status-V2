/****************************************************************************
** Meta object code from reading C++ file 'metadatatable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/metadatatable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'metadatatable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MetadataTable_t {
    QByteArrayData data[7];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MetadataTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MetadataTable_t qt_meta_stringdata_MetadataTable = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MetadataTable"
QT_MOC_LITERAL(1, 14, 12), // "debugMessage"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "addStaInformation"
QT_MOC_LITERAL(4, 46, 7), // "QMutex*"
QT_MOC_LITERAL(5, 54, 4), // "temp"
QT_MOC_LITERAL(6, 59, 14) // "updateMetadata"

    },
    "MetadataTable\0debugMessage\0\0"
    "addStaInformation\0QMutex*\0temp\0"
    "updateMetadata"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MetadataTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

       0        // eod
};

void MetadataTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MetadataTable *_t = static_cast<MetadataTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->debugMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addStaInformation((*reinterpret_cast< QMutex*(*)>(_a[1]))); break;
        case 2: _t->updateMetadata(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MetadataTable::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MetadataTable::debugMessage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MetadataTable::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_MetadataTable.data,
      qt_meta_data_MetadataTable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MetadataTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MetadataTable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MetadataTable.stringdata0))
        return static_cast<void*>(const_cast< MetadataTable*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int MetadataTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
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
void MetadataTable::debugMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
