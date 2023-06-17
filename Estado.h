#ifndef ESTADO_H
#define ESTADO_H
#include "DtFechaHora.h"
#include <string>

using namespace std;

class Estado{
    private:
       string texto;
       DtFechaHora fechayHora;
    public:
        Estado();
        Estado(string texto, DtFechaHora fechayHora);
        string getTexto();
        void setTexto(string);
        DtFechaHora getFechayHora();
       ~Estado();
};
#endif
