#include <iostream>
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
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
    mTutor.CargarOpciones("DAR DE ALTA NUEVAMENTE AL TUTOR");
    mTutor.CargarOpciones("ELIMINAR TUTOR");
    mTutor.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        rlutil::cls();
        mTutor.Mostrar();

        switch(mTutor.SeleccionarOpcion()){
        case 1:
            mTut.altaTutor();
            rlutil::anykey();
            break;
        case 2:
            mTut.modificarTutor();
            rlutil::anykey();
            break;
        case 3:
            mTut.listarTodosLosTutores();
            rlutil::anykey();
           break;
        case 4:
            mTut.listarTutoresInactivos();
            rlutil::anykey();
            break;
        case 5:
            mTut.listarTutoresActivos();
            rlutil::anykey();
            break;
        case 6:
            mTut.buscarTutor();
            rlutil::anykey();
            break;
        case 7:
            mTut.altaLogicoTutor();
            rlutil::anykey();
            break;
        case 8:
            mTut.eliminarLogicoTutor();
            rlutil::anykey();
            break;
        case 0: return 0;
            break;
        }
    }

}
