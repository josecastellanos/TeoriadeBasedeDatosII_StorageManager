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
    header.ant=ant;
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=4096*header.blockID;
    disco.seekp(offset);
    
    disco.write((const char*) &header, sizeof (Block));
    disco.flush();
    disco.close();
}
void Block::setSig(unsigned int sig){
    header.sig=sig;
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=4096*header.blockID;
    disco.seekp(offset);
    
    disco.write((const char*) &header, sizeof (Block));
    disco.flush();
    disco.close();
}

void Block::escribir()
{
    
}

unsigned int Block::getEspacioDisponible()
{
    
}