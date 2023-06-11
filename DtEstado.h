#ifndef DTESTADO_H
#define DTESTADO_H
#include "DtFechaHora.h"
#include <string>

using namespace std;

class DtEstado{
    private:
       string texto;
       DtFechaHora fechayHora;
    public:
        DtEstado();
        DtEstado(string texto, DtFechaHora fechayHora);
        string getTexto();
        DtFechaHora getFechayHora();
       ~DtEstado();
};
#endif