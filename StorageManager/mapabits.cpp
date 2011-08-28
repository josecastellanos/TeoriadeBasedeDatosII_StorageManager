#include "mapabits.h"

mapabits::mapabits(unsigned short mapa) {
    this->mapa = mapa;
}

void mapabits::mostrarmapa() {
    unsigned short m = mapa;
    unsigned short MASK = 1 << 15;
    for (int i = 0; i < 16; i++) {
        printf("%c", m & MASK ? '1' : '0');
        m <<= 1;
    }
    printf("-");
}

bool mapabits::getAt(unsigned int index) {
    if (index>16)
    {
        throw SMException("Index invalido para el mapa de bits");
    }

    unsigned short m = mapa;
    unsigned short MASK = 1 << 15;
    for (int i = 0; i < 16; i++) {
        if (i == index) {
            return m & MASK ? true : false;
        }
        m <<= 1;
    }
}

void mapabits::setOn(unsigned int index) {
    int i;

    unsigned short MASK = 1 << 15;
    for (int i = 0; i < 16; i++) {
        if (i == index) {
            mapa = mapa | (1 << (15 - index % 16));
        }
    }
}

void mapabits::setMapa(unsigned short mapa) {
    this->mapa = mapa;
}

unsigned short mapabits::getMapa() const {
    return mapa;
}
