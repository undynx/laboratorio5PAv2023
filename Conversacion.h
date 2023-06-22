#ifndef CONVERSACION_H
#define CONVERSACION_H
#include "DtConversacion.h"
#include "DtFechaHora.h"
#include "Mensaje.h"
#include <string>
#include <map>

using namespace std;


class Conversacion{
    private:
        bool activo;
        int id;
        map<string,Mensaje*> colMensajes;
    public:
        Conversacion();
        Conversacion(bool activo, int id);
        bool getActivo();
        void setActivo(bool activo);
        int getId();
        void setId(int id);
        Mensaje* getMensaje(string codigo);
        void setMensaje(Mensaje* codigo);
        map <string, Mensaje*> getListaMensajes();
        Conversacion seleccionarConversacion();
        Conversacion getConversacion();
        DtConversacion obtenerConv(Conversacion c);
        DtConversacion pedirDatos();
        Conversacion archivar(bool archivada);
        void mostrarDatos();
        int contar();
        Conversacion seleccionar(DtConversacion borrar);  
       ~Conversacion();
};
#endif
