#ifndef MSIMPLE_H
#define MSIMPLE_H
#include <string>
#include "DtFechaHora.h"
#include "Mensaje.h"

using namespace std;

class MSimple : public Mensaje
{
    private:
        string texto;
    public:
        MSimple();
        MSimple(string codigo, DtFechaHora fechayHora);
        string getCodigo();
        void setCodigo(string);
        DtFechaHora getfechayHora();
        void MostrardatosM();
        ~MSimple();
};
#endif
