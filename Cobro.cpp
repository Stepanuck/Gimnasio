#include <iostream>
#include <cstring>
#include "Cobro.h"


using namespace std;


Cobro::Cobro(){
    _idCobro = 0;
    _idInscripcion = 0;
    _fechaCobro = Fecha();
    _monto = 0;
}


Cobro::Cobro(int idCobro, int idInscripcion, Fecha fechaCobro, float monto){
    setIdCobro(idCobro);
    setIdInscripcion(idInscripcion);
    setFechaCobro(fechaCobro);
    setMonto(monto);

}




void Cobro::setIdCobro(int idCobro){
    _idCobro = idCobro;
}

int Cobro::getIdCobro(){
    return _idCobro;
}

void Cobro::setIdInscripcion(int idInscripcion){
    _idInscripcion = idInscripcion;
}

int Cobro::getIdInscripcion(){
    return _idInscripcion;
}

void Cobro::setFechaCobro(Fecha fechaCobro){
    _fechaCobro = fechaCobro;
}

Fecha Cobro::getFechaCobro(){
    return _fechaCobro;
}

void Cobro::setMonto(float monto){
    _monto = monto;
}

float Cobro::getMonto(){
    return _monto;
}
