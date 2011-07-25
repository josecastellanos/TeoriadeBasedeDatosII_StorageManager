/* 
 * File:   Block.h
 * Author: joc
 *
 * Created on 24 de julio de 2011, 18:33
 */

#ifndef BLOCK_H
#define	BLOCK_H

#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned int blockID;
    unsigned int ant;
    unsigned int sig;
    char type[3];
}header;

class Block {
public:
    header Header;
    Block(unsigned int blockID, unsigned int ant, unsigned int sig, const char *type);
private:

};

#endif	/* BLOCK_H */

