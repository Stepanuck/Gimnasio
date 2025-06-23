#include <iostream>
#include "Socio.h"
#include "Fecha.h"
#include "Plan.h"
#include "Inscripcion.h"
#include "ArchivoSocio.h"
#include "ArchivoPlan.h"

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
bool Inscripcion::operator == (Inscripcion Insc){

    if(_idSocioInscripto==Insc._idSocioInscripto&&_idPlanInscripto==Insc._idPlanInscripto&&_fechaInicio==Insc._fechaInicio){

       return true;

    }
    else {

        return false;

    }
}

void Inscripcion::MostrarInscripcion(){

    Socio s;
    ArchivoSocio archS;
    Plan p;
    ArchivoPlan archP;

    s=archS.Leer(getIdSocioInscripto()-1);
    p=archP.Leer(getIdPlanInscripto()-1);

    Fecha hoy;
    hoy.hoy(); //para cargar la fecha de hoy

    bool vigente = _activo && (_fechaFin >= hoy);

    cout << "------------------------------------------"<< endl;
    cout << "Inscripcion: ID " << getIdInscripcion() << endl;
    cout << "Socio Inscripto: ID " << getIdSocioInscripto()<< " " << s.getNombres() << " " << s.getApellidos() << endl;
    cout << "Plan Inscripto: ID " << getIdPlanInscripto()<< " " << p.getNombre() << endl;
    cout << "Fecha de Inicio: ";
    getFechaInicio().mostrar();
    cout << "Fecha de Fin: ";
    getFechaFin().mostrar();
    cout<<"Estado: "<<(vigente? "Activo" : "Vencido/Inactivo")<<endl;
    cout << "------------------------------------------"<< endl;


}
