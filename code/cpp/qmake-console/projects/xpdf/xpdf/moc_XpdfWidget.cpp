/****************************************************************************
** Meta object code from reading C++ file 'XpdfWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/xk/external/xpdf/xpdf/xpdf-qt/XpdfWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XpdfWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XpdfWidget_t {
    QByteArrayData data[26];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XpdfWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XpdfWidget_t qt_meta_stringdata_XpdfWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "XpdfWidget"
QT_MOC_LITERAL(1, 11, 10), // "pageChange"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "pageNum"
QT_MOC_LITERAL(4, 31, 13), // "midPageChange"
QT_MOC_LITERAL(5, 45, 7), // "preLoad"
QT_MOC_LITERAL(6, 53, 8), // "postLoad"
QT_MOC_LITERAL(7, 62, 8), // "keyPress"
QT_MOC_LITERAL(8, 71, 10), // "QKeyEvent*"
QT_MOC_LITERAL(9, 82, 1), // "e"
QT_MOC_LITERAL(10, 84, 10), // "mousePress"
QT_MOC_LITERAL(11, 95, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 108, 12), // "mouseRelease"
QT_MOC_LITERAL(13, 121, 9), // "mouseMove"
QT_MOC_LITERAL(14, 131, 10), // "mouseWheel"
QT_MOC_LITERAL(15, 142, 12), // "QWheelEvent*"
QT_MOC_LITERAL(16, 155, 9), // "linkClick"
QT_MOC_LITERAL(17, 165, 8), // "linkType"
QT_MOC_LITERAL(18, 174, 4), // "dest"
QT_MOC_LITERAL(19, 179, 4), // "page"
QT_MOC_LITERAL(20, 184, 10), // "selectDone"
QT_MOC_LITERAL(21, 195, 9), // "paintDone"
QT_MOC_LITERAL(22, 205, 8), // "finished"
QT_MOC_LITERAL(23, 214, 7), // "resized"
QT_MOC_LITERAL(24, 222, 8), // "tileDone"
QT_MOC_LITERAL(25, 231, 4) // "tick"

    },
    "XpdfWidget\0pageChange\0\0pageNum\0"
    "midPageChange\0preLoad\0postLoad\0keyPress\0"
    "QKeyEvent*\0e\0mousePress\0QMouseEvent*\0"
    "mouseRelease\0mouseMove\0mouseWheel\0"
    "QWheelEvent*\0linkClick\0linkType\0dest\0"
    "page\0selectDone\0paintDone\0finished\0"
    "resized\0tileDone\0tick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XpdfWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    0,   95,    2, 0x06 /* Public */,
       6,    0,   96,    2, 0x06 /* Public */,
       7,    1,   97,    2, 0x06 /* Public */,
      10,    1,  100,    2, 0x06 /* Public */,
      12,    1,  103,    2, 0x06 /* Public */,
      13,    1,  106,    2, 0x06 /* Public */,
      14,    1,  109,    2, 0x06 /* Public */,
      16,    3,  112,    2, 0x06 /* Public */,
      20,    0,  119,    2, 0x06 /* Public */,
      21,    1,  120,    2, 0x06 /* Public */,
      23,    0,  123,    2, 0x06 /* Public */,
      24,    0,  124,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, 0x80000000 | 15,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   17,   18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void XpdfWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XpdfWidget *_t = static_cast<XpdfWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pageChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->midPageChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->preLoad(); break;
        case 3: _t->postLoad(); break;
        case 4: _t->keyPress((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 5: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->mouseWheel((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 9: _t->linkClick((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->selectDone(); break;
        case 11: _t->paintDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->resized(); break;
        case 13: _t->tileDone(); break;
        case 14: _t->tick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (XpdfWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::pageChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::midPageChange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::preLoad)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::postLoad)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)(QKeyEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::keyPress)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::mousePress)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::mouseRelease)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::mouseMove)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)(QWheelEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::mouseWheel)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)(const QString & , const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::linkClick)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::selectDone)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::paintDone)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::resized)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (XpdfWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XpdfWidget::tileDone)) {
                *result = 13;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject XpdfWidget::staticMetaObject = { {
    &QAbstractScrollArea::staticMetaObject,
    qt_meta_stringdata_XpdfWidget.data,
    qt_meta_data_XpdfWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *XpdfWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XpdfWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XpdfWidget.stringdata0))
        return static_cast<void*>(this);
    return QAbstractScrollArea::qt_metacast(_clname);
}

int XpdfWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void XpdfWidget::pageChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XpdfWidget::midPageChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XpdfWidget::preLoad()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void XpdfWidget::postLoad()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void XpdfWidget::keyPress(QKeyEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void XpdfWidget::mousePress(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void XpdfWidget::mouseRelease(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void XpdfWidget::mouseMove(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void XpdfWidget::mouseWheel(QWheelEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void XpdfWidget::linkClick(const QString & _t1, const QString & _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void XpdfWidget::selectDone()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void XpdfWidget::paintDone(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void XpdfWidget::resized()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void XpdfWidget::tileDone()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
