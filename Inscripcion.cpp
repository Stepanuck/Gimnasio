#include <iostream>
#include "Socio.h"
#include "Fecha.h"
#include "Plan.h"
#include "Inscripcion.h"

using namespace std;


Plan Inscripcion::getIdPlanInscripto(){
    return _idPlanIncripto;
}


    Socio Inscripcion::getIdSocioInscripto(){
        return _idSocioInscripto;
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
