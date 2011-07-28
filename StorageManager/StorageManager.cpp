/*
 * File:   StorageManager.cpp
 * Author: rsiwady29
 * 
 * Created on July 26, 2011, 10:13 AM
 */

#include "StorageManager.h"
#define path "tablespace.dat"

StorageManager::StorageManager()
{    
}

void StorageManager::createTableSpace(const char* nombreBD, const char* version, const char* clave, unsigned int cantBloques) {
    if (cantBloques > 1) {
        fstream disco;

        disco.open(path, ios::binary | ios::out);
        if (!disco) {
            return;
        }

        Header header;
        
        header.blockID=0;
        header.ant=0;
        header.sig=1;
        strcpy(header.type, "SB");
        
        InfoSB info;
       
        info.primerBMD = 0;
        info.ultimoBMD =0;
        info.primerLibre = 1;
        strcpy(info.nombreBD, nombreBD);
        strcpy(info.version, version);
        strcpy(info.clave, clave);
                
        disco.write((const char*) &header, sizeof(Header));
        disco.flush();
        
        disco.write((const char*) &info, sizeof(SystemBlock));
        disco.flush();

        unsigned int tam = 4096 - sizeof (SystemBlock);

        unsigned char rellenoSB[tam];
        memset(rellenoSB, 0, tam);

        disco.write((const char*) &rellenoSB, tam);
        
        disco.flush();

        tam = 4096 - sizeof (Block);

        unsigned char rellenoB[tam];
        memset(rellenoB, 0, tam);

        for (int i = 1; i <= cantBloques; i++) {
            Block temp(i - 1, i, i + 1, "B");
            if (i == cantBloques) {
                temp.header.sig = 0;
            }

            disco.write((const char*) &temp, sizeof (Block));
            disco.flush();

            disco.write((const char*) &rellenoB, tam);
            disco.flush();
        }

        disco.close();
    }
}

void StorageManager::createTable(const char* nombreTabla,int cantCampos){
    fstream disco;
    
    disco.open(path, ios::binary | ios::in | ios::out);
        if (!disco) {
            return;
        }
    
    unsigned int offset = 0;

    SystemBlock SB;

    int libre_pos = SB.getFree();
    
    if(libre_pos != 0){
    
    if(SB.getPrimerMD()== 0){
        SB.setPrimerMD(libre_pos);
    }
    
    offset = 4096*libre_pos;
    Metadata m(libre_pos,SB.getUltimoMD(),0,"MD");
    SB.setUltimoMD(libre_pos);
    strcpy(m.info.nombreTabla, nombreTabla);
    m.info.cont_MD = 0;
    m.info.inic_BD = 0;
    m.info.cant_campos = cantCampos;
    disco.seekp(offset);
    disco.write((const char*) &m.header, sizeof (Block));
    
    disco.flush();
    disco.write((const char*) &m.info, sizeof (InfoMD));
    disco.flush();

    SB.acomodarPrimerLibre();
        
    disco.close();
    }else{
        disco.close();
        return;
    }
    
    
}
