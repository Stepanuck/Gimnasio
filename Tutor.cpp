#include <iostream>
#include "Tutor.h"
#include "Persona.h"
using namespace std;

Tutor::Tutor(){
    _IDTutor = 0;
}

void Tutor::setIDTutor(int id){
    _IDTutor=id;

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
