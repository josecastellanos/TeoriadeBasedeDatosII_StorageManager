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
    disco.open(path, ios::binary |ios::in |ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=4096*blockID;
    disco.seekg(offset);
    disco.read((char*) &header, sizeof(Header));
    disco.read((char*) &info, sizeof(InfoD));
    disco.close();
}

void Data::escribir()
{
    fstream disco;
    disco.open(path, ios::binary |ios::in |ios::out);
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
    disco.open(path, ios::binary | ios::in | ios::out);
    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }
    unsigned int offset=(4096*header.blockID)+sizeof(Header);
    disco.seekg(offset);
    disco.read((char*) &info, sizeof (InfoD));


    InfoReg tempInfo;
    offset += sizeof(InfoD);

    unsigned int offset2 = sizeof(Header)+sizeof(InfoD);
    printf("\ncanfisicos: %u\n",info.cantRegFisicos);

    for(int i=0; i<(int)info.cantRegFisicos; i++)
    {
        disco.seekg(offset);
        disco.read((char*) &tempInfo, sizeof(InfoReg));
        printf("\nsizeof(inforeg)%u\n",sizeof(InfoReg));
        printf("tam %u\n",tempInfo.tam);
        offset += sizeof(InfoReg) + tempInfo.tam;
        offset2 += sizeof(InfoReg) + tempInfo.tam;
    }
     disco.close();

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
    disco.open(path, ios::binary |ios::in |ios::out);
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
    disco.open(path, ios::binary |ios::in |ios::out);
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
    disco.open(path, ios::binary |ios::in |ios::out);
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
     printf("%u",info.blockIDMD);
     unsigned int sizeMalloc = md.getrecordsize();
     printf("\ntamaño: %u\n",reg.info.tam);
     printf("%d\n",md.getCant_campos());

     unsigned char* buffer = (unsigned char*)malloc(sizeMalloc);


     for(int i=0; i<(int)md.getCant_campos(); i++)
     {
         InfoMDC campo = md.readCampo(i);

         if(nulos.getAt(i))
         {
             switch(campo.tipo_campo){
                case 1:
                 for(int s=0; s<(int)sizeof(int);s++){
                     buffer[s]='#';
                 }
                 buffer+=sizeof(int);
                 break;
                case 2:
                 for(int s=0; s<(int)sizeof(double);s++){
                     buffer[s]='#';
                 }
                 buffer+=sizeof(double);
                 break;
                case 3:
                 for(int s=0; s<(int)campo.size+1;s++){
                     buffer[s]='#';
                 }
                 buffer+=campo.size;
                 break;

             case 4:
            {
                unsigned char *varchar=(unsigned char*)malloc(campo.size+2);
                varchar[0]=(unsigned char)0 ;
                for(int a=1;a<=(int)campo.size;a++){
                     varchar[a]='#';
                   }
                 varchar[campo.size+1]='\0';

                 SystemBlock SB;
                 unsigned int blockID = SB.getFree();
                 SB.acomodarPrimerLibre();
                 Varchar vr(blockID,info.blockIDMD,i,campo.size);
                 vr.escribir();

                 unsigned int pos =vr.insertVarchar(varchar);
                 campo.final_varchar=blockID;
                 campo.inicio_varchar=blockID;
                 md.setCampo(i,campo);
                 memcpy(buffer,&blockID,sizeof(unsigned int));
                 buffer+=sizeof(unsigned int);
                 memcpy(buffer,&pos,sizeof(unsigned int));
                 buffer+=sizeof(unsigned int);
                 free(varchar);

}

                 break;

               case 5:
                 for(int s=0; s<(int)sizeof(bool);s++){
                     buffer[s]='#';
                 }
                 buffer+=sizeof(bool);
                 break;


         }
      } else{


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
             memcpy(buffer,reg.contentReg,campo.size+1);
             buffer+=campo.size+1;
             reg.contentReg+=campo.size+1;

                 break;
             case 4://Varchar

         {   unsigned char size;
             memcpy(&size,reg.contentReg,sizeof(unsigned char));
             int SIZE_V = (int)size;

             unsigned char *varchar_u=(unsigned char*)malloc(SIZE_V+2);
              memcpy(varchar_u,reg.contentReg,SIZE_V+2);
              reg.contentReg+=(SIZE_V+2);
              unsigned char *varchar=(unsigned char*)malloc(campo.size+2);
              memcpy(varchar,varchar_u,SIZE_V+2);
              for(int a=SIZE_V+1;a<=(int)campo.size;a++){
                  varchar[a]='#';
              }
              varchar[campo.size+1]='\0';

             unsigned int varcharID = campo.final_varchar;
             if(varcharID==0){

                 SystemBlock SB;
                 unsigned int blockID = SB.getFree();
                 SB.acomodarPrimerLibre();
                 Varchar vr(blockID,info.blockIDMD,i,campo.size);
                 vr.escribir();

                 unsigned int pos =vr.insertVarchar(varchar);
                 campo.final_varchar=blockID;
                 campo.inicio_varchar=blockID;
                 md.setCampo(i,campo);
                 memcpy(buffer,&blockID,sizeof(unsigned int));
                 buffer+=sizeof(unsigned int);
                 memcpy(buffer,&pos,sizeof(unsigned int));
                 buffer+=sizeof(unsigned int);



             }else{
                 Varchar vr(varcharID);
                 unsigned int freespace = vr.getEspacioDisponible();
                 if(freespace>=vr.getMax_size()){

                    unsigned int pos=  vr.insertVarchar(varchar);
                    memcpy(buffer,&varcharID,sizeof(unsigned int));
                    buffer+=sizeof(unsigned int);
                    memcpy(buffer,&pos,sizeof(unsigned int));
                    buffer+=sizeof(unsigned int);

                 }else{

                     SystemBlock SB;
                     unsigned int blockID = SB.getFree();
                     SB.acomodarPrimerLibre();
                     Varchar vr_new(blockID,info.blockIDMD,i,campo.size);
                     vr_new.escribir();

                     unsigned int pos=vr_new.insertVarchar(varchar);
                     vr_new.setAnt(varcharID);
                     vr.setSig(blockID);
                     campo.final_varchar=blockID;
                     md.setCampo(i,campo);
                     memcpy(buffer,&blockID,sizeof(unsigned int));
                     buffer+=sizeof(unsigned int);
                     memcpy(buffer,&pos,sizeof(unsigned int));
                     buffer+=sizeof(unsigned int);


                 }
             }

             free(varchar_u);
             free(varchar);

         }
                 break;
             case 5://Bool
             memcpy(buffer,reg.contentReg,sizeof(bool));
             buffer+=sizeof(bool);
             reg.contentReg+=sizeof(bool);
                 break;
       }
     }

     }

    buffer-=md.getrecordsize();
    reg.setContentReg(buffer);
    reg.setTam(sizeMalloc);

     unsigned int offset = 4096*header.blockID + (4096-getEspacioDisponible());
     printf("\nsize del reg: %u\n",(sizeof(reg.info)+sizeMalloc));
    // printf("espaciodisponible: %u\n",getEspacioDisponible());
     printf("offset: %u\n",offset);
     disco.seekp(offset);
     disco.write((const char*) &reg.info, sizeof(InfoReg));
     disco.write((const char*) reg.contentReg,sizeMalloc);

     disco.flush();
     disco.close();


     free(buffer);
     this->setCantRegActivos(this->getCantRegActivos()+1);
     this->setCantRegFisicos(this->getCantRegFisicos()+1);
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

    Registro _old = selectRecord(index);
    mapabits nulos_new(_new.getNulos());

        Metadata md(info.blockIDMD);
        unsigned int sizeMalloc = md.getrecordsize();        

        offset+=sizeof(InfoD) + index*(sizeof(InfoReg)+sizeMalloc);

        unsigned char* buffer = (unsigned char*)malloc(sizeMalloc);

        for(int i=0; i<(int)md.getCant_campos(); i++)
        {            
            InfoMDC campo = md.readCampo(i);
            if(nulos_new.getAt(i))
            {
                switch(campo.tipo_campo){
                   case 1:
                    for(int s=0; s<(int)sizeof(int);s++){
                        buffer[s]='#';
                    }
                    buffer+=sizeof(int);
                    break;
                   case 2:
                    for(int s=0; s<(int)sizeof(double);s++){
                        buffer[s]='#';
                    }
                    buffer+=sizeof(double);
                    break;
                   case 3:
                    for(int s=0; s<(int)campo.size+1;s++){
                        buffer[s]='#';
                    }
                    buffer+=campo.size+1;
                    break;

                case 4:
                    for(int s=0; s<(int)(sizeof(unsigned int)+sizeof(unsigned int));s++){
                        buffer[s]='#';
                    }
                    buffer+=(sizeof(unsigned int)+sizeof(unsigned int));
                    break;

                  case 5:
                    for(int s=0; s<(int)sizeof(bool);s++){
                        buffer[s]='#';
                    }
                    buffer+=sizeof(bool);
                    break;
                }
            }
            else
            {
                switch(campo.tipo_campo)
                {
                    case 1://Int
                        memcpy(buffer,_new.contentReg,sizeof(int));
                        buffer+=sizeof(int);
                            _old.contentReg+=sizeof(int);
                        _new.contentReg+=sizeof(int);
                        break;
                    case 2://Double
                        memcpy(buffer,_new.contentReg,sizeof(double));
                        buffer+=sizeof(double);
                            _old.contentReg+=sizeof(double);
                        _new.contentReg+=sizeof(double);
                        break;
                    case 3://Char
                        memcpy(buffer,_new.contentReg,campo.size+1);
                        buffer+=campo.size+1;
                            _old.contentReg+=campo.size+1;
                        _new.contentReg+=campo.size+1;
                        break;
                    case 4://Varchar
                        {
                            //Poner en el API que me manden con terminacion nula la cadena, y poner en varchar que recibe char* y cambiar el max_size sumarle 1
                            unsigned int bIDV, pos;
                            printf("Llego aquiii!!!");
                            memcpy(&bIDV,_old.contentReg,sizeof(unsigned int));
                            _old.contentReg+=sizeof(unsigned int);
                            memcpy(&pos,_old.contentReg,sizeof(unsigned int));
                            _old.contentReg+=sizeof(unsigned int);

                            printf("%u %u",bIDV,pos);

                            Varchar vb(bIDV);                            

                            unsigned char *varchar = (unsigned char*)malloc(1+campo.size+1);

                            printf("\nvarchar %p\n",varchar);

                            if(!nulos_new.getAt(i))
                            {
                                unsigned char tam;
                                memcpy(&tam,_new.contentReg,sizeof(unsigned char));
                                _new.contentReg+=sizeof(unsigned char);
                                memcpy(varchar,&tam,sizeof(unsigned char));
                                varchar+=sizeof(unsigned char);
                                memcpy(varchar,_new.contentReg,(int)tam+1);
                                varchar-=sizeof(unsigned char);
                                _new.contentReg+=(int)tam+1;

                                int i;
                                for(i=(int)tam+1; i<=(int)campo.size; i++)
                                {
                                    varchar[i]='#';
                                }
                                varchar[i]='\0';
                            }
                            else
                            {
                                varchar[0]=(unsigned char)0;
                                int i;
                                for(i=1; i<=(int)campo.size; i++)
                                {
                                    varchar[i]='#';
                                }
                                varchar[i]='\0';
                            }

                            vb.updateVarchar(varchar,pos);

                            memcpy(buffer,&bIDV,sizeof(unsigned int));
                            buffer+=sizeof(unsigned int);
                            memcpy(buffer,&pos,sizeof(unsigned int));
                            buffer+=sizeof(unsigned int);

                            printf("\nvarchar %p\n",varchar);

                            printf("\n%s\n",varchar);

                            free(varchar);
                        }
                        break;
                    case 5://Bool
                        memcpy(buffer,_new.contentReg,sizeof(bool));
                        buffer+=sizeof(bool);
                            _old.contentReg+=sizeof(bool);
                        _new.contentReg+=sizeof(bool);
                        break;
                }
            }
        }

        buffer-=md.getrecordsize();
        _new.setContentReg(buffer);
        _new.setTam(sizeMalloc);

        disco.seekp(offset);

        disco.write((const char*) &_new.info, sizeof(InfoReg));
        disco.write((const char*) _new.contentReg,sizeMalloc);
        disco.flush();
        disco.close();

        free(buffer);
}

