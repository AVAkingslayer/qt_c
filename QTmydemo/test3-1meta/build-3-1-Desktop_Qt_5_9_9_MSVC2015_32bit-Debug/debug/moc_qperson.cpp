/****************************************************************************
** Meta object code from reading C++ file 'qperson.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../3-1/qperson.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qperson.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QPerson_t {
    QByteArrayData data[15];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPerson_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPerson_t qt_meta_stringdata_QPerson = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QPerson"
QT_MOC_LITERAL(1, 8, 6), // "Author"
QT_MOC_LITERAL(2, 15, 3), // "ava"
QT_MOC_LITERAL(3, 19, 7), // "Company"
QT_MOC_LITERAL(4, 27, 5), // "UESTC"
QT_MOC_LITERAL(5, 33, 7), // "Version"
QT_MOC_LITERAL(6, 41, 5), // "1.1.0"
QT_MOC_LITERAL(7, 47, 10), // "ageChanged"
QT_MOC_LITERAL(8, 58, 0), // ""
QT_MOC_LITERAL(9, 59, 5), // "value"
QT_MOC_LITERAL(10, 65, 3), // "age"
QT_MOC_LITERAL(11, 69, 4), // "type"
QT_MOC_LITERAL(12, 74, 4), // "name"
QT_MOC_LITERAL(13, 79, 7), // "Qstring"
QT_MOC_LITERAL(14, 87, 5) // "score"

    },
    "QPerson\0Author\0ava\0Company\0UESTC\0"
    "Version\0""1.1.0\0ageChanged\0\0value\0age\0"
    "type\0name\0Qstring\0score"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPerson[] = {

 // content:
       7,       // revision
       0,       // classname
       3,   14, // classinfo
       1,   20, // methods
       3,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,
       5,    6,

 // signals: name, argc, parameters, tag, flags
       7,    1,   25,    8, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    9,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x0049510b,
      12, 0x80000000 | 13, 0x0009500b,
      14, QMetaType::Int, 0x00095003,

 // properties: notify_signal_id
       0,
       0,
       0,

       0        // eod
};

void QPerson::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPerson *_t = static_cast<QPerson *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QPerson::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QPerson::ageChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QPerson *_t = static_cast<QPerson *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< type*>(_v) = _t->age(); break;
        case 1: *reinterpret_cast< Qstring*>(_v) = _t->m_name; break;
        case 2: *reinterpret_cast< int*>(_v) = _t->m_score; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QPerson *_t = static_cast<QPerson *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAge(*reinterpret_cast< type*>(_v)); break;
        case 1:
            if (_t->m_name != *reinterpret_cast< Qstring*>(_v)) {
                _t->m_name = *reinterpret_cast< Qstring*>(_v);
            }
            break;
        case 2:
            if (_t->m_score != *reinterpret_cast< int*>(_v)) {
                _t->m_score = *reinterpret_cast< int*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QPerson::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QPerson.data,
      qt_meta_data_QPerson,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QPerson::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPerson::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QPerson.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QPerson::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QPerson::ageChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE