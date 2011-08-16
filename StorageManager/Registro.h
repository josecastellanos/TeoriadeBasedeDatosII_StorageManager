#ifndef REGISTRO_H
#define REGISTRO_H

class Metadata;
#include "InfoReg.h"
#include "Metadata.h"

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

#endif // REGISTRO_H
