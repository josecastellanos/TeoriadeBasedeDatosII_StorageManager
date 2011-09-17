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

private:
    Ui::MainWindow *ui;
    StorageManager *SM;
    SystemBlock *sb;
    Metadata *md;
    int x;
    InfoMDC *inf;
};

#endif // MAINWINDOW_H
