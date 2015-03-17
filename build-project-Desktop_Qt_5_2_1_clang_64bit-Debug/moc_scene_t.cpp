/****************************************************************************
** Meta object code from reading C++ file 'scene_t.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/scene_t.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scene_t.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Scene_t_t {
    QByteArrayData data[22];
    char stringdata[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Scene_t_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Scene_t_t qt_meta_stringdata_Scene_t = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 12),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 18),
QT_MOC_LITERAL(4, 41, 9),
QT_MOC_LITERAL(5, 51, 8),
QT_MOC_LITERAL(6, 60, 11),
QT_MOC_LITERAL(7, 72, 8),
QT_MOC_LITERAL(8, 81, 11),
QT_MOC_LITERAL(9, 93, 12),
QT_MOC_LITERAL(10, 106, 11),
QT_MOC_LITERAL(11, 118, 10),
QT_MOC_LITERAL(12, 129, 13),
QT_MOC_LITERAL(13, 143, 14),
QT_MOC_LITERAL(14, 158, 8),
QT_MOC_LITERAL(15, 167, 11),
QT_MOC_LITERAL(16, 179, 9),
QT_MOC_LITERAL(17, 189, 9),
QT_MOC_LITERAL(18, 199, 8),
QT_MOC_LITERAL(19, 208, 4),
QT_MOC_LITERAL(20, 213, 3),
QT_MOC_LITERAL(21, 217, 8)
    },
    "Scene_t\0wasBornQueen\0\0queenWasFertilized\0"
    "toBeehive\0cellNumb\0createQueen\0position\0"
    "createDrone\0createWorker\0startTimers\0"
    "stopTimers\0killAllDrones\0killAllWorkers\0"
    "forDrone\0update_bees\0killQueen\0killDrone\0"
    "drawEggs\0Egg*\0egg\0getHoney\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scene_t[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06,
       3,    0,   95,    2, 0x06,
       4,    1,   96,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    2,   99,    2, 0x0a,
       8,    2,  104,    2, 0x0a,
       9,    2,  109,    2, 0x0a,
      10,    0,  114,    2, 0x0a,
      11,    0,  115,    2, 0x0a,
      12,    0,  116,    2, 0x0a,
      13,    0,  117,    2, 0x0a,
      14,    0,  118,    2, 0x0a,
      15,    0,  119,    2, 0x0a,
      16,    0,  120,    2, 0x0a,
      17,    0,  121,    2, 0x0a,
      18,    1,  122,    2, 0x0a,
      21,    0,  125,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    7,    5,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    7,    5,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    7,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,

       0        // eod
};

void Scene_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scene_t *_t = static_cast<Scene_t *>(_o);
        switch (_id) {
        case 0: _t->wasBornQueen(); break;
        case 1: _t->queenWasFertilized(); break;
        case 2: _t->toBeehive((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->createQueen((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->createDrone((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->createWorker((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->startTimers(); break;
        case 7: _t->stopTimers(); break;
        case 8: _t->killAllDrones(); break;
        case 9: _t->killAllWorkers(); break;
        case 10: _t->forDrone(); break;
        case 11: _t->update_bees(); break;
        case 12: _t->killQueen(); break;
        case 13: _t->killDrone(); break;
        case 14: _t->drawEggs((*reinterpret_cast< Egg*(*)>(_a[1]))); break;
        case 15: _t->getHoney(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
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
            typedef void (Scene_t::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scene_t::wasBornQueen)) {
                *result = 0;
            }
        }
        {
            typedef void (Scene_t::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scene_t::queenWasFertilized)) {
                *result = 1;
            }
        }
        {
            typedef void (Scene_t::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scene_t::toBeehive)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Scene_t::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_Scene_t.data,
      qt_meta_data_Scene_t,  qt_static_metacall, 0, 0}
};


const QMetaObject *Scene_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scene_t::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Scene_t.stringdata))
        return static_cast<void*>(const_cast< Scene_t*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int Scene_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Scene_t::wasBornQueen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Scene_t::queenWasFertilized()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Scene_t::toBeehive(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
