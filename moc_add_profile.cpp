/****************************************************************************
** Meta object code from reading C++ file 'add_profile.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "add_profile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'add_profile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_add_profile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   12,   12,   12, 0x08,
      55,   12,   12,   12, 0x08,
      79,   12,   12,   12, 0x08,
      93,   13,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_add_profile[] = {
    "add_profile\0\0state\0send(QString)\0"
    "on_btn_save_clicked()\0on_btn_delete_clicked()\0"
    "fill_fields()\0recieve(QString)\0"
};

void add_profile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        add_profile *_t = static_cast<add_profile *>(_o);
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_btn_save_clicked(); break;
        case 2: _t->on_btn_delete_clicked(); break;
        case 3: _t->fill_fields(); break;
        case 4: _t->recieve((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData add_profile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject add_profile::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_add_profile,
      qt_meta_data_add_profile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &add_profile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *add_profile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *add_profile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_add_profile))
        return static_cast<void*>(const_cast< add_profile*>(this));
    return QWidget::qt_metacast(_clname);
}

int add_profile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void add_profile::send(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
