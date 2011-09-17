#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    SM = new StorageManager();
    sb = new SystemBlock();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCrear_clicked()
{
    SM->createTableSpace(ui->lnNombreBD->text().toStdString().c_str(),
                         ui->lnVersion->text().toStdString().c_str(),
                         ui->lnContra->text().toStdString().c_str(),
                         ui->spinCantidad->value());
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    x=0;

    inf = new InfoMDC[ui->spinBox->value()];
}

void MainWindow::on_pushButton_2_clicked()
{
    InfoMDC info;
    strcpy(info.nombre_campo,ui->lnNombreCampo->text().toStdString().c_str());
    strcpy(info.DEFAULT,ui->lnDefault->text().toStdString().c_str());
    info.tipo_campo = ui->spinTipo->value();

    if(info.tipo_campo == 4)
    {
        info.inicio_varchar=0;
        info.final_varchar=0;
    }

    info.size = ui->spinSize->value();
    info.PK = ui->chkPK->isChecked();
    info.nulls = ui->chkNull->isChecked();

    inf[x++] = info;

    ui->listWidget->addItem(ui->lnNombreCampo->text());

    ui->lnNombreBD->setText("");
    ui->lnDefault->setText("");
    ui->spinTipo->setValue(1);
    ui->spinSize->setValue(1);
    ui->chkPK->setChecked(false);
    ui->chkNull->setChecked(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    SM->createTable(ui->lnNombreTabla->text().toStdString().c_str(),
                    ui->spinCantidad->value(),inf);

    QMessageBox::about(0,"BIDMD",QString::number(sb->getFree()-1));

    md = new Metadata(sb->getFree()-1);

    unsigned int bid = sb->getFree();
    sb->acomodarPrimerLibre();

    Data db(bid,md->header.blockID);
    db.escribir();

    md->setInicio_BD(bid);
    md->setFinalBD(bid);

    QMessageBox::about(0,"BlockID de Data",QString::number(bid));

    ui->stackedWidget->setCurrentIndex(3);
}
