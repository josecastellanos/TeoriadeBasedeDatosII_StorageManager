/* 
 * File:   Metadata.h
 * Author: joc
 *
 * Created on 24 de julio de 2011, 18:40
 */

#ifndef METADATA_H
#define	METADATA_H

#include "Block.h"

class Metadata : public Block {
public:
    Metadata(unsigned int blockID, unsigned int ant, unsigned int sig, const char* type);
private:

};

#endif	/* METADATA_H */

