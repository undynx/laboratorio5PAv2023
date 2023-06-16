#ifndef FACTORY_H
#define FACTORY_H

#include "InterfaceConvMens.h"
#include "InterfaceUsuario.h"
#include "InterfaceSesion.h"
#include "InterfaceGrupo.h"

class Factory {
  private:
    static Factory *instance;
    Factory();
  public:
    static Factory *getInstancia();
    InterfaceSesion *getInterfaceSesion();
    InterfaceConvMens *getInterfaceConvMens();
    InterfaceUsuario *getInterfaceUsuario();
    InterfaceGrupo *getInterfaceGrupo();
    ~Factory();
};

#endif;