// Asignado a Jaime
void Data::deleteRecord(unsigned int index)
{
    InfoReg reg;
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);

    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }

    unsigned int offset = ( 4096 * header.blockID ) + sizeof(Header) + sizeof(InfoD);
    int x=0;
    int cant = getCantRegFisicos();


    if(index>=getCantRegActivos())
    {
        throw SMException("Index invalido para el bloque de Data " + header.blockID);
    }
    else
    {

    for(int i=0; i< cant; i++)
    {
        disco.seekg(offset);
        disco.read( (char*) &reg , sizeof(InfoReg));

        if(reg.tombstone) // == true
        {
            continue;
        }
        else if(!reg.tombstone)// == false
        {
            if(x==(int)index)
            {
                reg.tombstone=true;
                disco.seekp(offset);
                disco.write((const char*) &reg, sizeof(InfoReg));
                disco.flush();
                disco.close();
                break;
            }
            else
            {
                x++;
            }
        }
        offset+=sizeof(InfoReg) + reg.tam;
    }

        this->setCantRegActivos(this->getCantRegActivos()-1);
    }
}

// Asignado a Richard
Registro Data::selectRecord(unsigned int index)
{
    InfoReg reg;
    fstream disco;
    disco.open(path, ios::binary | ios::in | ios::out);

    if (!disco) {
        throw SMException("No se pudo abrir el archivo tablespace.dat");
    }

    unsigned int offset = ( 4096 * header.blockID ) + sizeof(Header) + sizeof(InfoD);
    int x=0;
    int cant = getCantRegFisicos();


    if(index>=getCantRegActivos())
    {
        throw SMException("Index invalido para el bloque de Data " + header.blockID);
    }
    else
    {

    for(int i=0; i< cant; i++)
    {
        disco.seekg(offset);
        disco.read( (char*) &reg , sizeof(InfoReg));

        if(reg.tombstone) // == true
        {
            continue;
        }
        else if(!reg.tombstone)// == false
        {
            if(x==(int)index)
            {
                unsigned char *contenido = (unsigned char *)malloc(reg.tam);
                disco.read((char*)contenido,reg.tam);
                Registro registro;
                registro.info = reg;
                registro.setContentReg(contenido);
                return registro;
            }
            else
            {
                x++;
            }
        }
        offset+=sizeof(InfoReg) + reg.tam;
    }
    }


}
