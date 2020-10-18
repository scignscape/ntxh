/****************************************************************************
** Meta object code from reading C++ file 'XpdfViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/xk/external/xpdf/xpdf/xpdf-qt/XpdfViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XpdfViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XpdfMenuButton_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XpdfMenuButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XpdfMenuButton_t qt_meta_stringdata_XpdfMenuButton = {
    {
QT_MOC_LITERAL(0, 0, 14), // "XpdfMenuButton"
QT_MOC_LITERAL(1, 15, 10), // "btnPressed"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "XpdfMenuButton\0btnPressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XpdfMenuButton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void XpdfMenuButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XpdfMenuButton *_t = static_cast<XpdfMenuButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->btnPressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject XpdfMenuButton::staticMetaObject = { {
    &QToolButton::staticMetaObject,
    qt_meta_stringdata_XpdfMenuButton.data,
    qt_meta_data_XpdfMenuButton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *XpdfMenuButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XpdfMenuButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XpdfMenuButton.stringdata0))
        return static_cast<void*>(this);
    return QToolButton::qt_metacast(_clname);
}

int XpdfMenuButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_XpdfErrorWindow_t {
    QByteArrayData data[3];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XpdfErrorWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XpdfErrorWindow_t qt_meta_stringdata_XpdfErrorWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "XpdfErrorWindow"
QT_MOC_LITERAL(1, 16, 15), // "clearBtnPressed"
QT_MOC_LITERAL(2, 32, 0) // ""

    },
    "XpdfErrorWindow\0clearBtnPressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XpdfErrorWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void XpdfErrorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XpdfErrorWindow *_t = static_cast<XpdfErrorWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clearBtnPressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject XpdfErrorWindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_XpdfErrorWindow.data,
    qt_meta_data_XpdfErrorWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *XpdfErrorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XpdfErrorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XpdfErrorWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int XpdfErrorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_XpdfViewer_t {
    QByteArrayData data[70];
    char stringdata0[1174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XpdfViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XpdfViewer_t qt_meta_stringdata_XpdfViewer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "XpdfViewer"
QT_MOC_LITERAL(1, 11, 10), // "pdfResized"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "pdfPaintDone"
QT_MOC_LITERAL(4, 36, 8), // "finished"
QT_MOC_LITERAL(5, 45, 7), // "preLoad"
QT_MOC_LITERAL(6, 53, 8), // "postLoad"
QT_MOC_LITERAL(7, 62, 8), // "keyPress"
QT_MOC_LITERAL(8, 71, 10), // "QKeyEvent*"
QT_MOC_LITERAL(9, 82, 1), // "e"
QT_MOC_LITERAL(10, 84, 10), // "mousePress"
QT_MOC_LITERAL(11, 95, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 108, 12), // "mouseRelease"
QT_MOC_LITERAL(13, 121, 10), // "mouseWheel"
QT_MOC_LITERAL(14, 132, 12), // "QWheelEvent*"
QT_MOC_LITERAL(15, 145, 9), // "mouseMove"
QT_MOC_LITERAL(16, 155, 10), // "pageChange"
QT_MOC_LITERAL(17, 166, 2), // "pg"
QT_MOC_LITERAL(18, 169, 14), // "openMenuAction"
QT_MOC_LITERAL(19, 184, 22), // "openInNewWinMenuAction"
QT_MOC_LITERAL(20, 207, 16), // "reloadMenuAction"
QT_MOC_LITERAL(21, 224, 16), // "saveAsMenuAction"
QT_MOC_LITERAL(22, 241, 19), // "saveImageMenuAction"
QT_MOC_LITERAL(23, 261, 14), // "quitMenuAction"
QT_MOC_LITERAL(24, 276, 14), // "copyMenuAction"
QT_MOC_LITERAL(25, 291, 24), // "singlePageModeMenuAction"
QT_MOC_LITERAL(26, 316, 24), // "continuousModeMenuAction"
QT_MOC_LITERAL(27, 341, 30), // "sideBySideSingleModeMenuAction"
QT_MOC_LITERAL(28, 372, 34), // "sideBySideContinuousModeMenuA..."
QT_MOC_LITERAL(29, 407, 34), // "horizontalContinuousModeMenuA..."
QT_MOC_LITERAL(30, 442, 20), // "fullScreenMenuAction"
QT_MOC_LITERAL(31, 463, 7), // "checked"
QT_MOC_LITERAL(32, 471, 25), // "rotateClockwiseMenuAction"
QT_MOC_LITERAL(33, 497, 32), // "rotateCounterclockwiseMenuAction"
QT_MOC_LITERAL(34, 530, 25), // "zoomToSelectionMenuAction"
QT_MOC_LITERAL(35, 556, 16), // "newTabMenuAction"
QT_MOC_LITERAL(36, 573, 19), // "newWindowMenuAction"
QT_MOC_LITERAL(37, 593, 18), // "closeTabMenuAction"
QT_MOC_LITERAL(38, 612, 21), // "closeWindowMenuAction"
QT_MOC_LITERAL(39, 634, 25), // "openErrorWindowMenuAction"
QT_MOC_LITERAL(40, 660, 14), // "helpMenuAction"
QT_MOC_LITERAL(41, 675, 15), // "aboutMenuAction"
QT_MOC_LITERAL(42, 691, 15), // "popupMenuAction"
QT_MOC_LITERAL(43, 707, 3), // "idx"
QT_MOC_LITERAL(44, 711, 17), // "pageNumberChanged"
QT_MOC_LITERAL(45, 729, 17), // "backButtonPressed"
QT_MOC_LITERAL(46, 747, 20), // "forwardButtonPressed"
QT_MOC_LITERAL(47, 768, 20), // "zoomOutButtonPressed"
QT_MOC_LITERAL(48, 789, 19), // "zoomInButtonPressed"
QT_MOC_LITERAL(49, 809, 16), // "zoomIndexChanged"
QT_MOC_LITERAL(50, 826, 8), // "zoomText"
QT_MOC_LITERAL(51, 835, 19), // "zoomEditingFinished"
QT_MOC_LITERAL(52, 855, 21), // "fitWidthButtonPressed"
QT_MOC_LITERAL(53, 877, 20), // "fitPageButtonPressed"
QT_MOC_LITERAL(54, 898, 23), // "selectModeButtonPressed"
QT_MOC_LITERAL(55, 922, 22), // "statusIndicatorPressed"
QT_MOC_LITERAL(56, 945, 15), // "findTextChanged"
QT_MOC_LITERAL(57, 961, 21), // "findNextButtonPressed"
QT_MOC_LITERAL(58, 983, 21), // "findPrevButtonPressed"
QT_MOC_LITERAL(59, 1005, 19), // "newTabButtonPressed"
QT_MOC_LITERAL(60, 1025, 9), // "switchTab"
QT_MOC_LITERAL(61, 1035, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(62, 1052, 7), // "current"
QT_MOC_LITERAL(63, 1060, 8), // "previous"
QT_MOC_LITERAL(64, 1069, 19), // "infoComboBoxChanged"
QT_MOC_LITERAL(65, 1089, 18), // "outlineItemClicked"
QT_MOC_LITERAL(66, 1108, 11), // "QModelIndex"
QT_MOC_LITERAL(67, 1120, 16), // "layerItemClicked"
QT_MOC_LITERAL(68, 1137, 21), // "attachmentSaveClicked"
QT_MOC_LITERAL(69, 1159, 14) // "clearFindError"

    },
    "XpdfViewer\0pdfResized\0\0pdfPaintDone\0"
    "finished\0preLoad\0postLoad\0keyPress\0"
    "QKeyEvent*\0e\0mousePress\0QMouseEvent*\0"
    "mouseRelease\0mouseWheel\0QWheelEvent*\0"
    "mouseMove\0pageChange\0pg\0openMenuAction\0"
    "openInNewWinMenuAction\0reloadMenuAction\0"
    "saveAsMenuAction\0saveImageMenuAction\0"
    "quitMenuAction\0copyMenuAction\0"
    "singlePageModeMenuAction\0"
    "continuousModeMenuAction\0"
    "sideBySideSingleModeMenuAction\0"
    "sideBySideContinuousModeMenuAction\0"
    "horizontalContinuousModeMenuAction\0"
    "fullScreenMenuAction\0checked\0"
    "rotateClockwiseMenuAction\0"
    "rotateCounterclockwiseMenuAction\0"
    "zoomToSelectionMenuAction\0newTabMenuAction\0"
    "newWindowMenuAction\0closeTabMenuAction\0"
    "closeWindowMenuAction\0openErrorWindowMenuAction\0"
    "helpMenuAction\0aboutMenuAction\0"
    "popupMenuAction\0idx\0pageNumberChanged\0"
    "backButtonPressed\0forwardButtonPressed\0"
    "zoomOutButtonPressed\0zoomInButtonPressed\0"
    "zoomIndexChanged\0zoomText\0zoomEditingFinished\0"
    "fitWidthButtonPressed\0fitPageButtonPressed\0"
    "selectModeButtonPressed\0statusIndicatorPressed\0"
    "findTextChanged\0findNextButtonPressed\0"
    "findPrevButtonPressed\0newTabButtonPressed\0"
    "switchTab\0QListWidgetItem*\0current\0"
    "previous\0infoComboBoxChanged\0"
    "outlineItemClicked\0QModelIndex\0"
    "layerItemClicked\0attachmentSaveClicked\0"
    "clearFindError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XpdfViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  289,    2, 0x08 /* Private */,
       3,    1,  290,    2, 0x08 /* Private */,
       5,    0,  293,    2, 0x08 /* Private */,
       6,    0,  294,    2, 0x08 /* Private */,
       7,    1,  295,    2, 0x08 /* Private */,
      10,    1,  298,    2, 0x08 /* Private */,
      12,    1,  301,    2, 0x08 /* Private */,
      13,    1,  304,    2, 0x08 /* Private */,
      15,    1,  307,    2, 0x08 /* Private */,
      16,    1,  310,    2, 0x08 /* Private */,
      18,    0,  313,    2, 0x08 /* Private */,
      19,    0,  314,    2, 0x08 /* Private */,
      20,    0,  315,    2, 0x08 /* Private */,
      21,    0,  316,    2, 0x08 /* Private */,
      22,    0,  317,    2, 0x08 /* Private */,
      23,    0,  318,    2, 0x08 /* Private */,
      24,    0,  319,    2, 0x08 /* Private */,
      25,    0,  320,    2, 0x08 /* Private */,
      26,    0,  321,    2, 0x08 /* Private */,
      27,    0,  322,    2, 0x08 /* Private */,
      28,    0,  323,    2, 0x08 /* Private */,
      29,    0,  324,    2, 0x08 /* Private */,
      30,    1,  325,    2, 0x08 /* Private */,
      32,    0,  328,    2, 0x08 /* Private */,
      33,    0,  329,    2, 0x08 /* Private */,
      34,    0,  330,    2, 0x08 /* Private */,
      35,    0,  331,    2, 0x08 /* Private */,
      36,    0,  332,    2, 0x08 /* Private */,
      37,    0,  333,    2, 0x08 /* Private */,
      38,    0,  334,    2, 0x08 /* Private */,
      39,    0,  335,    2, 0x08 /* Private */,
      40,    0,  336,    2, 0x08 /* Private */,
      41,    0,  337,    2, 0x08 /* Private */,
      42,    1,  338,    2, 0x08 /* Private */,
      44,    0,  341,    2, 0x08 /* Private */,
      45,    0,  342,    2, 0x08 /* Private */,
      46,    0,  343,    2, 0x08 /* Private */,
      47,    0,  344,    2, 0x08 /* Private */,
      48,    0,  345,    2, 0x08 /* Private */,
      49,    1,  346,    2, 0x08 /* Private */,
      51,    0,  349,    2, 0x08 /* Private */,
      52,    0,  350,    2, 0x08 /* Private */,
      53,    0,  351,    2, 0x08 /* Private */,
      54,    0,  352,    2, 0x08 /* Private */,
      55,    0,  353,    2, 0x08 /* Private */,
      56,    0,  354,    2, 0x08 /* Private */,
      57,    0,  355,    2, 0x08 /* Private */,
      58,    0,  356,    2, 0x08 /* Private */,
      59,    0,  357,    2, 0x08 /* Private */,
      60,    2,  358,    2, 0x08 /* Private */,
      64,    1,  363,    2, 0x08 /* Private */,
      65,    1,  366,    2, 0x08 /* Private */,
      67,    1,  369,    2, 0x08 /* Private */,
      68,    1,  372,    2, 0x08 /* Private */,
      69,    0,  375,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, 0x80000000 | 14,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, QMetaType::Int,   17,
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
    QMetaType::Void, QMetaType::Bool,   31,
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
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 61, 0x80000000 | 61,   62,   63,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, 0x80000000 | 66,   43,
    QMetaType::Void, 0x80000000 | 66,   43,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,

       0        // eod
};

void XpdfViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XpdfViewer *_t = static_cast<XpdfViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pdfResized(); break;
        case 1: _t->pdfPaintDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->preLoad(); break;
        case 3: _t->postLoad(); break;
        case 4: _t->keyPress((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 5: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseWheel((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 8: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: _t->pageChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->openMenuAction(); break;
        case 11: _t->openInNewWinMenuAction(); break;
        case 12: _t->reloadMenuAction(); break;
        case 13: _t->saveAsMenuAction(); break;
        case 14: _t->saveImageMenuAction(); break;
        case 15: _t->quitMenuAction(); break;
        case 16: _t->copyMenuAction(); break;
        case 17: _t->singlePageModeMenuAction(); break;
        case 18: _t->continuousModeMenuAction(); break;
        case 19: _t->sideBySideSingleModeMenuAction(); break;
        case 20: _t->sideBySideContinuousModeMenuAction(); break;
        case 21: _t->horizontalContinuousModeMenuAction(); break;
        case 22: _t->fullScreenMenuAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->rotateClockwiseMenuAction(); break;
        case 24: _t->rotateCounterclockwiseMenuAction(); break;
        case 25: _t->zoomToSelectionMenuAction(); break;
        case 26: _t->newTabMenuAction(); break;
        case 27: _t->newWindowMenuAction(); break;
        case 28: _t->closeTabMenuAction(); break;
        case 29: _t->closeWindowMenuAction(); break;
        case 30: _t->openErrorWindowMenuAction(); break;
        case 31: _t->helpMenuAction(); break;
        case 32: _t->aboutMenuAction(); break;
        case 33: _t->popupMenuAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->pageNumberChanged(); break;
        case 35: _t->backButtonPressed(); break;
        case 36: _t->forwardButtonPressed(); break;
        case 37: _t->zoomOutButtonPressed(); break;
        case 38: _t->zoomInButtonPressed(); break;
        case 39: _t->zoomIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->zoomEditingFinished(); break;
        case 41: _t->fitWidthButtonPressed(); break;
        case 42: _t->fitPageButtonPressed(); break;
        case 43: _t->selectModeButtonPressed(); break;
        case 44: _t->statusIndicatorPressed(); break;
        case 45: _t->findTextChanged(); break;
        case 46: _t->findNextButtonPressed(); break;
        case 47: _t->findPrevButtonPressed(); break;
        case 48: _t->newTabButtonPressed(); break;
        case 49: _t->switchTab((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 50: _t->infoComboBoxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: _t->outlineItemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 52: _t->layerItemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 53: _t->attachmentSaveClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->clearFindError(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject XpdfViewer::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_XpdfViewer.data,
    qt_meta_data_XpdfViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *XpdfViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XpdfViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XpdfViewer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int XpdfViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 55;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
