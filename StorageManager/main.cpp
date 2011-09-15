#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <QString>
#include "Metadata.h"
#include "StorageManager.h"

using namespace std;

int main(int argc, char *argv[])
{

    StorageManager *SM = new StorageManager();
    SM->createTableSpace("myDB","1.0.0","123",40);
    InfoMDC campo1;
    strcpy(campo1.nombre_campo,"campo1");
    campo1.tipo_campo=1;
    InfoMDC campo2;
    strcpy(campo2.nombre_campo,"campo2");
    campo2.tipo_campo=1;
    InfoMDC campos[] = {campo1,campo2};
     SM->createTable("tabla1",2,campos);

    system("pause");
    return 0;
}
