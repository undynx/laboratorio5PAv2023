#ifndef INTERFACECONVMENS_H
#define INTERFACECONVMENS_H
#include <list>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include "Mensaje.h"
#include "MSimple.h"
#include "MVideo.h"
#include "MImagen.h"
#include "MContacto.h"
#include "Usuario.h"
#include "ControllerUsuario.h"
#include "Conversacion.h"
#include "ConversacionPrivada.h"
#include "ConversacionGrupal.h"
#include "ConversacionArchivada.h"
#include "DtConversacion.h"
#include "DtConversacionGrupal.h"
#include "DtConversacionPrivada.h"
#include "DtConversacionArchivada.h"

using namespace std;

class InterfaceConvMens {
	public:
        virtual int iniciarConversacion(int numTelContacto, Usuario* user, DtFechaHora* fechaSistema) = 0;
	//virtual set<DtConversacionGrupal> mostrarConverG() = 0;
	//virtual set<DtConversacionPrivada> mostrarConverP() = 0;
        /*virtual int mostrarCantidad()=0;
        virtual set<DtConversacion> seleccionarConversacion(string id)=0;
        virtual set<DtMensaje> datosMensajes(string id)=0;
        virtual  DtMensaje borrarMensaje(DtConversacion borrar)=0;
        virtual set<DtConversacion> seleccionarConversacionesTodas()=0;*/
        virtual void ingresarIdConversacion(int idConve, Usuario* user)=0;
        virtual string randomStr(int ch)=0;
        virtual Mensaje* enviarMsjSimple(string texto, DtFechaHora* fecEnvio)=0;
        //virtual Mensaje* enviarMsjVideo(string url, float duracion, DtFechaHora* fecEnvio)=0;
        virtual Mensaje* enviarMsjCompartirContacto(int celularCompContacto, DtFechaHora* fecEnvio)=0;
        virtual Mensaje* enviarMsjImagen(string url, string tamanio, string formato, DtFechaHora* fecEnvio, string texto)=0;
     //   virtual set<DtConversacion> buscarConv(int id)=0;
     //   virtual set<DtConversacion> buscarConvArch(int id)=0;
     //   virtual DtMensaje seleccionarMsj(int id)=0;
     //   virtual ~InterfaceConvMens(){};
};
#endif
