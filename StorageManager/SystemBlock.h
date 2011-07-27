/* 
 * File:   SystemBlock.h
 * Author: rsiwady29
 *
 * Created on July 26, 2011, 10:02 AM
 */

#ifndef SYSTEMBLOCK_H
#define	SYSTEMBLOCK_H

#include "Block.h"
#include <string>

class InfoSB
{
public:
    char nombreBD[32];
    char version[8];
    char clave[16];
    unsigned int primerBMD;
    unsigned int primerLibre;
};

class SystemBlock : public Block {
public:
    InfoSB info;
    char* path;
    SystemBlock();
    //void SystemBlock(const char* path);
    unsigned int getFree();
    
private:

};

#endif	/* SYSTEMBLOCK_H */

