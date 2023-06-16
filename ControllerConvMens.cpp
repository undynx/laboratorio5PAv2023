#include "ControllerConvMens.h"

ControllerConvMens* ControllerConvMens::instance=NULL;

ControllerConvMens::ControllerConvMens(){}

int mostrarCantidad(){}
set<DtConversacion> seleccionarConversacion(string id){}
set<DtMensaje> datosMensajes(string id){}
DtMensaje borrarMensaje(DtConversacion borrar){}
set<DtConversacion> seleccionarConversacionesTodas(){}
DtConversacion ingresarIdConversacion(int idConve){}
DtMensaje enviarMsjSimple(string texto){}
DtMensaje enviarMsjVideo(string url, string formato, float duracion){}
DtMensaje enviarMsjCompartirContacto(int celularCompContacto){}
DtMensaje enviarMsjImagen(string url, string tamanio, string formato){}
set<DtConversacion> buscarConv(int id){}
set<DtConversacion> buscarConvArch(int id){}
DtMensaje seleccionarMsj(int id){}

ControllerConvMens::~ControllerConvMens(){}
