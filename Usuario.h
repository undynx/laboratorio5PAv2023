#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
#include <map>
#include <set>
#include "DtFechaHora.h"
#include "DtUsuario.h"
#include "Estado.h"
#include "Conversacion.h"


using namespace std;

class Usuario{
    private:
       int numTel;
       string nombre;
       DtFechaHora* fecReg;
       string imagen;
       string descripcion;
       DtFechaHora* ultCon;
       map <int, Usuario*> colContactos;
       map <int,Conversacion*> colConvers;
       set <Estado*> estado;
    public:
        Usuario();
        Usuario(int numTel, string nombre, DtFechaHora* fecReg, string imagen, string descripcion, DtFechaHora* ultCon);
        int getNumTel();
        void setNumTel(int numtel);
        string getNombre();
        void setNombre(string nombre);
        DtFechaHora* getFecReg();
        string getImagen();
        void setImagen(string img);
        string getDescripcion();
        void setDescripcion(string desc);
        DtFechaHora* getUltCon();
        void setUltCon(DtFechaHora* ultCon);
        DtUsuario pedirDatos();
        Usuario* getContacto(int numtel);
        Conversacion* getConver(int id);
        void setConver(Conversacion* conver);
        DtUsuario setUsuario(DtUsuario u);
        void setContacto(Usuario* u);
        map <int, Usuario*> getListaContactos();
        map <int,Conversacion*> getListaConvers();
        ~Usuario();
};
#endif
