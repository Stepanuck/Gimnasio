#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"
#include "ManagerTutor.h"
#include "SubMenuTutores.h"
using namespace std;

SubMenuTutores::SubMenuTutores()
: Menu(){
}
SubMenuTutores::SubMenuTutores(string nombre)
: Menu(nombre){

}
int SubMenuTutores::EjecutarSubMenuTutores(){
    ManagerTutor mTut;
    SubMenuTutores mTutor("TUTORES");

    mTutor.CargarOpciones("CARGAR TUTOR");
    mTutor.CargarOpciones("MODIFICAR TUTOR");
    mTutor.CargarOpciones("LISTAR TODOS LOS TUTORES");
    mTutor.CargarOpciones("LISTAR TUTORES INACTIVOS");
    mTutor.CargarOpciones("LISTAR TUTORES ACTIVOS");
    mTutor.CargarOpciones("BUSCAR TUTOR");
    mTutor.CargarOpciones("ELIMINAR TUTOR");
    mTutor.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        system("cls");
        mTutor.Mostrar();

        switch(mTutor.SeleccionarOpcion()){
        case 1:
            mTut.altaTutor();
            system("Pause");
            break;
        case 2:
            mTut.modificarTutor();
            system("Pause");
            break;
        case 3:
            mTut.listarTodosLosTutores();
            system("Pause");
           break;
        case 4:
            mTut.listarTutoresInactivos();
            system("Pause");
            break;
        case 5:
            mTut.listarTutoresActivos();
            system("Pause");
            break;
        case 6:
            mTut.buscarTutor();
            system("Pause");
            break;
        case 7:
            mTut.eliminarLogicoTutor();
            system("Pause");
            break;
        case 0: return 0;
            break;
        }
    }

}
