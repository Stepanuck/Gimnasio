#include <iostream>
#include "Socio.h"
#include "Fecha.h"
#include "Plan.h"
#include "Inscripcion.h"

using namespace std;

Inscripcion::Inscripcion(){
}
Inscripcion::Inscripcion(int idInscripcion,int idSocio, int idPlan, Fecha fechaPago, bool pago){
    setIdInscripcion(idInscripcion);
    setIdSocioInscripto(idSocio);
    setIdPlanInscripto(idPlan);
    setFechaDePago(fechaPago);
    setPago(pago);

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

    _idPlanIncripto=idPlan;

}
int Inscripcion::getIdPlanInscripto(){

    return _idPlanIncripto;

}
void Inscripcion::setFechaDePago(Fecha fechaPago){

    _fechaDePago = fechaPago;

}
Fecha Inscripcion::getFechaDePago(){

    return _fechaDePago;

}
void Inscripcion::setPago(bool pago){

    _pago = pago;

}
bool Inscripcion::getPago(){

    return _pago;

}
bool Inscripcion::operator == (Inscripcion Insc){

    if(_idSocioInscripto==Insc._idSocioInscripto&&_idPlanIncripto==Insc._idPlanIncripto&&_fechaDePago==Insc._fechaDePago){

       return true;

    }
    else {

        return false;

    }
}
