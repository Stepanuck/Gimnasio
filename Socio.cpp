#include <iostream>
#include "Socio.h"
#include "Persona.h"

using namespace std;

    int Socio::_ultimoid = 0;


Socio::Socio(){
    _idsocio = ++_ultimoid;
}


int Socio::getIDSocio(){
    return _idsocio;
}

void Socio::cargar(){
    Persona::cargar();
}

void Socio::mostrar(){
    Persona::mostrar();
    cout<<"El Id del socio es: "<<_idsocio<<endl;
}
