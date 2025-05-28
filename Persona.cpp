#include <iostream>
#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Domicilio.h"
using namespace std;



Persona::Persona()
    : _fechaNacimiento(),_domicilio()
{

    strcpy(_nombres, "");
    strcpy(_apellidos, "");
    strcpy(_dni, "");
    _edad = 0;
    strcpy(_genero, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _estado = false;
}

Persona::Persona(const char* nombres, const char* apellidos, const char* dni, int edad, Fecha fechaNacimiento, const char* genero, const char* telefono, const char* email, Domicilio domicilio, bool estado){
    setNombres(nombres);
    setApellidos(apellidos);
    setDni(dni);
    setEdad(edad);
    setFecha(fechaNacimiento);
    setGenero(genero);
    setTelefono(telefono);
    setEmail(email);
    setDomicilio(domicilio);
    setEstado(estado);
}
// verifica que el nombre no este vacio
void Persona::setNombres(const char* nombres){
      if (strlen(nombres) > 0) {
        strcpy(_nombres, nombres);
    } else {
        strcpy(_nombres, "SinNombre");
    }
}

const char* Persona::getNombres(){
    return _nombres;
}

//verifica que no tenga apellidos
void Persona::setApellidos(const char* apellidos){
      if (strlen(apellidos) > 0) {
        strcpy(_apellidos, apellidos);
    } else {
        strcpy(_apellidos, "SinApellidos");
    }
}

const char* Persona::getApellidos(){
    return _apellidos;
}

//verifica que el dni este entre 7 y 8 caracteres
void Persona::setDni(const char* dni){
    if(strlen(dni)>=7 && strlen(dni) <=8){
    strcpy(_dni,dni);
    }else{
        strcpy(_dni,"00000000");
    }
}

void Persona::setEdad(int edad){
    if(edad>0){
    _edad=edad;
    }else{
    _edad = 0;
    }
}

int Persona::getEdad(){
    return _edad;
}
//verifica que sea uno de los valores validos
void Persona::setGenero(const char* genero){
     if (strcmp(genero, "Masculino") == 0 || strcmp(genero, "Femenino") == 0 || strcmp(genero, "Otro") == 0) {
        strcpy(_genero, genero);
    } else {
        strcpy(_genero, "No eleccion");
    }
}

const char* Persona::getGenero(){
    return _genero;
}

void Persona::setFecha(Fecha fechaNacimiento){
    _fechaNacimiento=fechaNacimiento;
}

Fecha Persona::getFecha(){
    return _fechaNacimiento;
}
void Persona::setTelefono(const char* telefono){
    strcpy(_telefono, telefono);
}

const char* Persona::getTelefono(){
    return _telefono;
}
//verifica que el email contenga un @

void Persona::setEmail(const char* email){
     if (strchr(email, '@') != nullptr) {
        strcpy(_email, email);
    } else {
        strcpy(_email, "invalido@mail.com");
    }
}

const char* Persona::getEmail(){
    return _email;
}

void Persona::setDomicilio(Domicilio domicilio){
    _domicilio=domicilio;
}

Domicilio Persona::getDomicilio(){
    return _domicilio;
}

void Persona::setEstado(bool estado){
    _estado = estado;
}

bool Persona::getEstado(){
    return _estado;
}



void Persona::cargar() {
    cout << "Ingrese nombres: ";
    cin.getline(_nombres, 40);

    cout << "Ingrese apellidos: ";
    cin.getline(_apellidos, 40);

    cout << "Ingrese DNI: ";
    cin.getline(_dni, 9);

    cout << "Ingrese edad: ";
    cin >> _edad;
    cin.ignore();

    cout << "Ingrese genero (Masculino/Femenino/Otro): ";
    cin.getline(_genero, 20);

    cout << "Ingrese telefono: ";
    cin.getline(_telefono, 11);

    cout << "Ingrese email: ";
    cin.getline(_email, 50);

    cout << "Ingrese fecha de nacimiento:" << endl;
    _fechaNacimiento.cargar();

    cout << "Ingrese domicilio:" << endl;
    _domicilio.cargar();

    _estado = true;
}

void Persona::mostrar() {
    cout << "Nombre: " << _nombres << endl;
    cout << "Apellido: " << _apellidos << endl;
    cout << "DNI: " << _dni << endl;
    cout << "Edad: " << _edad << endl;
    cout << "Genero: " << _genero << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;

    cout << "Fecha de nacimiento: ";
    _fechaNacimiento.mostrar();

    cout << "Domicilio: ";
    _domicilio.mostrar();

    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
}
