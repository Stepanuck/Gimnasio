#include <iostream>
#include <cstring>
#include "Socio.h"
#include "ManagerSocio.h"
#include "ArchivoSocio.h"
#include "ArchivoInscripcion.h"
#include "Inscripcion.h"
#include "Menu.h"
using namespace std;




void ManagerSocio::altaSocio(){
    ArchivoSocio archiv;
    Socio soc;

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
    ArchivoSocio archiv;
    archiv.listarRegistrosActivos();
}

void ManagerSocio::listarTodosLosSocios(){
    ArchivoSocio archiv;
    archiv.listarTodosLosRegistros();
}

void ManagerSocio::listarSociosInactivos(){
    ArchivoSocio archiv;
    archiv.listarRegistrosInactivos();
}


void ManagerSocio::modificarSocio(){
    ArchivoSocio archiv;
    char dni[10];
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
         system("cls");
        cout << "Datos actuales del socio:" << endl;
        soc.mostrar(); // Muestra los datos actuales.

        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()) {//switch para cada caso a modificar.
            case 1: {
                char aux[40];//se crea un vector auxiliar.
                cout << "Ingrese nuevos nombres: ";
                cin.ignore();
                cin.getline(aux, 40);
                soc.setNombres(aux);// se setea el nuevo valor.
                break;//se va.
            }
            case 2: {
                char aux[40];//Mismo proceso en cada uno.
                cout << "Ingrese nuevos apellidos: ";
                cin.ignore();
                cin.getline(aux, 40);
                soc.setApellidos(aux);
                break;
            }
            case 3: {
                char aux[10];
                cout << "Ingrese nuevo DNI: ";
                cin.ignore();
                cin.getline(aux, 9);
                soc.setDni(aux);
                break;
            }
            case 4: {
                int edad;
                cout << "Ingrese nueva edad: ";
                cin >> edad;
                soc.setEdad(edad);
                break;
            }
            case 5: {
                char aux[20];
                cout << "Ingrese nuevo genero (Masculino/Femenino/Otro): ";
                cin.ignore();
                cin.getline(aux, 20);
                soc.setGenero(aux);
                break;
            }
            case 6: {
                char aux[15];
                cout << "Ingrese nuevo telefono: ";
                cin.ignore();
                cin.getline(aux, 15);
                soc.setTelefono(aux);
                break;
            }
            case 7: {
                char aux[50];
                cout << "Ingrese nuevo email: ";
                cin.ignore();
                cin.getline(aux, 50);
                soc.setEmail(aux);
                break;
            }
            case 8: {
                Fecha f;
                cout << "Ingrese nueva fecha de nacimiento:" << endl;
                f.cargar();
                soc.setFecha(f);
                break;
            }
            case 9: {
                Domicilio d;
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
            system("pause");
        }
    }while(!salir);
}

void ManagerSocio::listarDeudores(){
    ArchivoSocio archSocio;
    ArchivoInscripcion archIns;//instanciamos los archivos.
    int totalSocios = archSocio.getCantidadRegistros();//agarramos la cantidad de socios.
    int totalInscripciones = archIns.getCantidadRegistros();
    if(totalSocios==0){
        cout << "No hay socios cargados." << endl;
        system("pause");
        return;
    }
    if(totalInscripciones == 0){
        cout<<"No hay inscripciones cargadas. No se puede generar el reporte de deudores."<<endl;
        system("pause");
        return;
    }
    Fecha hoy;//instanciamos la fecha para sacar el dia de hoy.
    hoy.hoy();//utilizamos la funcion para eso de arriba.

    cout<<"--------- LISTADO DE DEUDORES -----------"<<endl;

    bool hayDeudores = false;

    for (int i=0;i<totalSocios;i++){
        Socio soc = archSocio.Leer(i);
         //validacion de que el socio se haya leido bien
         if(strcmp(soc.getDni(), "-1") == 0) continue;
        if(soc.getEstado()){//Solo los socios activos
            //Buscamos si tienen inscripciones vigentes
            bool tieneVigencia = false;


            for(int j = 0; j<totalInscripciones; j++){//recorremos las inscripciones
                Inscripcion insc = archIns.Leer(j);//leemos
                if(insc.getIdSocioInscripto()==soc.getIDSocio()&& insc.getActivo() && insc.getFechaFin() >= hoy){//comprobamos que coinicida el id
                        //que este activo y que la fecha de fin se mayor o igual a la de hoy
                    tieneVigencia = true;
                    break;// si es asi, tiene vigencia y no adeuda
                }
            }
            if(!tieneVigencia){//caso contrario adeuda y se muestra, ademas se pone la flag en true.
                hayDeudores = true;
                soc.mostrar();
                cout<<"-----------------------------------"<<endl;
            }
        }
    }
    if(!hayDeudores) cout<<"No hay deudores actualmente."<<endl;
    system("pause");
}


void ManagerSocio::buscarSocio(){
    ArchivoSocio archiv;
    char dni[10];

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
    ArchivoSocio archiv;
    char dni[10];

    cout<<"Ingrese el DNI del socio a dar de baja: ";
    cin>>dni;

    if(archiv.bajaLogica(dni)){
        cout<<"Socio dado de baja correctamente."<<endl;
    }else{
        cout<<"No se pudo dar de baja al socio. Verifique el DNI."<<endl;
    }

}
