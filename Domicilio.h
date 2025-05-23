#pragma once

class Domicilio{

    private:
       char _calle[50];
       int _altura;
       int _piso;
       char _departamento;
       char _codigoPostal[10];
       char _partido[20];
       char _provincia[20];
    public:

    Domicilio();
    Domicilio(const char* calle, int altura, int piso, char departamento, const char* codigoPostal, const char* partido, const char* provincia);

    void setCalle(const char* calle);
    const char* getCalle();

    void setAltura(int altura);
    int getAltura();

    void setPiso(int piso);
    int getPiso();

    void setDepartamento(char departamento);
    char getDepartamento();

    void setCodigoPostal(const char* codigoPostal);
    const char* getCodigoPostal();

    void setPartido(const char* partido);
    const char* getPartido();

    void setProvincia(const char* Provincia);
    const char* getProvincia();

    void cargar();
    void mostrar();

};
