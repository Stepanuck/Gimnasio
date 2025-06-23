#include <iostream>
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
#include "ManagerActividad.h"
#include "Actividad.h"
#include "Horario.h"
#include "ArchivoActividad.h"
#include "ArchivoInscripcion.h"
#include "ArchivoPlan.h"
#include "Menu.h"
#include "ArchivoTutor.h"


using namespace std;

void ManagerActividad::CargarActividad(){
    rlutil::cls();
    ArchivoActividad Archivo;
    Actividad Act, ActGuardada;
    int idActividad;
    char nombre[20];
    char diaDeLaSemana[10];
    int cuposDisponibles;
    Horario horarioActividad;
    int idTutorACargo;
    bool estado;
    int cantReg=Archivo.getCantidadRegistros();
    cout << "---------------------------------------" << endl;
    cout << "            ALTA ACTIVIDAD             " << endl;
    cout << "---------------------------------------" << endl;

    if(cantReg>0){

        idActividad=Archivo.leer(cantReg-1).getIdActividad()+1;
    }
    else{
        idActividad=1;
    }
    cin.ignore();
    cout << "Ingresar nombre de la actividad: ";
    cin.getline(nombre,20);

    cout << "Ingresar dia de semana: ";
    cin.getline(diaDeLaSemana,10);

    horarioActividad.cargar();

    cout << "Ingresar Cupos Disponibles: ";
    cin >> cuposDisponibles;

    ArchivoTutor tutorArchivo;
    while(true){

        cout << "Ingresar el ID del Tutor a cargo: ";
        cin >> idTutorACargo;

        if(tutorArchivo.buscarTutor(idTutorACargo)!=-1){

            break;
        }
        else{

            cout << "El Tutor Ingresado no Existe" << endl;
            continue;
        }

    }
    estado=true;

    Act=Actividad(idActividad,nombre, diaDeLaSemana,cuposDisponibles,horarioActividad,idTutorACargo,estado);

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
    rlutil::anykey();


}
void ManagerActividad::ListarActividadesaActivas(){
    rlutil::cls();
    Actividad Act;
    ArchivoActividad Archivo;
    cout << "---------------------------------------" << endl;
    cout << "       LISTAR ACTIVIDADES ACTIVAS      " << endl;
    cout << "---------------------------------------" << endl;

    int cantidadRegistros=Archivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){

        Act=Archivo.leer(i);

        if(Act.getEstado()){

            Act.MostrarActividad();

        }
    }
    rlutil::anykey();

}
void ManagerActividad::ListarTodas(){
    rlutil::cls();
    Actividad Act;
    ArchivoActividad Archivo;
    int cantidadRegistros=Archivo.getCantidadRegistros();
    cout << "---------------------------------------" << endl;
    cout << "       LISTAR TODAS LAS ACTIVIDADES     " << endl;
    cout << "---------------------------------------" << endl;

    for(int i=0; i<cantidadRegistros; i++){

        Act=Archivo.leer(i);

        Act.MostrarActividad();


    }
    rlutil::anykey();

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
        rlutil::cls();
        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()){
        case 1:{
            rlutil::cls();
            int id, posicion;
            char nombre[20];
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;
            cout << "---------------------------------------" << endl;
            cout << "           MODIFICAR ACTIVIDAD         " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarActividad(id);

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
            rlutil::anykey();
            break;
        }
        case 2:{
            rlutil::cls();
            int id, posicion;
            char diaDeLaSemana[10];
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;
            cout << "---------------------------------------" << endl;
            cout << "           MODIFICAR ACTIVIDAD         " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarActividad(id);

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
            rlutil::anykey();
            break;
        }
        case 3:{
            rlutil::cls();
            int id, posicion;
            Horario horarioActividad;
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;
            cout << "---------------------------------------" << endl;
            cout << "           MODIFICAR ACTIVIDAD         " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarActividad(id);

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
            rlutil::anykey();
            break;
        }
        case 4:{
            rlutil::cls();
            int id, posicion;
            int cuposDisponibles;
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;
            cout << "---------------------------------------" << endl;
            cout << "           MODIFICAR ACTIVIDAD         " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;


            posicion=Archivo.buscarActividad(id);

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
            rlutil::anykey();
            break;
        }
        case 5:{
            rlutil::cls();
            int id, posicion;
            int idTutorACargo;
            ArchivoActividad Archivo;
            Actividad Act, ActGuardada;
            cout << "---------------------------------------" << endl;
            cout << "           MODIFICAR ACTIVIDAD         " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID de la Actividad a modificar: ";
            cin >> id;


            posicion=Archivo.buscarActividad(id);


            if(posicion>=0){

               Act=Archivo.leer(posicion);

                ArchivoTutor tutorArchivo;
                while(true){

                    cout << "Ingresar el ID del Tutor a cargo: ";
                    cin >> idTutorACargo;

                    if(tutorArchivo.buscarTutor(idTutorACargo)!=-1){

                        break;
                    }
                    else{

                        cout << "El Tutor Ingresado no Existe" << endl;
                        continue;
                    }

                }
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
            rlutil::anykey();
            break;
        }
        case 0: band=true;
            break;
        }
    }while(!band);



}
void ManagerActividad::EliminarActividad(){
            rlutil::cls();
            int id, posicion;
            bool estado;
            ArchivoActividad Archivo;
            Actividad Act;
            cout << "---------------------------------------" << endl;
            cout << "           ELIMINAR ACTIVIDAD          " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID de la Actividad a Eliminar: ";
            cin >> id;


            posicion=Archivo.buscarActividad(id);

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
            rlutil::anykey();

}
void ManagerActividad::altaLogica(){
            rlutil::cls();
            int id, posicion;
            bool estado;
            ArchivoActividad Archivo;
            Actividad Act;
            cout << "---------------------------------------" << endl;
            cout << "  DAR DE ALTA NUEVAMENTE UNA ACTIVIDAD " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID de la Actividad a dar alta: ";
            cin >> id;


            posicion=Archivo.buscarActividad(id);

            if(posicion>=0){

                Act=Archivo.leer(posicion);

                estado=true;

                Act.setEstado(estado);


                if(Archivo.modificarActividad(Act,posicion)!=-1){

                    cout << "El registro se dio de alta correctamene" << endl;

                }
                else{

                    cout << "No se pudo dar de alta" << endl;
                }
            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Actividad a dar de alta." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            rlutil::anykey();

}
void ManagerActividad::BuscarActividad(){
    Menu submenu("BUSCAR ACTIVIDAD");

    submenu.CargarOpciones("POR ID");
    submenu.CargarOpciones("POR NOMBRE");
    submenu.CargarOpciones("POR DIA");
    submenu.CargarOpciones("REGRESAR");
    bool band=false;
    do{
        rlutil::cls();
        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()){
        case 1:{
            rlutil::cls();
            int id, posicion;
            ArchivoActividad Archivo;
            Actividad Act;
            cout << "---------------------------------------" << endl;
            cout << "            BUSCAR ACTIVIDAD           " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID Actividad a buscar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarActividad(id);

            Act=Archivo.leer(posicion);

            Act.MostrarActividad();

            rlutil::anykey();

            break;
        }
        case 2:{
            rlutil::cls();
            char nombre[20];
            ArchivoActividad Archivo;
            Actividad Act;
            int cantReg=Archivo.getCantidadRegistros();
            bool band=false;
            cout << "---------------------------------------" << endl;
            cout << "            BUSCAR ACTIVIDAD           " << endl;
            cout << "---------------------------------------" << endl;

            cin.ignore();
            cout << "Ingresar Nombre Actividad a buscar: ";
            cin.getline(nombre,20);

            for(int i=0; i<cantReg; i++){

                Act=Archivo.leer(i);

                if(strcmp(nombre,Act.getNombre())==0){

                    Act.MostrarActividad();
                    band=true;
                }

            }
            if(!band){
                cout << "No se encontraron Actividades con ese nombre." << endl;
            }
            rlutil::anykey();
            break;
        }
        case 3:{
            rlutil::cls();
            char diaDeLaSemana[10];
            ArchivoActividad Archivo;
            Actividad Act;
            int cantReg=Archivo.getCantidadRegistros();
            bool band=false;
            cout << "---------------------------------------" << endl;
            cout << "            BUSCAR ACTIVIDAD           " << endl;
            cout << "---------------------------------------" << endl;

            cin.ignore();
            cout << "Ingresar dia de la semana: ";
            cin.getline(diaDeLaSemana,10);

            for(int i=0; i<cantReg; i++){

                Act=Archivo.leer(i);

                if(strcmp(diaDeLaSemana,Act.getDiaDeLaSemana())==0){

                    Act.MostrarActividad();
                    band=true;
                }

            }
            if(!band){
                cout << "No se encontraron Actividades en ese dia de la semana." << endl;
            }
            rlutil::anykey();

            break;
        }
        case 0: band=true;
            break;
        }
    }while(!band);

}
