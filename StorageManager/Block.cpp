/* 
 * File:   Block.cpp
 * Author: joc
 * 
 * Created on 24 de julio de 2011, 18:33
 */

#include "Block.h"

Block::Block(unsigned int blockID, unsigned int ant, unsigned int sig, const char* type) {
    this->Header.blockID = blockID;
    this->Header.ant = ant;
    this->Header.sig = sig;
    strcpy(this->Header.type, type);
}