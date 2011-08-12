/* 
 * File:   InfoReg.cpp
 * Author: rsiwady29
 * 
 * Created on August 7, 2011, 11:29 AM
 */

#include "Registro.h"
#include "Block.h"
#include "MetadataContinuo.h"

Registro::Registro() 
{
    
}

Registro::Registro(unsigned short nulos, unsigned int tam, bool tombstone, unsigned char* contentReg)
{
    info.nulos = nulos;
    info.tam = tam;
    info.tombstone = tombstone;
}

unsigned char* Registro::readCampo(unsigned int index,unsigned int blockIDMD)
{
    // Terminado
    Metadata md(blockIDMD);
    unsigned int off=0;
    char* resul;
    
    for(int i=0; i<md.getCant_campos(); i++) 
    {
        InfoMDC inf = md.readCampo(i);
        if(i==index)
        {
            // devolver reg
            int val;
            if(inf.tipo_campo==1){val=4;}
            else if(inf.tipo_campo==2){val=8;}
            else if(inf.tipo_campo==3){val=inf.escala;}
            else if(inf.tipo_campo==4){val=(4+4);}
            else if(inf.tipo_campo==5){val=1;}
            else{//Throw Exception
            }
            
            int off2 = off+val;
            for(int i=off;i<off2;i++ )
            {
                //strcat(resul,(char*)contentReg[i]);
            }
            return (unsigned char*)resul;
        }
        else
        {
            if(inf.tipo_campo==1){off+=4;}// es int
            else if(inf.tipo_campo==2){off+=8;} // es double
            else if(inf.tipo_campo==3){off+=inf.escala;} // es char
            else if(inf.tipo_campo==4){off+=(4+4);} // es Varchar
            else if(inf.tipo_campo==5){off+=1;} // es bool
        }
    }
    
    return 0;
}

void Registro::setNulos(unsigned short nulos){
    info.nulos = nulos;
}

void Registro::setTam(unsigned int tam){
    info.tam = tam;
}

void Registro::setTombstone(bool tombstone){
    info.tombstone = tombstone;
}

unsigned short Registro::getNulos(){
    return info.nulos;
}

unsigned int Registro::getTam(){
    return info.tam;
}

bool Registro::getTombstone(){
    return info.tombstone;
}

void Registro::setContentReg(unsigned char* contentReg){
    //this->contentReg = contentReg;
    // Cambiar por MemCpy
}

unsigned char* Registro::getContentReg(){
    return contentReg;
}