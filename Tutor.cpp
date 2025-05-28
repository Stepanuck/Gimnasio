#include <iostream>
#include "Tutor.h"
#include "Persona.h"
using namespace std;

int Tutor::_ultimoid = 0;

Tutor::Tutor(){
    _IDTutor = ++_ultimoid;
}


Tutor::Tutor(int id){
    setIDTutor(id);
    if(id > _ultimoid){
        _ultimoid = id;
    }
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
