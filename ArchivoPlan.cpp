#include <iostream>
#include <cstring>
#include "Plan.h"
#include "ArchivoPlan.h"

using namespace std;

    ArchivoPlan::ArchivoPlan(){

        strcpy(_nombre, "Plan.dat");
    }

    ArchivoPlan::ArchivoPlan(const char* nombreArchivo= "Plan.dat"){

        strcpy(_nombre,nombreArchivo);

    }
    int ArchivoPlan::agregarRegistro(Plan pla){
        FILE* pPlan;
        pPlan = fopen(_nombre, "ab");
        if(pPlan == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        int escribio = fwrite(&pla, sizeof(Plan), 1, pPlan);
        fclose(pPlan);
        return escribio;
    }

    Plan ArchivoPlan::Leer(int pos){
        FILE* pPlan;
        Plan pla;
        pPlan = fopen(_nombre, "rb");
        pla.setIdPlan(-1);
        if(pPlan == nullptr){
            cout<<"Error de archivo"<<endl;
            return pla;
        }
        fseek(pPlan, sizeof(Plan)*pos, SEEK_SET);
        fread(&pla, sizeof(Plan), 1, pPlan);
        fclose(pPlan);
        return pla;
    }

    int ArchivoPlan::getCantidadRegistros(){
        int total, cantidad;
        FILE* pPlan;
        pPlan = fopen(_nombre, "rb");
        if(pPlan == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        fseek(pPlan, 0, SEEK_END);
        total = ftell(pPlan);
        cantidad = total / sizeof(Plan);
        fclose(pPlan);
        return cantidad;
    }

    int ArchivoPlan::modificarPlan(Plan pla, int pos){
        FILE* pPlan;
        pPlan = fopen(_nombre, "rb+");
        if(pPlan == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        fseek(pPlan, pos*sizeof(Plan), SEEK_SET);
        int escribio = fwrite(&pla, sizeof(Plan),1,pPlan);
        fclose(pPlan);
        return escribio;
    }

    Plan ArchivoPlan::buscarPlan(int idPlan) {
    Plan plan;
    FILE* pPlan = fopen(_nombre, "rb");
    if (!pPlan) {
        // Si no existe el archivo, Se devuelve un plan vac�o (con id = 0, arancel = 0, etc.)
        return plan;
    }
    while (fread(&plan, sizeof(Plan), 1, pPlan) == 1) {
        if (plan.getIdPlan() == idPlan) {
            fclose(pPlan);
            return plan;
        }
    }
    fclose(pPlan);
    // Si no lo encontr�, devuelve el plan vac�o
    return Plan();
}


    int ArchivoPlan::buscarPosicionPlan(int idPlan){
        Plan pla;
        FILE* pPlan;
        pPlan = fopen(_nombre, "rb");
        if(pPlan == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;
        }
        int pos = 0;
        while(fread(&pla, sizeof(Plan),1,pPlan)==1){
            if(pla.getIdPlan()==idPlan){
                fclose(pPlan);
                return pos;
            }
            pos++;
        }
        fclose(pPlan);
        return -1;
    }


/*bool ArchivoPlan::altaLogica(int idPlan){
        Plan pla;
        ArchivoPlan archiv;
        int pos = archiv.buscarPlan(idPlan);
        if(pos==-1)return false;
        pla=archiv.Leer(pos);
        pla.setEstado(true);
        return archiv.modificarPlan(pla, pos);
    }

    bool ArchivoPlan::bajaLogica(int idPlan){
        Plan pla;
        ArchivoPlan archiv;
        int pos = archiv.buscarPlan(idPlan);
        if(pos==-1) return false;
        pla=archiv.Leer(pos);
        pla.setEstado(false);
        return archiv.modificarPlan(pla, pos);
    }
*/

















