#include <iostream>
#include "Tutor.h"
#include "Persona.h"
using namespace std;

int Tutor::_ultimoid = 0;

Tutor::Tutor(){
    _IDTutor = ++_ultimoid;
}




int Tutor::getIDTutor(){
    return _IDTutor;
}


void Tutor::cargar(){
    Persona::cargar();
}


void Tutor::mostrar(){
    Persona::mostrar();
    cout<<"El Id de tutor es: "<<_IDTutor<<endl;

}
