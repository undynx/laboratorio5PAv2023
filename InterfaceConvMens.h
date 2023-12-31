#ifndef INTERFACECONVMENS_H
#define INTERFACECONVMENS_H
#include <map>
#include <stdlib.h>
#include <string.h>
#include "Mensaje.h"
#include "MSimple.h"
#include "MVideo.h"
#include "MImagen.h"
#include "MContacto.h"
#include "VistoMensaje.h"
#include "Usuario.h"
#include "ControllerUsuario.h"
#include "Conversacion.h"
#include "ConversacionPrivada.h"
#include "ConversacionGrupal.h"
#include "ConversacionArchivada.h"

using namespace std;

class InterfaceConvMens {
	public:
        virtual void iniciarConversacion(int numTelContacto, DtFechaHora* fechaSistema)=0;
        virtual void listarConversacionesActivas()=0;
        virtual void setConversacionColSis(Conversacion *conv, int id) = 0;
        virtual Conversacion *getConverSis(int idConver) = 0;
        virtual void ingresarIdConversacionEnviarMsj(int idConve, DtFechaHora* fecEnvio)=0;
        virtual void ingresarIdConversacionEnviarMsjArch(int idConve, DtFechaHora* fecEnvio)=0;
        virtual void ingresarIdConversacionMostrar(int idConve, DtFechaHora* fecVisto, bool eliminar)=0;
        virtual void ingresarIdConversacionMostrarArch(int idConver, DtFechaHora* fecVisto, bool eliminar)=0;
        virtual string randomStr(int ch)=0;
        virtual Mensaje* encontrarMensaje(string codigo)=0;
        virtual Mensaje* enviarMsjSimple(string texto, DtFechaHora* fecEnvio, int numTelRemitente)=0;
        virtual Mensaje* enviarMsjVideo(string url, float duracion, DtFechaHora* fecEnvio, int numTelRemitente)=0;
        virtual Mensaje* enviarMsjCompartirContacto(int celularCompContacto, DtFechaHora* fecEnvio, int numTelRemitente)=0;
        virtual Mensaje* enviarMsjImagen(string url, string tamanio, string formato, DtFechaHora* fecEnvio, string texto, int numTelRemitente)=0;
        virtual bool verArchivadas()=0;  
        virtual void archivarConversacion()=0;
};
#endif
