/* 
 * File:   main.cpp
 * Author: administrador
 *
 * Created on 12 de agosto de 2011, 6:33
 */

#include <cstdlib>
#include <iostream>
#include "mapabits.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {    
    //Uso del unsigned short nulos de la clase InfoReg
    
    //Digamos q esta es la descripcion de la tabla
    //cod - int
    //nombre - varchar
    //edad - int - null
    
    //Supongamos q tenemos el siguiente registro a insertar
    //1 / 5Maria / - 
    
    //Entonces el mapa de bits de nulos de este registro
    //se haria de la siguiente forma en el orden de la
    //definicion de la tabla edad tiene como index 2 
    //y esta nulo para el registro anterior entonces
    unsigned short x = 0; //Iniciamos el mapa de bits de nulos en ceros
    
    mapabits m(x);
    m.mostrarmapa();
    cout<<endl;
    m.setOn(2); //Indicamos q el campo edad para el registro anterior es nulo
    m.mostrarmapa();
    if(m.getAt(2)) //Averiguamos si el campo edad para el registro anterior es nulo
    {
        cout<<"Encendido"<<endl;
    }
    else
    {
        cout<<"Apagado"<<endl;
    }
    //La variable x seria el mapa de bits de nulos para el registro
    //anterior

    return 0;
}

