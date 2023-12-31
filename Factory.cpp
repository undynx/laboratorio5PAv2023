#include "Factory.h"
#include <stdlib.h>

using namespace std;

Factory *Factory::instancia = NULL;

Factory::Factory(){}

Factory *Factory::getInstancia() {
  if(instancia == NULL) {
    instancia = new Factory();
  }
  return instancia;
}

InterfaceSesion *Factory::getInterfaceSesion() {
  InterfaceSesion *cs = ControllerSesion::getInstancia();
  return cs;
}

InterfaceConvMens *Factory::getInterfaceConvMens() {
  InterfaceConvMens *ccm = ControllerConvMens::getInstancia();
  return ccm;
}

InterfaceUsuario *Factory::getInterfaceUsuario() {
  InterfaceUsuario *cu = ControllerUsuario::getInstancia();
  return cu;
}

InterfaceGrupo* Factory::getInterfaceGrupo(){
  InterfaceGrupo *cg = ControllerGrupo::getInstancia();
  return cg;
}

Factory::~Factory(){}
