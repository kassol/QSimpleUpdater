//
//  This file is part of QSimpleUpdater
//
//  Copyright (c) 2014 Alex Spataru <alex_spataru@gmail.com>
//
//  Please check the license.txt file for more information.
//

#include "download_dialog.h"
#include "ui_download_dialog.h"

DownloadDialog::DownloadDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DownloadDialog)
{
    // Setup the UI
    ui->setupUi(this);
    ui->installButton->setEnabled(false);

    // Connect SIGNALS/SLOTS
    connect(ui->installButton, SIGNAL(clicked()), this, SLOT(openDownload()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancelDownload()));

    // Initialize the network access manager
    m_manager = new QNetworkAccessManager(this);

    // Avoid SSL issues
    connect(m_manager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
            this, SLOT(ignoreSslErrors(QNetworkReply*,QList<QSslError>)));
}

DownloadDialog::~DownloadDialog()
{
    delete ui;
}

void DownloadDialog::beginDownload(const QUrl &url)
{
    // Reset the UI
    ui->progressBar->setValue(0);
    ui->installButton->setEnabled(false);
    ui->cancelButton->setText(tr("Cancel"));
    ui->downloadLabel->setText(tr("Downloading update..."));

    // Begin the download
    m_reply = m_manager->get(QNetworkRequest(url));

    // Update the progress bar value automatically
    connect(m_reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(updateProgress(qint64,qint64)));

    // Write the file to the hard disk once the download is finished
    connect(m_reply, SIGNAL(finished()), this, SLOT(downloadFinished()));

    // Show the dialog
    showNormal();
}

void DownloadDialog::openDownload()
{
    if (!m_path.isEmpty()) {
        QString url = m_path;

        // Build a correct URL to open local files
        if (url.startsWith("/"))
            url = "file://" + url;
        else
            url = "file:///" + url;

        // Let the system open the downloaded file
        QDesktopServices::openUrl(url);
    }

    else {
        qWarning() << "QSimpleUpdater: cannot open downloaded file!";
    }
}

void DownloadDialog::cancelDownload()
{
    // Cancel download
    m_reply->abort();

    // Close the dialog
    close();
}

void DownloadDialog::downloadFinished()
{
    // Setup the UI
    ui->cancelButton->setText(tr("Close"));
    ui->installButton->setEnabled(true);
    ui->downloadLabel->setText(tr("Download complete!"));

    // Write the file
    QByteArray data = m_reply->readAll();

    if (!data.isEmpty()) {
        // Create a QFile with the name of the downloaded file
        QStringList list = m_reply->url().toString().split("/");
        QFile file(QDir::tempPath() + "/" + list.at(list.count() - 1));

        // Write download data to the opened file
        if (file.open(QIODevice::WriteOnly)) {
            file.write(data);
            m_path = file.fileName();
        }

        // Show a warning if we cannot open the file for writting
        else {
            qWarning() << "QSimpleUpdater: cannot write downloaded data!";
        }

        // Close the file
        file.close();
    }

    else {
        qWarning() << "QSimpleUpdater: invalid download data!";
    }
}

void DownloadDialog::updateProgress(qint64 received, qint64 total)
{
    // We know the size of the download, so we can calculate the progress....
    if (total > 0) {
        ui->progressBar->setMinimum(0);
        ui->progressBar->setMaximum(100);

        // Calculate and show download progress
        int _progress = (int) ((received * 100) / total);
        ui->progressBar->setValue(_progress);
        ui->downloadLabel->setText(tr("Downloading update (%1%)...").arg(_progress));

        // Get size information
        QString _total_string;
        QString _received_string;

        float _total = total;
        float _received = received;

        // Calculate the lenght unit for
        // the total size of the download
        if (_total < 1024) {
            _total_string = tr("%1 bytes").arg(_total);
        } else if (_total < 1024 * 1024) {
            _total = roundNumber(_total / 1024);
            _total_string = tr("%1 KB").arg(_total);
        } else {
            _total = roundNumber(_total / (1024 * 1024));
            _total_string = tr("%1 MB").arg(_total);
        }

        // Calculate the lenght unit for
        // the received data of the download
        if (_received < 1024) {
            _received_string = tr("%1 bytes").arg(_received);
        } else if (received < 1024 * 1024) {
            _received = roundNumber(_received / 1024);
            _received_string = tr("%1 KB").arg(_received);
        } else {
            _received = roundNumber(_received / (1024 * 1024));
            _received_string = tr("%1 MB").arg(_received);
        }

        // Update the progress label
        ui->progressLabel->setText(_received_string + " " + tr("of") + " " + _total_string);
    }

    // We do not know the size of the download, so we improvise...
    else {

        // Enable a marquee animation
        ui->progressBar->setValue(-1);
        ui->progressBar->setMinimum(0);
        ui->progressBar->setMaximum(0);

        ui->downloadLabel->setText(tr("Downloading update..."));
    }
}

void DownloadDialog::ignoreSslErrors (QNetworkReply *reply, const QList<QSslError> &error)
{
    reply->ignoreSslErrors (error);
}

float DownloadDialog::roundNumber(const float &input)
{
    // Round the input number to two decimal places
    return roundf(input * 100) / 100;
}
