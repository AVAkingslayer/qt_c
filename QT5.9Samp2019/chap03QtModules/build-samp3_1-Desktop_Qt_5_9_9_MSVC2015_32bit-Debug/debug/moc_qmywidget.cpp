/****************************************************************************
** Meta object code from reading C++ file 'qmywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../samp3_1/qmywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QmyWidget_t {
    QByteArrayData data[10];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QmyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QmyWidget_t qt_meta_stringdata_QmyWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QmyWidget"
QT_MOC_LITERAL(1, 10, 13), // "on_ageChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "value"
QT_MOC_LITERAL(4, 31, 20), // "on_spin_valueChanged"
QT_MOC_LITERAL(5, 52, 4), // "arg1"
QT_MOC_LITERAL(6, 57, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(7, 77, 20), // "on_btnBoyInc_clicked"
QT_MOC_LITERAL(8, 98, 21), // "on_btnGirlInc_clicked"
QT_MOC_LITERAL(9, 120, 23) // "on_btnClassInfo_clicked"

    },
    "QmyWidget\0on_ageChanged\0\0value\0"
    "on_spin_valueChanged\0arg1\0on_btnClear_clicked\0"
    "on_btnBoyInc_clicked\0on_btnGirlInc_clicked\0"
    "on_btnClassInfo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QmyWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QmyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QmyWidget *_t = static_cast<QmyWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_spin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_btnClear_clicked(); break;
        case 3: _t->on_btnBoyInc_clicked(); break;
        case 4: _t->on_btnGirlInc_clicked(); break;
        case 5: _t->on_btnClassInfo_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject QmyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QmyWidget.data,
      qt_meta_data_QmyWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QmyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QmyWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QmyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
