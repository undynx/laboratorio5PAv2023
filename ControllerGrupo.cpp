#include "ControllerGrupo.h"
#include "ControllerSesion.h"
#include "ControllerUsuario.h"

ControllerGrupo *ControllerGrupo::instancia = NULL;

ControllerGrupo::ControllerGrupo(){}

ControllerGrupo *ControllerGrupo::getInstancia() {
  if (instancia == NULL)
  {
    instancia = new ControllerGrupo();
  }
  return instancia;
}

void ControllerGrupo::listarContactosPart(DtUsuario* part)
{
  

}

void ControllerGrupo::listarContactosRest(DtUsuario* part)
{

}

void ControllerGrupo::agregarParticipante(Usuario* agregarP)
{

}

void ControllerGrupo::quitarParticipante(Usuario* quitarP)
{

}

void ControllerGrupo::ingresoGrupo(ConversacionGrupal* grupo)
{

}