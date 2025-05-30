#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"
#include "SubMenuTutores.h"
using namespace std;

SubMenuTutores::SubMenuTutores()
: Menu(){
}
SubMenuTutores::SubMenuTutores(string nombre)
: Menu(nombre){

}
int SubMenuTutores::EjecutarSubMenuTutores(){

    SubMenuTutores mTutor("TUTORES");

    mTutor.CargarOpciones("CARGAR TUTOR");
    mTutor.CargarOpciones("MODIFICAR TUTOR");
    mTutor.CargarOpciones("LISTAR TUTORES");
    mTutor.CargarOpciones("BUSCAR TUTOR");
    mTutor.CargarOpciones("ELIMINAR TUTOR");
    mTutor.CargarOpciones("REGRESAR AL MENU PRINCIPAL");

    while(true){
        system("cls");
        mTutor.Mostrar();

        switch(mTutor.SeleccionarOpcion()){
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
