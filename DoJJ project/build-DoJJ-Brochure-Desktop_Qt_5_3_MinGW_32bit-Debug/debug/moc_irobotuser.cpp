/****************************************************************************
** Meta object code from reading C++ file 'irobotuser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DoJJ-Brochure_/irobotuser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'irobotuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_iRobotUser_t {
    QByteArrayData data[15];
    char stringdata[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iRobotUser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iRobotUser_t qt_meta_stringdata_iRobotUser = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 26),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 23),
QT_MOC_LITERAL(4, 63, 26),
QT_MOC_LITERAL(5, 90, 24),
QT_MOC_LITERAL(6, 115, 25),
QT_MOC_LITERAL(7, 141, 19),
QT_MOC_LITERAL(8, 161, 20),
QT_MOC_LITERAL(9, 182, 29),
QT_MOC_LITERAL(10, 212, 8),
QT_MOC_LITERAL(11, 221, 9),
QT_MOC_LITERAL(12, 231, 9),
QT_MOC_LITERAL(13, 241, 21),
QT_MOC_LITERAL(14, 263, 25)
    },
    "iRobotUser\0on_actionLog_out_triggered\0"
    "\0on_actionQuit_triggered\0"
    "on_requestBrochure_clicked\0"
    "on_printBrochure_clicked\0"
    "on_addTestimonial_clicked\0on_purchase_clicked\0"
    "on_contactus_clicked\0on_actionUser_Guide_triggered\0"
    "WordWrap\0bigString\0lineLimit\0"
    "on_pushButton_clicked\0on_requestAccount_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iRobotUser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    2,   77,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void iRobotUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        iRobotUser *_t = static_cast<iRobotUser *>(_o);
        switch (_id) {
        case 0: _t->on_actionLog_out_triggered(); break;
        case 1: _t->on_actionQuit_triggered(); break;
        case 2: _t->on_requestBrochure_clicked(); break;
        case 3: _t->on_printBrochure_clicked(); break;
        case 4: _t->on_addTestimonial_clicked(); break;
        case 5: _t->on_purchase_clicked(); break;
        case 6: _t->on_contactus_clicked(); break;
        case 7: _t->on_actionUser_Guide_triggered(); break;
        case 8: { QString _r = _t->WordWrap((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_requestAccount_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject iRobotUser::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_iRobotUser.data,
      qt_meta_data_iRobotUser,  qt_static_metacall, 0, 0}
};


const QMetaObject *iRobotUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iRobotUser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_iRobotUser.stringdata))
        return static_cast<void*>(const_cast< iRobotUser*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int iRobotUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
