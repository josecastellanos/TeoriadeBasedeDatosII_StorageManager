/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Sep 18 18:38:36 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StorageManager/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      58,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     189,   11,   11,   11, 0x08,
     215,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     263,   11,   11,   11, 0x08,
     287,   11,   11,   11, 0x08,
     311,   11,   11,   11, 0x08,
     338,   11,   11,   11, 0x08,
     364,   11,   11,   11, 0x08,
     389,   11,   11,   11, 0x08,
     416,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_btnCrear_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_btnCrear_2_clicked()\0on_btnCrear_3_clicked()\0"
    "on_btnCrear_4_clicked()\0on_btnCrear_5_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_btnCrear_16_clicked()\0"
    "on_pushButton_34_clicked()\0"
    "on_pushButton_8_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btnCrear_clicked(); break;
        case 1: on_pushButton_clicked(); break;
        case 2: on_pushButton_2_clicked(); break;
        case 3: on_pushButton_3_clicked(); break;
        case 4: on_pushButton_4_clicked(); break;
        case 5: on_pushButton_5_clicked(); break;
        case 6: on_pushButton_10_clicked(); break;
        case 7: on_pushButton_6_clicked(); break;
        case 8: on_btnCrear_2_clicked(); break;
        case 9: on_btnCrear_3_clicked(); break;
        case 10: on_btnCrear_4_clicked(); break;
        case 11: on_btnCrear_5_clicked(); break;
        case 12: on_pushButton_11_clicked(); break;
        case 13: on_pushButton_7_clicked(); break;
        case 14: on_btnCrear_16_clicked(); break;
        case 15: on_pushButton_34_clicked(); break;
        case 16: on_pushButton_8_clicked(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
