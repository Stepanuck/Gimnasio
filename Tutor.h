#pragma once
#include "Persona.h"



class Tutor : public Persona{

private:
    int _IDTutor;
    static int _ultimoid;

public:
    Tutor();
    int getIDTutor();
    void cargar();
    void mostrar();
};
