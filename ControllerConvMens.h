#ifndef CONTROLLERCONVMENS_H
#define CONTROLLERCONVMENS_H
#include <map>
#include <stdlib.h>
#include "InterfaceConvMens.h"


class ControllerConvMens: public InterfaceConvMens {
    private:
        static ControllerConvMens* instancia;
        map <int,Conversacion*> colConvers; //Lista de conversaciones del sistema
        map<string,Mensaje*> colMensajesPorConver; //Lista aux - se utiliza para acceder a la lista de mensajes de una conversacion
        //map <int,Conversacion*> colConversUsuario; //Lista aux - se utiliza para acceder a la lista de conversaciones de un usuario
        //PseudoAtributos
        //Memoria del Controller
    public:
        ControllerConvMens();
        ControllerConvMens *getInstancia();
        ~ControllerConvMens();
        int iniciarConversacion(int numTelContacto, Usuario* user, DtFechaHora* fechaSistema);
        /*set<DtConversacionGrupal> mostrarConverG();
        set<DtConversacionPrivada> mostrarConverP();
        int mostrarCantidad();
        set<DtConversacion> seleccionarConversacion(int id);
        set<DtMensaje> datosMensajes(string id);
        DtMensaje borrarMensaje(DtConversacion borrar);
        set<DtConversacion> seleccionarConversacionesTodas();*/
        void ingresarIdConversacion(int idConver, Usuario* user);
        string randomStr(int ch);
        Mensaje* enviarMsjSimple(string texto, DtFechaHora* fecEnvio);
        //Mensaje* enviarMsjVideo(string url, float duracion, DtFechaHora* fecEnvio);
        Mensaje* enviarMsjCompartirContacto(int celularCompContacto, DtFechaHora* fecEnvio);
        Mensaje* enviarMsjImagen(string url, string tamanio, string formato, DtFechaHora* fecEnvio, string texto);
        //set<DtConversacion> buscarConv(int id);
        //set<DtConversacion> buscarConvArch(int id);
        //DtMensaje seleccionarMsj(int id);
};

#endif
