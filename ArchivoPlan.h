#pragma once
#include "Plan.h"



class ArchivoPlan{

private:
  char _nombre[50];
public:
       // ArchivoPlan();
        ArchivoPlan(const char* nombreArchivo = "Plan.dat");
        Plan buscarPlan(int idPlan);
        int buscarPosicionPlan(int idPlan);
        int agregarRegistro(Plan pla);
        bool listarRegistros();
        Plan Leer(int pos);
        int getCantidadRegistros();
        int modificarPlan(Plan pla, int pos);
        bool bajaLogica(int idPlan);
        bool altaLogica(int idPlan);
};


