#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Metadata.h"
#include "StorageManager.h"
#include "SystemBlock.h"
#include "Data.h"
#include <QMessageBox>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnCrear_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_btnCrear_2_clicked();

    void on_btnCrear_3_clicked();

    void on_btnCrear_4_clicked();

    void on_btnCrear_5_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();

    void on_btnCrear_16_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_btnCrear_35_clicked();

    void on_pushButton_71_clicked();

private:
    Ui::MainWindow *ui;
    StorageManager *SM;
    SystemBlock *sb;
    Metadata *md;
    InfoMDC *inf;
    int x;
};

#endif // MAINWINDOW_H
