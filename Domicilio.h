#pragma once

class Domicilio{

    private:
       std::string _direccion;
       int _altura;
       int _piso;
       char _departamento[1];
       std::string _codigoPostal;
    public:

    Domicilio();
    Domicilio(std::string direccion, int altura, int piso, char departamento[1], std::string codigoPostal);

    void setDireccion(std::string direccion);
    std::string getDireccion();

    void setAltura(int altura);
    int getAltura();

    void setPiso(int piso);
    int getPiso();

    void setDepartamento(char departamento[1]);
    char getDepartamento();

    void setCodigoPostal(std::string codigoPostal);
    std::string getCodigoPostal();

    void cargar();
    void mostrar();

};
