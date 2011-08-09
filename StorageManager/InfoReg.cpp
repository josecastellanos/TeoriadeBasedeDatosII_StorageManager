/* 
 * File:   InfoReg.cpp
 * Author: rsiwady29
 * 
 * Created on August 7, 2011, 11:29 AM
 */

#include "InfoReg.h"

InfoReg::InfoReg(unsigned int blockIDMD) 
{
    
}

unsigned char* InfoReg::readCampo(unsigned int index)
{
    
}

void InfoReg::setContentReg(unsigned char* contentReg) {
    this->contentReg = contentReg;
}

unsigned char* InfoReg::getContentReg() {
    return contentReg;
}

void InfoReg::setTombstone(unsigned char tombstone) {
    this->tombstone = tombstone;
}

unsigned char InfoReg::getTombstone() {
    return tombstone;
}

void InfoReg::setTam(unsigned int tam) {
    this->tam = tam;
}

unsigned int InfoReg::getTam() {
    return tam;
}

void InfoReg::setNulos(unsigned short nulos) {
    this->nulos = nulos;
}

unsigned short InfoReg::getNulos() {
    return nulos;
}


