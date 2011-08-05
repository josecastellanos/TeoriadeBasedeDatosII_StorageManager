/* 
 * File:   Metadata.cpp
 * Author: joc
 * 
 * Created on 24 de julio de 2011, 18:40
 */

#include "Metadata.h"
#define path "tablespace.dat"

Metadata::Metadata()
:Block(0, 0, 0, "MDB") {

}

Metadata::Metadata(const char* nombreTabla, unsigned int cant_campos):Block(0, 0, 0, "MD") {
    strcpy(info.nombreTabla, nombreTabla);
    info.cant_campos = cant_campos;
    info.cont_MD = 0;
    info.inicio_BD = 0;
    info.ultimo_BD = 0;
     SystemBlock SB;
    int libre_pos = SB.getFree();
    if (libre_pos != 0) {
        if (SB.getPrimerMD() == 0) {
            SB.setPrimerMD(libre_pos);
        }
    
    header.blockID=libre_pos;
    header.ant = SB.getUltimoMD();
    header.sig = 0;
    strcpy(header.type,"MDB");
     
    SB.setUltimoMD(libre_pos);
    }else{
        return;
    }

}

void Metadata::escribir() {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
   
    SystemBlock SB;
    unsigned int offset=4096*header.blockID;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Block));
    disco.flush();
    disco.write((const char*) &info, sizeof (InfoMD));
    disco.flush();
        
    SB.acomodarPrimerLibre();
    disco.close();


}

unsigned int Metadata::getEspacioDisponible()
{
    
}