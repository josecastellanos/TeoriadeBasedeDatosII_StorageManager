#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <QString>

using namespace std;

int main(int argc, char *argv[])
{
    unsigned char *temp = (unsigned char*)malloc(14);
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
    memcpy(temp,z.c_str(),(int)y);
    temp+=y;
    temp-=(sizeof(unsigned int)+sizeof(unsigned int)+sizeof(unsigned char)+y);

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
    char *varchar = (char*)malloc(10+1);
    memcpy(varchar,&tam,sizeof(unsigned char));
    varchar+=sizeof(unsigned char);
    strcat((char*)varchar,(const char*)temp);
    varchar+=(int)tam;
    /*for(int i=0; i<(int)tam; i++)
    {
        memcpy(varchar,temp,sizeof(unsigned char));
        temp++;
        varchar++;
    }*/
    varchar-=((int)tam+1);

    int i;
    for(i=(int)tam+1; i<=10; i++)
    {
        varchar[i]='#';
    }

    QString str(varchar);
    cout<<str.toStdString()<<endl;

    system("pause");
    return 0;
}
