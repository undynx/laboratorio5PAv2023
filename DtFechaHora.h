#ifndef DTFECHAHORA_H
#define DTFECHAHORA_H

class DtFechaHora{
    private:
        int dia;
        int mes;
        int anio;
        int hora;
        int min;
    public:
        DtFechaHora();
        DtFechaHora(int dia, int mes, int anio, int hora, int min);
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMin();
};
#endif