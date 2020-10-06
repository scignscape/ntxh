/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/xk/facs/facs-gui/facs-gui/gui/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[13];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "actionOpenProject"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "actionNewProject"
QT_MOC_LITERAL(4, 47, 15), // "actionDsChanged"
QT_MOC_LITERAL(5, 63, 11), // "actionAbout"
QT_MOC_LITERAL(6, 75, 13), // "actionWebsite"
QT_MOC_LITERAL(7, 89, 17), // "actionSetNumCores"
QT_MOC_LITERAL(8, 107, 17), // "actionSaveProject"
QT_MOC_LITERAL(9, 125, 19), // "actionSaveProjectAs"
QT_MOC_LITERAL(10, 145, 18), // "actionExportGraphs"
QT_MOC_LITERAL(11, 164, 22), // "actionExportStatistics"
QT_MOC_LITERAL(12, 187, 15) // "actionExportCSV"

    },
    "MainWindow\0actionOpenProject\0\0"
    "actionNewProject\0actionDsChanged\0"
    "actionAbout\0actionWebsite\0actionSetNumCores\0"
    "actionSaveProject\0actionSaveProjectAs\0"
    "actionExportGraphs\0actionExportStatistics\0"
    "actionExportCSV"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actionOpenProject(); break;
        case 1: _t->actionNewProject(); break;
        case 2: _t->actionDsChanged(); break;
        case 3: _t->actionAbout(); break;
        case 4: _t->actionWebsite(); break;
        case 5: _t->actionSetNumCores(); break;
        case 6: _t->actionSaveProject(); break;
        case 7: _t->actionSaveProjectAs(); break;
        case 8: _t->actionExportGraphs(); break;
        case 9: _t->actionExportStatistics(); break;
        case 10: _t->actionExportCSV(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
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
struct qt_meta_stringdata__MainWindow_GateCalcThread_t {
    QByteArrayData data[4];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata__MainWindow_GateCalcThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata__MainWindow_GateCalcThread_t qt_meta_stringdata__MainWindow_GateCalcThread = {
    {
QT_MOC_LITERAL(0, 0, 26), // "_MainWindow_GateCalcThread"
QT_MOC_LITERAL(1, 27, 23), // "callbackDoneCalc_signal"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 8) // "Dataset*"

    },
    "_MainWindow_GateCalcThread\0"
    "callbackDoneCalc_signal\0\0Dataset*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data__MainWindow_GateCalcThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void _MainWindow_GateCalcThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<_MainWindow_GateCalcThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->callbackDoneCalc_signal((*reinterpret_cast< Dataset*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (_MainWindow_GateCalcThread::*)(Dataset * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&_MainWindow_GateCalcThread::callbackDoneCalc_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject _MainWindow_GateCalcThread::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata__MainWindow_GateCalcThread.data,
    qt_meta_data__MainWindow_GateCalcThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *_MainWindow_GateCalcThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *_MainWindow_GateCalcThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata__MainWindow_GateCalcThread.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "GateCalcThread"))
        return static_cast< GateCalcThread*>(this);
    return QObject::qt_metacast(_clname);
}

int _MainWindow_GateCalcThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void _MainWindow_GateCalcThread::callbackDoneCalc_signal(Dataset * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
