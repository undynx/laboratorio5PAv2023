#ifndef INTERFACECONVMENS.H
#define INTERFACECONVMENS.H

#include <list>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include "Mensaje.h"
#include "Conversacion.h"
#include "DtConversacionGrupal.h"
#include "DtConversacionPrivada.h"

using namespace std;

class InterfaceConvMens
{
	public:
		virtual set<DtConversacionGrupal> mostrarConverG() = 0;
		virtual set<DtConversacionPrivada> mostrarConverP()=0;
        virtual int mostrarCantidad()=0;
        virtual set<DtConversacion> seleccionarConversacion(string id)=0;
        virtual set<DtMensaje> datosMensajes(string id)=0;
        virtual  DtMensaje borrarMensaje(DtConversacion borrar)=0;
        virtual set<DtConversacion> seleccionarConversacionesTodas()=0;
        virtual DtConversacion ingresarIDCOnversacion(int idConve)=0;
        virtual DtMensaje enviarMsjSimple(string texto)=0;
        virtual DtMensaje enviarMsjVideo(string url, string formato, float duracion)=0;
        virtual DtMensaje enviarMsjCompartirContacto(int celularCompContacto)=0;
        virtual DtMensaje enviarMsjImagen(string url, string tamanio, string formato)=0;
        virtual set<DtConversacion> buscarConv(int id)=0;
        virtual set<DtConversacion> buscarConvArch(int id)=0;
        virtual DtMensaje seleccionarMsj(int id)=0;
        virtual ~InterfaceConvMens();
};
#endif
