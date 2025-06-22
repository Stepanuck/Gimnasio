#pragma once
#include "Cobro.h"




class ArchivoCobro{
private:
    char _nombre[50];
public:
    ArchivoCobro(const char* nombre = "Cobro.dat");
    int agregarRegistro(Cobro cobro);
    int getCantidadRegistros();
    Cobro Leer(int pos);
    int modificarCobro(Cobro cobro, int pos);
};
