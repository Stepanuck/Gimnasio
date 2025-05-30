#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"
#include "SubMenuSocios.h"

using namespace std;

SubMenuSocios::SubMenuSocios()
: Menu(){
}
SubMenuSocios::SubMenuSocios(string nombre)
: Menu(nombre){

}

int SubMenuSocios::EjecutarSubMenuSocios(){

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
