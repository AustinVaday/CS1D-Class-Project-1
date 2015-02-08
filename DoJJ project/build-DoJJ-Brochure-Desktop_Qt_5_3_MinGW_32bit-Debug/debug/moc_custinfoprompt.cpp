/****************************************************************************
** Meta object code from reading C++ file 'custinfoprompt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DoJJ-Brochure_/custinfoprompt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'custinfoprompt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CustInfoPrompt_t {
    QByteArrayData data[7];
    char stringdata[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustInfoPrompt_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustInfoPrompt_t qt_meta_stringdata_CustInfoPrompt = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 13),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 17),
QT_MOC_LITERAL(4, 48, 14),
QT_MOC_LITERAL(5, 63, 17),
QT_MOC_LITERAL(6, 81, 15)
    },
    "CustInfoPrompt\0changeSuccess\0\0"
    "on_Cancel_clicked\0on_Add_clicked\0"
    "on_Remove_clicked\0on_Edit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustInfoPrompt[] = {

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
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CustInfoPrompt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustInfoPrompt *_t = static_cast<CustInfoPrompt *>(_o);
        switch (_id) {
        case 0: _t->changeSuccess(); break;
        case 1: _t->on_Cancel_clicked(); break;
        case 2: _t->on_Add_clicked(); break;
        case 3: _t->on_Remove_clicked(); break;
        case 4: _t->on_Edit_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CustInfoPrompt::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustInfoPrompt::changeSuccess)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CustInfoPrompt::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CustInfoPrompt.data,
      qt_meta_data_CustInfoPrompt,  qt_static_metacall, 0, 0}
};


const QMetaObject *CustInfoPrompt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustInfoPrompt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CustInfoPrompt.stringdata))
        return static_cast<void*>(const_cast< CustInfoPrompt*>(this));
    return QDialog::qt_metacast(_clname);
}

int CustInfoPrompt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CustInfoPrompt::changeSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
