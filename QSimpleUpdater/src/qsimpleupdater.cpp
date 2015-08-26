/*
 * (C) Copyright 2014 Alex Spataru
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 */

#include "qsimpleupdater.h"
#include <QtScript/QScriptEngine>
#include <Qtscript/qscriptvalueiterator.h>

QSimpleUpdater::QSimpleUpdater (QObject *parent)
    : QObject (parent)
    , m_download_count(0)
    , m_silent(false)
    , m_new_version_available (false)
{
    m_downloadDialog = new DownloadDialog();

    m_manager = new QNetworkAccessManager (this);
    connect (this, SIGNAL (checkingFinished()), this, SLOT (onCheckingFinished()));
}

void QSimpleUpdater::checkForUpdates (bool silent)
{
    m_silent = silent;
    QFile file(QCoreApplication::applicationDirPath()+"/version.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox _message;
        _message.setWindowTitle (tr ("错误"));
        _message.setIcon (QMessageBox::Critical);
        _message.setStandardButtons (QMessageBox::Ok);
        _message.setText(tr("找不到版本文件!"));
        _message.exec();
        return;
    }
    QTextStream in(&file);
    QString versionString;
    in>>versionString;
    file.close();

    m_installed_version = versionString.right(versionString.length()-versionString.lastIndexOf('=')-1);

    if (!m_reference_url.isEmpty())
    {
        connect (m_manager, SIGNAL (finished (QNetworkReply *)), this,
                 SLOT (checkDownloadedVersion (QNetworkReply *)));
        m_manager->get (QNetworkRequest (m_reference_url));
    }

    else
        qDebug() << "QSimpleUpdater: Invalid reference URL";
}

QString QSimpleUpdater::latestVersion() const
{
    return m_latest_version;
}


QString QSimpleUpdater::installedVersion() const
{
    return m_installed_version;
}

void QSimpleUpdater::downloadLatestVersion (void)
{
    if (!m_download_urlList.isEmpty())
    {
        connect(m_downloadDialog, SIGNAL(finished(bool)), this, SLOT(finished(bool)));
        m_downloadDialog->beginDownload (m_download_urlList, m_latest_version);
    }
}

void QSimpleUpdater::finished(bool success)
{
    emit downloadFinished(success);
}

bool QSimpleUpdater::newerVersionAvailable() const
{
    return m_new_version_available;
}

void QSimpleUpdater::setReferenceUrl (const QString& url)
{
    Q_ASSERT (!url.isEmpty());
    m_reference_url.setUrl (url);
}

void QSimpleUpdater::cancel (void)
{
    m_manager->disconnect();
    emit checkingFinished();
}

void QSimpleUpdater::onCheckingFinished (void)
{
    QPixmap _icon = qApp->windowIcon().pixmap (
                        qApp->windowIcon().actualSize (QSize (96, 96)));
    if (_icon.isNull())
        _icon = QPixmap (":/icons/update.png");

    QMessageBox _message;
    _message.setIconPixmap (_icon);

    if (newerVersionAvailable())
    {
        _message.setStandardButtons (QMessageBox::Yes | QMessageBox::No);
        _message.setText ("<b>" + tr ("有新版本可用！") + "</b>");
        _message.setInformativeText (tr ("%1 可用 - 您的版本是 %2. 确定现在下载？")
                                     .arg (latestVersion())
                                     .arg (installedVersion()));

        if (_message.exec() == QMessageBox::Yes)
            downloadLatestVersion();
    }

    else if (!m_latest_version.isEmpty() && !m_silent)
    {
        _message.setStandardButtons (QMessageBox::Ok);
        _message.setText ("<b>" + tr ("您的版本已经是最新！") +
                          "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</b>");
        _message.setInformativeText (
            tr ("您的程序是目前最新的版本%1")
            .arg (installedVersion()));

        _message.exec();
    }
}

void QSimpleUpdater::checkDownloadedVersion (QNetworkReply *reply)
{
    bool _new_update = false;

    QString _reply = QString(reply->readAll());
    QScriptEngine engine;
    QScriptValue result = engine.evaluate("("+_reply+")");

    m_latest_version = result.property("Version").toString();
    m_download_count = result.property("Itemscount").toInteger();
    QScriptValue items = result.property("Items");
    QScriptValueIterator it(items);
    m_download_urlList.clear();
    for (int i = 0; i< m_download_count; ++i)
    {
        it.next();
        QString url = it.value().property("Url").toString();
        m_download_urlList.push_back(url);
    }

    if (!_reply.isEmpty())
    {

        QStringList _download = m_latest_version.split (".");
        QStringList _installed = m_installed_version.split (".");

        for (int i = 0; i <= _download.count() - 1; ++i)
        {
            if (_download.count() - 1 >= i && _installed.count() - 1 >= i)
            {
                if (_download.at (i) > _installed.at (i))
                {
                    _new_update = true;
                    break;
                }
            }

            else
            {
                if (_installed.count() < _download.count())
                {
                    if (_installed.at (i - 1) == _download.at (i - 1))
                        break;

                    else
                    {
                        _new_update = true;
                        break;
                    }
                }
            }
        }
    }

    m_new_version_available = _new_update;

    emit checkingFinished();
}
