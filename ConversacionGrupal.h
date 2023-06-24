#ifndef CONVERSACIONGRUPAL_H
#define CONVERSACIONGRUPAL_H
#include "DtFechaHora.h"
#include "Conversacion.h"
#include "Usuario.h"
#include <string>

using namespace std;


class ConversacionGrupal: public Conversacion{
    private:
        string nombre;
        string imagen;
        map<int,Usuario*> colAdministradores;
        map<int,Usuario*> colParticipantes;
        DtFechaHora* fechayHora;
    public:
        ConversacionGrupal();
        ConversacionGrupal(int id, bool activo,string nombre, string imagen, DtFechaHora* fechayHora);
        string getNombre();
        void setNombre(string);
        string getImagen();
        void setImagen(string);
        Usuario* getParticipante(int numTel);
        void setParticipante(Usuario* participante);
        bool perteneceParticipante(int numTel);
        map <int, Usuario*> getListaParticipantes();
        DtFechaHora* getFechayHora();
        void setFechayHora(DtFechaHora*);
        virtual void mostrarDatosC();
        ~ConversacionGrupal();
};
#endif
