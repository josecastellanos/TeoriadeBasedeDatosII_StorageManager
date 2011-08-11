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

InfoReg::InfoReg(unsigned short nulos, unsigned int tam, bool tombstone, unsigned char* contentReg)
{
    this->nulos = nulos;
    this->tam = tam;
    this->tombstone = tombstone;
    this->contentReg = contentReg;
}

unsigned char* InfoReg::readCampo(unsigned int index,unsigned int blockIDMD)
{
    // Terminado
    Metadata md(blockIDMD);
    unsigned int off=0;
    unsigned char* resul;
    
    for(int i=0; i<md.getCant_campos(); i++) 
    {
        InfoMDC info = md.readCampo(i);
        if(i==index)
        {
            // devolver reg
            int val;
            if(info.tipo_campo==1){val=4;}
            else if(info.tipo_campo==2){val=8;}
            else if(info.tipo_campo==3){val=info.escala;}
            else if(info.tipo_campo==4){val=(4+4);}
            else if(info.tipo_campo==5){val=1;}
            else{//Throw Exception
            }
            
            int off2 = off+val;
            for(int i=off;i<off2;i++ )
            {
                strcat(resul,contentReg[i]);
            }
            return resul;
        }
        else
        {
            if(info.tipo_campo==1){off+=4;}// es int
            else if(info.tipo_campo==2){off+=8;} // es double
            else if(info.tipo_campo==3){off+=info.escala;} // es char
            else if(info.tipo_campo==4){off+=(4+4);} // es Varchar
            else if(info.tipo_campo==5){off+=1;} // es bool
        }
    }
    
    return 0;
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


