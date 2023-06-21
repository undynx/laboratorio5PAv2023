#ifndef CONVERSACION_H
#define CONVERSACION_H
#include "DtConversacion.h"
#include "DtFechaHora.h"
#include "Mensaje.h"
#include "Usuario.h"
#include <string>
#include <map>

using namespace std;


class Conversacion{
    private:
        bool activo;
        int id;
        map<string,Mensaje*> colMensajes;
        //map<int,Usuario*> colParticipantes;
    public:
        Conversacion();
        Conversacion(bool activo, int id);
        bool getActivo();
        void setActivo(bool activo);
        int getId();
        void setId(int id);
        //Usuario* getParticipante(int numTel);
        //void setParticipante(Usuario* participante);
        Mensaje* getMensaje(string codigo);
        void setMensaje(Mensaje* codigo);
        //bool perteneceParticipante(int numTel);
        //map <int, Usuario*> getListaParticipantes();
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
