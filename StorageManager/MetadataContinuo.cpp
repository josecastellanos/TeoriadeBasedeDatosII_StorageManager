/* 
 * File:   MetadataContinuo.cpp
 * Author: camilo
 * 
 * Created on July 28, 2011, 8:31 PM
 */

#include "MetadataContinuo.h"
#define path "tablespace.dat"

MetadataContinuo::MetadataContinuo() :Block(0, 0, 0, "MDC"){
    SystemBlock SB;
    int libre_pos = SB.getFree();
    header.blockID = libre_pos;
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    
    unsigned int offset=4096*libre_pos;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Block));
    disco.flush();
    info.cant_campos=0;
    disco.write((const char*) &info, sizeof (InfoCMD));
    disco.flush();
    SB.acomodarPrimerLibre();
    disco.close();
}

MetadataContinuo::MetadataContinuo(unsigned int pos):Block(0,0,0,"MDC"){
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=4096*pos;
    disco.seekg(offset);
    disco.read((char*) &header, sizeof(Block));
    disco.close();
    
    
}

void MetadataContinuo::setcant_campos(unsigned int cantidad){
    info.cant_campos=cantidad;
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekp(offset);
    
    disco.write((const char*) &info, sizeof (InfoCMD));
    disco.flush();
    disco.close();
}


