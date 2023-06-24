#ifndef MIMAGEN_H
#define MIMAGEN_H
#include <string>
#include "DtFechaHora.h"
#include "Mensaje.h"

using namespace std;

class MImagen : public Mensaje
{
    private:
        string formato;
        string tamano;
        string texto;
    public:
        MImagen();
        MImagen(string codigo, DtFechaHora fechayHora,string formato, string tamano, string texto);
        string getFormato();
        string getTamano();
        string getTexto();
        void setFormato(string formato);
        void setTamano(string tamano);
        void setTexto(string texto);
        void MostrardatosM();
        ~MImagen();
};
#endif
