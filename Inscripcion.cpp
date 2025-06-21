#include <iostream>
#include "Socio.h"
#include "Fecha.h"
#include "Plan.h"
#include "Inscripcion.h"

using namespace std;

Inscripcion::Inscripcion(){
    _idInscripcion = 0;
    _idSocioInscripto = 0;
    _idPlanInscripto = 0;
    _fechaInicio = Fecha();
    _fechaFin = Fecha();
    _activo = true;
}
Inscripcion::Inscripcion(int idInscripcion,int idSocio, int idPlan, Fecha fechaInicio, Fecha fechaFin, bool activo){
    setIdInscripcion(idInscripcion);
    setIdSocioInscripto(idSocio);
    setIdPlanInscripto(idPlan);
    setFechaInicio(fechaInicio);
    setFechaFin(fechaFin);
    setActivo(activo);
}
void Inscripcion::setIdInscripcion(int idInscripcion){
    _idInscripcion = idInscripcion;
 }

 int Inscripcion::getIdInscripcion(){
    return _idInscripcion;
 }
void Inscripcion::setIdSocioInscripto(int idSocio){
    _idSocioInscripto=idSocio;

}
int Inscripcion::getIdSocioInscripto(){

    return _idSocioInscripto;

}
void Inscripcion::setIdPlanInscripto(int idPlan){
    _idPlanInscripto=idPlan;

}
int Inscripcion::getIdPlanInscripto(){

    return _idPlanInscripto;

}

void Inscripcion::setFechaInicio(Fecha fechaInicio){
    _fechaInicio = fechaInicio;
}

Fecha Inscripcion::getFechaInicio(){
    return _fechaInicio;
}

void Inscripcion::setFechaFin(Fecha fechaFin){
    _fechaFin = fechaFin;
}

Fecha Inscripcion::getFechaFin(){
    return _fechaFin;
}

void Inscripcion::setActivo(bool activo){
    _activo = activo;
}

bool Inscripcion::getActivo(){
    return _activo;
}
    /// comparacion  (para evitar dobles inscripciones iguales)
/*bool Inscripcion::operator==(const Inscripcion& otra) const {
    return _idSocioInscripto == otra._idSocioInscripto &&
           _idPlanInscripto == otra._idPlanInscripto &&
           _fechaInicio == otra._fechaInicio;
}
*/

bool Inscripcion::operator == (Inscripcion Insc){

    if(_idSocioInscripto==Insc._idSocioInscripto&&_idPlanInscripto==Insc._idPlanInscripto&&_fechaInicio==Insc._fechaInicio){

       return true;

    }
    else {

        return false;

    }
}

void MostrarInscripcion(){




}
