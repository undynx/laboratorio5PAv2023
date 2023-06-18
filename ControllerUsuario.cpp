#include "Factory.h"
#include "ControllerUsuario.h"
#include "InterfaceUsuario.h"

ControllerUsuario* ControllerUsuario::instancia=NULL;

ControllerUsuario::ControllerUsuario(){}

ControllerUsuario* ControllerUsuario::getinstancia()
{
    if(instancia==NULL){
        instancia = new ControllerUsuario();
    }
    return instancia;
}

ControllerUsuario::~ControllerUsuario() {}

Usuario* ControllerUsuario::altaUsuario(int numTel, string nombre, string imagen, string descripcion)
{
    DtFechaHora fecReg = DtFechaHora(24, 9, 1999, 19, 30);
    DtFechaHora ultCon = DtFechaHora(24, 9, 1999, 19, 30);

    this->getinstancia();

    Usuario* user = new Usuario(numTel, nombre, fecReg, imagen, descripcion, ultCon);

    instancia->colUsuarios.insert({numTel, user});

    cout << "Se dio de alta su usuario correcatmente.\n";
    cout << "Hora de conexión:" << ultCon.getHora() <<":"<< ultCon.getMin();

    return user;
}

bool ControllerUsuario::ingresarNumero(int numTel)
{
    this->getinstancia();

    if(instancia->colUsuarios.find(numTel) != instancia->colUsuarios.end())
    {  
        return true; //Si encunetro el numTel antes del final del map devuelvo true
    }
    else
    {
        return false; //Si no encunetro el numTel antes del final del map devuelvo true
    }
}

Usuario* ControllerUsuario::encontrarUsuarioxnumTel(int numTel)
{
    this->getinstancia();
    Usuario* user = NULL;

    if(instancia->colUsuarios.find(numTel) != instancia->colUsuarios.end())
    {  
          user = instancia->colUsuarios.at(numTel);
    }
    
    return user;
}

//Si existe el contacto devuelve el usuario, sino devuelve NULL
Usuario *ControllerUsuario::encontrarContactoxNumTel(int numTel){
    if (colContactos.find(numTel) != instancia->colUsuarios.end())
    {
        return instancia->colContactos.at(numTel);
    }

    return NULL;
}

void ControllerUsuario::agregarContacto(int numTel, Usuario* user) {

    // Primero busco si el usuario existe en el sistema
    //ControllerSesion* cs = ControllerSesion::getInstancia();
    //Usuario *user = cs->getUserLoggeado();
    //Llamar a una instancia nueva de sesión genera problemas con la sesión.
    //Lo mejor es pasar el usuario logeado por parametro

    Usuario *contacto = NULL;
    contacto = encontrarUsuarioxnumTel(numTel);

    if(contacto == NULL) { //Si no existe no hago nada
        cout << "  ERROR: No existe ningun usuario con el número " << numTel << " en el sistema" << endl;

    }else {
        //Busca si ya tiene ese contacto agregado
        if (user->getContacto(numTel) != NULL)
        {
            cout << "  ERROR: Ya existe el usuario con el numero " << numTel << " en tu lista de contactos" << endl;
        }
        else
        {
            DtFechaHora ultCon = contacto->getUltCon();
            DtFechaHora fecReg = contacto->getFecReg();

            cout << "Nombre: " << contacto->getNombre() << endl;
            //cout << "Numero: " << contacto->getNumTel() << endl;
            cout << "Descripcion: " << contacto->getDescripcion() << endl;
            cout << "URL imagen: " << contacto->getImagen() << endl;
            cout << "Ultima conexion: " << ultCon.getDia() << "/" << ultCon.getMes() << "/" << ultCon.getAnio() << " " << ultCon.getHora() << ":" << ultCon.getMin() << endl;
            cout << "Fecha de Registro: " << fecReg.getDia() << "/" << fecReg.getMes() << "/" << fecReg.getAnio() << " " << fecReg.getHora() << ":" << fecReg.getMin() << endl;
            cout << "\nDeseas agregar a este usuario a tus contactos?" << endl;
            cout << "  1) SI \n  2) NO" << endl;
            int opt;
            cin >> opt;
            if (opt == 1)
            { // Desea agregarlo a contactos
                user->setContacto(contacto);
            }
        }
    }
}

//Muestra en consola todos los usuarios en la lista de contactos
void ControllerUsuario::listarContactos(Usuario* user){

    //ControllerSesion* cs = ControllerSesion::getInstancia();
    //Usuario *user = cs->getUserLoggeado();
    //Llamar a una instancia nueva de sesión genera problemas con la sesión.
    //Lo mejor es pasar el usuario logeado por parametro
    colContactos = user->getListaContactos();

    for (auto it = colContactos.begin(); it != colContactos.end(); it++){
        cout << it->second->getNombre() << " - " << it->second->getNumTel() << endl;
    }
} 
