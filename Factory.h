#ifndef FACTORY_H
#define FACTORY_H
#include "ControllerConvMens.h"
#include "ControllerUsuario.h"
#include "ControllerGrupo.h"
#include "ControllerSesion.h"
#include "ControllerSesion.h"
#include "InterfaceConvMens.h"
#include "InterfaceGrupo.h"
#include "InterfaceSesion.h"
#include "InterfaceUsuario.h"

class Factory {
  private:
    static Factory *instancia;
    Factory();
  public:
    static Factory *getInstancia();
    InterfaceSesion *getInterfaceSesion();
    InterfaceConvMens *getInterfaceConvMens();
    InterfaceUsuario *getInterfaceUsuario();
    InterfaceGrupo *getInterfaceGrupo();
    ~Factory();
};

#endif
