#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "Socio.h"
#include "ManagerSocio.h"
#include "ArchivoSocio.h"
#include "ArchivoInscripcion.h"
#include "Inscripcion.h"
#include "Menu.h"
using namespace std;




void ManagerSocio::altaSocio(){
    rlutil::cls();
    ArchivoSocio archiv;
    Socio soc;
    cout << "---------------------------------------" << endl;
    cout << "             ALTA SOCIO                " << endl;
    cout << "---------------------------------------" << endl;
    soc.cargar();//Se le piden los datos al socio

   int pos = archiv.buscarSocio(soc.getDni());
   if (pos>=0){
    cout<<"Este socio ya existe"<<endl;
    return;
   }//Con esto si la posicion retorna mas de 0, es porque existe

    int cantidad = archiv.getCantidadRegistros();
    int nuevoID = (cantidad >0)//me constato que haya almenos un socio guardado
        ? archiv.Leer(cantidad-1).getIDSocio()+1 //si es verdadero se lee el ultimo socio, sacamos el id y le sumamos 1
        : 1;//si es falso el primero siempre tendra 1
    soc.setIdSocio(nuevoID);//Se le asigna el nuevo id al socio

    //Guardamos el socio
    if(archiv.agregarRegistro(soc)==1){
        cout<<"Socio agregado con ID: "<< nuevoID <<endl;
    }else{
        cout<<"Error al agregar socio: "<<endl;
    }
}


void ManagerSocio::listarSociosActivos(){
    rlutil::cls();
    ArchivoSocio archiv;
    cout << "---------------------------------------" << endl;
    cout << "          LISTADO SOCIOS ACTIVOS       " << endl;
    cout << "---------------------------------------" << endl;

    archiv.listarRegistrosActivos();

}

void ManagerSocio::listarTodosLosSocios(){
    rlutil::cls();
    ArchivoSocio archiv;
    cout << "---------------------------------------" << endl;
    cout << "       LISTADO DE TODOS LOS SOCIOS     " << endl;
    cout << "---------------------------------------" << endl;

    archiv.listarTodosLosRegistros();
}

void ManagerSocio::listarSociosInactivos(){
    rlutil::cls();
    ArchivoSocio archiv;
    cout << "---------------------------------------" << endl;
    cout << "        LISTADO SOCIOS INACTIVOS       " << endl;
    cout << "---------------------------------------" << endl;

    archiv.listarRegistrosInactivos();

}


