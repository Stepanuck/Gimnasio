#include <iostream>
#include <cstring>
#include "Actividad.h"
#include "Tutor.h"


using namespace std;

Actividad::Actividad(){
    _idActividad=0;
    strcpy(_nombre,"");
    strcpy(_diaDeLaSemana,"");
    _cuposDisponibles=0;
    _horarioActividad=Horario();
    _idTutorACargo=0;
    _estado=true;

}

Actividad::Actividad(int idActividad, const char* nombre, const char* diaDeLaSemana, int cuposDisponibles, Horario horarioActividad,
int idTutorACargo, bool estado){

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

    string DiasDeLaSemana[7]={ "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    bool band=false;

    for(int i=0; i<7; i++){

        if(diaDeLaSemana==DiasDeLaSemana[i]){

           strcpy(_diaDeLaSemana, diaDeLaSemana);
           band=true;

        }
    }
    if(!band){

        strcpy(_diaDeLaSemana, "Falta Dia");
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
void Actividad::setIdTutorACargo(int idTutorACargo){

    _idTutorACargo=idTutorACargo;

}
int Actividad::getIdTutorACargo(){

    return _idTutorACargo;

}
void Actividad::setEstado(bool estado){

    _estado=estado;

}
bool Actividad::getEstado(){

    return _estado;

}
