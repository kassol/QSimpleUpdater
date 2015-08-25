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

#include "download_dialog.h"
#include "ui_download_dialog.h"

#include <QMutex>
#include <QProcess>

DownloadDialog::DownloadDialog (QWidget *parent)
    : QWidget (parent)
    , ui (new Ui::DownloadDialog)
{

    // Setup the UI
    ui->setupUi (this);

    // Make the window look like a dialog
    QIcon _blank;
    setWindowIcon (_blank);
    setWindowModality (Qt::WindowModal);
    setWindowFlags (Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    // Connect SIGNALS/SLOTS
    connect (ui->stopButton, SIGNAL (clicked()), this, SLOT (cancelDownload()));
    connect (ui->openButton, SIGNAL (clicked()), this, SLOT (installUpdate()));

    // Configure open button
    ui->openButton->setEnabled (false);
    ui->openButton->setVisible (false);
    setWindowTitle(tr("软件更新"));

    // Initialize the network access manager
    m_manager = new QNetworkAccessManager (this);

    // Avoid SSL issues
    connect (m_manager, SIGNAL (sslErrors (QNetworkReply *, QList<QSslError>)), this,
             SLOT (ignoreSslErrors (QNetworkReply *, QList<QSslError>)));
}

DownloadDialog::~DownloadDialog (void)
{
    delete ui;
}

void DownloadDialog::beginDownload (QList<QUrl>& download_urlList)
{
    m_download_count = download_urlList.count();
    m_download_urlList = download_urlList;
    download_urlList.clear();
    // Reset the UI
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(m_download_count);
    ui->progressBar->setValue (m_download_count-m_download_urlList.count());
    ui->stopButton->setText (tr ("停止"));
    ui->downloadLabel->setText (tr ("下载更新 %1/%2").arg(m_download_count-m_download_urlList.count()).arg(m_download_count));

    // Begin the download
    m_reply = m_manager->get (QNetworkRequest (m_download_urlList.front()));
    m_download_urlList.pop_front();

    connect (m_reply, SIGNAL (finished()), this, SLOT (downloadFinished()));

    // Show the dialog
    showNormal();
}

void DownloadDialog::installUpdate (void)
{
    QMessageBox msg;
    msg.setIcon (QMessageBox::Question);
    msg.setText ("<b>" +
                 tr ("要进行更新您必须退出智能终端")+"</b>");
    msg.setInformativeText (tr ("您想现在退出智能终端?"));
    msg.setStandardButtons (QMessageBox::Yes | QMessageBox::No);

    if (msg.exec() == QMessageBox::Yes)
    {
        QProcess p;
        p.start("taskkill /IM 1.exe /F");
        p.waitForFinished();
        p.start("taskkill /IM 2.exe /F");
        p.waitForFinished();
        copyFiles();
        ui->downloadLabel->setText(tr("更新完成"));
    }

    else
    {
        ui->openButton->setEnabled (true);
        ui->openButton->setVisible (true);
    }
}

void DownloadDialog::copyFiles(void)
{
    for (int i = 0; i < m_tmpFilePathList.count(); ++i)
    {
       QString filename = QDir::currentPath()+"/"+m_tmpFilePathList[i].right(m_tmpFilePathList[i].length()-m_tmpFilePathList[i].lastIndexOf('/')-1);
       if(QFile::exists(filename))
       {
           QFile::remove(filename);
           QFile::copy(m_tmpFilePathList[i], filename);
       }
    }
}

void DownloadDialog::openDownload (void)
{
    if (!m_tmpFilePathList.isEmpty())
    {
        QString url;

        if (url.startsWith ("/"))
            url = "file://" + url;

        else
            url = "file:///" + url;

        QDesktopServices::openUrl (url);
    }
}

void DownloadDialog::cancelDownload (void)
{
    if (!m_reply->isFinished())
    {
        QMessageBox _message;
        _message.setWindowTitle (tr ("更新"));
        _message.setIcon (QMessageBox::Question);
        _message.setStandardButtons (QMessageBox::Yes | QMessageBox::No);
        _message.setText (tr ("您确定要取消下载？"));

        if (_message.exec() == QMessageBox::Yes)
        {
            hide();
            m_reply->abort();
        }
    }

    else
        hide();
}

void DownloadDialog::downloadFinished (void)
{
    ui->downloadLabel->setText (tr ("下载更新 %1/%2").arg(m_download_count-m_download_urlList.count()).arg(m_download_count));
    ui->progressBar->setValue (m_download_count-m_download_urlList.count());
    QByteArray data = m_reply->readAll();

    if (!data.isEmpty())
    {
        QStringList list = m_reply->url().toString().split ("/");
        QFile file (QDir::tempPath() + "/" + list.at (list.count() - 1));
        QMutex _mutex;

        if (file.open (QIODevice::WriteOnly))
        {
            _mutex.lock();
            file.write (data);
            m_tmpFilePathList.push_back(file.fileName());
            file.close();
            _mutex.unlock();
        }

        if (m_download_urlList.isEmpty())
        {
            ui->stopButton->setText (tr ("关闭"));
            ui->downloadLabel->setText (tr ("下载完成！"));
            installUpdate();
        }
        else
        {
            ui->stopButton->setText (tr ("停止"));

            m_reply = m_manager->get (QNetworkRequest (m_download_urlList.front()));
            m_download_urlList.pop_front();
            connect (m_reply, SIGNAL (finished()), this, SLOT (downloadFinished()));
        }
    }
}

void DownloadDialog::ignoreSslErrors (QNetworkReply *reply,
                                      const QList<QSslError>& error)
{
#ifndef Q_OS_IOS
    reply->ignoreSslErrors (error);
#else
    Q_UNUSED (reply);
    Q_UNUSED (error);
#endif
}

float DownloadDialog::roundNumber (const float& input)
{
    return roundf (input * 100) / 100;
}
