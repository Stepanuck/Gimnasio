#include <iostream>
#include <cstring>
#include "Actividad.h"

using namespace std;

Actividad::Actividad(){
    _idActividad=0;
    strcpy(_nombre,"");
    strcpy(_diaDeLaSemana,"");
    _cuposDisponibles=0;
    _horarioActividad=Horario.Horario();
    _idTutorACargo=Tutor.Tutor();

}

    Actividad(int idActividad, const char* nombre, const char* diaDeLaSemana, int cuposDisponibles, Horario horarioActividad, Tutor idTutorACargo);
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
