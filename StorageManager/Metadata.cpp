/* 
 * File:   Metadata.cpp
 * Author: joc
 * 
 * Created on 24 de julio de 2011, 18:40
 */

#include "Metadata.h"

Metadata::Metadata(unsigned int blockID, unsigned int ant, unsigned int sig, const char* type) 
: Block(blockID, ant, sig, type){
}