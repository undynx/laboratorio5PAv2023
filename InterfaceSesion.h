#ifndef INTERFACESESION_H
#define INTERFACESESION_H

using namespace std;

class InterfaceSesion {
  public:
    virtual int abrirApp(int numTel) = 0;
    virtual bool loggedIn() = 0;
    virtual Usuario *getUserLoggeado() = 0;
    virtual void modificarUsuario() = 0;
    virtual void cerrarApp() = 0;
};

#endif
