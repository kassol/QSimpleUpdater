#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QDialog>
#include <QMessageBox>
#include <QSimpleUpdater>

namespace Ui
{
class Example;
}

class Example : public QDialog
{
        Q_OBJECT

    public:
        explicit Example (QWidget *parent = 0);
        ~Example();

    public slots:
        void checkForUpdates();
        void cancel();
        void downloadFinished(bool success);
        void checkingFinished();

        void timerEvent( QTimerEvent *event );

    private:
        Ui::Example *ui;

        QString m_installed_version;
        QSimpleUpdater *updater;
        bool m_isCheckingUpdate;
        int m_timeID;
};

#endif
