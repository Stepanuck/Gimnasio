#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ManagerInscripcion.h"
#include "ArchivoInscripcion.h"
#include "ArchivoPlan.h"
#include "ArchivoCobro.h"
#include "Cobro.h"
#include "Menu.h"

using namespace std;



void ManagerInscripcion::CargarInscripcion(){

    ArchivoInscripcion archivoIns;
    ArchivoCobro archivoCobro;
    ArchivoPlan archivoPlan;

    int idSocio, idPlan, cantidadMeses;
    Fecha fechaPago, fechaFin, fechaCobro;
    bool pago = true;
    float monto;


    //calcular el id autonumerico

    int cantReg = archivoIns.getCantidadRegistros();
    int idInscripcion = 1;
    if(cantReg>0){
        Inscripcion ultima = archivoIns.Leer(cantReg - 1);
        idInscripcion = ultima.getIdInscripcion() + 1;
    }
        //datos
    cout << "Ingresar ID del Socio a Inscribir: ";
    cin >> idSocio;
    cout << "Ingresar ID del Plan seleccionado: ";
    cin >> idPlan;

    cout << "Ingrese fecha de pago/inicio (primer mes que paga): " << endl;
    fechaPago.cargar();

    cout << "¿Cuantos meses desea pagar? ";
    cin >> cantidadMeses;

    // Calcular la fecha de vencimiento

    fechaFin = fechaPago;
    fechaFin.sumarMeses(cantidadMeses);

    ///Verificar si la inscripcion ya existe para el mismo socio, plan y periodo

    bool existe = false;
    for(int i=0;i<cantReg;i++){

            Inscripcion guardada= archivoIns.Leer(i);
            if(guardada.getIdSocioInscripto()==idSocio &&
               guardada.getIdPlanInscripto()== idPlan &&
               guardada.getFechaInicio()==fechaPago){
                existe = true;
                break;
               }
    }

    if(!existe){
        //creamos la inscripcion y la guardamos
         Inscripcion insc(idInscripcion, idSocio, idPlan, fechaPago, fechaFin, true);
        if(archivoIns.agregarRegistro(insc) != -1) {
            cout << "Inscripción guardada correctamente. Generando cobro..." << endl;

            // Obtenemos el valor del plan
            Plan p = archivoPlan.buscarPlan(idPlan);
            if(p.getIdPlan()==0){
                cout<<"El plan ingresado no existe. Inscripcion cancelada."<<endl;
                return;
            }
            monto = p.getArancel() * cantidadMeses;

            cout << "Ingrese fecha de cobro: " << endl;
            fechaCobro.cargar();

             //Genero el id de cobro autonumérico
            int idCobro = archivoCobro.getCantidadRegistros() + 1;

            Cobro cobro(idCobro, idInscripcion, fechaCobro, monto);
            if (archivoCobro.agregarRegistro(cobro) == 1) {
                cout << "Cobro registrado correctamente." << endl;
            } else {
                cout << "Error al registrar el cobro." << endl;
            }
        } else {
            cout << "No se pudo guardar la inscripción" << endl;
        }
    } else {
        cout << "Inscripción existente para ese socio, plan y fecha de inicio." << endl;
    }

    }


/*
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

}*/
//void ManagerInscripcion::ListarInscripcionesActivas();
//void ManagerInscripcion::ListarInscripciones();
void ManagerInscripcion::ModificarInscripcion(){
    Menu submenu("MODIFICAR INSCRIPCION");

    submenu.CargarOpciones("ID SOCIO");
    submenu.CargarOpciones("ID PLAN");
    submenu.CargarOpciones("FECHA INICIO");
    submenu.CargarOpciones("REGRESAR");
    bool band=false;
    do{
        system("cls");
        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()){
        case 1:{
            int id, posicion, idSocio;
            ArchivoInscripcion Archivo;
            Inscripcion insc, inscGuardada;

            cout << "Ingresar ID de la Inscripcion a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarInscripcion(id);

            if(posicion>=0){

               insc=Archivo.Leer(posicion);

               cout << "Ingresar nuevo ID del socio: ";
               cin >> idSocio;

               insc.setIdSocioInscripto(idSocio);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    inscGuardada=Archivo.Leer(i);


                    if(insc==inscGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarInscripcion(insc,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Inscripcion existente" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Inscripcion buscada." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");
            break;
        }
        case 2:{
            int id, posicion, idPlan;
            ArchivoInscripcion Archivo;
            Inscripcion insc, inscGuardada;

            cout << "Ingresar ID de la Inscripcion a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarInscripcion(id);

            if(posicion>=0){

               insc=Archivo.Leer(posicion);

               cout << "Ingresar nuevo ID del Plan: ";
               cin >> idPlan;

               insc.setIdPlanInscripto(idPlan);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    inscGuardada=Archivo.Leer(i);

                    if(insc==inscGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarInscripcion(insc,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Inscripcion existente" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Inscripcion buscada." << endl;
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
            Fecha fechaDeInicio;
            ArchivoInscripcion Archivo;
            Inscripcion insc, inscGuardada;

            cout << "Ingresar ID de la Inscripcion a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarInscripcion(id);

            if(posicion>=0){

               insc=Archivo.Leer(posicion);

               cout << "Ingresar la nueva fecha ingreso: ";
               fechaDeInicio.cargar();

               insc.setFechaInicio(fechaDeInicio);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    inscGuardada=Archivo.Leer(i);

                    if(insc==inscGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarInscripcion(insc,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Inscripcion existente" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Inscripcion buscada." << endl;
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
//void ManagerInscripcion::BuscarInscripcion();
