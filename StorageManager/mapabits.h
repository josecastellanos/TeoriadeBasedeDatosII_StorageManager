#ifndef MAPABITS_H
#define MAPABITS_H

#include <stdio.h>
#include <stdlib.h>
#include <SMException.h>

class mapabits
{
public:
    unsigned short mapa;
    mapabits(unsigned short mapa);
    void mostrarmapa();
    bool getAt(unsigned int index);
    void setOn(unsigned int index);
    void setMapa(unsigned short mapa);
    unsigned short getMapa() const;
};

#endif // MAPABITS_H
