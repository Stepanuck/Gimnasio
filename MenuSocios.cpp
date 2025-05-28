#include <iostream>
#include <cstdlib>
#include <cstring>
#include "MenuSocios.h"

using namespace std;

int MenuSocios() {
    int opc;
    while(true){
        system("cls");
        cout << "-------------SOCIOS-------------" << endl;
        cout << "1. CARGAR SOCIO" << endl;
        cout << "2. MODIFICAR SOCIO" << endl;
        cout << "3. LISTAR SOCIOS" << endl;
        cout << "4. BUSCAR SOCIO" << endl;
        cout << "5. ELIMINAR SOCIO" << endl;
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
