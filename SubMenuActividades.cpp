#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"
#include "SubMenuActividades.h"
#include "ManagerActividad.h"

using namespace std;

SubMenuActividades::SubMenuActividades()
: Menu(){
}
SubMenuActividades::SubMenuActividades(string nombre)
: Menu(nombre){

}
int SubMenuActividades::EjecutarSubMenuActividades(){
    ManagerActividad ManagerAct;

    SubMenuActividades mActividad("ACTIVIDADES");

    mActividad.CargarOpciones("CARGAR ACTIVIDAD");
    mActividad.CargarOpciones("MODIFICAR ACTIVIDAD");
    mActividad.CargarOpciones("LISTAR ACTIVIDADES ACTIVAS");
    mActividad.CargarOpciones("LISTAR ACTIVIDADES TODAS");
    mActividad.CargarOpciones("BUSCAR ACTIVIDAD");
    mActividad.CargarOpciones("DAR DE ALTA NUEVAMENTE UNA ACTIVIDAD");
    mActividad.CargarOpciones("ELIMINAR ACTIVIDAD");
    mActividad.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        system("cls");
        mActividad.Mostrar();

        switch(mActividad.SeleccionarOpcion()){
        case 1:ManagerAct.CargarActividad();
            break;
        case 2:ManagerAct.ModificarActividad();
            break;
        case 3:ManagerAct.ListarActividadesaActivas();
           break;
        case 4:ManagerAct.ListarTodas();
            break;
        case 5:ManagerAct.BuscarActividad();
            break;
        case 6:
            ManagerAct.altaLogica();
            break;
        case 7:ManagerAct.EliminarActividad();
            break;
        case 0: return 0;
            break;
        }
    }

}
