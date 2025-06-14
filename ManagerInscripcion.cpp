#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ManagerInscripcion.h"
#include "ArchivoInscripcion.h"

using namespace std;

void ManagerInscripcion::CargarInscripcion(){

    ArchivoInscripcion Archivo;
    Inscripcion Insc, InscGuardada;
    int idSocio;
    int idPlan;
    Fecha fechaDePago;
    bool pago;
    int cantReg=Archivo.getCantidadRegistros();

    int idInscripcion = 1; //por defecto el primero es 1

    if(cantReg>0){
        InscGuardada = Archivo.Leer(cantReg - 1); //leo el ultimo registro
        idInscripcion = InscGuardada.getIdInscripcion() + 1; // Sumo uno al ultimo registro
    }

    cout << "Ingresar ID del Socio a Inscribir: ";
    cin >> idSocio;

    cout << "Ingresar ID del Plan seleccionado: ";
    cin >> idPlan;

    fechaDePago.cargar();

    pago=true;

    Insc=Inscripcion(idInscripcion,idSocio, idPlan, fechaDePago, pago);

    bool existe=false;

    for(int i = 0; i < cantReg; i++){
        InscGuardada = Archivo.Leer(i);
        if(Insc == InscGuardada){
            existe = true;
            break;
        }
    }

    if(!existe){


        if(Archivo.agregarRegistro(Insc)!=-1){

            cout << "El registro se guardo correctamente" << endl;

        }
        else{

            cout << "No se pudo guardar" << endl;
        }
    }
    else{

        cout << "Inscripcion existente" << endl;

    }
    system("pause");



}
//void ManagerInscripcion::ListarInscripciones();
//void ManagerInscripcion::ModificarInscripcion();
//void ManagerInscripcion::BuscarInscripcion();
