#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <QString>
#include "Metadata.h"

using namespace std;

int main(int argc, char *argv[])
{
    unsigned char *temp = (unsigned char*)malloc(15);
    unsigned int x=155;
    memcpy(temp,&x,sizeof(unsigned int));
    temp+=sizeof(unsigned int);
    x=4;
    memcpy(temp,&x,sizeof(unsigned int));
    temp+=sizeof(unsigned int);
    unsigned char y = 5;
    memcpy(temp,&y,sizeof(unsigned char));
    temp+=sizeof(unsigned char);
    string z = "Maria";
    char* cadena = (char*)z.c_str();
    memcpy(temp,z.c_str(),(int)y+1);
    temp+=y+1;
    temp-=(sizeof(unsigned int)+sizeof(unsigned int)+sizeof(unsigned char)+y+1);

    unsigned int bIDV, pos;
    memcpy(&bIDV,temp,sizeof(unsigned int));
    temp+=sizeof(unsigned int);
    memcpy(&pos,temp,sizeof(unsigned int));
    temp+=sizeof(unsigned int);

    cout<<bIDV<<endl;
    cout<<pos<<endl;

    unsigned char tam;
    memcpy(&tam,temp,sizeof(unsigned char));
    temp+=sizeof(unsigned char);
    char *varchar = (char*)malloc(1+10);
    memcpy(varchar,&tam,sizeof(unsigned char));
    varchar+=sizeof(unsigned char);
    memcpy(varchar,temp,(int)tam);
    varchar+=(int)tam;
    /*for(int i=0; i<(int)tam; i++)
    {
        memcpy(varchar,temp,sizeof(unsigned char));
        temp++;
        varchar++;
    }*/
    varchar-=(1+(int)tam);

    int i;
    for(i=(int)tam+1; i<=10; i++)
    {
        varchar[i]='#';
    }

    printf("%s\n",varchar);

    char* prueba = (char*)malloc(12);
    memcpy(prueba,varchar,12);
    prueba[(int)tam+1]='\0';

    printf("%s\n",prueba);

    unsigned char byte = 255;
    cout<<byte<<":"<<(int)byte<<endl;

    cout<<sizeof(Header)<<endl;
    cout<<sizeof(InfoMD)<<endl;
    cout<<sizeof(InfoMDC)<<endl;

    system("pause");
    return 0;
}
