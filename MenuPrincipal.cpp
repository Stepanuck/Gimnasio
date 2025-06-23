#include <iostream>
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
#include "Menu.h"
#include "MenuPrincipal.h"
#include "SubMenuSocios.h"
#include "SubMenuTutores.h"
#include "SubMenuActividades.h"
#include "SubMenuPlanes.h"
#include "SubMenuInscripciones.h"
#include "SubMenuCobros.h"
#include "SubMenuInformes.h"
#include "SubMenuConfiguraciones.h"

using namespace std;

MenuPrincipal::MenuPrincipal() : Menu() {}
MenuPrincipal::MenuPrincipal(string nombre) : Menu(nombre) {}

int MenuPrincipal::EjecutarMenuPrincipal() {
    SubMenuSocios SubMenuSocios;
    SubMenuTutores SubMenuTutores;
    SubMenuActividades SubMenuActividades;
    SubMenuPlanes SubMenuPlanes;
    SubMenuInscripciones SubMenuInscripciones;
    SubMenuCobros SubMenuCobros;
    SubMenuInformes SubMenuInformes;
    SubMenuConfiguraciones SubMenuConfiguraciones;

    MenuPrincipal menuGimnacio("SISTEMA GIMNASIO");
    menuGimnacio.CargarOpciones("MENU SOCIOS");
    menuGimnacio.CargarOpciones("MENU TUTORES");
    menuGimnacio.CargarOpciones("MENU ACTIVIDADES");
    menuGimnacio.CargarOpciones("MENU PLANES");
    menuGimnacio.CargarOpciones("MENU INSCRIPCIONES");
    menuGimnacio.CargarOpciones("MENU COBROS");
    menuGimnacio.CargarOpciones("INFORMES");
    menuGimnacio.CargarOpciones("CONFIGURACIONES");
    menuGimnacio.CargarOpciones("FIN DEL PROGRAMA");

    while(true) {

        rlutil::cls();

        menuGimnacio.Mostrar();

        switch(menuGimnacio.SeleccionarOpcion()) {
            case 1: SubMenuSocios.EjecutarSubMenuSocios();
                    break;
            case 2: SubMenuTutores.EjecutarSubMenuTutores();
                    break;
            case 3: SubMenuActividades.EjecutarSubMenuActividades();
                    break;
            case 4: SubMenuPlanes.EjecutarSubMenuPlanes();
                    break;
            case 5: SubMenuInscripciones.EjecutarSubMenuInscripciones();
                    break;
            case 6: SubMenuCobros.EjecutarSubMenuCobros();
                    break;
            case 7: SubMenuInformes.EjecutarSubMenuInformes();
                    break;
            case 8: SubMenuConfiguraciones.EjecutarSubMenuConfiguraciones();
                    break;
            case 0: return 0;
        }
    }
}
