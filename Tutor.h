#pragma once
#include "Persona.h"



class Tutor : public Persona{

private:
    int _IDTutor;

public:
    Tutor();
    void setIDTutor(int id);
    int getIDTutor();
    void cargar();
    void mostrar();
};
