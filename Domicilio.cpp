#include <iostream>
#include <cstring>
#include "Domicilio.h"
using namespace std;


 Domicilio::Domicilio(){
    strcpy(_calle, "");
    _altura = 0;
    _piso = 0;
    _departamento = ' ';
    strcpy(_codigoPostal, "");
    strcpy(_partido, "");
    strcpy(_provincia, "");
}

 Domicilio::Domicilio(const char* calle, int altura, int piso, char departamento,const char* codigoPostal, const char* partido, const char* provincia){
    setCalle(calle);
    setAltura(altura);
    setPiso(piso);
    setDepartamento(departamento);
    setCodigoPostal(codigoPostal);
    setPartido(partido);
    setProvincia(provincia);
 }



void Domicilio::setCalle(const char* calle){
    strcpy(_calle, calle);
}

const char* Domicilio::getCalle() {
    return _calle;
}

void Domicilio::setAltura(int altura){
        _altura=altura;
}

int Domicilio::getAltura(){
    return _altura;
}

void Domicilio::setPiso(int piso){
    _piso=piso;
}

int Domicilio::getPiso(){
    return _piso;
}


void Domicilio::setDepartamento(char departamento){
    _departamento=departamento;
}

char Domicilio::getDepartamento(){
    return _departamento;
}

void Domicilio::setCodigoPostal(const char* codigoPostal){
    strcpy(_codigoPostal,codigoPostal);
}

string Domicilio::getCodigoPostal(){
    return _codigoPostal;
}

void Domicilio::setPartido(const char* partido){
    strcpy(_partido,partido);
}

const char* Domicilio::getPartido(){
    return _partido;
}

void Domicilio::setProvincia(const char* provincia){
    strcpy(_provincia, provincia);
}

const char* Domicilio::getProvincia(){
    return _provincia;
}

void Domicilio::cargar() {
    cout << "Ingrese calle: ";
    cin.ignore();
    cin.getline(_calle, 50);

    cout << "Ingrese altura: ";
    cin >> _altura;

    cout << "Ingrese piso: ";
    cin >> _piso;

    cout << "Ingrese departamento (una letra): ";
    cin >> _departamento;

    cout << "Ingrese codigo postal: ";
    cin.ignore();
    cin.getline(_codigoPostal, 10);

    cout << "Ingrese partido: ";
    cin.getline(_partido, 20);

    cout << "Ingrese provincia: ";
    cin.getline(_provincia, 20);
}

void Domicilio::mostrar() {
    cout << "Domicilio: " << _calle << " " << _altura << ", Piso " << _piso << ", Depto " << _departamento << endl;
    cout << "Codigo Postal: " << _codigoPostal << ", Partido: " << _partido << ", Provincia: " << _provincia << endl;
}




