/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 33), // "on_findPasswordPushButton_cli..."
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 35), // "on_createPasswordPushButton_c..."
QT_MOC_LITERAL(4, 82, 29), // "on_printAllPushButton_clicked"
QT_MOC_LITERAL(5, 112, 12), // "saveDataSlot"
QT_MOC_LITERAL(6, 125, 12), // "openDataSlot"
QT_MOC_LITERAL(7, 138, 14), // "createNameSlot"
QT_MOC_LITERAL(8, 153, 12), // "checkPinSlot"
QT_MOC_LITERAL(9, 166, 13), // "createPinSlot"
QT_MOC_LITERAL(10, 180, 12), // "wrongPinSlot"
QT_MOC_LITERAL(11, 193, 18), // "createPasswordSlot"
QT_MOC_LITERAL(12, 212, 5), // "myKey"
QT_MOC_LITERAL(13, 218, 7), // "myLogin"
QT_MOC_LITERAL(14, 226, 10), // "myPassword"
QT_MOC_LITERAL(15, 237, 20), // "generatePasswordSlot"
QT_MOC_LITERAL(16, 258, 16), // "showPasswordSlot"
QT_MOC_LITERAL(17, 275, 30), // "on_changePinPushButton_clicked"
QT_MOC_LITERAL(18, 306, 35), // "on_deletePasswordPushButton_c..."
QT_MOC_LITERAL(19, 342, 12) // "oldToNewSlot"

    },
    "MainWindow\0on_findPasswordPushButton_clicked\0"
    "\0on_createPasswordPushButton_clicked\0"
    "on_printAllPushButton_clicked\0"
    "saveDataSlot\0openDataSlot\0createNameSlot\0"
    "checkPinSlot\0createPinSlot\0wrongPinSlot\0"
    "createPasswordSlot\0myKey\0myLogin\0"
    "myPassword\0generatePasswordSlot\0"
    "showPasswordSlot\0on_changePinPushButton_clicked\0"
    "on_deletePasswordPushButton_clicked\0"
    "oldToNewSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    3,  108,    2, 0x08 /* Private */,
      11,    2,  115,    2, 0x28 /* Private | MethodCloned */,
      11,    1,  120,    2, 0x28 /* Private | MethodCloned */,
      15,    0,  123,    2, 0x08 /* Private */,
      16,    0,  124,    2, 0x08 /* Private */,
      17,    0,  125,    2, 0x08 /* Private */,
      18,    0,  126,    2, 0x08 /* Private */,
      19,    0,  127,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_findPasswordPushButton_clicked(); break;
        case 1: _t->on_createPasswordPushButton_clicked(); break;
        case 2: _t->on_printAllPushButton_clicked(); break;
        case 3: _t->saveDataSlot(); break;
        case 4: _t->openDataSlot(); break;
        case 5: { QString _r = _t->createNameSlot();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->checkPinSlot(); break;
        case 7: _t->createPinSlot(); break;
        case 8: _t->wrongPinSlot(); break;
        case 9: _t->createPasswordSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 10: _t->createPasswordSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->createPasswordSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: { QString _r = _t->generatePasswordSlot();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->showPasswordSlot(); break;
        case 14: _t->on_changePinPushButton_clicked(); break;
        case 15: _t->on_deletePasswordPushButton_clicked(); break;
        case 16: _t->oldToNewSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
