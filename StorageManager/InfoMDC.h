#ifndef INFOMDC_H
#define INFOMDC_H

class InfoMDC
{
public:
    InfoMDC();
    unsigned short tipo_campo;
    char nombre_campo[30];
    unsigned int size;
    bool nulls;
    bool PK;
    char DEFAULT[30];
    unsigned int inicio_varchar ;
    unsigned int final_varchar ;
};

#endif // INFOMDC_H
