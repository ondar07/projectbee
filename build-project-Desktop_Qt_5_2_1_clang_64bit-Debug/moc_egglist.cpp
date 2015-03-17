/****************************************************************************
** Meta object code from reading C++ file 'egglist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/egglist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'egglist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EggList_t {
    QByteArrayData data[19];
    char stringdata[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_EggList_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_EggList_t qt_meta_stringdata_EggList = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 8),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 9),
QT_MOC_LITERAL(4, 28, 4),
QT_MOC_LITERAL(5, 33, 3),
QT_MOC_LITERAL(6, 37, 15),
QT_MOC_LITERAL(7, 53, 8),
QT_MOC_LITERAL(8, 62, 8),
QT_MOC_LITERAL(9, 71, 16),
QT_MOC_LITERAL(10, 88, 15),
QT_MOC_LITERAL(11, 104, 9),
QT_MOC_LITERAL(12, 114, 9),
QT_MOC_LITERAL(13, 124, 6),
QT_MOC_LITERAL(14, 131, 12),
QT_MOC_LITERAL(15, 144, 8),
QT_MOC_LITERAL(16, 153, 11),
QT_MOC_LITERAL(17, 165, 12),
QT_MOC_LITERAL(18, 178, 11)
    },
    "EggList\0finished\0\0toDrawEgg\0Egg*\0egg\0"
    "signCreateQueen\0position\0cellNumb\0"
    "signCreateWorker\0signCreateDrone\0"
    "fromQueen\0countEggs\0fertil\0placeEmpCell\0"
    "killEggs\0createQueen\0createWorker\0"
    "createDrone\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EggList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06,
       3,    1,   65,    2, 0x06,
       6,    2,   68,    2, 0x06,
       9,    2,   73,    2, 0x06,
      10,    2,   78,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    4,   83,    2, 0x0a,
      15,    0,   92,    2, 0x0a,
      16,    2,   93,    2, 0x0a,
      17,    2,   98,    2, 0x0a,
      18,    2,  103,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QPoint, QMetaType::Int,   12,   13,   14,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    7,    8,

       0        // eod
};

void EggList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EggList *_t = static_cast<EggList *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->toDrawEgg((*reinterpret_cast< Egg*(*)>(_a[1]))); break;
        case 2: _t->signCreateQueen((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->signCreateWorker((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->signCreateDrone((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->fromQueen((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QPoint(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->killEggs(); break;
        case 7: _t->createQueen((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->createWorker((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->createDrone((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Egg* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EggList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EggList::finished)) {
                *result = 0;
            }
        }
        {
            typedef void (EggList::*_t)(Egg * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EggList::toDrawEgg)) {
                *result = 1;
            }
        }
        {
            typedef void (EggList::*_t)(QPoint , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EggList::signCreateQueen)) {
                *result = 2;
            }
        }
        {
            typedef void (EggList::*_t)(QPoint , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EggList::signCreateWorker)) {
                *result = 3;
            }
        }
        {
            typedef void (EggList::*_t)(QPoint , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EggList::signCreateDrone)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject EggList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EggList.data,
      qt_meta_data_EggList,  qt_static_metacall, 0, 0}
};


const QMetaObject *EggList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EggList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EggList.stringdata))
        return static_cast<void*>(const_cast< EggList*>(this));
    return QObject::qt_metacast(_clname);
}

int EggList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void EggList::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EggList::toDrawEgg(Egg * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EggList::signCreateQueen(QPoint _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EggList::signCreateWorker(QPoint _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EggList::signCreateDrone(QPoint _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
