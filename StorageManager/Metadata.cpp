/* 
 * File:   Metadata.cpp
 * Author: joc
 * 
 * Created on 24 de julio de 2011, 18:40
 */

#include "Metadata.h"
#define path "tablespace.dat"

Metadata::Metadata(unsigned int blockID):Block(0,0,0,"MD")
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset=4096*blockID;
    disco.seekg(offset);
    disco.read((const char*) &header,sizeof(Header));
    disco.read((const char*) &info,sizeof(InfoMD));
    disco.close();
    
    
}

Metadata::Metadata(unsigned int blockID, char* nombreTabla, unsigned int cant_campos):Block(0, 0, 0, "MD") {
      strcpy(info.nombreTabla, nombreTabla);
      info.cant_campos = cant_campos;
      info.inicio_MDCont = 0;
      info.final_MDCont = 0;
      info.inicio_BD = 0;
      info.final_BD = 0;
      SystemBlock SB;
    if (blockID != 0) {
        if (SB.getPrimerMD() == 0) {
            SB.setPrimerMD(blockID);
        }
    
    header.blockID=blockID;
    header.ant = SB.getUltimoMD();
    header.sig = 0;
    strcpy(header.type,"MDB");     
    SB.setUltimoMD(blockID);
    }else{
        return;
    }

}

void Metadata::escribir() {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
   
    unsigned int offset=4096*header.blockID;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Block));
    disco.flush();
    disco.write((const char*) &info, sizeof (InfoMD));
    disco.flush();
    disco.close();


}

char* Metadata::get_nombreTabla() {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoMD));
    disco.close();
    return info.nombreTabla;


}

unsigned int Metadata::getCant_campos() {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoMD));
    disco.close();
    return info.cant_campos;
}

unsigned int Metadata::getFinalBD() {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoMD));
    disco.close();
    return info.final_BD;

}

unsigned int Metadata::getInicio_BD() {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoMD));
    disco.close();
    return info.inicio_BD;
}

unsigned int Metadata::getFinal_MDCont() {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoMD));
    disco.close();
    return info.final_MDCont;

}

unsigned int Metadata::getInicio_MDCont() {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoMD));
    disco.close();
    return info.inicio_MDCont;
}

void Metadata::setNombreTabla(char* nombreTabla) {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekp(offset);
    strcpy(info.nombreTabla, nombreTabla);

    disco.write((const char*) &info, sizeof (InfoMD));
    disco.flush();
    disco.close();

}

void Metadata::setCant_campos(unsigned int cant_campos) {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekp(offset);
    info.cant_campos = cant_campos;
    disco.write((const char*) &info, sizeof (InfoMD));
    disco.flush();
    disco.close();
}

void Metadata::setFinalBD(unsigned int final_BD) {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekp(offset);
    info.final_BD = final_BD;
    disco.write((const char*) &info, sizeof (InfoMD));
    disco.flush();
    disco.close();
}

void Metadata::setInicio_BD(unsigned int inicio_BD) {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekp(offset);
    info.inicio_BD = inicio_BD;
    disco.write((const char*) &info, sizeof (InfoMD));
    disco.flush();
    disco.close();
}

void Metadata::setFinal_MDCont(unsigned int final_MDCont) {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekp(offset);
    info.final_MDCont = final_MDCont;
    disco.write((const char*) &info, sizeof (InfoMD));
    disco.flush();
    disco.close();
}

void Metadata::setInicio_MDCont(unsigned int inicio_MDCont) {
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        return;
    }
    unsigned int offset = (4096 * header.blockID) + sizeof (Header);
    disco.seekp(offset);
    info.inicio_MDCont = inicio_MDCont;
    disco.write((const char*) &info, sizeof (InfoMD));
    disco.flush();
    disco.close();
}

unsigned int Metadata::getEspacioDisponible() {
    int espacio_disponible = 4096 - (sizeof (Header) + sizeof (InfoMD)+(info.cant_campos * sizeof (InfoMDC)));

    if (espacio_disponible > 0) {
        return espacio_disponible;
    } else {
        return 0;
    }

}

unsigned int Metadata::getFreeSpace(unsigned int espacio) {

}

InfoMDC Metadata::readCampo(unsigned int index) {

    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }

    int max_campos_md = (4096 - sizeof (Header) - sizeof (InfoMD)) / sizeof (InfoMDC);
    unsigned int offset = 0;
    InfoMDC imdc;

    if (index < max_campos_md) {
        offset = (4096 * header.blockID) + sizeof (Header) + sizeof (InfoMD);
        offset += (index * sizeof (InfoMDC));
        disco.seekg(offset);
        disco.read((char*) &imdc, sizeof (InfoMDC));
    }else{
        MetadataContinuo *meta_cont = new MetadataContinuo(info.inicio_MDCont);
        int campos_por_contar = (index+1)-max_campos_md;
        unsigned int ind = index - max_campos_md;
        bool find = false;
        while (campos_por_contar>0){
                       
            if(ind<meta_cont->getCant_campos()){
                imdc = meta_cont->readCampo(ind);
                campos_por_contar=0;
                find = true;
            }else{
                campos_por_contar = campos_por_contar-meta_cont->getCant_campos();
                ind = ind -meta_cont->getCant_campos();
                
                meta_cont = new MetadataContinuo(meta_cont->getSig());
            }
        }
        if(find== false){
          throw SMException("Indice invalido");  
        }
    }
    
    disco.close();
    return imdc;
}
