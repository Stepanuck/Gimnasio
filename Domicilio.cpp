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

const char* Domicilio::getCodigoPostal(){
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
    char opc[3];
    bool SiDpto=false;

    //verificacion de que calle no este vacio
    do{
    cout << "Ingrese calle: ";
    //cin.ignore();
    cin.getline(_calle, 50);
     if(strlen(_calle)==0){
        cout<<"No se puede ingresar una calle vacia"<<endl;
     }
    }while(strlen(_calle)==0);

    // que altura no sea menor de 0
    do{
    cout << "Ingrese altura: ";
    cin >> _altura;
    if(_altura<0){
        cout<<"La altura no puede ser menor a 0"<<endl;
    }
    }while(_altura<0);

    //Verifica si vive en departamento o no
  do {
        cout << "¿Vive en departamento? (SI / NO): ";
        cin.ignore();
        cin.getline(opc, 3);

        if (!(strcmp(opc, "SI") == 0 || strcmp(opc, "Si") == 0 || strcmp(opc, "si") == 0 ||
              strcmp(opc, "NO") == 0 || strcmp(opc, "No") == 0 || strcmp(opc, "no") == 0)) {
            cout << "Respuesta inválida. Escriba SI o NO.\n";
        }

        if (strcmp(opc, "SI") == 0 || strcmp(opc, "Si") == 0 || strcmp(opc, "si") == 0) {
        do {
            cout << "Ingrese piso (mayor o igual a 0): ";
            cin >> _piso;
            if (_piso < 0) {
                cout << "El piso no puede ser negativo.\n";
            }
        } while (_piso < 0);

        do {
            cout << "Ingrese departamento (una letra): ";
            cin >> _departamento;
            cin.ignore();
        } while (!((_departamento >= 'A' && _departamento <= 'Z') || (_departamento >= 'a' && _departamento <= 'z')));
    } else {
        _piso = 0;
        _departamento = ' ';
    }
    } while (!(strcmp(opc, "SI") == 0 || strcmp(opc, "Si") == 0 || strcmp(opc, "si") == 0 ||
               strcmp(opc, "NO") == 0 || strcmp(opc, "No") == 0 || strcmp(opc, "no") == 0));
    //verificacion del codigo postal
    do{
    cout << "Ingrese codigo postal: ";
    cin.getline(_codigoPostal, 10);
    if(strlen(_codigoPostal)==0){
        cout<<"El codigo Postal no puede estar vacio"<<endl;
    }
    }while(strlen(_codigoPostal)==0);

    //Verificacion de provincia
    do{
    cout << "Ingrese partido: ";
    cin.getline(_partido, 20);
    if(strlen(_partido)==0){
        cout<<"El partido no puede estar vacio"<<endl;
    }
    }while(strlen(_partido)==0);

    //verificacion de provincia
    do{
    cout << "Ingrese provincia: ";
    cin.getline(_provincia, 20);
    if(strlen(_provincia)==0){
        cout<<"La provincia no puede estar vacia"<<endl;
    }
    }while(strlen(_provincia) == 0);
}

void Domicilio::mostrar() {
    cout << "Domicilio: " << _calle << " " << _altura << ", Piso " << _piso << ", Depto " << _departamento << endl;
    cout << "Codigo Postal: " << _codigoPostal << ", Partido: " << _partido << ", Provincia: " << _provincia << endl;
}




