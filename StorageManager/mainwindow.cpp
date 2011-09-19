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
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
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
                    ui->spinBox->value(),inf);

    QMessageBox::about(0,"BIDMD",QString::number(sb->getFree()-1));

    md = new Metadata(sb->getFree()-1);

    unsigned int bid = sb->getFree();
    sb->acomodarPrimerLibre();

    Data db(bid,md->header.blockID);
    db.escribir();

    md->setInicio_BD(bid);
    md->setFinalBD(bid);

    QMessageBox::about(0,"BlockID Data",QString::number(bid));

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    unsigned int bid = ui->lineEdit_5->text().toUInt();
    int sizeChar = ui->lineEdit_37->text().toInt();

    int _int = ui->lineEdit->text().toInt();
    double _double = ui->lineEdit_2->text().toDouble();
    string _char = ui->lineEdit_3->text().toStdString();
    string _varchar = ui->lineEdit_4->text().toStdString();
    bool _boolean = ui->checkBox->isChecked();

    unsigned int sizeMalloc = 0;

    mapabits m(0);

    if(ui->checkBox_3->isChecked()){ m.setOn(0); }else{ sizeMalloc+=sizeof(int); }
    if(ui->checkBox_4->isChecked()){ m.setOn(1); }else{ sizeMalloc+=sizeof(double); }
    if(ui->checkBox_5->isChecked()){ m.setOn(2); }else{ sizeMalloc+=sizeof(char)*sizeChar+1; }
    if(ui->checkBox_6->isChecked()){ m.setOn(3); }else{ sizeMalloc+=1+_varchar.size()+1; }
    if(ui->checkBox_7->isChecked()){ m.setOn(4); }else{ sizeMalloc+=sizeof(bool); }

    unsigned char *contenido = (unsigned char*)malloc(sizeMalloc);

    if(!ui->checkBox_3->isChecked())
    {
        memcpy(contenido,&_int,sizeof(int));
        contenido+=sizeof(int);
    }
    if(!ui->checkBox_4->isChecked())
    {
        memcpy(contenido,&_double,sizeof(double));
        contenido+=sizeof(double);
    }
    if(!ui->checkBox_5->isChecked())
    {
        memcpy(contenido,_char.c_str(),sizeof(char)*sizeChar+1);
        contenido+=sizeof(char)*sizeChar+1;
    }
    if(!ui->checkBox_6->isChecked())
    {
        unsigned char *temp = (unsigned char*)malloc(1+_varchar.size()+1);
        unsigned char size = _varchar.size();
        memcpy(temp,&size,sizeof(unsigned char));
        temp+=sizeof(unsigned char);
        memcpy(temp,_varchar.c_str(),(int)size+1);
        temp-=sizeof(unsigned char);
        temp[1+_varchar.size()]='\0';

        memcpy(contenido,temp,1+_varchar.size()+1);
        contenido+=1+_varchar.size()+1;
    }
    if(!ui->checkBox_7->isChecked())
    {
        memcpy(contenido,&_boolean,sizeof(bool));
        contenido+=sizeof(bool);
    }

    contenido-=sizeMalloc;

    Data db(bid);

    Registro reg(m.getMapa(),sizeMalloc,false,contenido);
    db.insertRecord(reg);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btnCrear_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnCrear_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnCrear_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnCrear_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_11_clicked()
{
    unsigned int bid = ui->lineEdit_6->text().toUInt();
    unsigned int mdid = ui->lineEdit_12->text().toUInt();
    unsigned int index = ui->lineEdit_11->text().toUInt();

    Data db(bid);

    Registro reg;
    reg = db.selectRecord(index);

    mapabits m(reg.getNulos());

    unsigned char*temp = reg.readCampo(1,mdid);
    double x;
    memcpy(&x,temp,sizeof(double));

    m.getAt(0) ? ui->checkBox_8->setChecked(true) : ui->lineEdit_7->setText(QString::number(*(reg.readCampo(0,mdid))));
    m.getAt(1) ? ui->checkBox_9->setChecked(true) : ui->lineEdit_8->setText(QString::number(x));
    m.getAt(2) ? ui->checkBox_10->setChecked(true) : ui->lineEdit_9->setText(QString((char*)reg.readCampo(2,mdid)));
    m.getAt(3) ? ui->checkBox_11->setChecked(true) : ui->lineEdit_10->setText(QString((char*)reg.readCampo(3,mdid)));
    m.getAt(4) ? ui->checkBox_10->setChecked(true) : ui->checkBox_2->setChecked(*(reg.readCampo(4,mdid)));
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_btnCrear_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_34_clicked()
{
    unsigned int bid = ui->lineEdit_45->text().toUInt();
    unsigned int index = ui->lineEdit_46->text().toUInt();
    int sizeChar = ui->lineEdit_38->text().toInt();

    int _int = ui->lineEdit_40->text().toInt();
    double _double = ui->lineEdit_41->text().toDouble();
    string _char = ui->lineEdit_42->text().toStdString();
    string _varchar = ui->lineEdit_43->text().toStdString();
    bool _boolean = ui->checkBox_37->isChecked();

    unsigned int sizeMalloc = 0;

    mapabits m(0);

    if(ui->checkBox_38->isChecked()){ m.setOn(0); }else{ sizeMalloc+=sizeof(int); }
    if(ui->checkBox_39->isChecked()){ m.setOn(1); }else{ sizeMalloc+=sizeof(double); }
    if(ui->checkBox_40->isChecked()){ m.setOn(2); }else{ sizeMalloc+=sizeof(char)*sizeChar+1; }
    if(ui->checkBox_41->isChecked()){ m.setOn(3); }else{ sizeMalloc+=1+_varchar.size()+1; }
    if(ui->checkBox_42->isChecked()){ m.setOn(4); }else{ sizeMalloc+=sizeof(bool); }

    unsigned char *contenido = (unsigned char*)malloc(sizeMalloc);

    if(!ui->checkBox_38->isChecked())
    {
        memcpy(contenido,&_int,sizeof(int));
        contenido+=sizeof(int);
    }
    if(!ui->checkBox_39->isChecked())
    {
        memcpy(contenido,&_double,sizeof(double));
        contenido+=sizeof(double);
    }
    if(!ui->checkBox_40->isChecked())
    {
        memcpy(contenido,_char.c_str(),sizeof(char)*sizeChar+1);
        contenido+=sizeof(char)*sizeChar+1;
    }
    if(!ui->checkBox_41->isChecked())
    {
        unsigned char *temp = (unsigned char*)malloc(1+_varchar.size()+1);
        unsigned char size = _varchar.size();
        memcpy(temp,&size,sizeof(unsigned char));
        temp+=sizeof(unsigned char);
        memcpy(temp,_varchar.c_str(),(int)size+1);
        temp-=sizeof(unsigned char);
        temp[1+_varchar.size()]='\0';

        memcpy(contenido,temp,1+_varchar.size()+1);
        contenido+=1+_varchar.size()+1;
    }
    if(!ui->checkBox_42->isChecked())
    {
        memcpy(contenido,&_boolean,sizeof(bool));
        contenido+=sizeof(bool);
    }

    contenido-=sizeMalloc;

    Data db(bid);

    Registro reg(m.getMapa(),sizeMalloc,false,contenido);
    db.updateRecord(reg,index);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_btnCrear_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_71_clicked()
{
    unsigned int blockID = ui->lineEdit_106->text().toUInt();
    unsigned int index = ui->lineEdit_105->text().toUInt();

    Data db(blockID);

    db.deleteRecord(index);

    ui->stackedWidget->setCurrentIndex(0);
}
