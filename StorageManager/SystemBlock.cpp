/* 
 * File:   SystemBlock.cpp
 * Author: rsiwady29
 * 
 * Created on July 26, 2011, 10:02 AM
 */

#include "SystemBlock.h"

SystemBlock::SystemBlock()
        :Block(0,0,1,"SB") 
{    
}

//void SystemBlock::SystemBlock(const char* path)
//{
//    strcpy(this->path,path);
//}

unsigned int SystemBlock::getFree()
{    
    fstream disco;
    //Abro el archivo, sino se puede retorno 0
    disco.open(path, ios::binary | ios::in | ios::out);
    //disco.open("/home/mairen/jj.dat", ios::binary | ios::in | ios::out);
    
    if (!disco) {
        return 0;
    }
    //Avanzo hasta despues del Header
    unsigned int offset = sizeof(Header);
    disco.seekg(offset);
    
    //Leo la Info del bloque se Sistema
    InfoSB myinfo;        
    disco.read((char*) &myinfo, sizeof(InfoSB));
    
    
    
    //Si el PrimerLibre es O quiere decir que no hay espacio
    if(myinfo.primerLibre!=0)
    {    
        //Guardo el Valor del PrimerLibre, 
        //porque se le dara return mas adelante.
        unsigned int temp = myinfo.primerLibre;
        
        //Avanzo hasta el PrimerLibre para leer su Header.
        offset = temp*4096;
        disco.seekg(offset);
        Header freeheader;
        disco.read((char*) &freeheader, sizeof(Header));
        
        //Actualizo el PrimerLibre con el id del nuevo libre
        myinfo.primerLibre=freeheader.sig;
        //Offset para escribir la actualizacion del PrimerLibre
        //en el SystemBlock.
        offset = sizeof(Header);
        disco.seekp(offset);
        disco.write((const char*) &myinfo, sizeof(InfoSB));
        disco.flush();
        //Offset hasta el que sera nuestro PrimerLibre.
        offset = freeheader.sig*4096;
        disco.seekg(offset);
        //Leer el Header del que sera nuestro PrimerLibre,
        //para setearle valores.
        Header newfreeheader;
        disco.read((char*) &newfreeheader,sizeof(Header));
        newfreeheader.ant=0;
        //Offset para escribir la actualizacion del que sera nuestro PrimerLibre
        offset = freeheader.sig*4096;
        disco.seekp(offset);
        disco.write((const char*) &newfreeheader, sizeof(Header));
        disco.flush();
        //Cierro el Disco y hago el return de la variable temp que
        //guarde al principio de este if.
        disco.close();        
        return temp;
    }
    else
    {
        disco.close();
        return 0;        
    }
    
    
    

    
}

