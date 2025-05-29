#include <iostream>
#include <cstring>
#include "Horario.h"
using namespace std;


Horario::Horario(){
    _hora = 0;
    _minuto = 0;
}


 Horario::Horario(int hora, int minuto){
    setHora(hora);
    setMinuto(minuto);
}

void Horario::setHora(int hora){
    if(hora>0 && hora<24){
    _hora = hora;
    }else{
        cout<<"Hora invalida"<<endl;
    }
}

int Horario::getHora(){
    return _hora;
}

void Horario::setMinuto(int minuto){
    if(minuto>0 && minuto<59){
    _minuto = minuto;
    }else{
        cout<<"Minuto invalida"<<endl;
    }
}

int Horario::getMinuto(){
    return _minuto;
}


void Horario::cargar() {
    cout << "Ingrese hora (0 a 23): ";
    cin >> _hora;
    while (_hora < 0 || _hora > 23) {
        cout << "Hora invalida. Ingrese una hora entre 0 y 23: ";
        cin >> _hora;
    }

    cout << "Ingrese minuto (0 a 59): ";
    cin >> _minuto;
    while (_minuto < 0 || _minuto > 59) {
        cout << "Minuto invalido. Ingrese un minuto entre 0 y 59: ";
        cin >> _minuto;
    }
}

void Horario::mostrar() {
    cout << "Horario: ";
    if (_hora < 10) cout << "0";
    cout << _hora << ":";
    if (_minuto < 10) cout << "0";
    cout << _minuto << endl;
}
