/* 
 * File:   Block.h
 * Author: joc
 *
 * Created on 24 de julio de 2011, 18:33
 */

#ifndef BLOCK_H
#define	BLOCK_H

#include <string.h>
#include <fstream>
#include <iostream>
#include <cstdlib>

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
    void setAnt(unsigned int ant);
    void setSig(unsigned int sig);
    virtual void escribir() = 0;
    virtual unsigned int getEspacioDisponible(); 
private:

};

#endif	/* BLOCK_H */

