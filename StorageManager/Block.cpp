/* 
 * File:   Block.cpp
 * Author: joc
 * 
 * Created on 24 de julio de 2011, 18:33
 */

#include "Block.h"
#define path "tablespace.dat"

Block::Block(unsigned int blockID, unsigned int ant, unsigned int sig, const char* type) : Template() {
    this->header.blockID = blockID;
    this->header.ant = ant;
    this->header.sig = sig;
    strcpy(this->header.type, type);
}

void Block::setAnt(unsigned int ant){
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*header.blockID;
    disco.seekg(offset);    
    disco.read((char*) &header, sizeof (Header));
    header.ant = ant;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Header));
    disco.flush();
    disco.close();
}

void Block::setSig(unsigned int sig){
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*header.blockID;
    disco.seekg(offset);    
    disco.read((char*) &header, sizeof (Header));
    header.sig = sig;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Header));
    disco.flush();
    disco.close();
}

void Block::setBlockID(unsigned int blockID)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*header.blockID;
    disco.seekg(offset);    
    disco.read((char*) &header, sizeof (Header));
    header.blockID = blockID;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Header));
    disco.flush();
    disco.close();
}

void Block::setType(const char* type)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*header.blockID;
    disco.seekg(offset);    
    disco.read((char*) &header, sizeof (Header));
    strcpy(header.type, type);
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Header));
    disco.flush();
    disco.close();
}

unsigned int Block::getSig()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*header.blockID;
    disco.seekg(offset);    
    disco.read((char*) &header, sizeof (Header));
    disco.close();
    
    return header.sig;
}

unsigned int Block::getAnt()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*header.blockID;
    disco.seekg(offset);    
    disco.read((char*) &header, sizeof (Header));
    disco.close();
    
    return header.ant;
}

unsigned int Block::getBlockID()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*header.blockID;
    disco.seekg(offset);    
    disco.read((char*) &header, sizeof (Header));
    disco.close();
    
    return header.blockID;
}

char* Block::getType()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*header.blockID;
    disco.seekg(offset);    
    disco.read((char*) &header, sizeof (Header));
    disco.close();
    
    return header.type;
}

void Block::escribir()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }   
    
    unsigned int offset = this->header.blockID*4096;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Header));
    disco.flush();
    disco.close();
}

unsigned int Block::getEspacioDisponible()
{    
    return 4096-sizeof(Header);
}