void ManagerSocio::modificarSocio(){
    rlutil::cls();
    ArchivoSocio archiv;
    char dni[10];

    cout << "---------------------------------------" << endl;
    cout << "            MOFIFICAR SOCIO            " << endl;
    cout << "---------------------------------------" << endl;

    cout<<"Ingrese el DNI del socio a modificar: ";
    cin>>dni;

    int pos = archiv.buscarSocio(dni);//lo buscamos y obtenemos la posicion
    if(pos == -1){
        cout<<"No se ha encontrado un socio con ese DNI."<<endl;//si no lo encuentra se va
        return;
    }

    Socio soc = archiv.Leer(pos);//existe lo leo

    Menu submenu("MODIFICAR SOCIO");
    submenu.CargarOpciones("NOMBRES");
    submenu.CargarOpciones("APELLIDOS");
    submenu.CargarOpciones("DNI");
    submenu.CargarOpciones("EDAD");
    submenu.CargarOpciones("GENERO");
    submenu.CargarOpciones("TELEFONO");
    submenu.CargarOpciones("EMAIL");
    submenu.CargarOpciones("FECHA DE NACIMIENTO");
    submenu.CargarOpciones("DOMICILIO");
    submenu.CargarOpciones("REGRESAR");

    bool salir = false;//Banderita que solo sale cuando le ponemos regresar.
    do{
        rlutil::cls();
        cout << "Datos actuales del socio:" << endl;
        soc.mostrar(); // Muestra los datos actuales.

        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()) {//switch para cada caso a modificar.
            case 1: {
                rlutil::cls();
                char aux[40];//se crea un vector auxiliar.
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR SOCIO            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevos nombres: ";
                cin.ignore();
                cin.getline(aux, 40);
                soc.setNombres(aux);// se setea el nuevo valor.
                break;//se va.
            }
            case 2: {
                rlutil::cls();
                char aux[40];//Mismo proceso en cada uno.
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR SOCIO            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevos apellidos: ";
                cin.ignore();
                cin.getline(aux, 40);
                soc.setApellidos(aux);
                break;
            }
            case 3: {
                rlutil::cls();
                char aux[10];
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR SOCIO            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo DNI: ";
                cin.ignore();
                cin.getline(aux, 9);
                soc.setDni(aux);
                break;
            }
            case 4: {
                rlutil::cls();
                int edad;
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR SOCIO            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nueva edad: ";
                cin >> edad;
                soc.setEdad(edad);
                break;
            }
            case 5: {
                rlutil::cls();
                char aux[20];
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR SOCIO            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo genero (Masculino/Femenino/Otro): ";
                cin.ignore();
                cin.getline(aux, 20);
                soc.setGenero(aux);
                break;
            }
            case 6: {
                rlutil::cls();
                char aux[15];
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR SOCIO            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo telefono: ";
                cin.ignore();
                cin.getline(aux, 15);
                soc.setTelefono(aux);
                break;
            }
            case 7: {
                rlutil::cls();
                char aux[50];
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR SOCIO            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo email: ";
                cin.ignore();
                cin.getline(aux, 50);
                soc.setEmail(aux);
                break;
            }
            case 8: {
                rlutil::cls();
                Fecha f;
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR SOCIO            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nueva fecha de nacimiento:" << endl;
                f.cargar();
                soc.setFecha(f);
                break;
            }
            case 9: {
                rlutil::cls();
                Domicilio d;
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR SOCIO            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo domicilio:" << endl;
                d.cargar();
                soc.setDomicilio(d);
                break;
            }
            case 0:
                salir = true;//la banderita se pone true y se sale del ciclo.
                break;
        }

        if(!salir) {// como la banderita es false, entra y repite el proceso porque sigue con el while.
            // Actualiza el socio en el archivo después de cada modificación.
            soc.setIdSocio(archiv.Leer(pos).getIDSocio());//le seteo el idsocio que ya tenia previamente para conservarle el mismo id.
            archiv.modificarSocio(soc, pos);//modifica el socio.
            cout << "Dato modificado correctamente. Presione una tecla para continuar." << endl;
            rlutil::anykey();
        }
    }while(!salir);
}

void ManagerSocio::buscarSocio(){
    rlutil::cls();
    ArchivoSocio archiv;
    char dni[10];
    cout << "---------------------------------------" << endl;
    cout << "             BUSCAR SOCIO              " << endl;
    cout << "---------------------------------------" << endl;

    cout<<"Ingrese el DNI del socio a buscar: ";
    cin>>dni;

    int pos = archiv.buscarSocio(dni);//con buscar obtengo la posicion
    if(pos == -1){
        cout<<"No se encontre un socio con ese DNI."<<endl;//si no lo encuentra se va
        return;
    }
    Socio soc=archiv.Leer(pos);//si lo encuentra lo lee
    soc.mostrar();//luego lo muestra
}

void ManagerSocio::eliminarLogicoSocio(){
    rlutil::cls();
    ArchivoSocio archiv;
    char dni[10];
    cout << "---------------------------------------" << endl;
    cout << "            ELIMINAR SOCIO             " << endl;
    cout << "---------------------------------------" << endl;

    cout<<"Ingrese el DNI del socio a dar de baja: ";
    cin>>dni;

    if(archiv.bajaLogica(dni)){
        cout<<"Socio dado de baja correctamente."<<endl;
    }else{
        cout<<"No se pudo dar de baja al socio. Verifique el DNI."<<endl;
    }

}

void ManagerSocio::altaLogicoSocio(){
    rlutil::cls();
    ArchivoSocio archiv;
    char dni[10];
    cout << "---------------------------------------" << endl;
    cout << "    DAR DE ALTA NUEVAMENTE AL SOCIO    " << endl;
    cout << "---------------------------------------" << endl;

    cout<<"Ingrese el DNI del socio a dar de alta: ";
    cin>>dni;

    if(archiv.altaLogica(dni)){
        cout<<"Socio dado de alta correctamente."<<endl;
    }else{
        cout<<"No se pudo dar de alta al socio. Verifique el DNI."<<endl;
    }

}
