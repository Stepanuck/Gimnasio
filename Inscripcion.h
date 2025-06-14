#pragma once
#include "Fecha.h"





class Inscripcion{

private:
    int _idInscripcion;
    int _idSocioInscripto;
    int _idPlanIncripto;
    Fecha _fechaDePago;
    bool _pago;
public:

    Inscripcion();
    Inscripcion(int idInscripcion,int idSocio, int idPlan, Fecha fechaPago, bool pago);
    void setIdSocioInscripto(int idSocio);
    int getIdSocioInscripto();
    void setIdPlanInscripto(int idPlan);
    int getIdPlanInscripto();
    void setIdInscripcion(int idInscripcion);
    int getIdInscripcion();
    void setFechaDePago(Fecha fechaPago);
    Fecha getFechaDePago();
    void setPago(bool pago);
    bool getPago();
    bool operator == (Inscripcion Insc);


};
