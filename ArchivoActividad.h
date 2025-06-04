#pragma once
#include "Actividad.h"

class ArchivoActividad{

private:
    char _nombre[50];
public:

    ArchivoActividad(const char* nombreArchivo= "Actividad.dat");
    int buscarActividad(int idActividad);
    int agregarRegistro(Actividad act);
    Actividad leer(int pos);
    bool listarRegistros();
    int getCantidadRegistros();
    int modificarActividad(Actividad act, int pos);
    bool bajaLogica(int idActividad);
    bool altaLogica(int idActividad);
};
