#pragma once
#include "Inscripcion.h"



class ArchivoInscripcion{

private:
    char _nombre[50];

public:

    ArchivoInscripcion(const char* nombre = "Inscripciones.dat");
    Inscripcion Leer(int pos);
    int buscarInscripcion(int idInscripcion);
    int agregarRegistro (Inscripcion insc);
    bool listarRegistros();
    int getCantidadRegistros();
    int modificarInscripcion(Inscripcion insc, int pos);
    bool bajaLogica(int idInscripcion);
    bool altaLogica(int idInscripcion);



};

