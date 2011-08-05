/* 
 * File:   MetadataContinuo.h
 * Author: camilo
 *
 * Created on July 28, 2011, 8:31 PM
 */

#ifndef METADATACONTINUO_H
#define	METADATACONTINUO_H
#include "Block.h"
#include "Metadata.h"
#include "SystemBlock.h"

class InfoCMD{
public:
    unsigned int cant_campos;
};

class MetadataContinuo : public Block {
public:
    MetadataContinuo();
    MetadataContinuo(unsigned int blockID);
    InfoMDC retornar_Campo(unsigned int pos);
    InfoCMD info;
    void setcant_campos(unsigned int cantidad);
    virtual void escribir();
    unsigned int getEspacioDisponible();

private:

};

#endif	/* METADATACONTINUO_H */

