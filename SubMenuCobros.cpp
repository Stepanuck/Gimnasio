#include <iostream>
#include <cstdlib>
#include <cstring>
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
        system("cls");
        mCobros.Mostrar();

        switch (mCobros.SeleccionarOpcion()) {
            case 1:
                managerCobro.listarCobros();
                system("pause");
                break;
            case 2:
                managerCobro.buscarCobroPorID();
                system("pause");
                break;
            case 3:
                managerCobro.ListarCobrosPorSocio();
                system("pause");
                break;
            case 0: return 0;
        }
    }
}
