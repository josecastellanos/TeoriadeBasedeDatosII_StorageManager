/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Sep 16 20:51:25 2011
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
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
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
    QLabel *label_6;
    QLineEdit *lnNombreTabla;
    QPushButton *pushButton;
    QLabel *label_8;
    QSpinBox *spinBox;
    QWidget *page_3;
    QLabel *label_7;
    QLineEdit *lnNombreCampo;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_13;
    QSpinBox *spinSize;
    QCheckBox *chkNull;
    QCheckBox *chkPK;
    QLineEdit *lnDefault;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QSpinBox *spinTipo;
    QPushButton *pushButton_3;
    QLabel *label_11;
    QWidget *page_4;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
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
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 70, 111, 17));
        lnNombreTabla = new QLineEdit(page_2);
        lnNombreTabla->setObjectName(QString::fromUtf8("lnNombreTabla"));
        lnNombreTabla->setGeometry(QRect(150, 60, 113, 27));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 150, 111, 27));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 110, 121, 17));
        spinBox = new QSpinBox(page_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(150, 100, 111, 27));
        spinBox->setMinimum(1);
        spinBox->setMaximum(16);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 100, 111, 17));
        lnNombreCampo = new QLineEdit(page_3);
        lnNombreCampo->setObjectName(QString::fromUtf8("lnNombreCampo"));
        lnNombreCampo->setGeometry(QRect(170, 140, 113, 27));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 150, 111, 17));
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 190, 151, 17));
        label_13 = new QLabel(page_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 230, 151, 20));
        spinSize = new QSpinBox(page_3);
        spinSize->setObjectName(QString::fromUtf8("spinSize"));
        spinSize->setGeometry(QRect(170, 180, 111, 27));
        spinSize->setMinimum(1);
        spinSize->setMaximum(255);
        chkNull = new QCheckBox(page_3);
        chkNull->setObjectName(QString::fromUtf8("chkNull"));
        chkNull->setGeometry(QRect(20, 270, 97, 22));
        chkPK = new QCheckBox(page_3);
        chkPK->setObjectName(QString::fromUtf8("chkPK"));
        chkPK->setGeometry(QRect(20, 310, 97, 22));
        lnDefault = new QLineEdit(page_3);
        lnDefault->setObjectName(QString::fromUtf8("lnDefault"));
        lnDefault->setGeometry(QRect(170, 220, 113, 27));
        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 340, 97, 27));
        listWidget = new QListWidget(page_3);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(340, 90, 161, 281));
        spinTipo = new QSpinBox(page_3);
        spinTipo->setObjectName(QString::fromUtf8("spinTipo"));
        spinTipo->setGeometry(QRect(170, 100, 111, 27));
        spinTipo->setMinimum(1);
        spinTipo->setMaximum(5);
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 400, 97, 27));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 40, 111, 17));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_14 = new QLabel(page_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 10, 67, 17));
        label_15 = new QLabel(page_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(30, 40, 67, 17));
        label_16 = new QLabel(page_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(30, 70, 67, 17));
        label_17 = new QLabel(page_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(30, 100, 67, 17));
        label_18 = new QLabel(page_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 130, 67, 17));
        label_19 = new QLabel(page_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(30, 160, 67, 17));
        label_20 = new QLabel(page_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(30, 190, 67, 17));
        label_21 = new QLabel(page_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(30, 220, 67, 17));
        label_22 = new QLabel(page_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(30, 280, 67, 17));
        label_23 = new QLabel(page_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(30, 310, 67, 17));
        label_24 = new QLabel(page_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(30, 340, 67, 17));
        label_25 = new QLabel(page_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(30, 370, 67, 17));
        label_26 = new QLabel(page_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(30, 400, 67, 17));
        label_27 = new QLabel(page_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(30, 250, 67, 17));
        label_28 = new QLabel(page_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(30, 430, 67, 17));
        label_29 = new QLabel(page_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(30, 460, 67, 17));
        stackedWidget->addWidget(page_4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 784, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


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
        label_6->setText(QApplication::translate("MainWindow", "Nombre Tabla", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Add Campos", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Cantidad Campos", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Tipo campo", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Nombre Campo", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Size (Varchar y Char)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Default", 0, QApplication::UnicodeUTF8));
        chkNull->setText(QApplication::translate("MainWindow", "Null", 0, QApplication::UnicodeUTF8));
        chkPK->setText(QApplication::translate("MainWindow", "PK", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Agregar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Crear Tabla", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Crear Tabla", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
