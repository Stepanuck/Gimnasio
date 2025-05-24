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

Actividad::Actividad(int idActividad, const char* nombre, const char* diaDeLaSemana, int cuposDisponibles, Horario horarioActividad, Tutor idTutorACargo){

    setIdActividad(idActividad);
    setNombre(nombre);
    setDiaDeLaSemana(diaDeLaSemana);
    setCuposDisponibles(cuposDisponibles);
    setHorarioActividad(horarioActividad);
    setIdTutorACargo(idTutorACargo);


}
void Actividad::setIdActividad(int idActividad){

    _idActividad=idActividad;


}
int Actividad::getIdActividad(){

    return _idActividad;

}
void Actividad::setNombre(const char* nombre){

    if (strlen(nombres) > 0) {
        strcpy(_nombres, nombres);
    } else {
        strcpy(_nombres, "SinNombre");
    }

}
const char* Actividad::getNombre(){

    return _nombre;

}
    void setDiaDeLaSemana(const char* diaDeLaSemana);
    const char* getDiaDeLaSemana();
    void setCuposDisponibles(int cuposDisponibles);
    int getCuposDisponibles();
    void setHorarioActividad(Horario horirioActividad);
    Horario getHorarioActividad();
    void setIdTutorACargo(Tutor idTutorACargo);
    Tutor getIdTutorACargo();
