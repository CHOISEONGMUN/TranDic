/********************************************************************************
** Form generated from reading UI file 'qtexam2.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTEXAM2_H
#define UI_QTEXAM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtExam2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtExam2Class)
    {
        if (QtExam2Class->objectName().isEmpty())
            QtExam2Class->setObjectName(QStringLiteral("QtExam2Class"));
        QtExam2Class->resize(600, 400);
        menuBar = new QMenuBar(QtExam2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtExam2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtExam2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtExam2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtExam2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtExam2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtExam2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtExam2Class->setStatusBar(statusBar);

        retranslateUi(QtExam2Class);

        QMetaObject::connectSlotsByName(QtExam2Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtExam2Class)
    {
        QtExam2Class->setWindowTitle(QApplication::translate("QtExam2Class", "QtExam2", 0));
    } // retranslateUi

};

namespace Ui {
    class QtExam2Class: public Ui_QtExam2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEXAM2_H
