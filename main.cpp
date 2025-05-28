#include <iostream>
#include "Fecha.h"
#include "Persona.h"
#include "Tutor.h"
#include "Actividad.h"
#include "MenuSocios.h"
#include "MenuTutores.h"
using namespace std;

int main()
{
    //Fecha obj;
    //obj.cargar();
    //obj.mostrar();

    int opc;
    while(true){
        system("cls");
        cout << "---------SISTEMA GIMNASIO--------" << endl;
        cout << "1. MENU SOCIOS" << endl;
        cout << "2. MENU TUTORES" << endl;
        cout << "3. MENU ACTIVIDADES" << endl;
        cout << "4. MENU PLANES" << endl;
        cout << "5. MENU INSCRIPCIONES" << endl;
        cout << "6. INFORMES" << endl;
        cout << "7. CONFIGURACIONES" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "---------------------------------" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: MenuSocios();
                    break;
            case 2: MenuTutores();
                    break;
            case 3:
                    break;
            case 4:
                    break;
            case 5:
                    break;
            case 6:
                    break;
            case 7:
                    break;
            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }

    }






    return 0;
}
