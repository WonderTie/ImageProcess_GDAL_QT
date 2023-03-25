/****************************************************************************
** Meta object code from reading C++ file 'dialog_slider_line.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dialog_slider_line.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_slider_line.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_slider_line_t {
    QByteArrayData data[11];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_slider_line_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_slider_line_t qt_meta_stringdata_Dialog_slider_line = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Dialog_slider_line"
QT_MOC_LITERAL(1, 19, 9), // "send_line"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "silder_value"
QT_MOC_LITERAL(4, 43, 13), // "send_line_min"
QT_MOC_LITERAL(5, 57, 16), // "silder_value_min"
QT_MOC_LITERAL(6, 74, 15), // "slider_changed_"
QT_MOC_LITERAL(7, 90, 18), // "slider_changed_min"
QT_MOC_LITERAL(8, 109, 11), // "receive_par"
QT_MOC_LITERAL(9, 121, 9), // "max_value"
QT_MOC_LITERAL(10, 131, 9) // "min_value"

    },
    "Dialog_slider_line\0send_line\0\0"
    "silder_value\0send_line_min\0silder_value_min\0"
    "slider_changed_\0slider_changed_min\0"
    "receive_par\0max_value\0min_value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_slider_line[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    2,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

       0        // eod
};

void Dialog_slider_line::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog_slider_line *_t = static_cast<Dialog_slider_line *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_line((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->send_line_min((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slider_changed_(); break;
        case 3: _t->slider_changed_min(); break;
        case 4: _t->receive_par((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog_slider_line::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_slider_line::send_line)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dialog_slider_line::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_slider_line::send_line_min)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_slider_line::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog_slider_line.data,
      qt_meta_data_Dialog_slider_line,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Dialog_slider_line::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_slider_line::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_slider_line.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_slider_line::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void Dialog_slider_line::send_line(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog_slider_line::send_line_min(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
