#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ManagerActividad.h"
#include "Actividad.h"
#include "Horario.h"
#include "ArchivoActividad.h"
#include "Menu.h"

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

    int cantReg=Archivo.getCantidadRegistros();
    bool existe=false;

    if (cantReg>0){
    for(int i=0; i<cantReg; i++){

        ActGuardada=Archivo.leer(i);

        if(Act==ActGuardada){

           existe=true;

        }

    }
    }
    if(!existe){


        if(Archivo.agregarRegistro(Act)!=-1){

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
void ManagerActividad::ModificarActividad(){
    Menu submenu("MODIFICAR ACTIVIDAD");

    submenu.CargarOpciones("NOMBRE");
    submenu.CargarOpciones("DIA DE LA SEMANA");
    submenu.CargarOpciones("HORARIO");
    submenu.CargarOpciones("CUPOS");
    submenu.CargarOpciones("TUTOR A CARGO");
    submenu.CargarOpciones("REGRESAR");
    bool band=false;
    do{
        system("cls");
        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()){
        case 1:{
            int id, posicion;
            char nombre[20];
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarActividad(id-1);

            if(posicion>=0){

               Act=Archivo.leer(posicion);

               cout << "Ingresar nuevo nombre: ";
               cin.getline(nombre,20);

               Act.setNombre(nombre);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    ActGuardada=Archivo.leer(i);

                    if(Act==ActGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarActividad(Act,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Actividad existente en ese Dia y Horario" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Actividad buscada." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");
            break;
        }
        case 2:{
            int id, posicion;
            char diaDeLaSemana[10];
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarActividad(id-1);

            if(posicion>=0){

               Act=Archivo.leer(posicion);

               cout << "Ingresar nuevo Dia de Semana: ";
               cin.getline(diaDeLaSemana,10);

               Act.setDiaDeLaSemana(diaDeLaSemana);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    ActGuardada=Archivo.leer(i);

                    if(Act==ActGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarActividad(Act,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Actividad existente en ese Dia y Horario" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Actividad buscada." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");
            break;
        }
        case 3:{
            int id, posicion;
            Horario horarioActividad;
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarActividad(id-1);

            if(posicion>=0){

               Act=Archivo.leer(posicion);

               cout << "Ingresar nuevo Horario: ";
               horarioActividad.cargar();

               Act.setHorarioActividad(horarioActividad);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    ActGuardada=Archivo.leer(i);

                    if(Act==ActGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarActividad(Act,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Actividad existente en ese Dia y Horario" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Actividad buscada." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");
            break;
        }
        case 4:{
            int id, posicion;
            int cuposDisponibles;
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;


            posicion=Archivo.buscarActividad(id-1);

            if(posicion>=0){

               Act=Archivo.leer(posicion);

               cout << "Ingresar nueva cantidad de cupos: ";
               cin >> cuposDisponibles;

               Act.setCuposDisponibles(cuposDisponibles);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    ActGuardada=Archivo.leer(i);

                    if(Act==ActGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarActividad(Act,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Actividad existente en ese Dia y Horario" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Actividad buscada." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");
            break;
        }
        case 5:{
            int id, posicion;
            int idTutorACargo;
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;


            posicion=Archivo.buscarActividad(id-1);

            if(posicion>=0){

               Act=Archivo.leer(posicion);

               cout << "Ingresar nuevo ID Tutor: ";
               cin >> idTutorACargo;

               Act.setIdTutorACargo(idTutorACargo);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    ActGuardada=Archivo.leer(i);

                    if(Act==ActGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarActividad(Act,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Actividad existente en ese Dia y Horario" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Actividad buscada." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");
            break;
        }
        case 0: band=true;
            break;
        }
    }while(!band);



}
void ManagerActividad::EliminarActividad(){
            int id, posicion;
            bool estado;
            ArchivoActividad Archivo;
            Actividad Act;

            cout << "Ingresar ID de la Actividad a Eliminar: ";
            cin >> id;


            posicion=Archivo.buscarActividad(id-1);

            if(posicion>=0){

                Act=Archivo.leer(posicion);

                estado=false;

                Act.setEstado(estado);


                if(Archivo.modificarActividad(Act,posicion)!=-1){

                    cout << "El registro se Elimino correctamente" << endl;

                }
                else{

                    cout << "No se pudo Eliminar" << endl;
                }
            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Actividad a Eliminar." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");




}
void BuscarActividad();
