#include <iostream>
#include "Tutor.h"
#include "Persona.h"
using namespace std;

Tutor::Tutor(){
    _IDTutor = 0;
    _Estado = true;
}

void Tutor::setIDTutor(int id){
    _IDTutor=id;

}


int Tutor::getIDTutor(){
    return _IDTutor;
}

void Tutor::setEstado(bool estado){
    _Estado = estado;
}
bool Tutor::getEstado(){
    return _Estado;
}

void Tutor::cargar(){
    Persona::cargar();
}


void Tutor::mostrar(){
    Persona::mostrar();
    cout<<"El Id de tutor es: "<<_IDTutor<<endl;
}
