#pragma once


class Horario{

    private:
    int _hora;
    int _minuto;

    public:
        Horario();
        Horario(int hora, int minuto);
        void setHora(int hora);
        int getHora();

        void setMinuto(int minuto);
        int getMinuto();

        void cargar();
        void mostrar();

        bool operator == (Horario Aux);
};
