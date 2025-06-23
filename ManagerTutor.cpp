#include <iostream>
#include "rlutil.h"
#include "ManagerTutor.h"
#include "ArchivoTutor.h"
#include "Menu.h"
using namespace std;




    void ManagerTutor::altaTutor(){
    rlutil::cls();
    ArchivoTutor archiv;
    Tutor tut;
    cout << "---------------------------------------" << endl;
    cout << "             ALTA TUTOR                " << endl;
    cout << "---------------------------------------" << endl;


    cin.ignore();
    tut.cargar();//Se le piden los datos al tutor

   int pos = archiv.buscarTutor(tut.getDni());
   if (pos>=0){
    cout<<"Este tutor ya existe"<<endl;
    return;
   }//Con esto si la posicion retorna mas de 0, es porque existe

    int cantidad = archiv.getCantidadRegistros();
    int nuevoID = (cantidad >0)//me constato que haya almenos un tutor guardado
        ? archiv.Leer(cantidad-1).getIDTutor()+1 //si es verdadero se lee el ultimo tutor, sacamos el id y le sumamos 1
        : 1;//si es falso el primero siempre tendra 1
    tut.setIDTutor(nuevoID);//Se le asigna el nuevo id al tutor

    //Guardamos el tutor
    if(archiv.agregarRegistro(tut)==1){
        cout<<"Tutor agregado con ID: "<< nuevoID <<endl;
    }else{
        cout<<"Error al agregar tutor: "<<endl;
    }
    }
    void ManagerTutor::listarTutoresActivos(){
        rlutil::cls();
        ArchivoTutor archiv;
    cout << "---------------------------------------" << endl;
    cout << "         LISTADO TUTORES ACTIVOS       " << endl;
    cout << "---------------------------------------" << endl;

        archiv.listarRegistrosActivos();
    }
    void ManagerTutor::listarTodosLosTutores(){
        rlutil::cls();
        ArchivoTutor archiv;
    cout << "---------------------------------------" << endl;
    cout << "      LISTADO DE TODOS LOS TUTORES     " << endl;
    cout << "---------------------------------------" << endl;

        archiv.listarTodosLosRegistros();
    }
    void ManagerTutor::listarTutoresInactivos(){
        rlutil::cls();
        ArchivoTutor archiv;
    cout << "---------------------------------------" << endl;
    cout << "        LISTADO TUTORES INACTIVOS      " << endl;
    cout << "---------------------------------------" << endl;

        archiv.listarRegistrosInactivos();
    }
   void ManagerTutor::modificarTutor() {
    rlutil::cls();
    ArchivoTutor archiv;
    char dni[10];
    cout << "---------------------------------------" << endl;
    cout << "            MOFIFICAR TUTOR            " << endl;
    cout << "---------------------------------------" << endl;

    cout << "Ingrese el DNI del tutor a modificar: ";
    cin >> dni;

    int pos = archiv.buscarTutor(dni); // lo buscamos y obtenemos la posición
    if (pos == -1) {
        cout << "No se ha encontrado un tutor con ese DNI." << endl; // si no lo encuentra, se va
        return;
    }

    Tutor tut = archiv.Leer(pos); // existe, lo leo
    cout << "Datos actuales del tutor:" << endl;
    tut.mostrar(); // muestro los datos actuales


    Menu submenu("MODIFICAR TUTOR");
    submenu.CargarOpciones("NOMBRE");
    submenu.CargarOpciones("APELLIDO");
    submenu.CargarOpciones("DNI");
    submenu.CargarOpciones("EDAD");
    submenu.CargarOpciones("GENERO");
    submenu.CargarOpciones("TELEFONO");
    submenu.CargarOpciones("EMAIL");
    submenu.CargarOpciones("FECHA DE NACIMIENTO");
    submenu.CargarOpciones("DOMICILIO");
    submenu.CargarOpciones("REGRESAR");

    bool salir = false;//Banderita que solo sale cuando le ponemos regresar.
    do {
        rlutil::cls();
        cout << "Datos actuales del tutor:" << endl;
        tut.mostrar(); // Siempre muestra el estado actualizado.
        submenu.Mostrar();

        switch (submenu.SeleccionarOpcion()) {
            case 1: {
                rlutil::cls();
                char aux[40];//se crea un vector auxiliar.
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR TUTOR            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo nombre: ";
                cin.ignore();
                cin.getline(aux, 40);
                tut.setNombres(aux);// se setea el nuevo valor.
                break;//se va
            }
            case 2: {
                rlutil::cls();
                char aux[40];//Mismo proceso en cada uno.
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR TUTOR            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo apellido: ";
                cin.ignore();
                cin.getline(aux, 40);
                tut.setApellidos(aux);
                break;
            }
            case 3: {
                rlutil::cls();
                char aux[10];
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR TUTOR            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo DNI: ";
                cin.ignore();
                cin.getline(aux, 9);
                tut.setDni(aux);
                break;
            }
            case 4: {
                rlutil::cls();
                int edad;
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR TUTOR            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nueva edad: ";
                cin >> edad;
                tut.setEdad(edad);
                break;
            }
            case 5: {
                rlutil::cls();
                char aux[20];
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR TUTOR            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo genero (Masculino/Femenino/Otro): ";
                cin.ignore();
                cin.getline(aux, 20);
                tut.setGenero(aux);
                break;
            }
            case 6: {
                rlutil::cls();
                char aux[15];
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR TUTOR            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo telefono: ";
                cin.ignore();
                cin.getline(aux, 15);
                tut.setTelefono(aux);
                break;
            }
            case 7: {
                rlutil::cls();
                char aux[50];
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR TUTOR            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo email: ";
                cin.ignore();
                cin.getline(aux, 50);
                tut.setEmail(aux);
                break;
            }
            case 8: {
                rlutil::cls();
                Fecha f;
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR TUTOR            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nueva fecha de nacimiento:" << endl;
                f.cargar();
                tut.setFecha(f);
                break;
            }
            case 9: {
                rlutil::cls();
                Domicilio d;
                cout << "---------------------------------------" << endl;
                cout << "            MOFIFICAR TUTOR            " << endl;
                cout << "---------------------------------------" << endl;

                cout << "Ingrese nuevo domicilio:" << endl;
                d.cargar();
                tut.setDomicilio(d);
                break;
            }
            case 0:
                salir = true; // la banderita se pone true y se sale del ciclo.
                break;
        }

        if (!salir) {//como la banderia es false, entra y repite el proceso porque sigue con el while.
            // Actualiza el tutor en el archivo después de cada modificación.
            tut.setIDTutor(archiv.Leer(pos).getIDTutor()); // le seteo el idTutor que ya tenía para previamente para conservarle el mismo id.
            archiv.modificarTutor(tut, pos); // modifica el tutor.
            cout << "Dato modificado correctamente. Presione una tecla para continuar." << endl;
            rlutil::anykey();
        }
    } while (!salir);
}
    void ManagerTutor::eliminarLogicoTutor(){
    rlutil::cls();
    ArchivoTutor archiv;
    char dni[10];
    cout << "---------------------------------------" << endl;
    cout << "            ELIMINAR TUTOR             " << endl;
    cout << "---------------------------------------" << endl;

    cout<<"Ingrese el DNI del tutor a dar de baja: ";
    cin>>dni;

    if(archiv.bajaLogica(dni)){
        cout<<"Tutor dado de baja correctamente."<<endl;
    }else{
        cout<<"No se pudo dar de baja al tutor. Verifique el DNI."<<endl;
    }
    }
    void ManagerTutor::altaLogicoTutor(){
    rlutil::cls();
    ArchivoTutor archiv;
    char dni[10];
    cout << "---------------------------------------" << endl;
    cout << "    DAR DE ALTA NUEVAMENTE AL TUTOR    " << endl;
    cout << "---------------------------------------" << endl;

    cout<<"Ingrese el DNI del tutor a dar de alta: ";
    cin>>dni;

    if(archiv.altaLogica(dni)){
        cout<<"Tutor dado de alta correctamente."<<endl;
    }else{
        cout<<"No se pudo dar de alta al tutor. Verifique el DNI."<<endl;
    }
    }
    void ManagerTutor::buscarTutor(){
        rlutil::cls();
        ArchivoTutor archiv;
        char dni[10];
    cout << "---------------------------------------" << endl;
    cout << "             BUSCAR TUTOR              " << endl;
    cout << "---------------------------------------" << endl;

        cout<<"Ingrese el DNI del Tutor a buscar: ";
        cin>>dni;
        int pos = archiv.buscarTutor(dni);//con buscar obtengo la posicion.
        if(pos == -1){
            cout<<"No se encontro un Tutor con ese DNI."<<endl;//si no lo encuentra se va
            return;
        }
        Tutor tut=archiv.Leer(pos);//si lo encuentra lo lee
        tut.mostrar();//Luego lo muestra.
    }


