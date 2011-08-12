/* 
 * File:   MetadataContinuo.cpp
 * Author: camilo
 * 
 * Created on July 28, 2011, 8:31 PM
 */

#include "MetadataContinuo.h"
#define path "tablespace.dat"

MetadataContinuo::MetadataContinuo(unsigned int blockID, unsigned int blockIDMD):Block(blockID, 0, 0, "MDCB"){
    this->info.blockIDMD = blockIDMD;
    this->info.cant_campos = 0;
}

MetadataContinuo::MetadataContinuo(unsigned int blockID):Block(0,0,0,"MDCB"){
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*blockID;
    disco.seekg(offset);
    disco.read((char*) &header, sizeof(Header));
    disco.close();  
}

void MetadataContinuo::setCant_campos(unsigned int cant_campos){
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoCMD));
    info.cant_campos = cant_campos;
    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoCMD));
    disco.flush();
    disco.close();
}

void MetadataContinuo::setBlockIDMD(unsigned int blockIDMD)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoCMD));
    info.blockIDMD = blockIDMD;
    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoCMD));
    disco.flush();
    disco.close();
}

unsigned int MetadataContinuo::getCant_campos()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoCMD));
    disco.close();
    
    return info.cant_campos;
}

unsigned int MetadataContinuo::getBlockIDMD()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoCMD));
    disco.close();
    
    return info.blockIDMD;
}

void MetadataContinuo::escribir()
{
    fstream disco;
    disco.open(path, ios::binary | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }   
    
    unsigned int offset = this->header.blockID*4096;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Header));
    disco.flush();
    disco.write((const char*) &info, sizeof (InfoCMD));
    disco.flush();
    disco.close();
}

unsigned int MetadataContinuo::getEspacioDisponible()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoCMD));
    disco.close();
    
    return 4096-sizeof(Header)-sizeof(InfoCMD)-info.cant_campos*sizeof(InfoMDC);
}

InfoMDC MetadataContinuo::readCampo(unsigned int index)
{
    InfoMDC temp;
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    
    unsigned int offset = 4096*header.blockID + sizeof(Header) + sizeof(InfoMDC);
    unsigned int cant_campos = this->getCant_campos();
    
    if(index>=cant_campos)
    {
        throw SMException("Index invalido para el bloque de MetadataContinuo " + header.blockID);
    }
    else 
    {
        offset += sizeof (InfoMDC) * cant_campos;
        disco.seekg(offset);
        disco.read((char*) &temp, sizeof (InfoMDC));
        disco.close();

        return temp;
    }
}
