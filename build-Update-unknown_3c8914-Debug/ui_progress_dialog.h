/********************************************************************************
** Form generated from reading UI file 'progress_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESS_DIALOG_H
#define UI_PROGRESS_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *ui_icon;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *ui_progress_bar;
    QProgressBar *progressBar;
    QWidget *button_widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *ui_cancel_button;

    void setupUi(QDialog *ProgressDialog)
    {
        if (ProgressDialog->objectName().isEmpty())
            ProgressDialog->setObjectName(QString::fromUtf8("ProgressDialog"));
        ProgressDialog->resize(410, 152);
        horizontalLayout = new QHBoxLayout(ProgressDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        ui_icon = new QLabel(ProgressDialog);
        ui_icon->setObjectName(QString::fromUtf8("ui_icon"));
        ui_icon->setPixmap(QPixmap(QString::fromUtf8(":/icons/update.png")));

        horizontalLayout->addWidget(ui_icon);

        widget = new QWidget(ProgressDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ui_progress_bar = new QLabel(widget);
        ui_progress_bar->setObjectName(QString::fromUtf8("ui_progress_bar"));

        verticalLayout->addWidget(ui_progress_bar);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(250, 0));
        progressBar->setMaximum(0);
        progressBar->setValue(-1);
        progressBar->setInvertedAppearance(false);

        verticalLayout->addWidget(progressBar);

        button_widget = new QWidget(widget);
        button_widget->setObjectName(QString::fromUtf8("button_widget"));
        horizontalLayout_2 = new QHBoxLayout(button_widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ui_cancel_button = new QPushButton(button_widget);
        ui_cancel_button->setObjectName(QString::fromUtf8("ui_cancel_button"));

        horizontalLayout_2->addWidget(ui_cancel_button);


        verticalLayout->addWidget(button_widget);


        horizontalLayout->addWidget(widget);


        retranslateUi(ProgressDialog);

        QMetaObject::connectSlotsByName(ProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *ProgressDialog)
    {
        ProgressDialog->setWindowTitle(QApplication::translate("ProgressDialog", "Software Updater", 0, QApplication::UnicodeUTF8));
        ui_icon->setText(QString());
        ui_progress_bar->setText(QApplication::translate("ProgressDialog", "\346\243\200\346\237\245\346\233\264\346\226\260...", 0, QApplication::UnicodeUTF8));
        ui_cancel_button->setText(QApplication::translate("ProgressDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProgressDialog: public Ui_ProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_DIALOG_H
