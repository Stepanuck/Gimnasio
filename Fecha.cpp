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
    if(dia>0 && dia<=31){
    _dia=dia;
    }else{
        cout<<"Dia invalido"<<endl;
    }
}
int Fecha::getDia(){
    return _dia;
}

void Fecha::setMes(int mes){
    if(mes >= 1 && mes <=12){
    _mes=mes;
    }else{
        cout<<"Mes invalido"<<endl;
    }
}

int Fecha::getMes(){
    return _mes;
}

void Fecha::setAnio(int anio){
    if(anio>1925 && anio<2025){
    _anio=anio;
    }else{
        cout<<"Anio invalido"<<endl;
    }
}

int Fecha::getAnio(){
    return _anio;
}


void Fecha::cargar(){
   do{
    cout<<"Ingrese dia: ";
    cin>> _dia;
    if(_dia <1 || _dia>31){
        cout<<"Dia invalido, ingrese un dia valido."<<endl;
    }
   }while(_dia <1 || _dia >31);

    do{
    cout<<"Ingrese mes: ";
    cin>>_mes;
    if(_mes<0 || _mes>12){
        cout<<"Ingrese un mes valido entre 1 y 12"<<endl;
    }
    }while (_mes < 1 || _mes > 12);
    do{
    cout<<"Ingrese anio: ";
    cin>>_anio;
    if(_anio<1925 || _anio>2025){
        cout<<"Ingrese un anio valido"<<endl;
    }
    }while(_anio<1925 || _anio >2025);
}
void Fecha::mostrar(){

    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;

}
    void Fecha::sumarMeses(int cantidad){
        _mes+=cantidad;
        while(_mes>12){
            _mes-=12;
            _anio++;
        }
        int diasPorMes[]={31,28,31,30,31,30,31,31,30,31,30,31};
            //Calculo para el año bisiesto
    if (_mes == 2 && (_anio % 4 == 0 && (_anio % 100 != 0 || _anio % 400 == 0))) {
    if (_dia > 29) _dia = 29;
    } else if (_dia > diasPorMes[_mes - 1]) {
        _dia = diasPorMes[_mes - 1];
    }
    }

    bool Fecha::operator==(const Fecha& otra) const {
    return _dia == otra._dia && _mes == otra._mes && _anio == otra._anio;
}

bool Fecha::operator == (Fecha fecha){

    if(_dia!=fecha._dia)return false;
    if(_mes!=fecha._mes)return false;
    if(_anio!=fecha._anio)return false;

    return true;
}
