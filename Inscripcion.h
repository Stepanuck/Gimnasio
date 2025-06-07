#pragma once
#include "Plan.h"
#include "Socio.h"
#include "Fecha.h"





class Inscripcion{

private:
    Socio _idSocioInscripto;
    Plan _idPlanIncripto;
    Fecha _fechaDePago;
    bool _pago;
public:

    Socio getIdSocioInscripto();
    Plan getIdPlanInscripto();

    void setFechaDePago(Fecha fechaPago);
    Fecha getFechaDePago();

    void setPago(bool pago);
    bool getPago();



};
