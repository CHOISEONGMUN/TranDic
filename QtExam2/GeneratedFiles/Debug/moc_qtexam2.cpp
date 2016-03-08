/****************************************************************************
** Meta object code from reading C++ file 'qtexam2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtexam2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtexam2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InfoDlg_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InfoDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InfoDlg_t qt_meta_stringdata_InfoDlg = {
    {
QT_MOC_LITERAL(0, 0, 7) // "InfoDlg"

    },
    "InfoDlg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfoDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void InfoDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject InfoDlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InfoDlg.data,
      qt_meta_data_InfoDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InfoDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfoDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InfoDlg.stringdata0))
        return static_cast<void*>(const_cast< InfoDlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int InfoDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_SettingDlg_t {
    QByteArrayData data[6];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingDlg_t qt_meta_stringdata_SettingDlg = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SettingDlg"
QT_MOC_LITERAL(1, 11, 10), // "ok_clicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "checked"
QT_MOC_LITERAL(4, 31, 14), // "cancel_clicked"
QT_MOC_LITERAL(5, 46, 11) // "set_clicked"

    },
    "SettingDlg\0ok_clicked\0\0checked\0"
    "cancel_clicked\0set_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingDlg[] = {

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
       1,    0,   47,    2, 0x28 /* Private | MethodCloned */,
       4,    1,   48,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x28 /* Private | MethodCloned */,
       5,    1,   52,    2, 0x08 /* Private */,
       5,    0,   55,    2, 0x28 /* Private | MethodCloned */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

       0        // eod
};

void SettingDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingDlg *_t = static_cast<SettingDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ok_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ok_clicked(); break;
        case 2: _t->cancel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->cancel_clicked(); break;
        case 4: _t->set_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->set_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SettingDlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SettingDlg.data,
      qt_meta_data_SettingDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SettingDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SettingDlg.stringdata0))
        return static_cast<void*>(const_cast< SettingDlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int SettingDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_RightMenu_t {
    QByteArrayData data[5];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RightMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RightMenu_t qt_meta_stringdata_RightMenu = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RightMenu"
QT_MOC_LITERAL(1, 10, 14), // "exit_triggered"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "info_triggered"
QT_MOC_LITERAL(4, 41, 17) // "setting_triggered"

    },
    "RightMenu\0exit_triggered\0\0info_triggered\0"
    "setting_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RightMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RightMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RightMenu *_t = static_cast<RightMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exit_triggered(); break;
        case 1: _t->info_triggered(); break;
        case 2: _t->setting_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RightMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_RightMenu.data,
      qt_meta_data_RightMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RightMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RightMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RightMenu.stringdata0))
        return static_cast<void*>(const_cast< RightMenu*>(this));
    return QMenu::qt_metacast(_clname);
}

int RightMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_QtExam2_t {
    QByteArrayData data[6];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtExam2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtExam2_t qt_meta_stringdata_QtExam2 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QtExam2"
QT_MOC_LITERAL(1, 8, 13), // "replyFinished"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 38, 11), // "changedSlot"
QT_MOC_LITERAL(5, 50, 16) // "QClipboard::Mode"

    },
    "QtExam2\0replyFinished\0\0QNetworkReply*\0"
    "changedSlot\0QClipboard::Mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtExam2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void QtExam2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtExam2 *_t = static_cast<QtExam2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->changedSlot((*reinterpret_cast< QClipboard::Mode(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject QtExam2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtExam2.data,
      qt_meta_data_QtExam2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtExam2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtExam2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtExam2.stringdata0))
        return static_cast<void*>(const_cast< QtExam2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QtExam2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
