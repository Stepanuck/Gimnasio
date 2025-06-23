#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits>
#include "Menu.h"
#include "rlutil.h"

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

    cout << "---------------------------------------" << endl;
    cout << "           "<<_nombre<<"           " << endl;
    cout << "---------------------------------------" << endl;


    for(int i=0; i<_numOpcion; i++){

        if(i!=(_numOpcion-1)){

            cout << i+1 << "." << _opcionesMenu[i] << endl;

        }
        else{

            cout << i-i << "." << _opcionesMenu[i] << endl;
        }
    }

    cout << "---------------------------------------" << endl;
}
int Menu::SeleccionarOpcion(){

    int opc;

    while(true){

        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;

        if(cin.fail()){///cin.fail se usa para identificar si lo ingresado no es un numero.
            cin.clear();///cin clear limpia el error.
            cin.ignore(numeric_limits<streamsize>::max(),'\n');///Descarta todo el contenido para dejar la variable sin basura.

            rlutil::setColor(rlutil::RED);
            cout << "INGRESO INVALIDO, DEBE INGRESAR UN NUMERO" <<endl;
            rlutil::setColor(rlutil::BLACK);

            rlutil::anykey();


            continue;///Salta al  siguiente ciclo del bucle, omitiendo el resto del codigo,
            ///regresando al inicio para sollicitar un nuevo ingreso y lo evalua.
        }
        if(opc>=0 && opc <_numOpcion){

            return opc;

        }
        else {
            rlutil::setColor(rlutil::RED);
            cout<<"LA SELECCION NO ES CORRECTA, INTENTELO NUEVAMENTE"<<endl;
            rlutil::setColor(rlutil::BLACK);

            rlutil::anykey();

        }
    }
}
