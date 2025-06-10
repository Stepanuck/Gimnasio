#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Menu.h"

using namespace std;

Menu::Menu(){

}
Menu::Menu(string nombre){

    _nombre=nombre;
    _numOpcion=0;

}
void Menu::CargarOpciones(string opcionMenu){

    if(_numOpcion<10){

        _opcionesMenu[_numOpcion]= opcionMenu;

        _numOpcion++;
    }

}
void Menu::Mostrar(){

    cout << "-------------"<<_nombre<<"-------------" << endl;

    for(int i=0; i<_numOpcion; i++){

        if(i!=(_numOpcion-1)){

            cout << i+1 << "." << _opcionesMenu[i] << endl;

        }
        else{

            cout << i-i << "." << _opcionesMenu[i] << endl;
        }
    }

    cout << "---------------------------------" << endl;
}
int Menu::SeleccionarOpcion(){

    int opc;

    cout << "SELECCIONAR OPCION " << endl;
    cin>>opc;

    if(opc>=0 && opc <_numOpcion){

        return opc;

    }
    else {

        cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        system("pause");

    }
}
