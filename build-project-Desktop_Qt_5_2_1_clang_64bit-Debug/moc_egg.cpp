/****************************************************************************
** Meta object code from reading C++ file 'egg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/egg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'egg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Egg_t {
    QByteArrayData data[9];
    char stringdata[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Egg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Egg_t qt_meta_stringdata_Egg = {
    {
QT_MOC_LITERAL(0, 0, 3),
QT_MOC_LITERAL(1, 4, 11),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 8),
QT_MOC_LITERAL(4, 26, 8),
QT_MOC_LITERAL(5, 35, 12),
QT_MOC_LITERAL(6, 48, 11),
QT_MOC_LITERAL(7, 60, 8),
QT_MOC_LITERAL(8, 69, 9)
    },
    "Egg\0createQueen\0\0position\0cellNumb\0"
    "createWorker\0createDrone\0killEggs\0"
    "evolution\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Egg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06,
       5,    2,   44,    2, 0x06,
       6,    2,   49,    2, 0x06,
       7,    0,   54,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       8,    0,   55,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Egg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Egg *_t = static_cast<Egg *>(_o);
        switch (_id) {
        case 0: _t->createQueen((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->createWorker((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->createDrone((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->killEggs(); break;
        case 4: _t->evolution(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Egg::*_t)(QPoint , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Egg::createQueen)) {
                *result = 0;
            }
        }
        {
            typedef void (Egg::*_t)(QPoint , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Egg::createWorker)) {
                *result = 1;
            }
        }
        {
            typedef void (Egg::*_t)(QPoint , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Egg::createDrone)) {
                *result = 2;
            }
        }
        {
            typedef void (Egg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Egg::killEggs)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Egg::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_Egg.data,
      qt_meta_data_Egg,  qt_static_metacall, 0, 0}
};


const QMetaObject *Egg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Egg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Egg.stringdata))
        return static_cast<void*>(const_cast< Egg*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int Egg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Egg::createQueen(QPoint _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Egg::createWorker(QPoint _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Egg::createDrone(QPoint _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Egg::killEggs()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
