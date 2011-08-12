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
    InfoReg(unsigned short nulos,unsigned int tam,bool tombstone,unsigned char* contentReg);
    InfoReg();
    // Atributos
    unsigned short nulos;
    unsigned int tam;
    bool tombstone;
    unsigned char* contentReg;
    
    // Funciones
    unsigned char* readCampo(unsigned int index,unsigned int blockIDMD);

    // Sets y Gets
    void setContentReg(unsigned char* contentReg);
    unsigned char* getContentReg();
    
    void setTombstone(bool tombstone);
    bool getTombstone();
    
    void setTam(unsigned int tam);
    unsigned int getTam();
    
    void setNulos(unsigned short nulos);
    unsigned short getNulos();
    
private:

};

#endif	/* INFOREG_H */

