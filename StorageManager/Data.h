/* 
 * File:   Data.h
 * Author: rsiwady29
 *
 * Created on August 7, 2011, 11:21 AM
 */

#ifndef DATA_H
#define	DATA_H
#include "Registro.h"
#include "Metadata.h"

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
    
    void insertRecord(InfoReg reg);
    InfoReg selectRecord(unsigned int index);
    void updateRecord(InfoReg reg,unsigned int index);
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

