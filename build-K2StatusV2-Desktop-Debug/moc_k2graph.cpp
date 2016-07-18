/****************************************************************************
** Meta object code from reading C++ file 'k2graph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/k2graph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'k2graph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_K2Graph_t {
    QByteArrayData data[8];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_K2Graph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_K2Graph_t qt_meta_stringdata_K2Graph = {
    {
QT_MOC_LITERAL(0, 0, 7), // "K2Graph"
QT_MOC_LITERAL(1, 8, 10), // "stnupdated"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "showTGraph"
QT_MOC_LITERAL(4, 31, 3), // "sta"
QT_MOC_LITERAL(5, 35, 10), // "showVGraph"
QT_MOC_LITERAL(6, 46, 20), // "on_graphTemp_clicked"
QT_MOC_LITERAL(7, 67, 20) // "on_graphVolt_clicked"

    },
    "K2Graph\0stnupdated\0\0showTGraph\0sta\0"
    "showVGraph\0on_graphTemp_clicked\0"
    "on_graphVolt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_K2Graph[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       6,    0,   46,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void K2Graph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        K2Graph *_t = static_cast<K2Graph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stnupdated(); break;
        case 1: _t->showTGraph((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->showVGraph((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_graphTemp_clicked(); break;
        case 4: _t->on_graphVolt_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject K2Graph::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_K2Graph.data,
      qt_meta_data_K2Graph,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *K2Graph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *K2Graph::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_K2Graph.stringdata0))
        return static_cast<void*>(const_cast< K2Graph*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int K2Graph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
