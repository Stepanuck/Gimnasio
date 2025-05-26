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
    bool _estado;

    public:
    Actividad();
    Actividad(int idActividad, const char* nombre, const char* diaDeLaSemana, int cuposDisponibles,
    Horario horarioActividad, Tutor idTutorACargo, bool estado);
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
    void setEstado(bool estado);
    bool getEstado();

};
