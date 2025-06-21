#include <iostream>
#include <cstdlib>
#include <cstring>
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
        system("cls");
        mConfiguracion.Mostrar();

        switch(mConfiguracion.SeleccionarOpcion()){
        case 1:
            ManagerConfiguracion::backupCompleto();
            system("pause");
            break;
        case 2:
            ManagerConfiguracion::restoreCompleto();
            system("pause");
            break;
        case 0: return 0;
            break;
        }
    }

}
