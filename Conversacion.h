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
        int id;
        bool activo;
        map<string,Mensaje*> colMensajes;
    public:
        Conversacion();
        Conversacion(int idConver, bool activo);
        bool getActivo();
        void setActivo(bool activo);
        int getId();
        void setId(int id);
        Mensaje* getMensaje(string codigo);
        void setMensaje(Mensaje* codigo);
        map <string, Mensaje*> getListaMensajes();
        map <string, DtMensaje*> getListaMensajesDt();
        bool isColMensajesEmpty();
        //Conversacion seleccionarConversacion();
        //Conversacion getConversacion();
        //DtConversacion obtenerConv(Conversacion c);
        //DtConversacion pedirDatos();
        //Conversacion archivar(bool archivada);
        virtual void mostrarDatosC()=0;
        int contar();
        //Conversacion seleccionar(DtConversacion borrar);
        virtual ~Conversacion();
};
#endif
