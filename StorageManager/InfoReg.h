/* 
 * File:   InfoReg.h
 * Author: rsiwady29
 *
 * Created on August 7, 2011, 11:29 AM
 */

#ifndef INFOREG_H
#define	INFOREG_H

class InfoReg {
public:
    InfoReg(unsigned int blockIDMD);
    // Atributos
    unsigned short nulos;
    unsigned int tam;
    unsigned char tombstone;
    unsigned char* contentReg;
    
    // Funciones
    unsigned char* readCampo(unsigned int index);

    // Sets y Gets
    void setContentReg(unsigned char* contentReg);
    unsigned char* getContentReg();
    
    void setTombstone(unsigned char tombstone);
    unsigned char getTombstone();
    
    void setTam(unsigned int tam);
    unsigned int getTam();
    
    void setNulos(unsigned short nulos);
    unsigned short getNulos();
    
private:

};

#endif	/* INFOREG_H */

