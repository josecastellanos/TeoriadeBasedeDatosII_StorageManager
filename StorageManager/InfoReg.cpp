/* 
 * File:   InfoReg.cpp
 * Author: rsiwady29
 * 
 * Created on August 7, 2011, 11:29 AM
 */

#include "InfoReg.h"
#include "Block.h"
#include "MetadataContinuo.h"

InfoReg::InfoReg() 
{
    
}

unsigned char* InfoReg::readCampo(unsigned int index,unsigned int blockIDMD)
{
    Block *bk = new Block(blockIDMD);
    char* tipo = bk.getType();
    
    if(strcmp(tipo,"MDB")==0)
    {
        Metadata *md;
        md = (Metadata*)bk;
        unsigned int cantidad = md->getCant_campos();
    }
    else if(strcmp(tipo,"MDCB")==0)
    {
        MetadataContinuo *md;
        md = (MetadataContinuo*)bk;
        unsigned int cantidad = md->getCant_campos();
        
        for(int i=0; i<cantidad; i++)
        {
            
        }
    }
    else 
    {
        // Excepcion
    }
}

void InfoReg::setContentReg(unsigned char* contentReg) {
    memcpy(this->contentReg,contentReg,strlen(contentReg));
}

unsigned char* InfoReg::getContentReg() {
    return contentReg;
}

void InfoReg::setTombstone(bool tombstone) {
    this->tombstone = tombstone;
}

bool InfoReg::getTombstone() {
    return tombstone;
}

void InfoReg::setTam(unsigned int tam) {
    this->tam = tam;
}

unsigned int InfoReg::getTam() {
    return tam;
}

void InfoReg::setNulos(unsigned short nulos) {
    this->nulos = nulos;
}

unsigned short InfoReg::getNulos() {
    return nulos;
}


