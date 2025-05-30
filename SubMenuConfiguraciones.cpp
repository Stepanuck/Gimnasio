#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"
#include "SubMenuConfiguraciones.h"

using namespace std;

SubMenuConfiguraciones::SubMenuConfiguraciones()
: Menu(){
}
SubMenuConfiguraciones::SubMenuConfiguraciones(string nombre)
: Menu(nombre){

}
int SubMenuConfiguraciones::EjecutarSubMenuConfiguraciones(){

    SubMenuConfiguraciones mConfiguracion("CONFIGURACIONES");

    mConfiguracion.CargarOpciones("COPIA DE SEGURIDAD");
    mConfiguracion.CargarOpciones("RESTAURAR COPIA DE SEGURIDAD");
    mConfiguracion.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        system("cls");
        mConfiguracion.Mostrar();

        switch(mConfiguracion.SeleccionarOpcion()){
        case 1:
            break;
        case 2:
            break;
        case 0: return 0;
            break;
        }
    }

}
