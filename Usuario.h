#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
#include <map>
#include <set>
#include "DtFechaHora.h"
#include "DtUsuario.h"
#include "Estado.h"

using namespace std;

class Usuario{
    private:
       int numTel;
       string nombre;
       DtFechaHora fecReg;
       string imagen;
       string descripcion;
       DtFechaHora ultCon;
       map <int, Usuario*> contacto;
       set <Estado*> estado;
    public:
        Usuario();
        Usuario(int numTel, string nombre, DtFechaHora fecReg, string imagen, string descripcion, DtFechaHora ultCon);
        int getNumTel();
        void setNumTel(int numtel);
        string getNombre();
        void setNombre(string nombre);
        DtFechaHora getFecReg();
        string getImagen();
        void setImagen(string img);
        string getDescripcion();
        void setDescripcion(string desc);
        DtFechaHora getUltCon();
        DtUsuario pedirDatos();
        DtUsuario getContacto(int numtel);
        DtUsuario setUsuario(DtUsuario u);
        void setContacto(Usuario* u);
        ~Usuario();
};
#endif
