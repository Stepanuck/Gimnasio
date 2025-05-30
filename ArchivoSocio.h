#pragma once
#include "Archivo.h"
#include "Socio.h"




class ArchivoSocio : public Archivo{

public:

    ArchivoSocio(const char* nombre = "Socios.dat");

    int agregarRegistro(Socio soc);
    Socio Leer(int pos);
    int modificarSocio(Socio soc, int pos);
    int BuscarSocio(const char* dniSocio);
    bool bajaLogica(const char* dni);
    bool altaLogica(const char* dni);
} ;

