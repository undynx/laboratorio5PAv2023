#ifndef CONTROLLERCONVMENS_H
#define CONTROLLERCONVMENS_H
#include <map>
#include <stdlib.h>
#include "InterfaceConvMens.h"


class ControllerConvMens: public InterfaceConvMens {
    private:
        static ControllerConvMens* instancia;
        map <int,Conversacion*> colConversSis; //Lista de conversaciones del sistema
        map<string,Mensaje*> colMensajesSis; //Lista de mensajes del sistema
        //map <int,Conversacion*> colConversUsuario; //Lista aux - se utiliza para acceder a la lista de conversaciones de un usuario
        //PseudoAtributos
        //Memoria del Controller
        int cantArchivadas; //Contador de conversaciones archivadas
    public:
        ControllerConvMens();
        ControllerConvMens *getInstancia();
        ~ControllerConvMens();
        int iniciarConversacion(int numTelContacto, Usuario* user, DtFechaHora* fechaSistema);
        //int getcantArchivadas();
        void listarConversacionesActivas(Usuario* user);
        /*set<DtConversacionGrupal> mostrarConverG();
        set<DtConversacionPrivada> mostrarConverP();
        set<DtConversacion> seleccionarConversacion(int id);
        set<DtMensaje> datosMensajes(string id);
        DtMensaje borrarMensaje(DtConversacion borrar);
        set<DtConversacion> seleccionarConversacionesTodas();*/
        void ingresarIdConversacion(int idConver, Usuario* user);
        string randomStr(int ch);
        Mensaje* encontrarMensaje(string codigo);
        Mensaje* enviarMsjSimple(string texto, DtFechaHora* fecEnvio, int numTelRemitente);
        //Mensaje* enviarMsjVideo(string url, float duracion, DtFechaHora* fecEnvio, int numTelRemitente);
        Mensaje* enviarMsjCompartirContacto(int celularCompContacto, DtFechaHora* fecEnvio, int numTelRemitente);
        Mensaje* enviarMsjImagen(string url, string tamanio, string formato, DtFechaHora* fecEnvio, string texto, int numTelRemitente);
        //set<DtConversacion> buscarConv(int id);
        //set<DtConversacion> buscarConvArch(int id);
        //DtMensaje seleccionarMsj(int id);
};

#endif
