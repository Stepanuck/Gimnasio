#include <iostream>
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
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
    mInscripcion.CargarOpciones("LISTAR INSCRIPCIONES ACTIVAS");
    mInscripcion.CargarOpciones("LISTAR TODAS INSCRIPCIONES");
    mInscripcion.CargarOpciones("BUSCAR INSCRIPCION");
    mInscripcion.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        rlutil::cls();
        mInscripcion.Mostrar();

        switch(mInscripcion.SeleccionarOpcion()){
        case 1:ManagerInsc.CargarInscripcion();
        break;
        case 2:ManagerInsc.ModificarInscripcion();
            break;
        case 3:ManagerInsc.ListarInscripcionesActivas();
           break;
        case 4:ManagerInsc.ListarInscripciones();
            break;
        case 5:ManagerInsc.BuscarInscripcion();
            break;
        case 0: return 0;
            break;
        }
    }

}
