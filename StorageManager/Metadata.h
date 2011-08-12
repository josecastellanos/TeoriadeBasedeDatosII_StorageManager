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
#include "Registro.h"
#include "MetadataContinuo.h"

class InfoMD{
public:
    char nombreTabla[50];
    unsigned int cant_campos;
    unsigned int inicio_MDCont;
    unsigned int final_MDCont;
    unsigned int inicio_BD;
    unsigned int final_BD;
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
    unsigned int inicio_varchar ;
    unsigned int final_varchar ;
    
};

class Metadata : public Block {
public:
    Metadata(unsigned int blockID,const char* nombreTabla, unsigned int cant_campos);
    Metadata(unsigned int blockID);
    virtual void escribir();
    virtual unsigned int getEspacioDisponible();
    unsigned int getFreeSpace(unsigned int espacio);
    InfoMDC readCampo(unsigned int index);
    
    char* get_nombreTabla();
    unsigned int getCant_campos();
    unsigned int getInicio_MDCont();
    unsigned int getFinal_MDCont();
    unsigned int getInicio_BD();
    unsigned int getFinalBD();
    void setNombreTabla(char* nombreTabla);
    void setCant_campos(unsigned int cant_campos);
    void setInicio_MDCont(unsigned int inicio_MDCont);
    void setFinal_MDCont(unsigned int final_MDCont);
    void setInicio_BD(unsigned int inicio_BD);
    void setFinalBD(unsigned int final_BD);
    InfoMD info;
private:

};

#endif	/* METADATA_H */

