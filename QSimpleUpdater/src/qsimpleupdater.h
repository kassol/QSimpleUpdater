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
 *
 */

#ifndef Q_SIMPLE_UPDATER_H
#define Q_SIMPLE_UPDATER_H

#define SUPPORTS_SSL !defined(Q_OS_IOS)

#include <QUrl>
#include <QIcon>
#include <QPixmap>
#include <QMessageBox>
#include <QApplication>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDesktopServices>
#include <QNetworkAccessManager>

#if SUPPORTS_SSL
#include <QSsl>
#include <QSslError>
#include <QSslConfiguration>
#endif

#include "dialogs/download_dialog.h"

class QSimpleUpdater : public QObject
{
        Q_OBJECT

    public:
        QSimpleUpdater (QObject *parent = 0);
        void checkForUpdates (bool silent = false);


    public slots:
        void setReferenceUrl (const QString& url);
        void cancel (void);

    signals:
        void checkingFinished (void);
        void checkingFinishedForUpdate(void);
        void downloadFinished(bool);

    private slots:
        void onCheckingFinished (void);
        void downloadLatestVersion (void);
        QString latestVersion() const;
        QString installedVersion() const;
        bool newerVersionAvailable() const;
        void checkDownloadedVersion (QNetworkReply *reply);
        void finished(bool success);

    private:
        bool m_silent;
        QString m_latest_version;
        QString m_installed_version;
        QNetworkAccessManager *m_manager;

        QList<QUrl> m_download_urlList;
        int m_download_count;
        QUrl m_reference_url;

        bool m_new_version_available;

        DownloadDialog *m_downloadDialog;
};

#endif
