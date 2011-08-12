/* 
 * File:   InfoReg.h
 * Author: rsiwady29
 *
 * Created on August 7, 2011, 11:29 AM
 */

#ifndef INFOREG_H
#define	INFOREG_H

class InfoReg
{
public:
    unsigned short nulos;
    unsigned int tam;
    bool tombstone;
};

class Registro {
public:
    Registro(unsigned short nulos,unsigned int tam,bool tombstone,unsigned char* contentReg);
    Registro();
    // Atributos
    InfoReg info;
    unsigned char* contentReg;
    
    // Funciones
    unsigned char* readCampo(unsigned int index,unsigned int blockIDMD);

    // Sets y Gets
    void setContentReg(unsigned char* contentReg);
    unsigned char* getContentReg();
    
    void setNulos(unsigned short nulos);
    unsigned short getNulos();
    
    void setTam(unsigned int tam);
    unsigned int getTam();
    
    void setTombstone(bool tombstone);
    bool getTombstone();
    
private:

};

#endif	/* INFOREG_H */

