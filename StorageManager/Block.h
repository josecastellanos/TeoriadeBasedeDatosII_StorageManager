#ifndef BLOCK_H
#define	BLOCK_H

#include <string.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "SMException.h"

using namespace std;

class Header
{
public:
    unsigned int blockID;
    unsigned int ant;
    unsigned int sig;
    char type[4];
};

class Block {
public:
    Header header;
    Block(unsigned int blockID, unsigned int ant, unsigned int sig, const char* type);
    Block(unsigned int blockID);
    void setAnt(unsigned int ant);
    void setSig(unsigned int sig);
    void setBlockID(unsigned int blockID);
    void setType(const char* type);
    unsigned int getAnt();
    unsigned int getSig();
    unsigned int getBlockID();
    char* getType();
    void escribir();
     unsigned int getEspacioDisponible();
private:

};

#endif	/* BLOCK_H */
