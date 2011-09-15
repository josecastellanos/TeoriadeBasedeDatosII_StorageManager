/*
 * File:   Varchar.h
 * Author: mairen
 *
 * Created on 10 de agosto de 2011, 17:24
 */

#ifndef VARCHAR_H
#define	VARCHAR_H
#include "Block.h"
#include "InfoV.h"


class Varchar : public Block{
public:
    Varchar(unsigned int blockID);
    //Agregar Index campo
    Varchar(unsigned int blockID, unsigned int blockIDMD, unsigned int index, unsigned int max_size);
    InfoV info;

    unsigned int insertVarchar(unsigned char* varchar);
    unsigned char* selectVarchar(unsigned int index);
    void updateVarchar(unsigned char* varchar, unsigned int index);

    void escribir();
    unsigned int getEspacioDisponible();


    void setBlockIDMD(unsigned int blockIDMD);
    unsigned int getBlockIDMD();

    void setCant_varchars(unsigned int cantidad);
    unsigned int getCant_varchars();

    void setMax_size(unsigned int max_size);
    unsigned int getMax_size();


    virtual ~Varchar();
private:

};

#endif	/* VARCHAR_H */
