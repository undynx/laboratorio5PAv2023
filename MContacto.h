#ifndef MCONTACTO_H
#define MCONTACTO_H

#include "Mensaje.h"
#include "DtMensaje.h"
#include <map>
#include "DtFechaHora.h"
#include "Usuario.h"

class MContacto: public Mensaje{
    private:
        DtUsuario contacto;
    public:
        MContacto();
        MContacto(string codigo, int numTelRemitente, DtFechaHora* fechayHora, DtUsuario contacto);    
        void mostrarDatos();
        MContacto borrar(DtMensaje m);////??????sera borrar?
        DtMensaje seleccionar();
        ~MContacto();
};
#endif
