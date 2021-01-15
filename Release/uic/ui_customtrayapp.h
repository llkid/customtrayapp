/********************************************************************************
** Form generated from reading UI file 'customtrayapp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMTRAYAPP_H
#define UI_CUSTOMTRAYAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customtrayappClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *customtrayappClass)
    {
        if (customtrayappClass->objectName().isEmpty())
            customtrayappClass->setObjectName(QString::fromUtf8("customtrayappClass"));
        customtrayappClass->resize(600, 400);
        menuBar = new QMenuBar(customtrayappClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        customtrayappClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(customtrayappClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        customtrayappClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(customtrayappClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        customtrayappClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(customtrayappClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        customtrayappClass->setStatusBar(statusBar);

        retranslateUi(customtrayappClass);

        QMetaObject::connectSlotsByName(customtrayappClass);
    } // setupUi

    void retranslateUi(QMainWindow *customtrayappClass)
    {
        customtrayappClass->setWindowTitle(QCoreApplication::translate("customtrayappClass", "customtrayapp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customtrayappClass: public Ui_customtrayappClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMTRAYAPP_H
