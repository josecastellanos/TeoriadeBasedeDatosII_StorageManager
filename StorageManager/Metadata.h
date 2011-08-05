/* 
 * File:   Metadata.h
 * Author: joc
 *
 * Created on 24 de julio de 2011, 18:40
 */

#ifndef METADATA_H
#define	METADATA_H

#include "Block.h"
#include "SystemBlock.h"

class InfoMD{
public:
    char nombreTabla[50];
    unsigned int cant_campos;
    unsigned int inicio_MDCont;
    unsigned int final_MDCont;
    unsigned int inicio_BD;
    unsigned int ultimo_BD;
};

class InfoMDC{
public:
    unsigned short tipo_campo;
    char nombre_campo[30];
    unsigned int escala;
    unsigned int precision;
    bool nulls;
    bool PK;
    char DEFAULT[30];
    
};

class Metadata : public Block {
public:
    Metadata(const char* nombreTabla, unsigned int cant_campos);
    Metadata(unsigned int Bloque_id);
    unsigned int getFinal_MDCont();
    virtual void escribir();
    virtual unsigned int getEspacioDisponible();
   
    InfoMD info;
private:

};

#endif	/* METADATA_H */

