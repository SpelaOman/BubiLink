/****************************************************************************
** Meta object code from reading C++ file 'addlink.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addlink.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addlink.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddLink[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,    8,    8,    8, 0x08,
      51,    8,    8,    8, 0x08,
      75,    8,    8,    8, 0x08,
      99,    8,    8,    8, 0x08,
     133,    8,    8,    8, 0x08,
     161,    8,    8,    8, 0x08,
     189,    8,    8,    8, 0x08,
     218,    8,    8,    8, 0x08,
     235,  232,    8,    8, 0x08,
     254,    8,    8,    8, 0x08,
     287,  277,    8,    8, 0x08,
     305,    8,    8,    8, 0x08,
     330,  325,  317,    8, 0x08,
     356,    8,    8,    8, 0x08,
     370,    8,    8,    8, 0x08,
     384,    8,    8,    8, 0x08,
     391,    8,    8,    8, 0x08,
     404,    9,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddLink[] = {
    "AddLink\0\0state\0send(QString)\0"
    "on_btn_save_clicked()\0on_btn_create_clicked()\0"
    "on_btn_delete_clicked()\0"
    "on_txt_original_url_textChanged()\0"
    "on_txt_medium_textChanged()\0"
    "on_txt_source_textChanged()\0"
    "on_txt_content_textChanged()\0fill_fields()\0"
    "id\0show_data(QString)\0introduce_completers()\0"
    "zaporedna\0randomizator(int)\0generator()\0"
    "QString\0word\0string_sanitizer(QString)\0"
    "save_source()\0save_medium()\0save()\0"
    "create_url()\0recieve(QString)\0"
};

void AddLink::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddLink *_t = static_cast<AddLink *>(_o);
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_btn_save_clicked(); break;
        case 2: _t->on_btn_create_clicked(); break;
        case 3: _t->on_btn_delete_clicked(); break;
        case 4: _t->on_txt_original_url_textChanged(); break;
        case 5: _t->on_txt_medium_textChanged(); break;
        case 6: _t->on_txt_source_textChanged(); break;
        case 7: _t->on_txt_content_textChanged(); break;
        case 8: _t->fill_fields(); break;
        case 9: _t->show_data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->introduce_completers(); break;
        case 11: _t->randomizator((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->generator(); break;
        case 13: { QString _r = _t->string_sanitizer((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: _t->save_source(); break;
        case 15: _t->save_medium(); break;
        case 16: _t->save(); break;
        case 17: _t->create_url(); break;
        case 18: _t->recieve((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddLink::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddLink::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddLink,
      qt_meta_data_AddLink, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddLink::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddLink::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddLink::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddLink))
        return static_cast<void*>(const_cast< AddLink*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddLink::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void AddLink::send(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
