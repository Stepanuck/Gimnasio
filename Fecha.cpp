#include <iostream>
#include "Fecha.h"
using namespace std;


Fecha::Fecha(int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}
Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}
void Fecha::setDia(int dia){
    _dia=dia;
}
int Fecha::getDia(){
    return _dia;
}

void Fecha::setMes(int mes){
    _mes=mes;
}

int Fecha::getMes(){
    return _mes;
}

void Fecha::setAnio(int anio){
    _anio=anio;
}

int Fecha::getAnio(){
    return _anio;
}


void Fecha::cargar(){
    cout<<"Ingrese dia: "<<endl;
    cin>>_dia;
    cout<<"Ingrese mes: "<<endl;
    cin>>_mes;
    cout<<"Ingrese anio: "<<endl;
    cin>>_anio;
}




void Fecha::mostrar(){
    cout<<"Dia: "<<_dia<<endl;
    cout<<"Mes: "<<_mes<<endl;
    cout<<"Anio: "<<_anio<<endl;
}
