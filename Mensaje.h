#ifndef MENSAJE_H
#define MENSAJE_H
#include <string>
#include "DtFechaHora.h"
#include "DtMensaje.h"
//#include "Usuario.h"

using namespace std;

class Mensaje {
    private:
        string codigo;
        DtFechaHora* fechayHora;
        //map<int,Usuario*> colVistoPor;
    public:
        Mensaje();
        Mensaje(string codigo, DtFechaHora* fechayHora);
        string getCodigo();
        void setCodigo(string);
        DtFechaHora* getFechayHora();
        void MostrardatosM();
        //DtMensaje delete(DtMensaje); ??
        DtMensaje seleccionar();
        ~Mensaje();
};
#endif
