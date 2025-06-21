#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"
#include "SubMenuInformes.h"
#include "ManagerSocio.h"
#include "ManagerCobro.h"
#include "ManagerActividad.h"
using namespace std;

SubMenuInformes::SubMenuInformes()
: Menu(){
}
SubMenuInformes::SubMenuInformes(string nombre)
: Menu(nombre){

}
int SubMenuInformes::EjecutarSubMenuInformes(){
    ManagerSocio mSoc;
    ManagerCobro mCob;
    ManagerActividad mAct;
    SubMenuInformes mInforme("INFORMES");

    mInforme.CargarOpciones("DETALLE DE COBROS");
    mInforme.CargarOpciones("DETALLE DE DEUDORES");
    mInforme.CargarOpciones("DETALLE DE ACTIVIDADES");
    mInforme.CargarOpciones("DETALLE DE CUPOS EN ACTIVIDADES");
    mInforme.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        system("cls");
        mInforme.Mostrar();

        switch(mInforme.SeleccionarOpcion()){
        case 1:
            mCob.listarCobros();
            system ("Pause");
            break;
        case 2:
            mSoc.listarDeudores();
            break;
        case 3:
            mAct.ListarTodas();
           break;
        case 4:
            mAct.detallesCuposEnActividades();
            break;
        case 0: return 0;
            break;
        }
    }

}
