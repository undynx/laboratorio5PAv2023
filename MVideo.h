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
        MVideo(string codigo, DtFechaHora fechayHora, float duracion);
        float getDuracion();
        void setDuracion(float duracion);
        void MostrardatosM();
        ~MVideo();
};
#endif
