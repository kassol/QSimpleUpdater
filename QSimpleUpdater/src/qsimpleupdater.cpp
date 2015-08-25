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

/*! \class QSimpleUpdater
 * \brief A simple auto-updater system for Qt
 *
 * QSimpleUpdater is an implementation of an auto-updating system to be used with Qt projects.
 * Aside from notifying you if there's a newer version, it allows you to download the change log in any
 * format (such as HTML or RTF) and download the updates directly from your application using a dialog.
 * QSimpleUpdater is free and open source LGPL software,
 * which means that you can use it for both open source and proprietary applications.
 *
 * \chapter Installation
 *
 * \list
 * \o Copy the QSimpleUpdater folder in your "3rd-party" folder.
 * \o Include the QSimpleUpdater project include (pri) file using the include() function.
 * \o That's all! Check the example project as a reference for your project.
 * \endlist
 *
 * \chapter Running the example project
 *
 * \list
 * \o Navigate to the Example folder and open example.pro with Qt Creator.
 * \o Compile the project and play with it :)
 * \endlist
 *
 * \chapter Warnings
 * Many websites today use the HTTP Secure protocol, which means that you will need SSL
 * in order to communicate with them.
 * If your project needs to access such a webiste (for example GitHub),
 * you will need to carefully read the following information in order to ensure that
 * QSimpleUpdater works with those websites (both in your machine and in the final users' machine).
 *
 * This section is extremely important for any developers wishing to deploy their applications under
 * the Windows platform, because the application will depend on the OpenSSL libaries in order to work.
 *
 * \bold {Linux}
 *
 * Make sure that you have installed the following libraries in your system:
 *
 * \list
 * \o lssl
 * \o lcrypto
 * \endlist
 *
 * \bold {Mac OS X}
 *
 * The libraries required by QSimpleUpdater are the same as Linux, however, these libraries
 * are installed by default in most Mac OS X installations.
 *
 * \bold {Microsoft Windows}
 *
 * QSimpleUpdater makes use of the OpenSSL-Win32 project, make sure that have it installed
 * and that the project knows where to find them (the default location is C:/OpenSSL-Win32).
 * Finally, deploy the following libraries with your compiled project:
 *
 * \list
 * \o libeay32.dll
 * \o ssleay32.dll
 * \endlist
 */

/*! \fn QSimpleUpdater::checkingFinished (void)
 * This signal is triggered when the updater system finishes downloading
 * and proccessing the version data and changelog data.
 */

#include "qsimpleupdater.h"
#include <QtScript/QScriptEngine>
#include <Qtscript/qscriptvalueiterator.h>

/*! \internal
 * Initializes and configures the class.
 */

QSimpleUpdater::QSimpleUpdater (QObject *parent)
    : QObject (parent)
    , m_download_count(0)
    , m_show_update_available (true)
    , m_new_version_available (false)
{

    m_progressDialog = new ProgressDialog();
    m_downloadDialog = new DownloadDialog();

    m_manager = new QNetworkAccessManager (this);
    connect (m_manager, SIGNAL (finished (QNetworkReply *)), this,
             SLOT (checkDownloadedVersion (QNetworkReply *)));
    connect (m_manager, SIGNAL (sslErrors (QNetworkReply *, QList<QSslError>)),
             this, SLOT (ignoreSslErrors (QNetworkReply *, QList<QSslError>)));

    connect (m_progressDialog, SIGNAL (cancelClicked()), this, SLOT (cancel()));
    connect (this, SIGNAL (checkingFinished()), this, SLOT (onCheckingFinished()));

    //setApplicationVersion (qApp->applicationVersion());
}

/*!
 * Checks for updates and calls the appropiate functions
 * when finished.
 *
 * \sa setDownloadUrl(), setReferenceUrl()
 */

