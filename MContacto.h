#ifndef MCONTACTO.H
#define MCONTACTO.H
#include "Mensaje.h"
#include "DtMensaje.h"
#include <map>
#include "DtFechaHora.h"
#include "Usuario.h"

class MContacto: public Mensaje{
    private:
        map <int, Usuario*> usuario;


    public:
        MContacto();
        MContacto(std::string codigo, DtFechaHora fechayHora);    
        void mostrarDatos();
        MContacto borrar(DtMensaje m);////??????sera borrar?
        DtMensaje seleccionar();
        ~MContacto();
};
#endif