/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WineryProject/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[59];
    char stringdata[1224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionHelp_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(4, 58, 25), // "on_adminLogButton_clicked"
QT_MOC_LITERAL(5, 84, 33), // "on_viewListWineriesButton_cli..."
QT_MOC_LITERAL(6, 118, 28), // "on_planDayTripButton_clicked"
QT_MOC_LITERAL(7, 147, 30), // "on_admin_log_ok_button_clicked"
QT_MOC_LITERAL(8, 178, 35), // "on_adming_log_cancel_button_c..."
QT_MOC_LITERAL(9, 214, 31), // "on_admin_log_out_button_clicked"
QT_MOC_LITERAL(10, 246, 19), // "on_ViewBack_clicked"
QT_MOC_LITERAL(11, 266, 23), // "on_PlanTripBack_clicked"
QT_MOC_LITERAL(12, 290, 19), // "on_TourBack_clicked"
QT_MOC_LITERAL(13, 310, 20), // "on_LogInBack_clicked"
QT_MOC_LITERAL(14, 331, 29), // "on_passwordLine_returnPressed"
QT_MOC_LITERAL(15, 361, 20), // "on_visit_all_clicked"
QT_MOC_LITERAL(16, 382, 25), // "on_backToTripType_clicked"
QT_MOC_LITERAL(17, 408, 15), // "on_next_clicked"
QT_MOC_LITERAL(18, 424, 12), // "ShortestPath"
QT_MOC_LITERAL(19, 437, 14), // "QList<Winery>&"
QT_MOC_LITERAL(20, 452, 16), // "shortestPathList"
QT_MOC_LITERAL(21, 469, 6), // "float&"
QT_MOC_LITERAL(22, 476, 17), // "distanceTravelled"
QT_MOC_LITERAL(23, 494, 12), // "shortestTrip"
QT_MOC_LITERAL(24, 507, 13), // "const Winery*"
QT_MOC_LITERAL(25, 521, 15), // "beginningWinery"
QT_MOC_LITERAL(26, 537, 15), // "wineriesToVisit"
QT_MOC_LITERAL(27, 553, 10), // "customTrip"
QT_MOC_LITERAL(28, 564, 17), // "QMap<int,Winery>*"
QT_MOC_LITERAL(29, 582, 16), // "customWineryList"
QT_MOC_LITERAL(30, 599, 14), // "closestToVilla"
QT_MOC_LITERAL(31, 614, 6), // "Winery"
QT_MOC_LITERAL(32, 621, 17), // "QMap<int,Winery>&"
QT_MOC_LITERAL(33, 639, 15), // "localWineryList"
QT_MOC_LITERAL(34, 655, 24), // "on_shortest_trip_clicked"
QT_MOC_LITERAL(35, 680, 22), // "on_custom_trip_clicked"
QT_MOC_LITERAL(36, 703, 22), // "on_prev_winery_clicked"
QT_MOC_LITERAL(37, 726, 20), // "on_addToCart_clicked"
QT_MOC_LITERAL(38, 747, 17), // "on_goBack_clicked"
QT_MOC_LITERAL(39, 765, 26), // "on_wineryTable_itemClicked"
QT_MOC_LITERAL(40, 792, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(41, 810, 4), // "item"
QT_MOC_LITERAL(42, 815, 23), // "on_addNewWinery_clicked"
QT_MOC_LITERAL(43, 839, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(44, 863, 19), // "on_addNew_2_clicked"
QT_MOC_LITERAL(45, 883, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(46, 907, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(47, 931, 26), // "on_AddWineryButton_clicked"
QT_MOC_LITERAL(48, 958, 24), // "on_backAddWinery_clicked"
QT_MOC_LITERAL(49, 983, 23), // "on_AddWinesBack_clicked"
QT_MOC_LITERAL(50, 1007, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(51, 1031, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(52, 1055, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(53, 1079, 25), // "on_removeFromCart_clicked"
QT_MOC_LITERAL(54, 1105, 18), // "on_AddWine_clicked"
QT_MOC_LITERAL(55, 1124, 22), // "on_doneAddWine_clicked"
QT_MOC_LITERAL(56, 1147, 24), // "on_NextToAddWine_clicked"
QT_MOC_LITERAL(57, 1172, 26), // "on_BacktoAddWinery_clicked"
QT_MOC_LITERAL(58, 1199, 24) // "on_startShortest_clicked"

    },
    "MainWindow\0on_actionHelp_triggered\0\0"
    "on_quitButton_clicked\0on_adminLogButton_clicked\0"
    "on_viewListWineriesButton_clicked\0"
    "on_planDayTripButton_clicked\0"
    "on_admin_log_ok_button_clicked\0"
    "on_adming_log_cancel_button_clicked\0"
    "on_admin_log_out_button_clicked\0"
    "on_ViewBack_clicked\0on_PlanTripBack_clicked\0"
    "on_TourBack_clicked\0on_LogInBack_clicked\0"
    "on_passwordLine_returnPressed\0"
    "on_visit_all_clicked\0on_backToTripType_clicked\0"
    "on_next_clicked\0ShortestPath\0"
    "QList<Winery>&\0shortestPathList\0float&\0"
    "distanceTravelled\0shortestTrip\0"
    "const Winery*\0beginningWinery\0"
    "wineriesToVisit\0customTrip\0QMap<int,Winery>*\0"
    "customWineryList\0closestToVilla\0Winery\0"
    "QMap<int,Winery>&\0localWineryList\0"
    "on_shortest_trip_clicked\0"
    "on_custom_trip_clicked\0on_prev_winery_clicked\0"
    "on_addToCart_clicked\0on_goBack_clicked\0"
    "on_wineryTable_itemClicked\0QTableWidgetItem*\0"
    "item\0on_addNewWinery_clicked\0"
    "on_pushButton_6_clicked\0on_addNew_2_clicked\0"
    "on_pushButton_7_clicked\0on_pushButton_3_clicked\0"
    "on_AddWineryButton_clicked\0"
    "on_backAddWinery_clicked\0"
    "on_AddWinesBack_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_8_clicked\0"
    "on_removeFromCart_clicked\0on_AddWine_clicked\0"
    "on_doneAddWine_clicked\0on_NextToAddWine_clicked\0"
    "on_BacktoAddWinery_clicked\0"
    "on_startShortest_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  219,    2, 0x08 /* Private */,
       3,    0,  220,    2, 0x08 /* Private */,
       4,    0,  221,    2, 0x08 /* Private */,
       5,    0,  222,    2, 0x08 /* Private */,
       6,    0,  223,    2, 0x08 /* Private */,
       7,    0,  224,    2, 0x08 /* Private */,
       8,    0,  225,    2, 0x08 /* Private */,
       9,    0,  226,    2, 0x08 /* Private */,
      10,    0,  227,    2, 0x08 /* Private */,
      11,    0,  228,    2, 0x08 /* Private */,
      12,    0,  229,    2, 0x08 /* Private */,
      13,    0,  230,    2, 0x08 /* Private */,
      14,    0,  231,    2, 0x08 /* Private */,
      15,    0,  232,    2, 0x08 /* Private */,
      16,    0,  233,    2, 0x08 /* Private */,
      17,    0,  234,    2, 0x08 /* Private */,
      18,    7,  235,    2, 0x08 /* Private */,
      30,    1,  250,    2, 0x08 /* Private */,
      34,    0,  253,    2, 0x08 /* Private */,
      35,    0,  254,    2, 0x08 /* Private */,
      36,    0,  255,    2, 0x08 /* Private */,
      37,    0,  256,    2, 0x08 /* Private */,
      38,    0,  257,    2, 0x08 /* Private */,
      39,    1,  258,    2, 0x08 /* Private */,
      42,    0,  261,    2, 0x08 /* Private */,
      43,    0,  262,    2, 0x08 /* Private */,
      44,    0,  263,    2, 0x08 /* Private */,
      45,    0,  264,    2, 0x08 /* Private */,
      46,    0,  265,    2, 0x08 /* Private */,
      47,    0,  266,    2, 0x08 /* Private */,
      48,    0,  267,    2, 0x08 /* Private */,
      49,    0,  268,    2, 0x08 /* Private */,
      50,    0,  269,    2, 0x08 /* Private */,
      51,    0,  270,    2, 0x08 /* Private */,
      52,    0,  271,    2, 0x08 /* Private */,
      53,    0,  272,    2, 0x08 /* Private */,
      54,    0,  273,    2, 0x08 /* Private */,
      55,    0,  274,    2, 0x08 /* Private */,
      56,    0,  275,    2, 0x08 /* Private */,
      57,    0,  276,    2, 0x08 /* Private */,
      58,    0,  277,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 21, QMetaType::Bool, 0x80000000 | 24, QMetaType::Int, QMetaType::Bool, 0x80000000 | 28,   20,   22,   23,   25,   26,   27,   29,
    0x80000000 | 31, 0x80000000 | 32,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionHelp_triggered(); break;
        case 1: _t->on_quitButton_clicked(); break;
        case 2: _t->on_adminLogButton_clicked(); break;
        case 3: _t->on_viewListWineriesButton_clicked(); break;
        case 4: _t->on_planDayTripButton_clicked(); break;
        case 5: _t->on_admin_log_ok_button_clicked(); break;
        case 6: _t->on_adming_log_cancel_button_clicked(); break;
        case 7: _t->on_admin_log_out_button_clicked(); break;
        case 8: _t->on_ViewBack_clicked(); break;
        case 9: _t->on_PlanTripBack_clicked(); break;
        case 10: _t->on_TourBack_clicked(); break;
        case 11: _t->on_LogInBack_clicked(); break;
        case 12: _t->on_passwordLine_returnPressed(); break;
        case 13: _t->on_visit_all_clicked(); break;
        case 14: _t->on_backToTripType_clicked(); break;
        case 15: _t->on_next_clicked(); break;
        case 16: _t->ShortestPath((*reinterpret_cast< QList<Winery>(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const Winery*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< QMap<int,Winery>*(*)>(_a[7]))); break;
        case 17: { Winery _r = _t->closestToVilla((*reinterpret_cast< QMap<int,Winery>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Winery*>(_a[0]) = _r; }  break;
        case 18: _t->on_shortest_trip_clicked(); break;
        case 19: _t->on_custom_trip_clicked(); break;
        case 20: _t->on_prev_winery_clicked(); break;
        case 21: _t->on_addToCart_clicked(); break;
        case 22: _t->on_goBack_clicked(); break;
        case 23: _t->on_wineryTable_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 24: _t->on_addNewWinery_clicked(); break;
        case 25: _t->on_pushButton_6_clicked(); break;
        case 26: _t->on_addNew_2_clicked(); break;
        case 27: _t->on_pushButton_7_clicked(); break;
        case 28: _t->on_pushButton_3_clicked(); break;
        case 29: _t->on_AddWineryButton_clicked(); break;
        case 30: _t->on_backAddWinery_clicked(); break;
        case 31: _t->on_AddWinesBack_clicked(); break;
        case 32: _t->on_pushButton_2_clicked(); break;
        case 33: _t->on_pushButton_4_clicked(); break;
        case 34: _t->on_pushButton_8_clicked(); break;
        case 35: _t->on_removeFromCart_clicked(); break;
        case 36: _t->on_AddWine_clicked(); break;
        case 37: _t->on_doneAddWine_clicked(); break;
        case 38: _t->on_NextToAddWine_clicked(); break;
        case 39: _t->on_BacktoAddWinery_clicked(); break;
        case 40: _t->on_startShortest_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 41;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
