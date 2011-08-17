#include "Data.h"
#define path "tablespace.dat"

Data::Data(unsigned int blockID, unsigned int blockIDMD):Block(blockID,0,0,"DB")
{
    info.blockIDMD = blockIDMD;
    info.cantRegActivos = 0;
    info.cantRegFisicos = 0;
}

Data::Data(unsigned int blockID):Block(0,0,0,"DB")
{
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*blockID;
    disco.seekg(offset);
    disco.read((char*) &header, sizeof(Header));
    disco.close();
}

void Data::escribir()
{
    fstream disco;
    disco.open(path, ios::binary | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }

    unsigned int offset = this->header.blockID*4096;
    disco.seekp(offset);
    disco.write((const char*) &header, sizeof (Header));
    disco.flush();

    disco.write((const char*) &info, sizeof (InfoD));
    disco.flush();
    disco.close();
}

unsigned int Data::getEspacioDisponible()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoD));
    disco.close();

    InfoReg tempInfo;
    offset += sizeof(InfoD);

    unsigned int offset2 = sizeof(Header)+sizeof(InfoD);

    for(int i=0; i<info.cantRegFisicos; i++)
    {
        disco.seekg(offset);
        disco.read((char*) &tempInfo, sizeof(InfoReg));

        offset += sizeof(InfoReg) + tempInfo.tam;
        offset2 += sizeof(InfoReg) + tempInfo.tam;
    }

    return 4096 - offset2;
}

void Data::setBlockIDMD(unsigned int blockIDMD)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);

    disco.read((char*) &info, sizeof (InfoD));
    info.blockIDMD = blockIDMD;

    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoD));

    disco.flush();
    disco.close();
}

void Data::setCantRegActivos(unsigned int cantRegActivos)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoD));
    info.cantRegActivos = cantRegActivos;

    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoD));
    disco.flush();
    disco.close();
}

void Data::setCantRegFisicos(unsigned int cantRegFisicos)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoD));
    info.cantRegFisicos = cantRegFisicos;

    disco.seekp(offset);
    disco.write((const char*) &info, sizeof(InfoD));
    disco.flush();
    disco.close();
}

unsigned int Data::getBlockIDMD()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoD));
    disco.close();

    return info.blockIDMD;
}

unsigned int Data::getCantRegActivos()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoD));
    disco.close();

    return info.cantRegActivos;
}

unsigned int Data::getCantRegFisicos()
{
    fstream disco;
    disco.open(path, ios::binary | ios::in);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset = ( 4096 * header.blockID ) + sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoD));
    disco.close();

    return info.cantRegFisicos;
}

//Asignado a Camilo
void Data::insertRecord(Registro reg)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }

     mapabits nulos(reg.getNulos());
     Metadata md(info.blockIDMD);

     unsigned int sizeMalloc = 0;
     for(int i=0; i<md.getCant_campos(); i++)
     {
         if(nulos.getAt(i))
         {
             continue;
         }

         InfoMDC campo = md.readCampo(i);
         switch(campo.tipo_campo)
         {
             case 1://Int
                 sizeMalloc+=sizeof(int);
                 break;
             case 2://Double
                 sizeMalloc+=sizeof(double);
                 break;
             case 3://Char
                 sizeMalloc+=campo.size;
                 break;
             case 4://Varchar
                 sizeMalloc+=sizeof(int)+sizeof(int);
                 break;
             case 5://Bool
                 sizeMalloc+=sizeof(bool);
                 break;
         }
     }

     unsigned char* buffer = (unsigned char*)malloc(sizeMalloc);

     for(int i=0; i<md.getCant_campos(); i++)
     {
         if(nulos.getAt(i))
         {
             continue;
         }

         InfoMDC campo = md.readCampo(i);
         switch(campo.tipo_campo)
         {
             case 1://Int
             memcpy(buffer,reg.contentReg,sizeof(int));
             buffer+=sizeof(int);
             reg.contentReg+=sizeof(int);
                 break;
             case 2://Double
             memcpy(buffer,reg.contentReg,sizeof(double));
             buffer+=sizeof(double);
             reg.contentReg+=sizeof(double);
                 break;
             case 3://Char
             memcpy(buffer,reg.contentReg,campo.size);
             buffer+=campo.size;
             reg.contentReg+=campo.size;
                 break;
             case 4://Varchar
                // sizeMalloc+=sizeof(int)+sizeof(int);
                 break;
             case 5://Bool
             memcpy(buffer,reg.contentReg,sizeof(bool));
             buffer+=sizeof(bool);
             reg.contentReg+=sizeof(bool);
                 break;
         }
     }

    reg.setContentReg(buffer);
    reg.setTam(sizeMalloc);

     unsigned int offset = 4096*header.blockID + (4096-getEspacioDisponible());
     disco.seekp(offset);
     disco.write((const char*) &reg, sizeof(reg));
     disco.flush();
     disco.close();



}

