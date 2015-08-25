/********************************************************************************
** Form generated from reading UI file 'example.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLE_H
#define UI_EXAMPLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Example
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *versionLabel;
    QPushButton *updatesButton;

    void setupUi(QDialog *Example)
    {
        if (Example->objectName().isEmpty())
            Example->setObjectName(QString::fromUtf8("Example"));
        Example->resize(400, 120);
        horizontalLayout = new QHBoxLayout(Example);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        versionLabel = new QLabel(Example);
        versionLabel->setObjectName(QString::fromUtf8("versionLabel"));
        versionLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/update.png")));

        horizontalLayout->addWidget(versionLabel);

        updatesButton = new QPushButton(Example);
        updatesButton->setObjectName(QString::fromUtf8("updatesButton"));

        horizontalLayout->addWidget(updatesButton);


        retranslateUi(Example);

        QMetaObject::connectSlotsByName(Example);
    } // setupUi

    void retranslateUi(QDialog *Example)
    {
        Example->setWindowTitle(QApplication::translate("Example", "QSimpleUpdater Example", 0, QApplication::UnicodeUTF8));
        versionLabel->setText(QString());
        updatesButton->setText(QApplication::translate("Example", "Check for updates", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Example: public Ui_Example {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLE_H