void QSimpleUpdater::checkForUpdates (void)
{
    QFile file("/Users/kassol/Workspace/QSimpleUpdater/version.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QTextStream in(&file);
    QString versionString;
    in>>versionString;
    file.close();

    m_installed_version = versionString.right(versionString.length()-versionString.lastIndexOf('=')-1);

    if (!m_reference_url.isEmpty())
    {
        m_manager->get (QNetworkRequest (m_reference_url));

        m_progressDialog->show();
    }

    else
        qDebug() << "QSimpleUpdater: Invalid reference URL";
}

/*!
 * Returns the latest version as a \c QString.
 *
 * \sa setReferenceUrl(), checkForUpdates()
 */

QString QSimpleUpdater::latestVersion() const
{
    return m_latest_version;
}

/*!
 * Returns the local version of the application.
 *
 * \sa setApplicationVersion()
 */

QString QSimpleUpdater::installedVersion() const
{
    return m_installed_version;
}

/*!
 * Downloads the latest version of the application
 * and displays download info in a dialog.
 *
 * \sa setDownloadUrl(), checkForUpdates()
 */

void QSimpleUpdater::downloadLatestVersion (void)
{
    if (!m_download_urlList.isEmpty())
        m_downloadDialog->beginDownload (m_download_urlList);
}

/*!
 * Returns \c true if the system detected that there is
 * a newer version of the application available online.
 *
 * \sa setReferenceUrl(), checkForUpdates()
 */

bool QSimpleUpdater::newerVersionAvailable() const
{
    return m_new_version_available;
}

/*!
 * Tells the updater system from where to download the file
 * that indicates the latest version using the \a url parameter.
 *
 * The reference file should contain \bold {ONLY} the latest version
 * in a plain text format. For example:
 *
 * \list
 * \o 1
 * \o 0.1
 * \o 1.0.1
 * \o 2.2.12
 * \o etc
 * \endlist
 *
 * \sa latestVersion()
 */

void QSimpleUpdater::setReferenceUrl (const QString& url)
{
    Q_ASSERT (!url.isEmpty());
    m_reference_url.setUrl (url);
}

/*!
 * Tells the updater system from where to download the
 * change log using the \a url parameter.
 * The change log can be any file you like, however,
 * its recommended to write it in plain text,
 * such as TXT, HTML and RTF files.
 *
 * \sa changeLog()
 */


void QSimpleUpdater::setChangelogUrl (const QString& url)
{
    Q_ASSERT (!url.isEmpty());
    m_changelog_url.setUrl (url);
}

/*!
 * Tells the updater the version of the installed
 * copy of your application using the \a version parameter.
 *
 * Calling this function is optional, as the default
 * values are loaded from QApplication class.
 *
 * \sa installedVersion(), checkForUpdates()
 */


void QSimpleUpdater::setApplicationVersion (const QString& version)
{
    m_installed_version = version;
}

/*!
 * If the \a show parameter is set to \c true, the updater system will show a
 * message box notifying the user when there's an update available.
 *
 * \sa checkForUpdates()
 */

void QSimpleUpdater::setShowUpdateAvailableMessage (bool show)
{
    m_show_update_available = show;
}

/*! \internal
 * Disconnects the network access manager when the user
 * clicks on the "cancel" button in the progress dialog.
 */

void QSimpleUpdater::cancel (void)
{
    m_manager->disconnect();
}

/*! \internal
 * Alerts the user when the download of version information
 * data is corrupted.
 *
 * \sa checkDownloadedVersion()
 */

void QSimpleUpdater::showErrorMessage (void)
{

    m_progressDialog->hide();
    QMessageBox::warning (NULL, tr ("软件更新"),
                              tr ("检查更新是出现未知错误！"));
}

/*! \internal
 * Informs the user if there's a newer version available for download
 * or if he or she is running the latest version of the application.
 *
 * \sa checkDownloadedVersion()
 */

void QSimpleUpdater::onCheckingFinished (void)
{
    // Hide the progress dialog
    m_progressDialog->hide();

    // Get the application icon as a pixmap
    QPixmap _icon = qApp->windowIcon().pixmap (
                        qApp->windowIcon().actualSize (QSize (96, 96)));

    // If the icon is invalid, use default icon
    if (_icon.isNull())
        _icon = QPixmap (":/icons/update.png");

    QMessageBox _message;
    _message.setIconPixmap (_icon);

    // Ask user if he/she wants to download newer version
    if (newerVersionAvailable() && m_show_update_available)
    {
        _message.setStandardButtons (QMessageBox::Yes | QMessageBox::No);
        _message.setText ("<b>" + tr ("%1 有新版本可用！").arg (qApp->applicationName()) + "</b>");
        _message.setInformativeText (tr ("%1 %2 可用 - 您的版本是 %3. 确定现在下载？")
                                     .arg (qApp->applicationName())
                                     .arg (latestVersion())
                                     .arg (installedVersion()));

        if (_message.exec() == QMessageBox::Yes)
            downloadLatestVersion();
    }

    // Tell user that he/she is up to date (only if necessary)
    else if (!m_latest_version.isEmpty())
    {
        _message.setStandardButtons (QMessageBox::Ok);
        _message.setText ("<b>" + tr ("您的版本已经是最新！") +
                          "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</b>");
        _message.setInformativeText (
            tr ("%1 %2 是目前最新的版本")
            .arg (qApp->applicationName())
            .arg (installedVersion()));

        _message.exec();
    }
}

/*! \internal
 * Compares downloaded version information with local version information
 * and decides if there's a newer version available.
 *
 * Finally, the function downloads the changelog if there's a newer version
 * available online.
 *
 * \sa checkForUpdates()
 */

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

    else
        showErrorMessage();

    m_new_version_available = _new_update;

    if (!m_changelog_url.isEmpty() && newerVersionAvailable())
    {
        QNetworkAccessManager *_manager = new QNetworkAccessManager (this);

        connect (_manager, SIGNAL (finished (QNetworkReply *)), this,
                 SLOT (processDownloadedChangelog (QNetworkReply *)));

        connect (_manager, SIGNAL (sslErrors (QNetworkReply *, QList<QSslError>)),
                 this, SLOT (ignoreSslErrors (QNetworkReply *, QList<QSslError>)));

        _manager->get (QNetworkRequest (m_changelog_url));
    }

    else
        emit checkingFinished();
}

/*! \internal
 * Reads the downloaded changelog data and transforms it into a QString.
 *
 * \sa setChangelogUrl(), changeLog()
 */

void QSimpleUpdater::processDownloadedChangelog (QNetworkReply *reply)
{
    QString _reply = QString::fromUtf8 (reply->readAll());

    emit checkingFinished();
}

/*! \internal
 * Allows the download process to continue even if there are SSL errors.
 *
 * \sa checkForUpdates()
 */

void QSimpleUpdater::ignoreSslErrors (QNetworkReply *reply,
                                      const QList<QSslError>& error)
{
#if SUPPORTS_SSL
    reply->ignoreSslErrors (error);
#else
    Q_UNUSED (reply);
    Q_UNUSED (error);
#endif
}
