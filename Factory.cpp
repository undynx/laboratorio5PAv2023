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
  InterfaceSesion *cs = new ControllerSesion();
  return cs;
}

InterfaceConvMens *Factory::getInterfaceConvMens() {
  InterfaceConvMens *ccm = new ControllerConvMens();
  return ccm;
}

InterfaceUsuario *Factory::getInterfaceUsuario() {
  InterfaceUsuario *cu = new ControllerUsuario();
  return cu;
}

InterfaceGrupo* Factory::getInterfaceGrupo(){
  InterfaceGrupo *cg = new ControllerGrupo();
  return cg;
}

Factory::~Factory(){}
