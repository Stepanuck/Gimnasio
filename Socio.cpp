#include <iostream>
#include "Socio.h"
#include "Persona.h"

using namespace std;



Socio::Socio(){
    _idsocio = 0;
}

void Socio::setIdSocio(int id){
    _idsocio=id;
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
