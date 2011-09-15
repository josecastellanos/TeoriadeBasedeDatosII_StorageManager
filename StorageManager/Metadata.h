
#ifndef METADATA_H
#define	METADATA_H

class Data;
class Registro;
#include "MetadataContinuo.h"
#include "InfoMD.h"
#include "Data.h"
#include "Registro.h"

class Metadata : public Block {
public:
    Metadata(unsigned int blockID, const char* nombreTabla, unsigned int cant_campos);

    Metadata(unsigned int blockID);
    void escribir();
    unsigned int getEspacioDisponible();
    unsigned int getFreeSpace(int espacio);
    InfoMDC readCampo(unsigned int index);
    void setCampo(unsigned int index,InfoMDC imdc);
    unsigned int getrecordsize();

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
