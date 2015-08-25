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


    // Create the dialog and show it
    Example example;
    example.show();

//    QSimpleUpdater *updater = new QSimpleUpdater();
//    updater->setReferenceUrl ("http://96.126.103.128:3000/update");

//    updater->checkForUpdates(true);

    // Run the app
    return app.exec();
}

Example::Example (QWidget *parent) : QDialog (parent), ui (new Ui::Example)
{
    // Create and configure the user interface
    ui->setupUi (this);
    connect (ui->updatesButton, SIGNAL (clicked()), this, SLOT (checkForUpdates()));

    // Initialize the updater
    updater = new QSimpleUpdater (this);
    setWindowTitle(tr("更新程序"));
    ui->updatesButton->setText ("检查更新");
}

Example::~Example()
{
    delete ui;
}

void Example::checkForUpdates()
{
    //ui->updatesButton->setEnabled (false);
    //ui->updatesButton->setText ("检查更新...");

    updater->setReferenceUrl ("http://96.126.103.128:3000/update");

    updater->checkForUpdates();
}

