#ifndef CONVERSACION_H
#define CONVERSACION_H
#include "DtConversacion.h"
#include "DtFechaHora.h"
#include <string>

using namespace std;


class Conversacion{
    private:
        bool activo;
        int id;
    public:
        Conversacion();
        Conversacion(bool activo, int id);
        bool getActivo();
        void setActivo(bool activo);
        int getId();
        void setId(int id);
        Conversacion seleccionarConversacion();
        Conversacion getConversacion();
        DtConversacion obtenerConv(Conversacion c);
        DtConversacion pedirDatos();
        Conversacion archivar(bool archivada);
        void mostrarDatos();
        int contar();
        // Conversacion seleccionar(DtConversacion borrar);  
       ~Conversacion();
};
#endif
