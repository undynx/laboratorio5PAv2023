#ifndef MSIMPLE_H
#define MSIMPLE_H
#include <string>
#include "DtFechaHora.h"
#include "Mensaje.h"

using namespace std;

class MSimple : public Mensaje
{
    private:
        string texto;
    public:
        MSimple();
        MSimple(std::string codigo, DtFechaHora* fechayhora, std::string texto);
        std::string getTexto();
        void setTexto(std::string texto);
        void MostrardatosM();
        ~MSimple();
};
#endif
