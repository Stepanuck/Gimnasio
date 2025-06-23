#include <iostream>
#include "rlutil.h"
#include "Cobro.h"
#include "ManagerCobro.h"
#include "ArchivoCobro.h"
#include "ArchivoInscripcion.h"
using namespace std;

void ManagerCobro::listarCobros(){
    rlutil::cls();
    ArchivoCobro archivo;
    int cantidad = archivo.getCantidadRegistros();
    cout << "---------------------------------------" << endl;
    cout << "        LISTAR TODOS LOS COBROS        " << endl;
    cout << "---------------------------------------" << endl;

    if (cantidad == 0) {
        cout << "No hay cobros registrados." << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Cobro cobro = archivo.Leer(i);
        cout << "-------------------------" << endl;
        cout << "ID Cobro: " << cobro.getIdCobro() << endl;
        cout << "ID Inscripcion: " << cobro.getIdInscripcion()<< endl;
        cout << "Fecha de Cobro: ";
        cobro.getFechaCobro().mostrar();
        cout << "Monto: $" << cobro.getMonto() << endl;
    }
}

void ManagerCobro::buscarCobroPorID(){
    rlutil::cls();
    ArchivoCobro archivo;
    int cantidad = archivo.getCantidadRegistros();
    int idBuscar;
    bool encontrado = false;
    cout << "---------------------------------------" << endl;
    cout << "          BUSCAR COBRO POR ID          " << endl;
    cout << "---------------------------------------" << endl;

    cout << "Ingrese ID del cobro a buscar: ";
    cin >> idBuscar;

    for (int i = 0; i < cantidad; i++) {
        Cobro cobro = archivo.Leer(i);
        if (cobro.getIdCobro() == idBuscar) {
            cout << "-------------------------" << endl;
            cout << "ID Cobro: " << cobro.getIdCobro() << endl;
            cout << "ID Inscripcion: " << cobro.getIdInscripcion() << endl;
            cout << "Fecha de Cobro: ";
            cobro.getFechaCobro().mostrar();
            cout << "Monto: $" << cobro.getMonto() << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "No se encontro el cobro con ese ID." << endl;
    }
}
void ManagerCobro::ListarCobrosPorSocio() {
    rlutil::cls();
    ArchivoCobro archivoCobro;
    ArchivoInscripcion archivoInscripcion;
    int cantidad = archivoCobro.getCantidadRegistros();
    int idSocioBuscar;
    bool alguno = false;
    cout << "---------------------------------------" << endl;
    cout << "        LISTAR COBROS POR SOCIO        " << endl;
    cout << "---------------------------------------" << endl;


    cout << "Ingrese ID del socio: ";
    cin >> idSocioBuscar;

    for (int i = 0; i < cantidad; i++) {
        Cobro cobro = archivoCobro.Leer(i);
        Inscripcion insc = archivoInscripcion.Leer(cobro.getIdInscripcion() - 1); // Suponiendo que el idInscripcion coincide con la posición+1
        if (insc.getIdSocioInscripto() == idSocioBuscar) {
            cout << "-------------------------" << endl;
            cout << "ID Cobro: " << cobro.getIdCobro() << endl;
            cout << "Fecha de Cobro: ";
            cobro.getFechaCobro().mostrar();
            cout << "Monto: $" << cobro.getMonto() << endl;
            alguno = true;
        }
    }
    if (!alguno) {
        cout << "No se encontraron cobros para ese socio." << endl;
    }
}

