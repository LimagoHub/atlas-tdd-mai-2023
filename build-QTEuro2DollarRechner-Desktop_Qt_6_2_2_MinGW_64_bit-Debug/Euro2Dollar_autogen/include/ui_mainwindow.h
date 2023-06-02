/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_rechnen;
    QLineEdit *txt_euro;
    QLineEdit *txt_dollar;
    QPushButton *btn_ende;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(219, 134);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_rechnen = new QPushButton(centralwidget);
        btn_rechnen->setObjectName(QString::fromUtf8("btn_rechnen"));
        btn_rechnen->setEnabled(false);
        btn_rechnen->setGeometry(QRect(20, 70, 80, 18));
        txt_euro = new QLineEdit(centralwidget);
        txt_euro->setObjectName(QString::fromUtf8("txt_euro"));
        txt_euro->setGeometry(QRect(70, 10, 113, 20));
        txt_dollar = new QLineEdit(centralwidget);
        txt_dollar->setObjectName(QString::fromUtf8("txt_dollar"));
        txt_dollar->setEnabled(false);
        txt_dollar->setGeometry(QRect(70, 40, 113, 20));
        btn_ende = new QPushButton(centralwidget);
        btn_ende->setObjectName(QString::fromUtf8("btn_ende"));
        btn_ende->setGeometry(QRect(100, 70, 80, 18));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 37, 12));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 37, 12));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 219, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_rechnen->setText(QCoreApplication::translate("MainWindow", "Rechnen", nullptr));
        btn_ende->setText(QCoreApplication::translate("MainWindow", "Beenden", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Euro:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Dollar:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
