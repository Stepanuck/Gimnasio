#pragma once






class ManagerConfiguracion{
private:

public:

        //Metodos estaticos para llamarlos sin crear un objeto.
        //Para hacer copias y restauraciones indivuales.
        static void backupArchivo(const char* origen, const char* destino);
        static void restoreArchivo(const char* backup, const char* destino);
        //Para hacer copia y restauracion completa.
        static void backupCompleto();
        static void restoreCompleto();

};
