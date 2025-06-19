#pragma once






class ManagerConfiguracion{
private:

public:
        static void backupArchivo(const char* origen, const char* destino);
        static void restoreArchivo(const char* backup, const char* destino);
        static void backupCompleto();
        static void restoreCompleto();

};
