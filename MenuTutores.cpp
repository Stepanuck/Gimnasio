#include <iostream>
#include <cstdlib>
#include <cstring>
#include "MenuTutores.h"
using namespace std;

int MenuTutores() {
    int opc;
    while(true){
        system("cls");
        cout << "-------------TUTORES-------------" << endl;
        cout << "1. CARGAR TUTOR" << endl;
        cout << "2. MODIFICAR TUTOR" << endl;
        cout << "3. LISTAR TUTORES" << endl;
        cout << "4. BUSCAR TUTOR" << endl;
        cout << "5. ELIMINAR TUTOR" << endl;
        cout << "0. REGRESAR AL MENU PRICIPAL" << endl;
        cout << "---------------------------------" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
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
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
    }
	return 0;
}
