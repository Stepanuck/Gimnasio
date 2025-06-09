#pragma once
#include "Persona.h"


class Socio : public Persona {

private:
    int _idsocio;

public:
    Socio();
    int getIDSocio();
    void setIdSocio(int id);
    void cargar();
    void mostrar();


};
