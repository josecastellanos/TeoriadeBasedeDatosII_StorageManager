/* 
 * File:   StorageManager.h
 * Author: rsiwady29
 *
 * Created on July 26, 2011, 10:13 AM
 */

#ifndef STORAGEMANAGER_H
#define	STORAGEMANAGER_H

#include <string>
#include "SystemBlock.h"

class StorageManager {
public:
    StorageManager();
    //static string getPath();
    void createTableSpace(const char* nombreBD,const char* version ,const char* clave,const char* direccion,unsigned int cantBloques);
        
private:

};

#endif	/* STORAGEMANAGER_H */

