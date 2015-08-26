#include "example.h"
#include "ui_example.h"
#include <QTextCodec>
#include <QDebug>
#include <QSettings>

int main (int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));

    app.setApplicationVersion(QObject::tr("1.0"));
    app.setApplicationName ("更新程序");

    Example example;
    example.show();

//    QSimpleUpdater *updater = new QSimpleUpdater();
//    updater->setReferenceUrl ("http://96.126.103.128:3000/update");

//    updater->checkForUpdates(true);

    return app.exec();
}

Example::Example (QWidget *parent) :
    QDialog (parent),
    ui (new Ui::Example),
    m_isCheckingUpdate(false),
    m_timeID(0)
{
    ui->setupUi (this);
    connect(ui->updatesButton, SIGNAL(clicked()), this, SLOT(checkForUpdates()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    updater = new QSimpleUpdater (this);
    updater->setReferenceUrl ("http://96.126.103.128:3000/update");

    connect(updater, SIGNAL(downloadFinished(bool)), this, SLOT(downloadFinished(bool)));
    connect(updater, SIGNAL(checkingFinishedForUpdate()), this, SLOT(checkingFinished()));

    setWindowTitle(tr("更新程序"));
    ui->updatesButton->setText (tr("检查更新"));
    ui->label->setText(tr(""));
    ui->cancelButton->setText(tr("退出"));
    m_timeID = startTimer(1000*10*60*3);
}

Example::~Example()
{
    if (m_timeID != 0)
    {
        killTimer(m_timeID);
    }
    delete ui;
}

void Example::checkForUpdates()
{
    ui->updatesButton->setEnabled (false);
    ui->updatesButton->setText ("正在检查更新...");
    ui->label->setText(tr(""));
    m_isCheckingUpdate = true;
    ui->cancelButton->setText(tr("取消"));
    updater->checkForUpdates();
    killTimer(m_timeID);
}

void Example::timerEvent(QTimerEvent *event)
{
    ui->updatesButton->setEnabled (false);
    ui->updatesButton->setText ("正在检查更新...");
    ui->label->setText(tr(""));
    m_isCheckingUpdate = true;
    ui->cancelButton->setText(tr("取消"));
    updater->checkForUpdates(true);
    killTimer(m_timeID);
}

void Example::cancel()
{
    if (!m_isCheckingUpdate)
    {
        QApplication::quit();
    }
    else
    {
        updater->cancel();
        ui->updatesButton->setEnabled (true);
        ui->updatesButton->setText ("检查更新");
        m_isCheckingUpdate = false;
        ui->cancelButton->setText(tr("退出"));
        m_timeID = startTimer(1000*10*60*3);
    }
}

void Example::checkingFinished()
{
    ui->updatesButton->setEnabled (true);
    ui->updatesButton->setText ("检查更新");
    m_isCheckingUpdate = false;
    ui->cancelButton->setText(tr("退出"));
    m_timeID = startTimer(1000*10*60*3);
}

void Example::downloadFinished(bool success)
{
    if (success)
    {
        ui->label->setText(tr("更新完成"));
    }
    else
    {
        ui->label->setText(tr("复制文件失败，请关闭所有程序后\n把updatefile文件夹里的文件复制到\n上层文件夹中。"));
    }
    ui->updatesButton->setEnabled (true);
    ui->updatesButton->setText ("检查更新");
    m_isCheckingUpdate = false;
    ui->cancelButton->setText(tr("退出"));
    m_timeID = startTimer(1000*10*60*3);
}

