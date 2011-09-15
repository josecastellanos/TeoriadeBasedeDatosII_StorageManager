
#ifndef STORAGEMANAGER_H
#define	STORAGEMANAGER_H

#include <string>
#include "SystemBlock.h"
#include "Metadata.h"
#include <stdio.h>

class StorageManager {
public:
    StorageManager();
    //static string getPath();
    void createTableSpace(const char* nombreBD, const char* version, const char* clave, unsigned int cantBloques);
    //void createTable(const char* nombreTabla, unsigned int cant_campos, InfoMDC *campos);
    void createTable(const char* nombreTabla, unsigned int cant_campos, InfoMDC *campos);

private:

};

#endif	/* STORAGEMANAGER_H */
