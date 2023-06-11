#include <stdlib.h>
#include "Factory.h"
#include "ControllerConvMens.h"
#include "ControllerUsuario.h"

using namespace std;

Factory *Factory::instance = NULL;

Factory::Factory(){}

Factory *Factory::getInstancia() {
  if(instance == NULL) {
    instance = new Factory();
  }
  return instance;
}

InterfaceConvMens *Factory::getInterfaceConvMens() {
  return new ControllerConvMens();
}
InterfaceUsuario *Factory::getInterfaceUsuario() {
  return new ControllerUsuario();
}
