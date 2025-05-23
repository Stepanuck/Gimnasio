#include <iostream>
#include "Domicilio.h"
using namespace std;


 Domicilio::Domicilio(){
    _direccion=" ";
    _altura = 0;
    _piso = 0;
    _departamento[0] = 'A';
    _codigoPostal = " ";

}

 Domicilio::Domicilio(std::string direccion, int altura, int piso, char departamento, string codigoPostal){
    setDireccion(direccion);
    setAltura(altura);
    setPiso(piso);
    setDepartamento(departamento);
    setCodigoPostal(codigoPostal);
 }



void Domicilio::setDireccion(string direccion){
    _direccion=direccion;
}

string Domicilio::getDireccion() {
    return _direccion;
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

void Domicilio::setCodigoPostal(string codigoPostal){
    _codigoPostal = codigoPostal;
}

string Domicilio::getCodigoPostal(){
    return _codigoPostal;
}

void Domicilio::cargar() {
    cout << "Ingrese direccion: ";
    cin.ignore();
    getline(cin, _direccion);

    cout << "Ingrese altura: ";
    cin >> _altura;

    cout << "Ingrese piso: ";
    cin >> _piso;

    cout << "Ingrese departamento (una letra): ";
    cin >> _departamento;

    cout << "Ingrese código postal: ";
    cin.ignore();
    getline(cin, _codigoPostal);
}

void Domicilio::mostrar() {
    cout << "Direccion: " << _direccion << " " << _altura;
    cout << ", Piso: " << _piso << ", Depto: " << _departamento << endl;
    cout << "Código Postal: " << _codigoPostal << endl;
}




