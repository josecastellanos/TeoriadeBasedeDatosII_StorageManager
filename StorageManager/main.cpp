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

#include "Block.h"
#include "Metadata.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Metadata a(1,2,4,"MD");
    cout<<a.Header.type<<" "<<sizeof(a.Header.type)<<" "<<strlen(a.Header.type)<<" "<<sizeof(header);
    system("pause");
    return 0;
}

