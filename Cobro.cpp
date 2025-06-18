#include <iostream>
#include <cstring>
#include "Cobro.h"


using namespace std;


Cobro::Cobro(){

}


Cobro::Cobro(int idCobro, int idInscripcion, Fecha fechaCobro, float monto, const char* tipoCobro){


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

void Cobro::setTipoCobro(const char* tipo){
    strncpy(_tipoCobro, tipo, 19); _tipoCobro[19]= 0;
}

const char* Cobro::getTipoCobro(){
    return _tipoCobro;
}
