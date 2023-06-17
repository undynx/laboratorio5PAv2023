#include "ControllerGrupo.h"

ControllerGrupo *ControllerGrupo::instancia = NULL;

ControllerGrupo::ControllerGrupo(){}

ControllerGrupo *ControllerGrupo::getInstancia() {
  if (instancia == NULL)
  {
    instancia = new ControllerGrupo();
  }
  return instancia;
}
