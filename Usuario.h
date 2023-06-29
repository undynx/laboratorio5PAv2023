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
       int cantArchivadas;
       map <int, Usuario*> colContactos;
       map <int,Conversacion*> colConvers;
     //   map <int,Conversacion*> colArchivadas;// Lista de conversaciones archivadas
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
        int getCantArchivadas();
        void setCantArchivadas(int cantArchivadas);
        DtUsuario pedirDatos();
        Usuario* getContacto(int numtel);
        Conversacion* getConver(int id);
        void setConver(Conversacion* conver);
        void eraseConver(int id);
        bool isEmptyColConvers();
        DtUsuario setUsuario(DtUsuario u);
        void setContacto(Usuario* u);
        map <int, Usuario*> getListaContactos();
        map <int,Conversacion*> getListaConvers();
      /*  map <int,Conversacion*> getListaArchivadas();
        Conversacion* getConverArch(int idConver);
         bool isEmptyArchivadas();*/
        ~Usuario();
};
#endif