// Asignado a Dago
void Data::updateRecord(Registro _new, unsigned int index)
{
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }

    if(index>=getCantRegActivos())
    {
        throw SMException("Index invalido para el bloque de Data " + header.blockID);
    }

    unsigned int offset = 4096*header.blockID + sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof(InfoD));

    unsigned int tamDisp = getEspacioDisponible();
    unsigned int inicio_oldReg = offset + sizeof(InfoD);
    unsigned int finalRegs_bloque = 4096*(header.blockID+1) - tamDisp;

    InfoReg tempInfo;

    int x=0;

    for(int i=0; i<info.cantRegFisicos; i++)
    {
        disco.seekg(inicio_oldReg);
        disco.read((char*) &tempInfo, sizeof(InfoReg));

        if(!tempInfo.tombstone)
        {
            if(x==index)
            {
                break;
            }
            else
            {
                x++;
            }
        }

        inicio_oldReg += sizeof(InfoReg) + tempInfo.tam;
    }

    Registro _old = selectRecord(index);
    mapabits nulos_new(_new.getNulos());
    mapabits nulos_old(_old.getNulos());
    if(_old.getTam() == _new.getTam())
    {
        Metadata md(info.blockIDMD);
        unsigned int sizeMalloc = 0;
        for(int i=0; i<md.getCant_campos(); i++)
        {
            if(nulos_new.getAt(i))
            {
                continue;
            }

            InfoMDC campo = md.readCampo(i);
            switch(campo.tipo_campo)
            {
                case 1://Int
                    sizeMalloc+=sizeof(int);
                    break;
                case 2://Double
                    sizeMalloc+=sizeof(double);
                    break;
                case 3://Char
                    sizeMalloc+=campo.size;
                    break;
                case 4://Varchar
                    sizeMalloc+=sizeof(int)+sizeof(int);
                    break;
                case 5://Bool
                    sizeMalloc+=sizeof(bool);
                    break;
            }
        }

        unsigned char* buffer = (unsigned char*)malloc(sizeMalloc);

        for(int i=0; i<md.getCant_campos(); i++)
        {
            if(nulos_new.getAt(i))
            {
                continue;
            }

            InfoMDC campo = md.readCampo(i);
            switch(campo.tipo_campo)
            {
                case 1://Int
                    memcpy(buffer,_new.contentReg,sizeof(int));
                    buffer+=sizeof(int);
                    if(!nulos_old.getAt(i))
                    {
                        _old.contentReg+=sizeof(int);
                    }
                    _new.contentReg+=sizeof(int);
                    break;
                case 2://Double
                    memcpy(buffer,_new.contentReg,sizeof(double));
                    buffer+=sizeof(double);
                    if(!nulos_old.getAt(i))
                    {
                        _old.contentReg+=sizeof(double);
                    }
                    _new.contentReg+=sizeof(double);
                    break;
                case 3://Char
                    memcpy(buffer,_new.contentReg,campo.size);
                    buffer+=campo.size;
                    if(!nulos_old.getAt(i))
                    {
                        _old.contentReg+=campo.size;
                    }
                    _new.contentReg+=campo.size;
                    break;
                case 4://Varchar
                    if(!nulos_old.getAt(i))
                    {
                        //Poner en el API que me manden con terminacion nula la cadena, y poner en varchar que recibe char* y cambiar el max_size sumarle 1
                        unsigned int bIDV, pos;
                        memcpy(&bIDV,_old.contentReg,sizeof(unsigned int));
                        _old.contentReg+=sizeof(unsigned int);
                        memcpy(&pos,_old.contentReg,sizeof(unsigned int));
                        _old.contentReg+=sizeof(unsigned int);

                        Varchar vb(bIDV);

                        unsigned char tam;
                        memcpy(&tam,_new.contentReg,sizeof(unsigned char));
                        _new.contentReg+=sizeof(unsigned char);
                        char *varchar = (char*)malloc(1+campo.size+1);
                        memcpy(varchar,&tam,sizeof(unsigned char));
                        varchar+=sizeof(unsigned char);
                        memcpy(varchar,_new.contentReg,(int)tam+1);
                        _new.contentReg+=(int)tam+1;

                        int i;
                        for(i=(int)tam+1; i<=campo.size; i++)
                        {
                            varchar[i]='#';
                        }
                        varchar[i+1]='\0';

                        //vb.updateVarchar(varchar,pos);
                    }
                    else
                    {

                    }
                    break;
                case 5://Bool
                    memcpy(buffer,_new.contentReg,sizeof(bool));
                    buffer+=sizeof(bool);
                    if(!nulos_old.getAt(i))
                    {
                        _old.contentReg+=sizeof(bool);
                    }
                    _new.contentReg+=sizeof(bool);
                    break;
            }
        }
    }
}

// Asignado a Jaime
void Data::deleteRecord(unsigned int index)
{

}

// Asignado a Richard
Registro Data::selectRecord(unsigned int index)
{
    Registro reg;
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset = ( 4096 * header.blockID ) + sizeof(Header) + sizeof(InfoD);
    disco.seekg(offset);
    int x=0;
    int cant = getCantRegFisicos();

    for(int i=0; i< cant; i++)
    {
        disco.read( (char*) &reg , sizeof(InfoReg));

        if(reg.info.tombstone) // == true
        {
            continue;
        }
        else if(!reg.info.tombstone)// == false
        {
            if(x==index)
            {
                return reg;
            }
            else
            {
                x++;
            }
        }
    }

}
