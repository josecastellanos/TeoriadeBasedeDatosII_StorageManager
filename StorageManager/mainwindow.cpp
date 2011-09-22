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
    unsigned int _md = ui->lineEditMD->text().toUInt();
    unsigned int bid = ui->lineEdit_5->text().toUInt();

    Metadata md(_md);

    InfoMDC campo1 = md.readCampo(0);
    InfoMDC campo2 = md.readCampo(1);
    InfoMDC campo3 = md.readCampo(2);
    InfoMDC campo4 = md.readCampo(3);
    InfoMDC campo5 = md.readCampo(4);

    unsigned int sizeMalloc = 0;

    mapabits m(0);

    if(ui->checkBox_3->isChecked()){ m.setOn(0); }
    else{
        switch(campo1.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->lineEdit1->text().size() + 1;
                break;
            case 4:
                sizeMalloc+=1 + ui->lineEdit1->text().size() + 1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }
    if(ui->checkBox_4->isChecked()){ m.setOn(1); }
    else{
        switch(campo2.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->lineEdit2->text().size()+1;
                break;
            case 4:
                sizeMalloc+=1+ui->lineEdit2->text().size()+1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }
    if(ui->checkBox_5->isChecked()){ m.setOn(2); }
    else{
        switch(campo3.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->lineEdit3->text().size()+1;
                break;
            case 4:
                sizeMalloc+=1+ui->lineEdit3->text().size()+1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }
    if(ui->checkBox_6->isChecked()){ m.setOn(3); }
    else{
        switch(campo4.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->lineEdit4->text().size()+1;
                break;
            case 4:
                sizeMalloc+=1+ui->lineEdit4->text().size()+1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }
    if(ui->checkBox_7->isChecked()){ m.setOn(4); }
    else{
        switch(campo5.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->lineEdit5->text().size()+1;
                break;
            case 4:
                sizeMalloc+=1+ui->lineEdit5->text().size()+1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }

    unsigned char *contenido = (unsigned char*)malloc(sizeMalloc);

    if(!ui->checkBox_3->isChecked())
    {
        switch(campo1.tipo_campo)
        {
            case 1:
                {
                    int _int = ui->lineEdit1->text().toInt();
                    memcpy(contenido,&_int,sizeof(int));
                    contenido+=sizeof(int);
                }
                break;
            case 2:
                {
                    double _double = ui->lineEdit1->text().toDouble();
                    memcpy(contenido,&_double,sizeof(double));
                    contenido+=sizeof(double);
                }
                break;
            case 3:
                {
                    string _char = ui->lineEdit1->text().toStdString();
                    memcpy(contenido,_char.c_str(),sizeof(char)*ui->lineEdit1->text().size()+1);
                    contenido+=sizeof(char)*ui->lineEdit1->text().size()+1;
                }
                break;
            case 4:
                {
                string _varchar = ui->lineEdit1->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->lineEdit1->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }
    if(!ui->checkBox_4->isChecked())
    {
        switch(campo2.tipo_campo)
        {
            case 1:
        {
                int _int = ui->lineEdit2->text().toInt();
                memcpy(contenido,&_int,sizeof(int));
                contenido+=sizeof(int);
        }
                break;
            case 2:
        {
                double _double = ui->lineEdit2->text().toDouble();
                memcpy(contenido,&_double,sizeof(double));
                contenido+=sizeof(double);
        }
                break;
            case 3:
        {
                string _char = ui->lineEdit2->text().toStdString();
                memcpy(contenido,_char.c_str(),sizeof(char)*ui->lineEdit2->text().size()+1);
                contenido+=sizeof(char)*ui->lineEdit2->text().size()+1;
        }
                break;
            case 4:
        {
                string _varchar = ui->lineEdit2->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->lineEdit2->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }
    if(!ui->checkBox_5->isChecked())
    {
        switch(campo3.tipo_campo)
        {
            case 1:
        {
                int _int = ui->lineEdit3->text().toInt();
                memcpy(contenido,&_int,sizeof(int));
                contenido+=sizeof(int);
        }
                break;
            case 2:
        {
                double _double = ui->lineEdit3->text().toDouble();
                memcpy(contenido,&_double,sizeof(double));
                contenido+=sizeof(double);
        }
                break;
            case 3:
        {
                string _char = ui->lineEdit3->text().toStdString();
                memcpy(contenido,_char.c_str(),sizeof(char)*ui->lineEdit3->text().size()+1);
                contenido+=sizeof(char)*ui->lineEdit3->text().size()+1;
        }
                break;
            case 4:
        {
                string _varchar = ui->lineEdit3->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->lineEdit3->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }
    if(!ui->checkBox_6->isChecked())
    {
        switch(campo4.tipo_campo)
        {
            case 1:
        {
                int _int = ui->lineEdit4->text().toInt();
                memcpy(contenido,&_int,sizeof(int));
                contenido+=sizeof(int);
        }
                break;
            case 2:
        {
                double _double = ui->lineEdit4->text().toDouble();
                memcpy(contenido,&_double,sizeof(double));
                contenido+=sizeof(double);
        }
                break;
            case 3:
        {
                string _char = ui->lineEdit4->text().toStdString();
                memcpy(contenido,_char.c_str(),sizeof(char)*ui->lineEdit4->text().size()+1);
                contenido+=sizeof(char)*ui->lineEdit4->text().size()+1;
        }
                break;
            case 4:
        {
                string _varchar = ui->lineEdit4->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->lineEdit4->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }
    if(!ui->checkBox_7->isChecked())
    {
        switch(campo5.tipo_campo)
        {
            case 1:
        {
                int _int = ui->lineEdit5->text().toInt();
                memcpy(contenido,&_int,sizeof(int));
                contenido+=sizeof(int);
        }
                break;
            case 2:
        {
                double _double = ui->lineEdit5->text().toDouble();
                memcpy(contenido,&_double,sizeof(double));
                contenido+=sizeof(double);
        }
                break;
            case 3:
        {
                string _char = ui->lineEdit5->text().toStdString();
                memcpy(contenido,_char.c_str(),sizeof(char)*ui->lineEdit5->text().size()+1);
                contenido+=sizeof(char)*ui->lineEdit5->text().size()+1;
        }
                break;
            case 4:
        {
                string _varchar = ui->lineEdit5->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->lineEdit5->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }

    contenido-=sizeMalloc;

    Data db(bid);

    Registro reg(m.getMapa(),sizeMalloc,false,contenido);
    db.insertRecord(reg);

    ui->lineEdit1->setText("");
    ui->lineEdit2->setText("");
    ui->lineEdit3->setText("");
    ui->lineEdit4->setText("");
    ui->lineEdit5->setText("");

    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);

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
    ui->lineEdit1_->setText("");
    ui->lineEdit2_->setText("");
    ui->lineEdit3_->setText("");
    ui->lineEdit4_->setText("");
    ui->lineEdit5_->setText("");

    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->lineEdit1_->setText("");
    ui->lineEdit2_->setText("");
    ui->lineEdit3_->setText("");
    ui->lineEdit4_->setText("");
    ui->lineEdit5_->setText("");

    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);

    unsigned int bid = ui->lineEdit_6->text().toUInt();
    unsigned int mdid = ui->lineEdit_12->text().toUInt();
    unsigned int index = ui->lineEdit_11->text().toUInt();

    Metadata md(mdid);

    InfoMDC campo1 = md.readCampo(0);
    InfoMDC campo2 = md.readCampo(1);
    InfoMDC campo3 = md.readCampo(2);
    InfoMDC campo4 = md.readCampo(3);
    InfoMDC campo5 = md.readCampo(4);

    Data db(bid);

    Registro reg;
    reg = db.selectRecord(index);

    mapabits m(reg.getNulos());

    if (m.getAt(0)) { ui->checkBox_8->setChecked(true); }
    else{
        switch(campo1.tipo_campo)
        {
            case 1:
                ui->lineEdit1_->setText(QString::number(*(reg.readCampo(0,mdid))));
                break;
            case 2:
                {
                    unsigned char *temp = reg.readCampo(0,mdid);
                    double x;
                    memcpy(&x,temp,sizeof(double));
                    ui->lineEdit1_->setText(QString::number(x));
                }
                break;
            case 3:
                ui->lineEdit1_->setText(QString((char*)reg.readCampo(0,mdid)));
                break;
            case 4:
                ui->lineEdit1_->setText(QString((char*)reg.readCampo(0,mdid)));
                break;
            case 5:
                {
                    unsigned char *temp = reg.readCampo(0,mdid);
                    bool x;
                    memcpy(&x,temp,sizeof(bool));
                    if(x) { ui->lineEdit1_->setText("true"); }else{ ui->lineEdit1_->setText("false"); }
                }
                break;
        }
    }
    if (m.getAt(1)) { ui->checkBox_9->setChecked(true); }
    else{
        switch(campo2.tipo_campo)
        {
            case 1:
                ui->lineEdit2_->setText(QString::number(*(reg.readCampo(1,mdid))));
                break;
            case 2:
                {
                    unsigned char *temp = reg.readCampo(1,mdid);
                    double x;
                    memcpy(&x,temp,sizeof(double));
                    ui->lineEdit2_->setText(QString::number(x));
                }
                break;
            case 3:
                ui->lineEdit2_->setText(QString((char*)reg.readCampo(1,mdid)));
                break;
            case 4:
                ui->lineEdit2_->setText(QString((char*)reg.readCampo(1,mdid)));
                break;
            case 5:
                {
                    unsigned char *temp = reg.readCampo(1,mdid);
                    bool x;
                    memcpy(&x,temp,sizeof(bool));
                    if(x) { ui->lineEdit2_->setText("true"); }else{ ui->lineEdit2_->setText("false"); }
                }
                break;
        }
    }
    if (m.getAt(2)) { ui->checkBox_10->setChecked(true); }
    else{
        switch(campo3.tipo_campo)
        {
            case 1:
                ui->lineEdit3_->setText(QString::number(*(reg.readCampo(2,mdid))));
                break;
            case 2:
                {
                    unsigned char *temp = reg.readCampo(2,mdid);
                    double x;
                    memcpy(&x,temp,sizeof(double));
                    ui->lineEdit3_->setText(QString::number(x));
                }
                break;
            case 3:
                ui->lineEdit3_->setText(QString((char*)reg.readCampo(2,mdid)));
                break;
            case 4:
                ui->lineEdit3_->setText(QString((char*)reg.readCampo(2,mdid)));
                break;
            case 5:
                {
                    unsigned char *temp = reg.readCampo(2,mdid);
                    bool x;
                    memcpy(&x,temp,sizeof(bool));
                    if(x) { ui->lineEdit3_->setText("true"); }else{ ui->lineEdit3_->setText("false"); }
                }
                break;
        }
    }
    if (m.getAt(3)) { ui->checkBox_11->setChecked(true); }
    else{
        switch(campo4.tipo_campo)
        {
            case 1:
                ui->lineEdit4_->setText(QString::number(*(reg.readCampo(3,mdid))));
                break;
            case 2:
                {
                    unsigned char *temp = reg.readCampo(3,mdid);
                    double x;
                    memcpy(&x,temp,sizeof(double));
                    ui->lineEdit4_->setText(QString::number(x));
                }
                break;
            case 3:
                ui->lineEdit4_->setText(QString((char*)reg.readCampo(3,mdid)));
                break;
            case 4:
                ui->lineEdit4_->setText(QString((char*)reg.readCampo(3,mdid)));
                break;
            case 5:
                {
                    unsigned char *temp = reg.readCampo(3,mdid);
                    bool x;
                    memcpy(&x,temp,sizeof(bool));
                    if(x) { ui->lineEdit4_->setText("true"); }else{ ui->lineEdit4_->setText("false"); }
                }
                break;
        }
    }
    if (m.getAt(4)) { ui->checkBox_10->setChecked(true); }
    else{
        switch(campo5.tipo_campo)
        {
            case 1:
                ui->lineEdit5_->setText(QString::number(*(reg.readCampo(4,mdid))));
                break;
            case 2:
                {
                    unsigned char *temp = reg.readCampo(4,mdid);
                    double x;
                    memcpy(&x,temp,sizeof(double));
                    ui->lineEdit5_->setText(QString::number(x));
                }
                break;
            case 3:
                ui->lineEdit5_->setText(QString((char*)reg.readCampo(4,mdid)));
                break;
            case 4:
                ui->lineEdit5_->setText(QString((char*)reg.readCampo(4,mdid)));
                break;
            case 5:
                {
                    unsigned char *temp = reg.readCampo(4,mdid);
                    bool x;
                    memcpy(&x,temp,sizeof(bool));
                    if(x) { ui->lineEdit5_->setText("true"); }else{ ui->lineEdit5_->setText("false"); }
                }
                break;
        }
    }
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
    int _md = ui->lineEdit_13->text().toInt();
    Metadata md(_md);

    InfoMDC campo1 = md.readCampo(0);
    InfoMDC campo2 = md.readCampo(1);
    InfoMDC campo3 = md.readCampo(2);
    InfoMDC campo4 = md.readCampo(3);
    InfoMDC campo5 = md.readCampo(4);

    unsigned int sizeMalloc = 0;

    mapabits m(0);

    if(ui->checkBox_38->isChecked()){ m.setOn(0); }
    else{
        switch(campo1.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->_lineEdit1->text().size()+1;
                break;
            case 4:
                sizeMalloc+=1+ui->_lineEdit1->text().size()+1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }
    if(ui->checkBox_39->isChecked()){ m.setOn(1); }
    else{
        switch(campo2.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->_lineEdit2->text().size()+1;
                break;
            case 4:
                sizeMalloc+=1+ui->_lineEdit2->text().size()+1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }
    if(ui->checkBox_40->isChecked()){ m.setOn(2); }
    else{
        switch(campo3.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->_lineEdit3->text().size()+1;
                break;
            case 4:
                sizeMalloc+=1+ui->_lineEdit3->text().size()+1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }
    if(ui->checkBox_41->isChecked()){ m.setOn(3); }
    else{
        switch(campo4.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->_lineEdit4->text().size()+1;
                break;
            case 4:
                sizeMalloc+=1+ui->_lineEdit4->text().size()+1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }
    if(ui->checkBox_42->isChecked()){ m.setOn(4); }
    else{
        switch(campo5.tipo_campo)
        {
            case 1:
                sizeMalloc+=sizeof(int);
                break;
            case 2:
                sizeMalloc+=sizeof(double);
                break;
            case 3:
                sizeMalloc+=sizeof(char)*ui->_lineEdit5->text().size()+1;
                break;
            case 4:
                sizeMalloc+=1+ui->_lineEdit5->text().size()+1;
                break;
            case 5:
                sizeMalloc+=sizeof(bool);
                break;
        }
    }

    unsigned char *contenido = (unsigned char*)malloc(sizeMalloc);

    if(!ui->checkBox_38->isChecked())
    {
        switch(campo1.tipo_campo)
        {
            case 1:
        {
                int _int = ui->_lineEdit1->text().toInt();
                memcpy(contenido,&_int,sizeof(int));
                contenido+=sizeof(int);
        }
                break;
            case 2:
        {
                double _double = ui->_lineEdit1->text().toDouble();
                memcpy(contenido,&_double,sizeof(double));
                contenido+=sizeof(double);
        }
                break;
            case 3:
        {
                string _char = ui->_lineEdit1->text().toStdString();
                memcpy(contenido,_char.c_str(),sizeof(char)*ui->_lineEdit1->text().size()+1);
                contenido+=sizeof(char)*ui->_lineEdit1->text().size()+1;
        }
                break;
            case 4:
        {
                string _varchar = ui->_lineEdit1->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->_lineEdit1->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }
    if(!ui->checkBox_39->isChecked())
    {
        switch(campo2.tipo_campo)
        {
            case 1:
        {
                int _int = ui->_lineEdit2->text().toInt();
                memcpy(contenido,&_int,sizeof(int));
                contenido+=sizeof(int);
        }
                break;
            case 2:
        {
                double _double = ui->_lineEdit2->text().toDouble();
                memcpy(contenido,&_double,sizeof(double));
                contenido+=sizeof(double);
        }
                break;
            case 3:
        {
                string _char = ui->_lineEdit2->text().toStdString();
                memcpy(contenido,_char.c_str(),sizeof(char)*ui->_lineEdit2->text().size()+1);
                contenido+=sizeof(char)*ui->_lineEdit2->text().size()+1;
        }
                break;
            case 4:
        {
                string _varchar = ui->_lineEdit2->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->_lineEdit2->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }
    if(!ui->checkBox_40->isChecked())
    {
        switch(campo3.tipo_campo)
        {
            case 1:
        {
                int _int = ui->_lineEdit3->text().toInt();
                memcpy(contenido,&_int,sizeof(int));
                contenido+=sizeof(int);
        }
                break;
            case 2:
        {
                double _double = ui->_lineEdit3->text().toDouble();
                memcpy(contenido,&_double,sizeof(double));
                contenido+=sizeof(double);
        }
                break;
            case 3:
        {
                string _char = ui->_lineEdit3->text().toStdString();
                memcpy(contenido,_char.c_str(),sizeof(char)*ui->_lineEdit3->text().size()+1);
                contenido+=sizeof(char)*ui->_lineEdit3->text().size()+1;
        }
                break;
            case 4:
        {
                string _varchar = ui->lineEdit3->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->_lineEdit3->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }
    if(!ui->checkBox_41->isChecked())
    {
        switch(campo4.tipo_campo)
        {
            case 1:
        {
                int _int = ui->_lineEdit4->text().toInt();
                memcpy(contenido,&_int,sizeof(int));
                contenido+=sizeof(int);
        }
                break;
            case 2:
        {
                double _double = ui->_lineEdit4->text().toDouble();
                memcpy(contenido,&_double,sizeof(double));
                contenido+=sizeof(double);
        }
                break;
            case 3:
        {
                string _char = ui->_lineEdit4->text().toStdString();
                memcpy(contenido,_char.c_str(),sizeof(char)*ui->_lineEdit4->text().size()+1);
                contenido+=sizeof(char)*ui->_lineEdit4->text().size()+1;
        }
                break;
            case 4:
        {
                string _varchar = ui->_lineEdit4->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->_lineEdit4->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }
    if(!ui->checkBox_42->isChecked())
    {
        switch(campo5.tipo_campo)
        {
            case 1:
        {
                int _int = ui->_lineEdit5->text().toInt();
                memcpy(contenido,&_int,sizeof(int));
                contenido+=sizeof(int);
        }
                break;
            case 2:
        {
                double _double = ui->_lineEdit5->text().toDouble();
                memcpy(contenido,&_double,sizeof(double));
                contenido+=sizeof(double);
        }
                break;
            case 3:
        {
                string _char = ui->_lineEdit5->text().toStdString();
                memcpy(contenido,_char.c_str(),sizeof(char)*ui->_lineEdit5->text().size()+1);
                contenido+=sizeof(char)*ui->_lineEdit5->text().size()+1;
        }
                break;
            case 4:
        {
                string _varchar = ui->_lineEdit5->text().toStdString();
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
                break;
            case 5:
        {
                bool _boolean = ui->_lineEdit5->text() == "true" ? true : false;
                memcpy(contenido,&_boolean,sizeof(bool));
                contenido+=sizeof(bool);
        }
                break;
        }
    }

    contenido-=sizeMalloc;

    Data db(bid);

    Registro reg(m.getMapa(),sizeMalloc,false,contenido);
    db.updateRecord(reg,index);

    ui->_lineEdit1->setText("");
    ui->_lineEdit2->setText("");
    ui->_lineEdit3->setText("");
    ui->_lineEdit4->setText("");
    ui->_lineEdit5->setText("");

    ui->checkBox_38->setChecked(false);
    ui->checkBox_39->setChecked(false);
    ui->checkBox_40->setChecked(false);
    ui->checkBox_41->setChecked(false);
    ui->checkBox_42->setChecked(false);

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
