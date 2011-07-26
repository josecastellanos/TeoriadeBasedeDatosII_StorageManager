/*
 * File:   StorageManager.cpp
 * Author: rsiwady29
 * 
 * Created on July 26, 2011, 10:13 AM
 */

#include "StorageManager.h"

StorageManager::StorageManager()
{    
}

void StorageManager::createTableSpace(const char* nombreBD, const char* version, const char* clave, const char* direccion, unsigned int cantBloques) {
    if (cantBloques > 1) {
        fstream disco;

        char path[strlen(direccion) + strlen(nombreBD) + 4];
        strcpy(path, direccion);
        strcat(path, nombreBD);
        strcat(path, ".dat");

        disco.open(path, ios::binary | ios::in);
        if (!disco) {
            disco.open(path, ios::binary | ios::out);
        } else {
            disco.open(path, ios::binary | ios::in | ios::out);
        }

        SystemBlock SB;       
        SB.info.primerBMD = 0;
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


