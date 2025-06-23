#include <iostream>
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
#include "Menu.h"
#include "SubMenuCobros.h"
#include "ManagerCobro.h"

using namespace std;

SubMenuCobros::SubMenuCobros() : Menu() {}

SubMenuCobros::SubMenuCobros(string nombre) : Menu(nombre) {}

int SubMenuCobros::EjecutarSubMenuCobros() {
    ManagerCobro managerCobro;
    SubMenuCobros mCobros("COBROS");

    mCobros.CargarOpciones("LISTAR TODOS LOS COBROS");
    mCobros.CargarOpciones("BUSCAR COBRO POR ID");
    mCobros.CargarOpciones("LISTAR COBROS POR SOCIO");
    mCobros.CargarOpciones("REGRESAR AL MENU ANTERIOR");

    while (true) {
        rlutil::cls();
        mCobros.Mostrar();

        switch (mCobros.SeleccionarOpcion()) {
            case 1:
                managerCobro.listarCobros();
                rlutil::anykey();
                break;
            case 2:
                managerCobro.buscarCobroPorID();
                rlutil::anykey();
                break;
            case 3:
                managerCobro.ListarCobrosPorSocio();
                rlutil::anykey();
                break;
            case 0: return 0;
        }
    }
}
