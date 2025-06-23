#include <iostream>
#include <cstdio>
#include "ManagerConfiguracion.h"
using namespace std;



    void ManagerConfiguracion::backupArchivo(const char* origen, const char* destino){
        FILE* src = fopen(origen, "rb");//Abrimos el archivo origen en modo lectura.
        FILE* dst = fopen(destino, "wb");//Abrimos el archivo destino en modo escritura.
        if(!src){
            cout<<"No se pudo abrir el archivo de origen: "<<origen<<endl;
            return;
        }
        if(!dst){
            cout<<"No se pudo crear el archivo de backup: "<<destino<<endl;
            fclose(src);
            return;
        }/// Si no podemos abrir alguno, informa y retorna.
         char buffer[4096];//Bloque temporal de memoria para traer pedazos del archivo origen
         //tamaño grande para que la copia sea mas rapida
         size_t bytes;;//tipo de dato para cantidades de bytes, guarda cuantos bytes lee en cada
         //vuelta del bucle
          //lee el archivo en bloques
         //intenta leer hasta el tamaño asignado [4096] bytes(buffer) desde el archivo de origen (src)
         //devuelve cuantos bytes leyo y lo guarda en bytes, si lee menos igual los devuelve
         // cuando fread devuelve 0 ahi termina, porque no hay mas datos
         while((bytes = fread(buffer,1,sizeof(buffer), src))>0){
            fwrite(buffer, 1, bytes, dst);
            //Escribe en el archivo destino(dst) la cantidad de bytes que leiste, si lee menos,
            //escribe lo que hay
         }
         fclose(src);
         fclose(dst);
         cout<<"Backup de "<<origen<<" creado en "<<destino<<endl;
    }
        // todo lo mismo que antes pero al inverso, restaurando del backup al archivo de destino
    void ManagerConfiguracion::restoreArchivo(const char* backup, const char* destino){
        FILE* src = fopen(backup, "rb");
        FILE* dst = fopen(destino, "wb");
        if(!src){
            cout<<"No se pudo abrir el archivo de backup: "<<backup<<endl;
            return;
        }
        if(!dst){
            cout<<"No se pudo restaurar el archivo destino: "<<destino<<endl;
            fclose(src);
            return;
        }
        char buffer[4096];
         size_t bytes;

         while((bytes = fread(buffer,1,sizeof(buffer), src))>0){
            fwrite(buffer, 1, bytes, dst);
         }
         fclose(src);
         fclose(dst);
         cout<<"Archivo restaurado desde "<<backup<<" a "<<destino<<endl;
    }
    // Aca hacemos el backup completo de todos los archivos.
    void ManagerConfiguracion::backupCompleto() {
    backupArchivo("Socios.dat", "Socios.bkp");
    backupArchivo("Tutor.dat", "Tutor.bkp");
    backupArchivo("Plan.dat", "Plan.bkp");
    backupArchivo("Actividad.dat", "Actividad.bkp");
    backupArchivo("Inscripciones.dat", "Inscripciones.bkp");
    backupArchivo("Cobro.dat", "Cobro.bkp");
    cout << "Backup completo realizado!" << endl;
}
    //Hacemos la restauracion completa de todos los archivos.
    void ManagerConfiguracion::restoreCompleto() {
    restoreArchivo("Socios.bkp", "Socios.dat");
    restoreArchivo("Tutor.bkp", "Tutor.dat");
    restoreArchivo("Plan.bkp", "Plan.dat");
    restoreArchivo("Actividad.bkp", "Actividad.dat");
    restoreArchivo("Inscripciones.bkp", "Inscripciones.dat");
    restoreArchivo("Cobro.bkp", "Cobro.dat");
    cout << "Restauración completa realizada!" << endl;
}

