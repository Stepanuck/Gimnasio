#pragma once
#include "Persona.h"


class Socio : public Persona {

private:
    int _idsocio;
    bool _Estado;
public:
    Socio();
    int getIDSocio();
    void setIdSocio(int id);
    void setEstado(bool estado);
    bool getEstado();
    void cargar();
    void mostrar();


};
