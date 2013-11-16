/****************************************************************************
** Meta object code from reading C++ file 'laptimenotifier.h'
**
** Created: Sat Nov 16 21:07:44 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "laptimenotifier.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'laptimenotifier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LaptimeNotifier[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LaptimeNotifier[] = {
    "LaptimeNotifier\0\0lane,time\0"
    "sig_new_lap(int,double)\0parseData()\0"
};

void LaptimeNotifier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LaptimeNotifier *_t = static_cast<LaptimeNotifier *>(_o);
        switch (_id) {
        case 0: _t->sig_new_lap((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->parseData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LaptimeNotifier::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LaptimeNotifier::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_LaptimeNotifier,
      qt_meta_data_LaptimeNotifier, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LaptimeNotifier::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LaptimeNotifier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LaptimeNotifier::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LaptimeNotifier))
        return static_cast<void*>(const_cast< LaptimeNotifier*>(this));
    return QThread::qt_metacast(_clname);
}

int LaptimeNotifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void LaptimeNotifier::sig_new_lap(int _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
