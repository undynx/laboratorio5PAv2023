#ifndef CONVERSACIONGRUPAL_H
#define CONVERSACIONGRUPAL_H

#include "DtFechaHora.h"
#include "Conversacion.h"
#include <string>

using namespace std;


class ConversacionGrupal: public Conversacion{
    private:
        string nombre;
        string imagen;
        DtFechaHora fechayHora;
    public:
        ConversacionGrupal();
        ConversacionGrupal(string nombre, string imagen, DtFechaHora fechayHora, bool activo, int id);
        string getNombre();
        void setNombre(string);
        string getImagen();
        void setImagen(string);
        bool getActivo();
        void setActivo(bool);
        DtFechaHora getFechayHora();
        void setFechayHora(DtFechaHora);
        int getId();
        void setId(int);
        void mostrarConverG();
        ~ConversacionGrupal();
};
#endif
