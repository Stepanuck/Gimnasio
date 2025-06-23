#include <iostream>
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
#include "Menu.h"
#include "SubMenuPlanes.h"
#include "ManagerPlan.h"

using namespace std;

SubMenuPlanes::SubMenuPlanes()
: Menu(){
}
SubMenuPlanes::SubMenuPlanes(string nombre)
: Menu(nombre){

}
int SubMenuPlanes::EjecutarSubMenuPlanes(){
    ManagerPlan managerPlan;

    SubMenuPlanes mPlan("PLANES");

    mPlan.CargarOpciones("CARGAR PLAN");
    mPlan.CargarOpciones("MODIFICAR PLAN");
    mPlan.CargarOpciones("LISTAR PLANES ACTIVOS");
    mPlan.CargarOpciones("LISTAR TODOS LOS PLANES");
    mPlan.CargarOpciones("BUSCAR PLAN");
    mPlan.CargarOpciones("DAR DE ALTA NUEVAMENTE UN PLAN");
    mPlan.CargarOpciones("ELIMINAR PLAN");
    mPlan.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        rlutil::cls();
        mPlan.Mostrar();

        switch(mPlan.SeleccionarOpcion()){
        case 1:managerPlan.CargarPlan();
            break;
        case 2:managerPlan.ModificarPlan();
            break;
        case 3:managerPlan.ListarPlanesActivos();
           break;
        case 4:managerPlan.ListarPlanes();
           break;
        case 5:managerPlan.BuscarPlan();
            break;
        case 6:managerPlan.altaLogicaPlan();
            break;
        case 7:managerPlan.EliminarPlan();
            break;
        case 0: return 0;
            break;
        }
    }

}
