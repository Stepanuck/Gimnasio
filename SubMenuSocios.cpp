#include <iostream>
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
#include "Menu.h"
#include "SubMenuSocios.h"
#include "ManagerSocio.h"

using namespace std;

SubMenuSocios::SubMenuSocios()
: Menu(){
}
SubMenuSocios::SubMenuSocios(string nombre)
: Menu(nombre){

}

int SubMenuSocios::EjecutarSubMenuSocios(){
    ManagerSocio mSoc;
    SubMenuSocios mSocio("SOCIOS");

    mSocio.CargarOpciones("CARGAR SOCIO");
    mSocio.CargarOpciones("MODIFICAR SOCIO");
    mSocio.CargarOpciones("LISTAR TODOS LOS SOCIOS");
    mSocio.CargarOpciones("LISTAR SOCIOS INACTIVOS");
    mSocio.CargarOpciones("LISTAR SOCIOS ACTIVOS");
    mSocio.CargarOpciones("BUSCAR SOCIO");
    mSocio.CargarOpciones("DAR DE ALTA NUEVAMENTE AL SOCIO");
    mSocio.CargarOpciones("ELIMINAR SOCIO");
    mSocio.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        rlutil::cls();
        mSocio.Mostrar();

        switch(mSocio.SeleccionarOpcion()){
        case 1:
            cin.ignore();
            mSoc.altaSocio();
            rlutil::anykey();
            break;
        case 2:
            mSoc.modificarSocio();
            rlutil::anykey();
            break;
        case 3:
            mSoc.listarTodosLosSocios();
            rlutil::anykey();
           break;
        case 4:
            mSoc.listarSociosInactivos();
            rlutil::anykey();
            break;
        case 5:
            mSoc.listarSociosActivos();
            rlutil::anykey();
            break;
        case 6:
            mSoc.buscarSocio();
            rlutil::anykey();
            break;
        case 7:
            mSoc.altaLogicoSocio();
            rlutil::anykey();
            break;
        case 8:
            mSoc.eliminarLogicoSocio();
            rlutil::anykey();
            break;
        case 0: return 0;
            break;
        }
    }

}
