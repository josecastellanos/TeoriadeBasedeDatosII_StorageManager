
#ifndef METADATACONTINUO_H
#define	METADATACONTINUO_H

#include "Block.h"
#include "SystemBlock.h"
#include "Metadata.h"

class InfoCMD{
public:
    unsigned int cant_campos;
    unsigned int blockIDMD;
};

class MetadataContinuo : public Block {
public:
    InfoCMD info;
    MetadataContinuo(unsigned int blockID);
    MetadataContinuo(unsigned int blockID, unsigned int blockIDMD);
    void setCant_campos(unsigned int cant_campos);
    void setBlockIDMD(unsigned int blockIDMD);
    unsigned int getCant_campos();
    unsigned int getBlockIDMD();
   // InfoMDC readCampo(unsigned int index);
    virtual void escribir();
    unsigned int getEspacioDisponible();

private:
};

#endif	/* METADATACONTINUO_H */
