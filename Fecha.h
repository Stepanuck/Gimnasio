#pragma once


class Fecha{

    private:
        int _dia;
        int _mes;
        int _anio;

    public:
        Fecha(int dia, int mes, int anio);
        Fecha();
        void setDia(int dia);
        int getDia();

        void setMes(int mes);
        int getMes();

        void setAnio(int anio);
        int getAnio();

        void cargar();
        void mostrar();

        void sumarMeses(int cantidad);
        bool operator==(const Fecha& otra) const;

        bool operator == (Fecha fecha);
};
