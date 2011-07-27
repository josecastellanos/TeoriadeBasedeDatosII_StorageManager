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
    Metadata a(1,2,4,"MD");
    SystemBlock cp;
    cout<<sizeof(InfoSB)<<" "<<sizeof(SystemBlock);
    StorageManager b;
    b.createTableSpace("jj","1.3.4","123",10000);
    SystemBlock mySystemBlock;
        
    for (int i=0;i<6;i++)
    {
        cout<<"Libre que se Devuelve "<<mySystemBlock.getFree()<<endl;
        //cout<<"Libre que se Devuelve "<<mySystemBlock.getFree();
    }
    cout<<"TTTTTTT test de Git TTTTTTTT";
    system("pause");
    system("pause");
    system("pause");
    
    return 0;
}

