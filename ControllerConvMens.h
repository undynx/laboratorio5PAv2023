#ifndef CONTROLLERCONVMENS_H
#define CONTROLLERCONVMENS_H

#include "InterfaceConvMens.h"

class ControllerConvMens: public InterfaceConvMens {
    private:
        static ControllerConvMens* instancia;
        map <int, Conversacion*> colConversSis; //Lista de conversaciones del sistema
        map<string, Mensaje*> colMensajesSis; //Lista de mensajes del sistema
       // map <int,Conversacion*> colConversUsuario; //Lista aux - se utiliza para acceder a la lista de conversaciones de un usuario
        //PseudoAtributos
        //Memoria del Controller
        int cantArchivadas;
    public:
        ControllerConvMens();
        static ControllerConvMens *getInstancia();
        ~ControllerConvMens();
        Conversacion* getConverSis(int idConver);
        void iniciarConversacion(int numTelContacto, DtFechaHora* fechaSistema);
        void setConversacionColSis(Conversacion *conv, int id);
        void listarConversacionesActivas();        
        void ingresarIdConversacionEnviarMsj(int idConver, DtFechaHora* fecEnvio);
        void ingresarIdConversacionEnviarMsjArch(int idConver, DtFechaHora* fecEnvio);
        void ingresarIdConversacionMostrar(int idConver, DtFechaHora* fecVisto);
        void ingresarIdConversacionMostrarArch(int idConver, DtFechaHora* fecVisto);
        string randomStr(int ch);
        Mensaje* encontrarMensaje(string codigo);
        Mensaje* enviarMsjSimple(string texto, DtFechaHora* fecEnvio, int numTelRemitente);   
        Mensaje* enviarMsjCompartirContacto(int celularCompContacto, DtFechaHora* fecEnvio, int numTelRemitente);
        Mensaje* enviarMsjImagen(string url, string tamanio, string formato, DtFechaHora* fecEnvio, string texto, int numTelRemitente);
        void archivarConversacion();
        void verArchivadas();
        //set<DtConversacion> buscarConv(int id);
        //set<DtConversacion> buscarConvArch(int id);
        //DtMensaje seleccionarMsj(int id);
        /*set<DtConversacionGrupal> mostrarConverG();
        set<DtConversacionPrivada> mostrarConverP();
        set<DtConversacion> seleccionarConversacion(int id);
        set<DtMensaje> datosMensajes(string id);
        DtMensaje borrarMensaje(DtConversacion borrar);
        set<DtConversacion> seleccionarConversacionesTodas();*/
        //Mensaje* enviarMsjVideo(string url, float duracion, DtFechaHora* fecEnvio, int numTelRemitente);
};  

#endif
