#ifndef CONVERSACIONARCHIVADA_H
#define CONVERSACIONARCHIVADA_H
#include "Conversacion.h"
#include <string>

using namespace std;

class ConversacionArchivada: public Conversacion {
    private:
        //int cantArch; //como una instancia de conversaciónArch puede saber la cantidad de archivadas que tiene un usuario o el sistema??
    public:
        ConversacionArchivada();
        ConversacionArchivada(int id, bool activo);     
        //int contar();
        virtual void mostrarDatosC();
        ~ConversacionArchivada();
};
#endif
