/*
 * File:   Varchar.cpp
 * Author: mairen
 *
 * Created on 10 de agosto de 2011, 17:24
 */

#include "Varchar.h"
#define path "tablespace.dat"


Varchar::Varchar(unsigned int blockID):Block(0,0,0,"VB") {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*blockID;
    disco.seekg(offset);
    disco.read((char*) &header,sizeof(Header));
    //disco.read((char*) &info,sizeof(InfoV));
    disco.close();


}
Varchar::Varchar(unsigned int blockID, unsigned int blockIDMD, unsigned int index, unsigned int max_size ):Block(blockID,0,0,"VB") {

    info.blockIDMD=blockIDMD;
    info.index=index;
    info.max_size=1+max_size+1;
    info.cant_varchars=0;

      //SystemBlock SB;
    //strcpy(header.type,"VC");
    //SB.setUltimoMD(blockID);


}
unsigned int Varchar::insertVarchar(unsigned char* varchar){
    fstream disco;
    disco.open(path, ios::binary | ios::in| ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }

    unsigned int offset = this->header.blockID*4096+sizeof(Header)+sizeof(InfoV);
    unsigned int max_size=this->getMax_size();
    unsigned int cant_varchars=this->getCant_varchars();
    offset+=cant_varchars*max_size;
    disco.seekp(offset);
    disco.write((const char*) varchar, max_size);
    disco.flush();
    disco.close();
    cant_varchars++;
    this->setCant_varchars(cant_varchars);
    return cant_varchars-1;


}
void Varchar::escribir(){
    fstream disco;
    disco.open(path, ios::binary |ios::in| ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }

    unsigned int offset = this->header.blockID*4096;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Header));
    disco.flush();
    disco.write((const char*) &info, sizeof (InfoV));
    disco.flush();
    disco.close();
}
unsigned char* Varchar::selectVarchar(unsigned int index){
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
        
    unsigned int offset = this->header.blockID*4096+sizeof(Header)+sizeof(InfoV);

    unsigned int max_size=this->getMax_size();
    //Agregue la siguiente Linea para asignar el espacio a varchar
    unsigned char* varchar=(unsigned char*)malloc(max_size);
    

    offset+=index*max_size;
    disco.seekg(offset);
    disco.read((char*) varchar, max_size);
    disco.close();

    //Modificacion

    unsigned char tam;
    memcpy(&tam,varchar,sizeof(unsigned char));


    varchar[(int)tam+1]='\0';
    //*****


    return varchar;


}
void Varchar::updateVarchar(unsigned char* varchar, unsigned int index){

    fstream disco;
    disco.open(path, ios::binary |ios::in| ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    //if(index<info.cant_varchars){

    unsigned int offset = this->header.blockID*4096+sizeof(Header)+sizeof(InfoV);

    unsigned int max_size=this->getMax_size();
    //unsigned int cant_varchars=this->getCant_varchars();

    offset+=index*max_size;
    disco.seekp(offset);
    disco.write((const char*) varchar, max_size);
    disco.flush();
    disco.close();
}
unsigned int Varchar::getEspacioDisponible(){
    fstream disco;
    disco.open(path, ios::binary |ios::in| ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoV));
    disco.close();

    return 4096-sizeof(Header)-sizeof(InfoV)-info.cant_varchars*info.max_size;


}
unsigned int Varchar::getBlockIDMD(){

    fstream disco;
    disco.open(path, ios::binary|ios::in| ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoV));
    disco.close();

    return info.blockIDMD;

}
void Varchar::setBlockIDMD(unsigned int blockIDMD){
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoV));
    info.blockIDMD = blockIDMD;
    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoV));
    disco.flush();
    disco.close();
}
unsigned int Varchar::getCant_varchars(){

    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoV));
    disco.close();

    return info.cant_varchars;

}
void Varchar::setCant_varchars(unsigned int cantidad){
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoV));
    info.cant_varchars = cantidad;
    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoV));
    disco.flush();
    disco.close();
}
//Aqui
unsigned int Varchar::getMax_size(){

    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoV));
    disco.close();

    return info.max_size;

}
void Varchar::setMax_size(unsigned int max_size){
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoV));
    info.max_size = max_size;
    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoV));
    disco.flush();
    disco.close();
}



Varchar::~Varchar() {
}
