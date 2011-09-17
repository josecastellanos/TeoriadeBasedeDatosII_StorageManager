//#include <QtGui/QApplication>
//#include "mainwindow.h"

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <QString>
#include "Metadata.h"
#include "StorageManager.h"
#include "SystemBlock.h"
#include "Data.h"
using namespace std;

int main(int argc, char *argv[])
{

    StorageManager *SM = new StorageManager();
    //SM->createTableSpace("myDB","1.0.0","123",40);
    InfoMDC campo1;
    strcpy(campo1.nombre_campo,"campo1");
    campo1.tipo_campo=1;
    InfoMDC campo2;
    strcpy(campo2.nombre_campo,"campo2");
    //campo2.tipo_campo=1;
    campo2.tipo_campo=4;
    campo2.size=10;
    campo2.inicio_varchar=0;
    campo2.final_varchar=0;

    InfoMDC campos[] = {campo1,campo2};
     //SM->createTable("tabla2",2,campos);


     SystemBlock sb;
     //Metadata md(sb.getFree()-1);
     Metadata md(4);

    /*unsigned int bid = sb.getFree();
    sb.acomodarPrimerLibre();*/

    //Data db(bid,md.getBlockID());
    Data db(md.getInicio_BD());
    //db.escribir();

    //md.setInicio_BD(bid);
    //md.setFinalBD(bid);


     printf("%d\n",md.getBlockID());
     printf("%s\n",md.get_nombreTabla());
     printf("%u\n",md.getInicio_BD());
     printf("%u\n",sb.getPrimerMD());
     printf("%u\n",sb.getUltimoMD());
     printf("%u\n",md.getAnt());
     printf("%u\n",md.getSig());

     //unsigned char *contenido = (unsigned char *)malloc(sizeof(unsigned char)*11);
    //unsigned char *contenido = (unsigned char *)malloc(8);
    //printf("\ncontenido p: %p\n",contenido);

//----------------------------------------------------------------------------------

    //Esto es para probar lo de varchars

//     unsigned char *temp = (unsigned char*)malloc(7);
//     printf("\ntemp: %p\n",temp);
//     unsigned char y = 5;
//         memcpy(temp,&y,sizeof(unsigned char));
//         temp+=sizeof(unsigned char);
//         string z = "Maria";
//         //char* cadena = (char*)z.c_str();
//         memcpy(temp,z.c_str(),(int)y+1);
//         //temp+=y+1;
//         temp-=sizeof(unsigned char);
//         temp[6]='\0';
//        printf("\ntemp: %p\n",temp);

////-----------------------------------------------------------------------------------------

//         int x = 6;
//         //int y = 77;
//     memcpy(contenido,&x,sizeof(int));
//     contenido+=sizeof(int);
//     //memcpy(contenido,&y,sizeof(int));
//     memcpy(contenido,temp,7);
//     contenido-=(sizeof(int));

//     printf("\ncontenido p: %p\n",contenido);
//     printf("\not_insert:%p\n",contenido);
//     //printf("\ncontenido:%s\n",contenido);

//     //unsigned char *copia = contenido;

//     Registro reg(0,11,false,contenido); //con varchar
//     //Registro reg(0,8,false,contenido); //solo con dos ints
//     reg.setContentReg(contenido);
//     db.insertRecord(reg);
//     free(contenido);

//------------------------------------------------------------------------------------------------

     //Probando doble insert

          unsigned char *temp = (unsigned char*)malloc(7);
          printf("\ntemp: %p\n",temp);
          unsigned char y = 5;
              memcpy(temp,&y,sizeof(unsigned char));
              temp+=sizeof(unsigned char);
              string z = "Maria";
              //char* cadena = (char*)z.c_str();
              memcpy(temp,z.c_str(),(int)y+1);
              //temp+=y+1;
              temp-=sizeof(unsigned char);
              temp[6]='\0';
             printf("\ntemp: %p\n",temp);

    unsigned char *contenido = (unsigned char *)malloc(11);
    printf("\ncontenido p: %p\n",contenido);

              int x = 6;
              //int y = 77;
          memcpy(contenido,&x,sizeof(int));
          contenido+=sizeof(int);
          //memcpy(contenido,&y,sizeof(int));
          memcpy(contenido,temp,7);
          contenido-=(sizeof(int));

     Registro reg(0,11,false,contenido);
     reg.setContentReg(contenido);
     db.insertRecord(reg);
     free(contenido);


     unsigned char *contenido2 = (unsigned char *)malloc(11);

     unsigned char *temp2 = (unsigned char*)malloc(7);
     printf("\ntemp: %p\n",temp2);
     y = 5;
         memcpy(temp2,&y,sizeof(unsigned char));
         temp2+=sizeof(unsigned char);
         z = "Pedro";
         //char* cadena = (char*)z.c_str();
         memcpy(temp2,z.c_str(),(int)y+1);
         //temp+=y+1;
         temp2-=sizeof(unsigned char);
         temp2[6]='\0';
        //printf("\ntemp: %p\n",temp2);

     int x2 = 100;

      memcpy(contenido2,&x2,sizeof(int));
      contenido2+=sizeof(int);
      //memcpy(contenido2,&y2,sizeof(int));
      memcpy(contenido2,temp2,7);
      contenido2-=(sizeof(int));

      Registro reg2(0,11,false,contenido2);
      reg2.setContentReg(contenido2);
      db.insertRecord(reg2);
      free(contenido2);

      unsigned char *contenido3 = (unsigned char *)malloc(11);

      unsigned char *temp3 = (unsigned char*)malloc(7);
      printf("\ntemp: %p\n",temp3);
      y = 5;
          memcpy(temp3,&y,sizeof(unsigned char));
          temp3+=sizeof(unsigned char);
          z = "Buuuu";
          //char* cadena = (char*)z.c_str();
          memcpy(temp3,z.c_str(),(int)y+1);
          //temp+=y+1;
          temp3-=sizeof(unsigned char);
          temp3[6]='\0';
         printf("\ntemp: %p\n",temp3);

      int x3 = 99;
      //int y3 = 76;
       memcpy(contenido3,&x3,sizeof(int));
       contenido3+=sizeof(int);
       //memcpy(contenido3,&y3,sizeof(int));
       memcpy(contenido3,temp3,7);
       contenido3-=(sizeof(int));

       Registro reg3(0,11,false,contenido3);
       reg3.setContentReg(contenido3);
      db.updateRecord(reg3,0);
      free(contenido3);

//------------------------------------------------------------------------------------------------*/

     /*contenido = (unsigned char *)malloc(sizeof(unsigned char)*8);
     x = 7;
     y = 8;
     memcpy(contenido,&x,sizeof(int));
     contenido+=sizeof(int);
     memcpy(contenido,&y,sizeof(int));
     contenido-=sizeof(int);
     reg.setContentReg(contenido);

     db.updateRecord(reg,0);
     free(contenido);

     //db.deleteRecord(0);*/

     try
     {
        reg = db.selectRecord(1);

        //unsigned char *temp = reg.getContentReg();
        unsigned char *_temp = reg.readCampo(1,md.header.blockID); //Esto es para varchar
        printf("\n%s\n",_temp)   ;


        /*x = 0;
        y = 0;

        memcpy(&x,temp,sizeof(int));
        temp+=sizeof(int);
        memcpy(&y,temp,sizeof(int));

        printf("\nx: %d\n",x);
        printf("y: %d\n",y);*/
     }
     catch(SMException ex)
     {
         printf("%s",ex.what());
     }

     //De aqui para abajo no parar bola

     //cout<<md.getrecordsize();
//    unsigned char *temp = (unsigned char*)malloc(15);
//    unsigned int x=155;
//    memcpy(temp,&x,sizeof(unsigned int));
//    temp+=sizeof(unsigned int);
//    x=4;
//    memcpy(temp,&x,sizeof(unsigned int));
//    temp+=sizeof(unsigned int);
//    unsigned char y = 5;
//    memcpy(temp,&y,sizeof(unsigned char));
//    temp+=sizeof(unsigned char);
//    string z = "Maria";
//    char* cadena = (char*)z.c_str();
//    memcpy(temp,z.c_str(),(int)y+1);
//    temp+=y+1;
//    temp-=(sizeof(unsigned int)+sizeof(unsigned int)+sizeof(unsigned char)+y+1);

//    unsigned int bIDV, pos;
//    memcpy(&bIDV,temp,sizeof(unsigned int));
//    temp+=sizeof(unsigned int);
//    memcpy(&pos,temp,sizeof(unsigned int));
//    temp+=sizeof(unsigned int);

//    cout<<bIDV<<endl;
//    cout<<pos<<endl;

//    unsigned char tam;
//    memcpy(&tam,temp,sizeof(unsigned char));
//    temp+=sizeof(unsigned char);
//    char *varchar = (char*)malloc(1+10);
//    memcpy(varchar,&tam,sizeof(unsigned char));
//    varchar+=sizeof(unsigned char);
//    memcpy(varchar,temp,(int)tam);
//    varchar+=(int)tam;
//    /*for(int i=0; i<(int)tam; i++)
//    {
//        memcpy(varchar,temp,sizeof(unsigned char));
//        temp++;
//        varchar++;
//    }*/
//    varchar-=(1+(int)tam);

//    int i;
//    for(i=(int)tam+1; i<=10; i++)
//    {
//        varchar[i]='#';
//    }

//    printf("%s\n",varchar);

//    char* prueba = (char*)malloc(12);
//    memcpy(prueba,varchar,12);
//    prueba[(int)tam+1]='\0';

//    printf("%s\n",prueba);

//    unsigned char byte = 255;
//    cout<<byte<<":"<<(int)byte<<endl;

//    cout<<sizeof(Header)<<endl;
//    cout<<sizeof(InfoMD)<<endl;
//    cout<<sizeof(InfoMDC)<<endl;


    return 0;
}
