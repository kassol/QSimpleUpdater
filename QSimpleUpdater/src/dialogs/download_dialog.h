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

#ifndef DOWNLOAD_DIALOG_H
#define DOWNLOAD_DIALOG_H

#include <QDir>
#include <QIcon>
#include <QDateTime>
#include <QMessageBox>
#include <QNetworkReply>
#include <QDesktopServices>
#include <QNetworkAccessManager>

#include <math.h>

namespace Ui
{
class DownloadDialog;
}

class DownloadDialog : public QWidget
{
        Q_OBJECT

    public:
        explicit DownloadDialog (QWidget *parent = 0);
        ~DownloadDialog (void);

        void beginDownload (QList<QUrl>& download_urlList, QString newVersion);

    private slots:
        void openDownload (void);
        bool copyFiles(void);
        void updateVersion(void);
        void installUpdate (void);
        void cancelDownload (void);
        void downloadFinished (void);

    private:
        Ui::DownloadDialog *ui;
        bool m_download_paused;
        int m_download_count;
        QList<QUrl> m_download_urlList;
        QList<QString> m_tmpFilePathList;
        QString m_latest_version;

        QNetworkReply *m_reply;
        QNetworkAccessManager *m_manager;

        uint m_start_time;

        float roundNumber (const float& input);
};

#endif
