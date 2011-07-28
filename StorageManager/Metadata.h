/* 
 * File:   Metadata.h
 * Author: joc
 *
 * Created on 24 de julio de 2011, 18:40
 */

#ifndef METADATA_H
#define	METADATA_H

#include "Block.h"

class InfoMD{
public:
    char nombreTabla[50];
    unsigned int cant_campos;
    unsigned int cont_MD;
    unsigned int inic_BD;
};

class InfoMDC{
public:
    char tipo_campo[20];
    char nombre_campo[30];
    unsigned int escala;
    unsigned int precision;
    bool nulls;
    bool PK;
    bool DEFAULT;
    
};

class Metadata : public Block {
public:
    Metadata(unsigned int blockID, unsigned int ant, unsigned int sig, const char* type);
    
    InfoMD info;
private:

};

#endif	/* METADATA_H */

