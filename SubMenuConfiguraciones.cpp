#include <iostream>
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
#include "Menu.h"
#include "SubMenuConfiguraciones.h"
#include "ManagerConfiguracion.h"

using namespace std;

SubMenuConfiguraciones::SubMenuConfiguraciones()
: Menu(){
}
SubMenuConfiguraciones::SubMenuConfiguraciones(string nombre)
: Menu(nombre){

}
int SubMenuConfiguraciones::EjecutarSubMenuConfiguraciones(){

    SubMenuConfiguraciones mConfiguracion("CONFIGURACIONES");

    mConfiguracion.CargarOpciones("COPIA DE SEGURIDAD COMPLETA");
    mConfiguracion.CargarOpciones("RESTAURAR COPIA COMPLETA");
    mConfiguracion.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        rlutil::cls();
        mConfiguracion.Mostrar();

        switch(mConfiguracion.SeleccionarOpcion()){
        case 1:
            ManagerConfiguracion::backupCompleto();
            rlutil::anykey();
            break;
        case 2:
            ManagerConfiguracion::restoreCompleto();
            rlutil::anykey();
            break;
        case 0: return 0;
            break;
        }
    }

}
