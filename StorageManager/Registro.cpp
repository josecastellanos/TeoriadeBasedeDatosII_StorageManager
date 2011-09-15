#include "Registro.h"

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
    unsigned char* resul;

    for(int i=0; i<md.getCant_campos(); i++)
    {
        InfoMDC inf = md.readCampo(i);
        if(i==index)
        {
            // devolver reg
            int val;
            if(inf.tipo_campo==1){val=sizeof(int);}
            else if(inf.tipo_campo==2){val=sizeof(double);}
            else if(inf.tipo_campo==3){val=inf.size;}
            else if(inf.tipo_campo==4){val=(sizeof(int) + sizeof(int) );}
            else if(inf.tipo_campo==5){val=sizeof(bool);}
            else{
                throw SMException("Ese tipo de campo no es Soportado");
            }

            resul = (unsigned char*)malloc(val);
            this->contentReg += off;
            memcpy(resul,this->contentReg,val);
            this->contentReg -= off;

            return resul;
        }
        else
        {
            if(inf.tipo_campo==1){off+=sizeof(int);}// es int
            else if(inf.tipo_campo==2){off+=sizeof(double);} // es double
            else if(inf.tipo_campo==3){off+=inf.size;} // es char
            else if(inf.tipo_campo==4){off+=(sizeof(int) + sizeof(int) );} // es Varchar
            else if(inf.tipo_campo==5){off+=sizeof(bool);} // es bool
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
    this->contentReg=contentReg;
}

unsigned char* Registro::getContentReg(){
    return contentReg;
}
