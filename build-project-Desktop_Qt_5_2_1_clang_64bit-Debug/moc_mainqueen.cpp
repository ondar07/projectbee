/****************************************************************************
** Meta object code from reading C++ file 'mainqueen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/mainqueen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainqueen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainQueen_t {
    QByteArrayData data[18];
    char stringdata[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainQueen_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainQueen_t qt_meta_stringdata_MainQueen = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 9),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 9),
QT_MOC_LITERAL(4, 31, 9),
QT_MOC_LITERAL(5, 41, 9),
QT_MOC_LITERAL(6, 51, 6),
QT_MOC_LITERAL(7, 58, 12),
QT_MOC_LITERAL(8, 71, 10),
QT_MOC_LITERAL(9, 82, 9),
QT_MOC_LITERAL(10, 92, 8),
QT_MOC_LITERAL(11, 101, 7),
QT_MOC_LITERAL(12, 109, 7),
QT_MOC_LITERAL(13, 117, 11),
QT_MOC_LITERAL(14, 129, 12),
QT_MOC_LITERAL(15, 142, 16),
QT_MOC_LITERAL(16, 159, 9),
QT_MOC_LITERAL(17, 169, 13)
    },
    "MainQueen\0killQueen\0\0killDrone\0toEggList\0"
    "countEggs\0fertil\0placeEmpCell\0numberCell\0"
    "toBeehive\0finished\0process\0layEggs\0"
    "numbEmpCell\0wasBornQueen\0emitSignalToKill\0"
    "fromDrone\0whatEmptyCell\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainQueen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06,
       3,    0,   70,    2, 0x06,
       4,    4,   71,    2, 0x06,
       9,    0,   80,    2, 0x06,
      10,    0,   81,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    0,   82,    2, 0x0a,
      12,    2,   83,    2, 0x0a,
      14,    0,   88,    2, 0x0a,
      15,    0,   89,    2, 0x0a,
      16,    0,   90,    2, 0x0a,
      17,    0,   91,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QPoint, QMetaType::Int,    5,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,   13,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainQueen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainQueen *_t = static_cast<MainQueen *>(_o);
        switch (_id) {
        case 0: _t->killQueen(); break;
        case 1: _t->killDrone(); break;
        case 2: _t->toEggList((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QPoint(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->toBeehive(); break;
        case 4: _t->finished(); break;
        case 5: _t->process(); break;
        case 6: _t->layEggs((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 7: _t->wasBornQueen(); break;
        case 8: _t->emitSignalToKill(); break;
        case 9: _t->fromDrone(); break;
        case 10: _t->whatEmptyCell(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainQueen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainQueen::killQueen)) {
                *result = 0;
            }
        }
        {
            typedef void (MainQueen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainQueen::killDrone)) {
                *result = 1;
            }
        }
        {
            typedef void (MainQueen::*_t)(int , bool , QPoint , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainQueen::toEggList)) {
                *result = 2;
            }
        }
        {
            typedef void (MainQueen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainQueen::toBeehive)) {
                *result = 3;
            }
        }
        {
            typedef void (MainQueen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainQueen::finished)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject MainQueen::staticMetaObject = {
    { &Queen::staticMetaObject, qt_meta_stringdata_MainQueen.data,
      qt_meta_data_MainQueen,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainQueen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainQueen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainQueen.stringdata))
        return static_cast<void*>(const_cast< MainQueen*>(this));
    return Queen::qt_metacast(_clname);
}

int MainQueen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Queen::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainQueen::killQueen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainQueen::killDrone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainQueen::toEggList(int _t1, bool _t2, QPoint _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainQueen::toBeehive()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainQueen::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
