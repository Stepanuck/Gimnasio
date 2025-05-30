#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"
#include "SubMenuPlanes.h"

using namespace std;

SubMenuPlanes::SubMenuPlanes()
: Menu(){
}
SubMenuPlanes::SubMenuPlanes(string nombre)
: Menu(nombre){

}
int SubMenuPlanes::EjecutarSubMenuPlanes(){

    SubMenuPlanes mPlan("PLANES");

    mPlan.CargarOpciones("CARGAR PLAN");
    mPlan.CargarOpciones("MODIFICAR PLAN");
    mPlan.CargarOpciones("LISTAR PLANES");
    mPlan.CargarOpciones("BUSCAR PLAN");
    mPlan.CargarOpciones("ELIMINAR PLAN");
    mPlan.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        system("cls");
        mPlan.Mostrar();

        switch(mPlan.SeleccionarOpcion()){
        case 1:
            break;
        case 2:
            break;
        case 3:
           break;
        case 4:
            break;
        case 5:
            break;
        case 0: return 0;
            break;
        }
    }

}
