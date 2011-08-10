/* 
 * File:   Metadata.cpp
 * Author: joc
 * 
 * Created on 24 de julio de 2011, 18:40
 */

#include "Metadata.h"
#define path "tablespace.dat"

Metadata::Metadata(unsigned int blockID):Block(0,0,0,"MD")
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=4096*blockID;
    disco.seekg(offset);
    disco.read((const char*) &header,sizeof(Header));
    disco.read((const char*) &info,sizeof(InfoMD));
    disco.close();
    
    
}

Metadata::Metadata(unsigned int blockID, char* nombreTabla, unsigned int cant_campos):Block(0, 0, 0, "MD") {
      strcpy(info.nombreTabla, nombreTabla);
      info.cant_campos = cant_campos;
      info.inicio_MDCont = 0;
      info.final_MDCont = 0;
      info.inicio_BD = 0;
      info.final_BD = 0;
      SystemBlock SB;
    if (blockID != 0) {
        if (SB.getPrimerMD() == 0) {
            SB.setPrimerMD(blockID);
        }
    
    header.blockID=blockID;
    header.ant = SB.getUltimoMD();
    header.sig = 0;
    strcpy(header.type,"MDB");     
    SB.setUltimoMD(blockID);
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
   
    unsigned int offset=4096*header.blockID;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Block));
    disco.flush();
    disco.write((const char*) &info, sizeof (InfoMD));
    disco.flush();
    disco.close();


}

char* Metadata::get_nombreTabla(){
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((const char*) &info, sizeof (InfoMD));
    disco.close();
    return info.nombreTabla;
    
}

unsigned int Metadata::getCant_campos(){
    
}

unsigned int Metadata::getFinal_MDCont()
{
    
}

unsigned int Metadata::getEspacioDisponible()
{
    
}