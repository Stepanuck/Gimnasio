#pragma once
#include "Fecha.h"


class Cobro{
private:
    int _idCobro;
    int _idInscripcion;
    Fecha _fechaCobro;
    float _monto;
    char _tipoCobro[20];

public:

    Cobro();
    Cobro(int idCobro, int idInscripcion, Fecha fechaCobro, float monto, const char* tipoCobro);

    void setIdCobro(int id);
    int getIdCobro();

    void setIdInscripcion(int id);
    int getIdInscripcion();

    void setFechaCobro(Fecha fecha);
    Fecha getFechaCobro();

    void setMonto(float monto);
    float getMonto();

    void setTipoCobro(const char* tipo);
    const char* getTipoCobro();

};
