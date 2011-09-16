/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Sep 16 16:41:22 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLineEdit *lnNombreBD;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lnVersion;
    QLineEdit *lnContra;
    QSpinBox *spinCantidad;
    QPushButton *btnCrear;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(784, 536);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 781, 481));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 141, 17));
        lnNombreBD = new QLineEdit(page);
        lnNombreBD->setObjectName(QString::fromUtf8("lnNombreBD"));
        lnNombreBD->setGeometry(QRect(160, 100, 113, 27));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 110, 91, 17));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 150, 81, 17));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 190, 111, 17));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 230, 131, 17));
        lnVersion = new QLineEdit(page);
        lnVersion->setObjectName(QString::fromUtf8("lnVersion"));
        lnVersion->setGeometry(QRect(160, 140, 113, 27));
        lnContra = new QLineEdit(page);
        lnContra->setObjectName(QString::fromUtf8("lnContra"));
        lnContra->setGeometry(QRect(160, 180, 113, 27));
        spinCantidad = new QSpinBox(page);
        spinCantidad->setObjectName(QString::fromUtf8("spinCantidad"));
        spinCantidad->setGeometry(QRect(160, 220, 111, 27));
        btnCrear = new QPushButton(page);
        btnCrear->setObjectName(QString::fromUtf8("btnCrear"));
        btnCrear->setGeometry(QRect(140, 280, 131, 27));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 784, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Create TableSpace", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Nombre BD", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Version DB", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Contrase\303\261a BD", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Cantidad Bloques", 0, QApplication::UnicodeUTF8));
        btnCrear->setText(QApplication::translate("MainWindow", "Crear TableSpace", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
