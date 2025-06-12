#include <iostream>
#include <cstdlib>
#include <cstring>
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
    mPlan.CargarOpciones("LISTAR PLANES");
    mPlan.CargarOpciones("BUSCAR PLAN");
    mPlan.CargarOpciones("ELIMINAR PLAN");
    mPlan.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        system("cls");
        mPlan.Mostrar();

        switch(mPlan.SeleccionarOpcion()){
        case 1:managerPlan.CargarPlan();
            break;
        case 2:managerPlan.ModificarPlan();
            break;
        case 3:managerPlan.ListarPlanes();
           break;
        case 4:managerPlan.BuscarPlan();
            break;
        case 5:managerPlan.EliminarPlan();
            break;
        case 0: return 0;
            break;
        }
    }

}
