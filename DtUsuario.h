#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include "DtFechaHora.h"
#include <string>

using namespace std;

class DtUsuario{
    private:
       int numTel;
       string nombre;
       DtFechaHora fecReg;
       string imagen;
       string descripcion;
       DtFechaHora ultCon;
    public:
        DtUsuario();
        DtUsuario(int numTel, string nombre, DtFechaHora fecReg, string imagen, string descripcion, DtFechaHora ultCon);
        int getNumTel();
        string getNombre();
        DtFechaHora getFecReg();
        string getImagen();
        string getDescripcion();
        DtFechaHora getUltCon();
        ~DtUsuario();
};
#endif