#ifndef MCONTACTO.H
#define MCONTACTO.H
#include "Mensaje.h"
#include "DtMensaje.h"

class MContacto: public Mensaje{
    public:
    private:
        MContacto();
        MContacto(string codigo, DtFechaHora fechayHora);    
        void mostrarDatos();
        MContacto borrar(DtMensaje m);////??????sera borrar?
        DtMensaje seleccionar();
        ~MContacto();
};
#endif