/****************************************************************************
** Meta object code from reading C++ file 'download_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QSimpleUpdater/src/dialogs/download_dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'download_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   30,   30,   30, 0x08,
      31,   30,   30,   30, 0x08,
      43,   30,   30,   30, 0x08,
      59,   30,   30,   30, 0x08,
      76,   30,   30,   30, 0x08,
      95,  144,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DownloadDialog[] = {
    "DownloadDialog\0openDownload()\0\0"
    "copyFiles()\0installUpdate()\0"
    "cancelDownload()\0downloadFinished()\0"
    "ignoreSslErrors(QNetworkReply*,QList<QSslError>)\0"
    "reply,error\0"
};

void DownloadDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DownloadDialog *_t = static_cast<DownloadDialog *>(_o);
        switch (_id) {
        case 0: _t->openDownload(); break;
        case 1: _t->copyFiles(); break;
        case 2: _t->installUpdate(); break;
        case 3: _t->cancelDownload(); break;
        case 4: _t->downloadFinished(); break;
        case 5: _t->ignoreSslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DownloadDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DownloadDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DownloadDialog,
      qt_meta_data_DownloadDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownloadDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownloadDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownloadDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadDialog))
        return static_cast<void*>(const_cast< DownloadDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int DownloadDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
