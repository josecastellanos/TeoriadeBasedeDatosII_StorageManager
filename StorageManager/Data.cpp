/* 
 * File:   Data.cpp
 * Author: rsiwady29
 * 
 * Created on August 7, 2011, 11:21 AM
 */

#include "Data.h"
#include "SystemBlock.h"
#define path "tablespace.dat"

Data::Data(unsigned int blockID, unsigned int blockIDMD):Block(0,0,0,"DATA")
{
    header.blockID = blockID;
    
    info.blockIDMD = blockIDMD;
    info.cantRegActivos = 0;
    info.cantRegFisicos = 0;
    
}

Data::Data(unsigned int blockID):Block(0,0,0,"DATA")
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=4096*blockID;
    disco.seekg(offset);
    disco.read((char*) &header, sizeof(Header));
    disco.close();  
}

void Data::escribir()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }   
    
    unsigned int offset = this->header.blockID*4096;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Header));
    disco.flush();
    
    disco.write((const char*) &info, sizeof (InfoD));
    disco.flush();
    disco.close();
}

unsigned int Data::getEspacioDisponible()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return -1;
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoD));
    disco.close();
    
    return 4096-sizeof(Header)-sizeof(InfoD)-info.cantRegFisicos*sizeof(InfoD);
}

void Data::setBlockIDMD(unsigned int blockIDMD)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    
    disco.read((char*) &info, sizeof (InfoD));
    info.blockIDMD = blockIDMD;
    
    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoD));
    
    disco.flush();
    disco.close();
}

void Data::setCantRegActivos(unsigned int cantRegActivos)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoD));
    info.cantRegActivos = cantRegActivos;
    
    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoD));
    disco.flush();
    disco.close();
}

void Data::setCantRegFisicos(unsigned int cantRegFisicos)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoD));
    info.cantRegFisicos = cantRegFisicos;
    
    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoD));
    disco.flush();
    disco.close();    
}

unsigned int Data::getBlockIDMD()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return -1;
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoD));
    disco.close();
    
    return info.blockIDMD;
}

unsigned int Data::getCantRegActivos()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return -1;
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoD));
    disco.close();
    
    return info.cantRegActivos;    
}

unsigned int Data::getCantRegFisicos()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return -1;
    }
    unsigned int offset = ( 4096 * header.blockID ) + sizeof(Header);
    disco.seekg(offset);    
    disco.read((char*) &info, sizeof (InfoD));
    disco.close();
    
    return info.cantRegFisicos;    
}

// Asignado a Camilo
void Data::insertRecord(InfoReg reg)
{
}

// Asignado a Dago
void Data::updateRecord(InfoReg reg, unsigned int index)
{
    
}

// Asignado a Jaime
void Data::deleteRecord(unsigned int index)
{
}

// Asignado a Richard
InfoReg Data::selectRecord(unsigned int index)
{
}

