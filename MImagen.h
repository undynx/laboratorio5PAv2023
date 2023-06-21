#ifndef MIMAGEN_H
#define MIMAGEN_H
#include <string>
#include "DtFechaHora.h"
#include "Mensaje.h"

using namespace std;

class MImagen : public Mensaje
{
    private:
        string url;
        string formato;
        string tamaño;
        string texto;
    public:
        MImagen();
        MImagen(string codigo, DtFechaHora* fechayHora, string url, string formato, string tamaño, string texto);
        string getFormato();
        string getTamaño();
        string getTexto();
        void setFormato(string formato);
        void setTamaño(string tamaño);
        void setTexto(string texto);
        void MostrardatosM();
        ~MImagen();
};
#endif
