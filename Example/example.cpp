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
    app.setApplicationName ("���³���");

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

    setWindowTitle(tr("���³���"));
    ui->updatesButton->setText (tr("������"));
    ui->label->setText(tr(""));
    ui->cancelButton->setText(tr("�˳�"));
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
    ui->updatesButton->setText ("���ڼ�����...");
    ui->label->setText(tr(""));
    m_isCheckingUpdate = true;
    ui->cancelButton->setText(tr("ȡ��"));
    updater->checkForUpdates();
    killTimer(m_timeID);
}

void Example::timerEvent(QTimerEvent *event)
{
    ui->updatesButton->setEnabled (false);
    ui->updatesButton->setText ("���ڼ�����...");
    ui->label->setText(tr(""));
    m_isCheckingUpdate = true;
    ui->cancelButton->setText(tr("ȡ��"));
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
        ui->updatesButton->setText ("������");
        m_isCheckingUpdate = false;
        ui->cancelButton->setText(tr("�˳�"));
        m_timeID = startTimer(1000*10*60*3);
    }
}

void Example::checkingFinished()
{
    ui->updatesButton->setEnabled (true);
    ui->updatesButton->setText ("������");
    m_isCheckingUpdate = false;
    ui->cancelButton->setText(tr("�˳�"));
    m_timeID = startTimer(1000*10*60*3);
}

void Example::downloadFinished(bool success)
{
    if (success)
    {
        ui->label->setText(tr("�������"));
    }
    else
    {
        ui->label->setText(tr("�����ļ�ʧ�ܣ���ر����г����\n��updatefile�ļ�������ļ����Ƶ�\n�ϲ��ļ����С�"));
    }
    ui->updatesButton->setEnabled (true);
    ui->updatesButton->setText ("������");
    m_isCheckingUpdate = false;
    ui->cancelButton->setText(tr("�˳�"));
    m_timeID = startTimer(1000*10*60*3);
}

