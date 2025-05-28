#pragma once
#include "Persona.h"



class Tutor : public Persona{

private:
    int _IDTutor;
    static int _ultimoid;

public:
    Tutor();
    Tutor(int id);
    void setIDTutor(int id);
    int getIDTutor();

    void cargar();
    void mostrar();
};
