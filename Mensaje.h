#ifndef MENSAJE_H
#define MENSAJE_H
#include <string>
#include "DtFechaHora.h"
#include "DtMensaje.h"

using namespace std;

class Mensaje {
    private:
        std::string codigo;
        DtFechaHora fechayHora;
    public:
        Mensaje();
        Mensaje(string codigo, DtFechaHora fechayHora);
        string getCodigo();
        void setCodigo(string);
        DtFechaHora getFechayHora();
        void MostrardatosM();
        //DtMensaje delete(DtMensaje); ??
        DtMensaje seleccionar();
        ~Mensaje();
};
#endif
