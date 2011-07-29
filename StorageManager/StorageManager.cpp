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

        SystemBlock SB;       
        SB.info.primerBMD = 0;
        SB.info.ultimoBMD =0;
        SB.info.primerLibre = 1;
        strcpy(SB.info.nombreBD, nombreBD);
        strcpy(SB.info.version, version);
        strcpy(SB.info.clave, clave);
        disco.write((const char*) &SB, sizeof (SystemBlock));
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

void StorageManager::createTable(const char* nombreTabla, unsigned int cant_campos, InfoMDC* campos){
    Metadata metadata(nombreTabla,cant_campos);
    metadata.escribir();
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset = (metadata.header.blockID * 4096)+sizeof(Header)+sizeof(InfoMD);
    int temp = (4096-sizeof(Header)-sizeof(InfoMD))/sizeof(InfoMDC);
    
    disco.seekp(offset);
    for(int i=0;i<cant_campos;i++){
        if(i<temp){
           disco.write((const char*) &campos[i], sizeof(InfoMDC)); 
        }else{
            
        }
        
    }
}

