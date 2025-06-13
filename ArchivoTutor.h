#pragma once
#include "Tutor.h"


class ArchivoTutor{

private:
  char _nombre[50];
public:
        ArchivoTutor(const char* nombreArchivo = "Tutor.dat");
        int buscarTutor(const char* dni);
        int agregarRegistro(Tutor tut);
        bool listarRegistrosActivos();
        bool listarTodosLosRegistros();
        bool listarRegistrosInactivos();
        Tutor Leer(int pos);
        int getCantidadRegistros();
        int modificarTutor(Tutor tut, int pos);
        bool bajaLogica(const char* dni);
        bool altaLogica(const char* dni);
};

