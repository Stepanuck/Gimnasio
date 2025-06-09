#include <iostream>
#include <cstdlib>
#include <cstring>
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
    mSocio.CargarOpciones("LISTAR SOCIOS");
    mSocio.CargarOpciones("BUSCAR SOCIO");
    mSocio.CargarOpciones("ELIMINAR SOCIO");
    mSocio.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        system("cls");
        mSocio.Mostrar();

        switch(mSocio.SeleccionarOpcion()){
        case 1:
            cin.ignore();
            mSoc.altaSocio();
            break;
        case 2:
            mSoc.modificarSocio();
            break;
        case 3:
            mSoc.listarTodosLosSocios();
            system("Pause");
           break;
        case 4:
            mSoc.buscarSocio();
            break;
        case 5:
            mSoc.eliminarLogicoSocio();
            break;
        case 0: return 0;
            break;
        }
    }

}
