#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"
#include "SubMenuInformes.h"
#include "ManagerInformes.h"

using namespace std;

SubMenuInformes::SubMenuInformes()
: Menu(){
}
SubMenuInformes::SubMenuInformes(string nombre)
: Menu(nombre){

}
int SubMenuInformes::EjecutarSubMenuInformes(){
    ManagerInformes mInfo;

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
        case 1:mInfo.ListarCobros();
            break;
        case 2:mInfo.ListarDeudores();
            break;
        case 3:mInfo.InformarActividades();
           break;
        case 4:mInfo.DetallesCuposEnActividades();
            break;
        case 0: return 0;
            break;
        }
    }

}
