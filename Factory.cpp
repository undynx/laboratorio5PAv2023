#include <stdlib.h>
#include "Factory.h"
#include "ControllerConvMens.h"
#include "ControllerUsuario.h"
#include "ControllerGrupo.h"
#include "ControllerSesion.h"

using namespace std;

Factory *Factory::instance = NULL;

Factory::Factory(){}

Factory *Factory::getInstancia() {
  if(instance == NULL) {
    instance = new Factory();
  }
  return instance;
}

InterfaceSesion *Factory::getInterfaceSesion() {
  ControllerSesion *cs = new ControllerSesion();
  return cs;
}

InterfaceConvMens *Factory::getInterfaceConvMens() {
  ControllerConvMens *ccm = new ControllerConvMens();
  return ccm;
}

InterfaceUsuario *Factory::getInterfaceUsuario() {
  ControllerUsuario *cu = new ControllerUsuario();
  return cu;
}

InterfaceGrupo* Factory::getInterfaceGrupo(){
  InterfaceGrupo *cg = new ControllerGrupo();
  return cg;
}

Factory::~Factory(){}
