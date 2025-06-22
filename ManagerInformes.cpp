#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ManagerInformes.h"
#include "Actividad.h"
#include "ArchivoActividad.h"
#include "Socio.h"
#include "ArchivoSocio.h"
#include "Inscripcion.h"
#include "ArchivoInscripcion.h"
#include "Plan.h"
#include "ArchivoPlan.h"

using namespace std;

void ManagerInformes::InformarActividades(){

    Actividad act;
    ArchivoActividad actArchivo;
    Socio soc;
    ArchivoSocio socArchivo;
    Plan plan;
    ArchivoPlan planArchivo;
    Inscripcion insc;
    ArchivoInscripcion inscArchivo;


    int CantRegAct=actArchivo.getCantidadRegistros();
    int CantRegPlan=planArchivo.getCantidadRegistros();
    int CantRegInsc=inscArchivo.getCantidadRegistros();
    int CantRegSoc=socArchivo.getCantidadRegistros();

    for(int i=0; i<CantRegAct; i++){

        act=actArchivo.leer(i);

        if(act.getEstado()){

            bool band=false;
            act.MostrarActividad();

            cout << "Socios Inscriptos: "<< endl;

            for(int j=0; j<CantRegPlan; j++){

                plan=planArchivo.Leer(j);

                for(int k=0; k<5; k++){

                    if(act.getIdActividad()==plan.getIdActividadesIncluidas(k)){

                        for(int l=0; l<CantRegInsc; l++){

                            insc=inscArchivo.Leer(l);

                            if(insc.getIdPlanInscripto()==plan.getIdPlan()){

                                band=true;

                                soc=socArchivo.Leer(insc.getIdSocioInscripto()-1);

                                cout << " -ID " << insc.getIdSocioInscripto() << " " << soc.getNombres() << " " << soc.getApellidos() << endl;
                            }

                        }


                    }
                }
            }
            if(!band){
            cout<< "No hay socios Inscriptos" << endl;
            }

        }

    }
    system("pause");


}
