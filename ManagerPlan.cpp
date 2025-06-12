#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ManagerPlan.h"
#include "Plan.h"
#include "ArchivoPlan.h"
#include "Menu.h"

using namespace std;

void ManagerPlan::CargarPlan(){

    ArchivoPlan Archivo;
    Plan plan, planGuardado;
    int idPlan;
    char nombre[20];
    int IdActividadesIncluidas[5]={};
    float arancel;
    bool estado;
    int cantActividades;
    int cantReg=Archivo.getCantidadRegistros();

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

    if(cantActividades>0&&cantActividades<=5){
        cout << "Ingresar los ID: " << endl;

        for(int i=0; i<cantActividades;i++){

            cout << "ID Actividad " << i+1 << ": ";
            cin >> IdActividadesIncluidas[i];
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
    system("pause");

}
void ManagerPlan::ListarPlanes(){
    Plan plan;
    ArchivoPlan Archivo;
    int cantidadRegistros=Archivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){

        plan=Archivo.Leer(i);

        if(plan.getEstado()){

            plan.MostrarPlan();

        }
    }
    system("pause");

}
void ManagerPlan::ModificarPlan(){
    Menu submenu("MODIFICAR PLAN");

    submenu.CargarOpciones("NOMBRE");
    submenu.CargarOpciones("ACTIVIDADES INCLUIDAS");
    submenu.CargarOpciones("VALOR DEL PLAN");
    submenu.CargarOpciones("REGRESAR");
    bool band=false;
    do{
        system("cls");
        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()){
        case 1:{
            int id, posicion;
            char nombre[20];
            ArchivoPlan Archivo;
            Plan plan, planGuardado;

            cout << "Ingresar ID del Plan a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarPlan(id);

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
            system("pause");
            break;
        }
        case 2:{
            int id, posicion, cantActividades;
            int IdActividadesIncluidas[5];
            ArchivoPlan Archivo;
            Plan plan, planGuardado;

            cout << "Ingresar ID del Plan a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarPlan(id);

            if(posicion>=0){

               plan=Archivo.Leer(posicion);

                cout << "Ingresar la cantidad de Actividades a incluir en el plan, maximo 5: ";
                cin >> cantActividades;

                if(cantActividades>0&&cantActividades<=5){
                    cout << "Ingresar los ID: " << endl;

                    for(int i=0; i<cantActividades;i++){

                        cout << "ID Actividad " << i+1 << ": ";
                        cin >> IdActividadesIncluidas[i];
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
            }            system("pause");
            break;
        }
        case 3:{
            int id, posicion;
            float arancel;
            ArchivoPlan Archivo;
            Plan plan, planGuardado;

            cout << "Ingresar ID del Plan a modificar: ";
            cin >> id;

            posicion=Archivo.buscarPlan(id);

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
            system("pause");
            break;
        }
        case 0: band=true;
            break;
        }
    }while(!band);



}
void ManagerPlan::EliminarPlan(){
            int id, posicion;
            bool estado;
            ArchivoPlan Archivo;
            Plan plan, planGuardado;

            cout << "Ingresar ID del Plan a Eliminar: ";
            cin >> id;


            posicion=Archivo.buscarPlan(id);

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
            system("pause");

}
void ManagerPlan::BuscarPlan(){
    Menu submenu("BUSCAR PLAN");

    submenu.CargarOpciones("POR ID");
    submenu.CargarOpciones("POR NOMBRE");
    submenu.CargarOpciones("REGRESAR");
    bool band=false;
    do{
        system("cls");
        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()){
        case 1:{
            int id, posicion;
            ArchivoPlan Archivo;
            Plan plan;

            cout << "Ingresar ID Plan a buscar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarPlan(id);

            plan=Archivo.Leer(posicion);

            plan.MostrarPlan();

            system("pause");

            break;
        }
        case 2:{
            char nombre[20];
            ArchivoPlan Archivo;
            Plan plan;
            int cantReg=Archivo.getCantidadRegistros();
            bool band=false;

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
            system("pause");
            break;
        }
        case 0: band=true;
            break;
        }
    }while(!band);

}
