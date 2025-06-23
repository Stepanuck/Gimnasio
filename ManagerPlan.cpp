#include <iostream>
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
#include "ManagerPlan.h"
#include "Plan.h"
#include "ArchivoPlan.h"
#include "Menu.h"
#include "ArchivoActividad.h"

using namespace std;

void ManagerPlan::CargarPlan(){
    rlutil::cls();
    ArchivoPlan Archivo;
    Plan plan, planGuardado;
    int idPlan;
    char nombre[20];
    int IdActividad, IdActividadesIncluidas[5]={};
    float arancel;
    bool estado;
    int cantActividades;
    int cantReg=Archivo.getCantidadRegistros();
    cout << "---------------------------------------" << endl;
    cout << "              ALTA PLAN                " << endl;
    cout << "---------------------------------------" << endl;

    if(cantReg>0){

        idPlan=Archivo.Leer(cantReg-1).getIdPlan()+1;
    }
    else{
        idPlan=1;
    }
    cin.ignore();
    cout << "Ingresar nombre del Plan: ";
    cin.getline(nombre,20);

    cout << "Ingresar la cantidad de Actividades a incluir en el plan, maximo 5: ";
    cin >> cantActividades;

    ArchivoActividad archivoAct;
    if(cantActividades>0&&cantActividades<=5){
        cout << "Ingresar los ID: " << endl;

        for(int i=0; i<cantActividades;i++){

            while(true){
            cout << "ID Actividad " << i+1 << ": ";
            cin >> IdActividad;
                if(archivoAct.buscarActividad(IdActividad)!=-1){

                    IdActividadesIncluidas[i]=IdActividad;
                    break;
                }
                else{

                    cout << "El ID del Plan Ingresado no existe" << endl;
                    continue;
                }
            }
        }
    }

    cout << "Ingresar Valor del Plan: ";
    cin >> arancel;

    estado=true;

    plan=Plan(idPlan, nombre, IdActividadesIncluidas,arancel,estado);

    bool existe=false;

    if (cantReg>0){
    for(int i=0; i<cantReg; i++){

        planGuardado=Archivo.Leer(i);

        if(plan==planGuardado){

           existe=true;

        }

    }
    }
    if(!existe){


        if(Archivo.agregarRegistro(plan)!=-1){

            cout << "El registro se guardo correctamente" << endl;

        }
        else{

            cout << "No se pudo guardar" << endl;
        }
    }
    else{

        cout << "Plan existente" << endl;

    }
    rlutil::anykey();

}
void ManagerPlan::ListarPlanesActivos(){
    rlutil::cls();
    Plan plan;
    ArchivoPlan Archivo;
    int cantidadRegistros=Archivo.getCantidadRegistros();
    cout << "---------------------------------------" << endl;
    cout << "        LISTADO PLANES ACTIVOS         " << endl;
    cout << "---------------------------------------" << endl;

    for(int i=0; i<cantidadRegistros; i++){

        plan=Archivo.Leer(i);

        if(plan.getEstado()){

            plan.MostrarPlan();

        }
    }
    rlutil::anykey();

}
void ManagerPlan::ListarPlanes(){
    rlutil::cls();
    Plan plan;
    ArchivoPlan Archivo;
    int cantidadRegistros=Archivo.getCantidadRegistros();
    cout << "---------------------------------------" << endl;
    cout << "        LISTADO TODOS LOS PLANES       " << endl;
    cout << "---------------------------------------" << endl;

    for(int i=0; i<cantidadRegistros; i++){

        plan=Archivo.Leer(i);

        plan.MostrarPlan();

    }
    rlutil::anykey();

}
void ManagerPlan::ModificarPlan(){
    Menu submenu("MODIFICAR PLAN");

    submenu.CargarOpciones("NOMBRE");
    submenu.CargarOpciones("ACTIVIDADES INCLUIDAS");
    submenu.CargarOpciones("VALOR DEL PLAN");
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
            ArchivoPlan Archivo;
            Plan plan, planGuardado;
            cout << "---------------------------------------" << endl;
            cout << "             MODIFICAR PLAN            " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID del Plan a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarPosicionPlan(id);

            if(posicion>=0){

               plan=Archivo.Leer(posicion);

               cout << "Ingresar nuevo nombre: ";
               cin.getline(nombre,20);

               plan.setNombre(nombre);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    planGuardado=Archivo.Leer(i);

                    if(plan==planGuardado){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarPlan(plan,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Plan existente" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID del Plan buscado." << endl;
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
            int id, posicion, cantActividades;
            int IdActividad, IdActividadesIncluidas[5]={};
            ArchivoPlan Archivo;
            Plan plan, planGuardado;
            cout << "---------------------------------------" << endl;
            cout << "             MODIFICAR PLAN            " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID del Plan a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarPosicionPlan(id);

            if(posicion>=0){

               plan=Archivo.Leer(posicion);

                cout << "Ingresar la cantidad de Actividades a incluir en el plan, maximo 5: ";
                cin >> cantActividades;

                ArchivoActividad archivoAct;
                if(cantActividades>0&&cantActividades<=5){
                cout << "Ingresar los ID: " << endl;

                for(int i=0; i<cantActividades;i++){

                    while(true){
                        cout << "ID Actividad " << i+1 << ": ";
                        cin >> IdActividad;
                        if(archivoAct.buscarActividad(IdActividad)!=-1){

                            IdActividadesIncluidas[i]=IdActividad;
                            break;
                        }
                        else{

                            cout << "El ID del Plan Ingresado no existe" << endl;
                            continue;
                        }
                    }
                }
            }
                plan.setIdActividadesIncluidas(IdActividadesIncluidas);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    planGuardado=Archivo.Leer(i);

                    if(plan==planGuardado){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarPlan(plan,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Plan existente" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID del Plan buscado." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }            rlutil::anykey();
            break;
        }
        case 3:{
            rlutil::cls();
            int id, posicion;
            float arancel;
            ArchivoPlan Archivo;
            Plan plan, planGuardado;
            cout << "---------------------------------------" << endl;
            cout << "             MODIFICAR PLAN            " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID del Plan a modificar: ";
            cin >> id;

            posicion=Archivo.buscarPosicionPlan(id);

            if(posicion>=0){

               plan=Archivo.Leer(posicion);

               cout << "Ingresar nuevo Valor del Plan: ";
               cin >> arancel;

               plan.setArancel(arancel);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    planGuardado=Archivo.Leer(i);

                    if(plan==planGuardado){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarPlan(plan,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Plan existente" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID del Plan buscado." << endl;
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
void ManagerPlan::altaLogicaPlan(){
    rlutil::cls();
    ArchivoPlan archPlan;
    int idPlan;
    cout << "---------------------------------------" << endl;
    cout << "     DAR DE ALTA NUEVAMENTE UN PLAN    " << endl;
    cout << "---------------------------------------" << endl;

    cout<<"Ingrese el ID del plan que queres dar de alta nuevamente: ";
    cin>>idPlan;

    if(archPlan.altaLogica(idPlan)){
        cout<<"Plan dado de alta correctamente."<<endl;
    }else{
        cout<<"No se pudo dar de alta el plan. Verifique el ID."<<endl;
    }
    }


void ManagerPlan::EliminarPlan(){
            rlutil::cls();
            int id, posicion;
            bool estado;
            ArchivoPlan Archivo;
            Plan plan, planGuardado;
    cout << "---------------------------------------" << endl;
    cout << "             ELIMINAR PLAN             " << endl;
    cout << "---------------------------------------" << endl;

            cout << "Ingresar ID del Plan a Eliminar: ";
            cin >> id;


            posicion=Archivo.buscarPosicionPlan(id);

            if(posicion>=0){

                plan=Archivo.Leer(posicion);

                estado=false;

                plan.setEstado(estado);


                if(Archivo.modificarPlan(plan,posicion)!=-1){

                    cout << "El registro se Elimino correctamente" << endl;

                }
                else{

                    cout << "No se pudo Eliminar" << endl;
                }
            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID del Plan a Eliminar." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            rlutil::anykey();

}


void ManagerPlan::BuscarPlan(){

    Menu submenu("BUSCAR PLAN");

    submenu.CargarOpciones("POR ID");
    submenu.CargarOpciones("POR NOMBRE");
    submenu.CargarOpciones("REGRESAR");
    bool band=false;
    do{
        rlutil::cls();
        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()){
        case 1:{
            rlutil::cls();
            int id, posicion;
            ArchivoPlan Archivo;
            Plan plan;
            cout << "---------------------------------------" << endl;
            cout << "              BUSCAR PLAN              " << endl;
            cout << "---------------------------------------" << endl;

            cout << "Ingresar ID Plan a buscar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarPosicionPlan(id);

            plan=Archivo.Leer(posicion);

            plan.MostrarPlan();

            rlutil::anykey();

            break;
        }
        case 2:{
            rlutil::cls();
            char nombre[20];
            ArchivoPlan Archivo;
            Plan plan;
            int cantReg=Archivo.getCantidadRegistros();
            bool band=false;
            cout << "---------------------------------------" << endl;
            cout << "              BUSCAR PLAN              " << endl;
            cout << "---------------------------------------" << endl;

            cin.ignore();
            cout << "Ingresar Nombre Plan a buscar: ";
            cin.getline(nombre,20);

            for(int i=0; i<cantReg; i++){

                plan=Archivo.Leer(i);

                if(strcmp(nombre,plan.getNombre())==0){

                    plan.MostrarPlan();
                    band=true;
                }

            }
            if(!band){
                cout << "No se encontraron Planes con ese nombre." << endl;
            }
            rlutil::anykey();
            break;
        }
        case 0: band=true;
            break;
        }
    }while(!band);

}

