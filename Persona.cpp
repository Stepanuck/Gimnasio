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
const char* Persona::getDni() {
    return _dni;
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
     if (strchr(email, '@') != nullptr) {///strchr compara cada caracter con @, si encuentra una coincidencia, devuelve un puntero al lugar de la cadena, si no, devuelve nullptr
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

    char auxNombres[40];
    do {
        cout << "Ingrese nombres: ";
        cin.getline(auxNombres, 40);
        if (strlen(auxNombres) == 0) {
            cout << "Error: El nombre no puede estar vacio.";
        }
    } while (strlen(auxNombres) == 0);
    setNombres(auxNombres);


    char auxApellidos[40];
    do {
        cout << "Ingrese apellidos: ";
        cin.getline(auxApellidos, 40);
        if (strlen(auxApellidos) == 0) {
            cout << "Error: El apellido no puede estar vacio.";
        }
    } while (strlen(auxApellidos) == 0);
    setApellidos(auxApellidos);


    char auxDni[9];
    do {
        cout << "Ingrese DNI (7 u 8 digitos): ";
        cin.getline(auxDni, 9);
        size_t len = strlen(auxDni);//tipo de dato que mide logintudes y tamanios, strlen devuelve la longitud de la cadena
        if (len < 7 || len > 8) {
            cout << "Error: El DNI debe tener entre 7 y 8 caracteres.";
        }
    } while (strlen(auxDni) < 7 || strlen(auxDni) > 8);
    setDni(auxDni);


    int auxEdad;//cin.fail() lo usamos para ver que en el ingreso sea un numero y si es una letra tira el fallo, es una bandera que se pone en true al tener el fallo
    do {//cin.clear() limpia la bandera del fallo para restablecer el flujo
        cout << "Ingrese edad (mayor a 0): ";
        cin >> auxEdad;
        if (cin.fail() || auxEdad <= 0) {
            cout << "Error: Edad invalida.";
            cin.clear();
            cin.ignore();
            auxEdad = 0;
        }
    } while (auxEdad <= 0);
    setEdad(auxEdad);
    cin.ignore();


    char auxGenero[20];
    do {
        cout << "Ingrese genero (Masculino/Femenino/Otro): ";
        cin.getline(auxGenero, 20);
        if (strcmp(auxGenero, "Masculino") != 0 &&
            strcmp(auxGenero, "Femenino")  != 0 &&
            strcmp(auxGenero, "Otro")      != 0) {
            cout << "Error: Genero invalido.";
        }
    } while (strcmp(auxGenero, "Masculino") != 0 &&
             strcmp(auxGenero, "Femenino")  != 0 &&
             strcmp(auxGenero, "Otro")      != 0);
    setGenero(auxGenero);


   char auxTelefono[15];
do {
    cout << "Ingrese teléfono: ";
    cin.getline(auxTelefono, 15);
    if (strlen(auxTelefono) == 0) {
        cout << "Error: El telefono no puede estar vacio." << endl;
    }
} while (strlen(auxTelefono) == 0);
setTelefono(auxTelefono);



    char auxEmail[50];
    do {
        cout << "Ingrese email (debe contener '@'): ";
        cin.getline(auxEmail, 50);
        if (strchr(auxEmail, '@') == nullptr) {
            cout << "Error: Email invalido.";
        }
    } while (strchr(auxEmail, '@') == nullptr);
    setEmail(auxEmail);


    Fecha auxFecha;
    cout << "Ingrese fecha de nacimiento:" << endl;
    auxFecha.cargar();
    setFecha(auxFecha);


    Domicilio auxDomicilio;
    cout << "Ingrese domicilio:" << endl;
    cin.ignore();
    auxDomicilio.cargar();
    setDomicilio(auxDomicilio);

    setEstado(true);
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

    //cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
}
