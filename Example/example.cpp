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
    m_isCheckingUpdate(false)
{
    ui->setupUi (this);
    connect(ui->updatesButton, SIGNAL(clicked()), this, SLOT(checkForUpdates()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    updater = new QSimpleUpdater (this);
    setWindowTitle(tr("���³���"));
    ui->updatesButton->setText ("������");
    ui->label->setText(tr(""));
}

Example::~Example()
{
    delete ui;
}

void Example::checkForUpdates()
{
    ui->updatesButton->setEnabled (false);
    ui->updatesButton->setText ("���ڼ�����...");
    ui->label->setText(tr(""));
    updater->setReferenceUrl ("http://96.126.103.128:3000/update");
    connect(updater, SIGNAL(downloadFinished(bool)), this, SLOT(downloadFinished(bool)));
    connect(updater, SIGNAL(checkingFinished()), this, SLOT(checkingFinished()));
    m_isCheckingUpdate = true;
    updater->checkForUpdates();
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
    }
}

void Example::checkingFinished()
{
    ui->updatesButton->setEnabled (true);
    ui->updatesButton->setText ("������");
    m_isCheckingUpdate = false;
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
}

