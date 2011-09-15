
#ifndef METADATACONTINUO_H
#define	METADATACONTINUO_H

#include "SystemBlock.h"
#include "InfoMDC.h"
#include "InfoCMD.h"

class MetadataContinuo : public Block {
public:
    InfoCMD info;
    MetadataContinuo(unsigned int blockID);
    MetadataContinuo(unsigned int blockID, unsigned int blockIDMD);
    void setCant_campos(unsigned int cant_campos);
    void setBlockIDMD(unsigned int blockIDMD);
    unsigned int getCant_campos();
    unsigned int getBlockIDMD();
    InfoMDC readCampo(unsigned int index);
    void escribir();
    unsigned int getEspacioDisponible();
    void setCampo(unsigned int index,InfoMDC imdc);

private:
};

#endif	/* METADATACONTINUO_H */
