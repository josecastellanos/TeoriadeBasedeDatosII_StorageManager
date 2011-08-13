#ifndef DATA_H
#define	DATA_H

class Metadata;
class Registro;
#include <cstdlib>
#include "mapabits.h"
#include "SystemBlock.h"
#include "Block.h"
#include "Metadata.h"
#include "Registro.h"

class InfoD
{
public:
    unsigned int blockIDMD;
    unsigned int cantRegFisicos;
    unsigned int cantRegActivos;
};

class Data: public Block {
public:
    Data(unsigned int blockID,unsigned int blockIDMD);
    Data(unsigned int blockID);

    void insertRecord(Registro reg);
    Registro selectRecord(unsigned int index);
    void updateRecord(Registro _new,unsigned int index);
    void deleteRecord(unsigned int index);
    virtual void escribir();
    unsigned int getEspacioDisponible();

    InfoD info;

    //Sets, y Gets
    void setBlockIDMD(unsigned int blockIDMD);
    void setCantRegFisicos(unsigned int cantRegFisicos);
    void setCantRegActivos(unsigned int cantRegActivos);

    unsigned int getBlockIDMD();
    unsigned int getCantRegFisicos();
    unsigned int getCantRegActivos();

private:

};

#endif	/* DATA_H */
