#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ManagerActividad.h"
#include "Actividad.h"
#include "Horario.h"
#include "ArchivoActividad.h"

using namespace std;

void ManagerActividad::CargarActividad(){

    ArchivoActividad Archivo;
    Actividad Act, ActGuardada;
    char nombre[20];
    char diaDeLaSemana[10];
    int cuposDisponibles;
    Horario horarioActividad;
    int idTutorACargo;
    bool estado;

    cin.ignore();
    cout << "Ingresar nombre de la actividad: ";
    cin.getline(nombre,20);

    cout << "Ingresar dia de semana: ";
    cin.getline(diaDeLaSemana,10);

    horarioActividad.cargar();

    cout << "Ingresar Cupos Disponibles: ";
    cin >> cuposDisponibles;

    cout << "Ingresar el ID del Tutor a cargo: ";
    cin >> idTutorACargo;

    estado=true;

    Act=Actividad(nombre, diaDeLaSemana,cuposDisponibles,horarioActividad,idTutorACargo,estado);

    cout << "ID: " << Act.getIdActividad()+1 << endl;
        cout << "Actividad: " << Act.getNombre() << endl;
        cout << Act.getDiaDeLaSemana() << endl;
        Act.getHorarioActividad().mostrar();
        cout << "Cupos: " << Act.getCuposDisponibles() << endl;
        cout << "Tutor a Cargo: "<< Act.getIdTutorACargo() << endl;

    int cantReg=Archivo.getCantidadRegistros();

    bool existe=false;
    int idGuardado;

    for(int i=0; i<cantReg; i++){

        ActGuardada=Archivo.leer(i);

        if(Act==ActGuardada){

           existe=true;

        }

    }
    if(!existe){


        if(Archivo.agregarRegistro(Act)!=-1){

            idGuardado=Act.getIdActividad();
            Act.GuardarUltimoId(idGuardado);

            cout << "El registro se guardo correctamente" << endl;

        }
        else{

            cout << "No se pudo guardar" << endl;
        }
    }
    else{

        cout << "Actividad existente en ese Dia y Horario" << endl;

    }
    system("pause");


}
void ManagerActividad::ListarActividades(){
    Actividad Act;
    ArchivoActividad Archivo;
    int cantidadRegistros=Archivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){

        Act=Archivo.leer(i);

        if(Act.getEstado()){
        cout << "ID: " << Act.getIdActividad()+1 << endl;
        cout << "Actividad: " << Act.getNombre() << endl;
        cout << Act.getDiaDeLaSemana() << endl;
        Act.getHorarioActividad().mostrar();
        cout << "Cupos: " << Act.getCuposDisponibles() << endl;
        cout << "Tutor a Cargo: "<< Act.getIdTutorACargo() << endl;
        }
    }
    system("pause");

}
    void ModificarActividad();
    void EliminarActividad();
    void BuscarActividad();
