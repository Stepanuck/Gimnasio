#pragma once
#include "Horario.h"
#include "Tutor.h"

class Actividad{

    private:
    int _idActividad;
    char _nombre[20];
    char _diaDeLaSemana[10];
    int _cuposDisponibles;
    Horario _horarioActividad;
    Tutor _idTutorACargo;

    public:
    void setIdActividad(int idActividad);
    int getIdActividad();
    void setNombre(const char* nombre);
    const char* getNombre();
    void setDiaDeLaSemana(const char* diaDeLaSemana);
    const char* getDiaDeLaSemana();
    void setCuposDisponibles(int cuposDisponibles);
    int getCuposDisponibles();
    void setHorarioActividad(Horario horirioActividad);
    Horario getHorarioActividad();
    void setIdTutorACargo(Tutor idTutorACargo);
    Tutor getIdTutorACargo();

};
