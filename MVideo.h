#ifndef MVIDEO_H
#define MVIDEO_H
#include <string>
#include "DtFechaHora.h"
#include "Mensaje.h"

using namespace std;

class MVideo : public Mensaje
{
    private:
        float duracion;
    public:
        MVideo();
        MVideo(string codigo, DtFechaHora fechayHora);
        string getCodigo();
        void setCodigo(string);
        DtFechaHora getfechayHora();
        void MostrardatosM();
        ~MVideo();
};
#endif
