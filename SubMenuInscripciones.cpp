#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"
#include "SubMenuInscripciones.h"
#include "ManagerInscripcion.h"

using namespace std;

SubMenuInscripciones::SubMenuInscripciones()
: Menu(){
}
SubMenuInscripciones::SubMenuInscripciones(string nombre)
: Menu(nombre){

}
int SubMenuInscripciones::EjecutarSubMenuInscripciones(){
    ManagerInscripcion ManagerInsc;

    SubMenuInscripciones mInscripcion("INSCRIPCIONES");

    mInscripcion.CargarOpciones("CARGAR INSCRIPCION");
    mInscripcion.CargarOpciones("MODIFICAR INSCRIPCION");
    mInscripcion.CargarOpciones("LISTAR INSCRIPCIONES");
    mInscripcion.CargarOpciones("BUSCAR INSCRIPCION");
    mInscripcion.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        system("cls");
        mInscripcion.Mostrar();

        switch(mInscripcion.SeleccionarOpcion()){
        case 1:ManagerInsc.CargarInscripcion();
        break;
        case 2:ManagerInsc.ModificarInscripcion();
            break;
        case 3:
           break;
        case 4:
            break;
        case 0: return 0;
            break;
        }
    }

}
