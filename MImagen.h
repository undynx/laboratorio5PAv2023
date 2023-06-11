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
        string tamaño;
        string texto;
    public:
        MImagen();
        MImagen(string codigo, DtFechaHora fechayHora);
        string getCodigo();
        void setCodigo(string);
        DtFechaHora getfechayHora();
        void MostrardatosM();
        ~MImagen();
};
#endif
