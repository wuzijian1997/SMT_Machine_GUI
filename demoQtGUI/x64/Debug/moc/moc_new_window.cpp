/****************************************************************************
** Meta object code from reading C++ file 'new_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../new_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'new_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_new_window_t {
    QByteArrayData data[8];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_new_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_new_window_t qt_meta_stringdata_new_window = {
    {
QT_MOC_LITERAL(0, 0, 10), // "new_window"
QT_MOC_LITERAL(1, 11, 21), // "sendMachineCoordinate"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "vector<Point2f>"
QT_MOC_LITERAL(4, 50, 30), // "on_showImagePushButton_clicked"
QT_MOC_LITERAL(5, 81, 37), // "on_clearClickNumberPushButton..."
QT_MOC_LITERAL(6, 119, 22), // "recvCurrentPointNumber"
QT_MOC_LITERAL(7, 142, 25) // "on_cropPushButton_clicked"

    },
    "new_window\0sendMachineCoordinate\0\0"
    "vector<Point2f>\0on_showImagePushButton_clicked\0"
    "on_clearClickNumberPushButton_clicked\0"
    "recvCurrentPointNumber\0on_cropPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_new_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void new_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        new_window *_t = static_cast<new_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMachineCoordinate((*reinterpret_cast< vector<Point2f>(*)>(_a[1]))); break;
        case 1: _t->on_showImagePushButton_clicked(); break;
        case 2: _t->on_clearClickNumberPushButton_clicked(); break;
        case 3: _t->recvCurrentPointNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_cropPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (new_window::*_t)(vector<Point2f> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&new_window::sendMachineCoordinate)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject new_window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_new_window.data,
      qt_meta_data_new_window,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *new_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *new_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_new_window.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int new_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void new_window::sendMachineCoordinate(vector<Point2f> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
