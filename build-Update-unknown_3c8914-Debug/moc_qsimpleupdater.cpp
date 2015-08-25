/****************************************************************************
** Meta object code from reading C++ file 'qsimpleupdater.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QSimpleUpdater/src/qsimpleupdater.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsimpleupdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSimpleUpdater[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   34,   34,   34, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   60,   34,   34, 0x0a,
      64,   60,   34,   34, 0x0a,
      89,  125,   34,   34, 0x0a,
     130,  161,   34,   34, 0x0a,
     169,   34,   34,   34, 0x08,
     178,   34,   34,   34, 0x08,
     197,   34,   34,   34, 0x08,
     218,   34,   34,   34, 0x08,
     242,   34,  258,   34, 0x08,
     266,   34,  258,   34, 0x08,
     285,   34,  309,   34, 0x08,
     314,  353,   34,   34, 0x08,
     359,  353,   34,   34, 0x08,
     402,  451,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QSimpleUpdater[] = {
    "QSimpleUpdater\0checkingFinished()\0\0"
    "setReferenceUrl(QString)\0url\0"
    "setChangelogUrl(QString)\0"
    "setShowUpdateAvailableMessage(bool)\0"
    "show\0setApplicationVersion(QString)\0"
    "version\0cancel()\0showErrorMessage()\0"
    "onCheckingFinished()\0downloadLatestVersion()\0"
    "latestVersion()\0QString\0installedVersion()\0"
    "newerVersionAvailable()\0bool\0"
    "checkDownloadedVersion(QNetworkReply*)\0"
    "reply\0processDownloadedChangelog(QNetworkReply*)\0"
    "ignoreSslErrors(QNetworkReply*,QList<QSslError>)\0"
    "reply,error\0"
};

void QSimpleUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSimpleUpdater *_t = static_cast<QSimpleUpdater *>(_o);
        switch (_id) {
        case 0: _t->checkingFinished(); break;
        case 1: _t->setReferenceUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setChangelogUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setShowUpdateAvailableMessage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setApplicationVersion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->cancel(); break;
        case 6: _t->showErrorMessage(); break;
        case 7: _t->onCheckingFinished(); break;
        case 8: _t->downloadLatestVersion(); break;
        case 9: { QString _r = _t->latestVersion();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { QString _r = _t->installedVersion();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->newerVersionAvailable();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->checkDownloadedVersion((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 13: _t->processDownloadedChangelog((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 14: _t->ignoreSslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSimpleUpdater::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSimpleUpdater::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSimpleUpdater,
      qt_meta_data_QSimpleUpdater, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSimpleUpdater::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSimpleUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSimpleUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSimpleUpdater))
        return static_cast<void*>(const_cast< QSimpleUpdater*>(this));
    return QObject::qt_metacast(_clname);
}

int QSimpleUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void QSimpleUpdater::checkingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
