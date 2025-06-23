#pragma once
#include "Fecha.h"





class Inscripcion{

private:
    int _idInscripcion;
    int _idSocioInscripto;
    int _idPlanInscripto;
    Fecha _fechaInicio;
    Fecha _fechaFin;
    bool _activo;
public:

    Inscripcion();

    Inscripcion(int idInscripcion,int idSocio, int idPlan, Fecha fechaInicio, Fecha fechaFin, bool activo);

    void setIdInscripcion(int idInscripcion);
    int getIdInscripcion();

    void setIdSocioInscripto(int idSocio);
    int getIdSocioInscripto();

    void setIdPlanInscripto(int idPlan);
    int getIdPlanInscripto();

    void setFechaInicio(Fecha fechaInicio);
    Fecha getFechaInicio();

    void setFechaFin(Fecha fechaFin);
    Fecha getFechaFin();

    void setActivo(bool activo);
    bool getActivo();
    //operador para comparar inscripciones
    bool operator == (Inscripcion Insc);

    void MostrarInscripcion();

};
