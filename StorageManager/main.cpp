/* 
 * File:   main.cpp
 * Author: joc
 *
 * Created on 24 de julio de 2011, 19:29
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>

#include "Metadata.h"
#include "SystemBlock.h"
#include "StorageManager.h"

using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
   
    SystemBlock cp;
    StorageManager b;
    b.createTableSpace("jj","777","555",50);
    Metadata meta("camilo",4);
    meta.escribir();
    
//    InfoMDC array[4];
//    
//    InfoMDC x1;
//   
//    
//    array[0] = x1;
    
    
    
    
    return 0;
}

