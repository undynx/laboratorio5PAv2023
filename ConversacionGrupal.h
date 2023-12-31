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
        map<int, Usuario*> colAdministradores;
        map<int, Usuario*> colParticipantes;
        DtFechaHora* fechayHora;
        map<int, DtFechaHora*> colFechasIngresosParticipantes; //Guarda la fecha de ingreso de cada participante
    public:
        ConversacionGrupal();
        ConversacionGrupal(int id, bool activo,string nombre, string imagen, DtFechaHora* fechayHora);
        string getNombre();
        void setNombre(string);
        string getImagen();
        void setImagen(string);
        Usuario* getParticipante(int numTel);
        Usuario* getAdministrador(int numTel);
        DtFechaHora* getFechaIngresoParticipante(int numTel);
        void setParticipante(Usuario* participante);
        void eliminarParticipante(int numTel);
        void setAdministrador(Usuario *administrador);
        void setFechaIngresoParticipante(int numTel, DtFechaHora* fechaIngreso);
        bool perteneceParticipante(int numTel);
        bool perteneceAdministrador(int numTel);
        map <int, Usuario*> getListaParticipantes();
        map<int, DtFechaHora*> getListaIngresosParticipantes();
        DtFechaHora* getFechayHora();
        void setFechayHora(DtFechaHora*);
        virtual void mostrarDatosC();
        ~ConversacionGrupal();
};
#endif

