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

Example::Example (QWidget *parent) : QDialog (parent), ui (new Ui::Example)
{
    ui->setupUi (this);
    connect (ui->updatesButton, SIGNAL (clicked()), this, SLOT (checkForUpdates()));

    updater = new QSimpleUpdater (this);
    setWindowTitle(tr("更新程序"));
    ui->updatesButton->setText ("检查更新");
    ui->label->setText(tr(""));
}

Example::~Example()
{
    delete ui;
}

void Example::checkForUpdates()
{
    //ui->updatesButton->setEnabled (false);
    //ui->updatesButton->setText ("检查更新...");
    ui->label->setText(tr(""));
    updater->setReferenceUrl ("http://96.126.103.128:3000/update");
    connect(updater, SIGNAL(downloadFinished(bool)), this, SLOT(downloadFinished(bool)));
    updater->checkForUpdates();
}

void Example::downloadFinished(bool success)
{
    if (success)
    {
        ui->label->setText(tr("更新完成"));
    }
    else
    {
        ui->label->setText(tr("复制文件失败，请关闭所有程序后把updatefile文件夹里的文件复制到上层文件夹中。"));
    }
}

