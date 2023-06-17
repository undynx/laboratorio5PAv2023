#ifndef CONVERSACIONARCHIVADA_H
#define CONVERSACIONARCHIVADA_H
#include "Conversacion.h"
#include <string>

using namespace std;

class ConversacionArchivada: public Conversacion {
    private:
        int cantArch;
    public:
        ConversacionArchivada();
        ConversacionArchivada(bool activo, int id, int cantArch);
        int getCantArch();
        void setCantArch(int);
        bool getActivo();
        void setActivo(bool);
        int getId();
        void setId(int);        
        int contar();
        void MostrarDatos();
        ~ConversacionArchivada();
};
#endif
