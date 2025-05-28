#include <iostream>
#include <cstring>
#include "Actividad.h"

using namespace std;

Actividad::Actividad(){
    _idActividad=0;
    strcpy(_nombre,"");
    strcpy(_diaDeLaSemana,"");
    _cuposDisponibles=0;
    _horarioActividad=Horario();
    _idTutorACargo=Tutor();
    _estado=true;

}

Actividad::Actividad(int idActividad, const char* nombre, const char* diaDeLaSemana, int cuposDisponibles, Horario horarioActividad,
Tutor idTutorACargo, bool estado){

    setIdActividad(idActividad);
    setNombre(nombre);
    setDiaDeLaSemana(diaDeLaSemana);
    setCuposDisponibles(cuposDisponibles);
    setHorarioActividad(horarioActividad);
    setIdTutorACargo(idTutorACargo);
    setEstado(estado);

}
void Actividad::setIdActividad(int idActividad){

    _idActividad=idActividad;


}
int Actividad::getIdActividad(){

    return _idActividad;

}
void Actividad::setNombre(const char* nombre){

    if (strlen(nombre) > 0) {
        strcpy(_nombre, nombre);
    }
    else {
        strcpy(_nombre, "Sin Nombre");
    }

}
const char* Actividad::getNombre(){

    return _nombre;

}
void Actividad::setDiaDeLaSemana(const char* diaDeLaSemana){

    if (strlen(diaDeLaSemana) > 0) {
        strcpy(_diaDeLaSemana, diaDeLaSemana);
    }
    else {
        strcpy(_diaDeLaSemana, "Sin Dia Asignado");
    }

}
const char* Actividad::getDiaDeLaSemana(){

    return _diaDeLaSemana;

}
void Actividad::setCuposDisponibles(int cuposDisponibles){

    if(cuposDisponibles>0){

        _cuposDisponibles=cuposDisponibles;
    }
    else{

        _cuposDisponibles=0;
    }
}
int Actividad::getCuposDisponibles(){

    return _cuposDisponibles;

}
void Actividad::setHorarioActividad(Horario horirioActividad){

    _horarioActividad=horirioActividad;

}
Horario Actividad::getHorarioActividad(){

    return _horarioActividad;

}
void Actividad::setIdTutorACargo(Tutor idTutorACargo){

    _idTutorACargo=idTutorACargo;

}
Tutor Actividad::getIdTutorACargo(){

    return _idTutorACargo;

}
void Actividad::setEstado(bool estado){

    _estado=estado;

}
bool Actividad::getEstado(){

    return _estado;

}
