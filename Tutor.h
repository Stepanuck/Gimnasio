#pragma once
#include "Persona.h"



class Tutor : public Persona{

private:
    int _IDTutor;
    bool _Estado;
public:
    Tutor();
    void setIDTutor(int id);
    int getIDTutor();
    void setEstado(bool estado);
    bool getEstado();
    void cargar();
    void mostrar();
};
