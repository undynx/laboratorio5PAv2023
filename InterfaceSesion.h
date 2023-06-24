#ifndef INTERFACESESION_H
#define INTERFACESESION_H

using namespace std;

class InterfaceSesion {
  public:
    virtual int abrirApp(int numTel, DtFechaHora *fechaSesion) = 0;
    virtual bool loggedIn() = 0;
    virtual Usuario *getUserLoggeado() = 0;
    virtual void modificarUsuario() = 0;
    virtual void setUserLoggeado(Usuario* user) = 0;
    virtual void cerrarApp(DtFechaHora *fechaUltCon) = 0;
};

#endif
