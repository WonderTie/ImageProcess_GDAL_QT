/****************************************************************************
** Meta object code from reading C++ file 'dialog_region_growing.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dialog_region_growing.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_region_growing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_region_growing_t {
    QByteArrayData data[8];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_region_growing_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_region_growing_t qt_meta_stringdata_Dialog_region_growing = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Dialog_region_growing"
QT_MOC_LITERAL(1, 22, 20), // "send_auto_region_par"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 8), // "AUTO_PAR"
QT_MOC_LITERAL(4, 53, 19), // "send_peo_region_par"
QT_MOC_LITERAL(5, 73, 7), // "PEO_PAR"
QT_MOC_LITERAL(6, 81, 15), // "run_auto_region"
QT_MOC_LITERAL(7, 97, 14) // "run_peo_region"

    },
    "Dialog_region_growing\0send_auto_region_par\0"
    "\0AUTO_PAR\0send_peo_region_par\0PEO_PAR\0"
    "run_auto_region\0run_peo_region"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_region_growing[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog_region_growing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog_region_growing *_t = static_cast<Dialog_region_growing *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_auto_region_par((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->send_peo_region_par((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->run_auto_region(); break;
        case 3: _t->run_peo_region(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog_region_growing::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_region_growing::send_auto_region_par)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dialog_region_growing::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_region_growing::send_peo_region_par)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_region_growing::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog_region_growing.data,
      qt_meta_data_Dialog_region_growing,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Dialog_region_growing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_region_growing::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_region_growing.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_region_growing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Dialog_region_growing::send_auto_region_par(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog_region_growing::send_peo_region_par(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
