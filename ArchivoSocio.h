#pragma once
#include "Socio.h"



class ArchivoSocio{

private:
  char _nombre[50];
public:

        ArchivoSocio(const char* nombreArchivo = "Socios.dat");
        int buscarSocio(const char* dni);
        int buscarSocio(int idSocio);
        int agregarRegistro(Socio soc);
        bool listarRegistrosActivos();
        bool listarTodosLosRegistros();
        bool listarRegistrosInactivos();
        Socio Leer(int pos);
        int getCantidadRegistros();
        int modificarSocio(Socio soc, int pos);
        bool bajaLogica(const char* dni);
        bool altaLogica(const char* dni);
};
