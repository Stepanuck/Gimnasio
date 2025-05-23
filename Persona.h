#pragma once
#include "Fecha.h"
#include "Domicilio.h"


class Persona{

private:
    char _nombres[40];
    char _apellidos[40];
    char _dni[9];
    Fecha _fechaNacimiento;
    char _genero[20];
    char _telefono[11];
    char _email[50];
    Domicilio _domicilio;
    bool _estado;

public:
    Persona();
    Persona(const char* nombres, const char* apellidos, const char* dni, Fecha fechaNacimiento, const char* genero, const char* telefono, const char* email, Domicilio domicilio, bool estado);

    void setNombres(const char* nombres);
    const char* getNombres();

    void setApellidos(const char* apellidos);
    const char* getApellidos();

    void setDni(const char* dni);
    const char* getDni();

    void setFecha(Fecha fechaNacimiento);
    Fecha getFecha();

    void setGenero(const char* genero);
    const char* getGenero();

    void setTelefono(const char* telefono);
    const char* getTelefono();

    void setEmail(const char* email);
    const char* getEmail();

    void setDomicilio(Domicilio domicilio);
    Domicilio getDomicilio();

    void setEstado(bool estado);
    bool getEstado();

    void cargar();
    void mostrar();

};
