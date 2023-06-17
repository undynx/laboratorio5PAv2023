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

ControllerSesion* ControllerUsuario::altaUsuario(int numTel, string nombre, string imagen, string descripcion)
{
    DtFechaHora fecReg = DtFechaHora(24, 9, 1999, 19, 30);
    DtFechaHora ultCon = DtFechaHora(24, 9, 1999, 19, 30);

    this->getinstancia();
    ControllerSesion* cs = ControllerSesion::getInstancia();

    Usuario* user = new Usuario(numTel, nombre, fecReg, imagen, descripcion, ultCon);

    instancia->colUsuarios.insert({numTel, user});
    cs->setUserLoggeado(user);

    cout << "Se dio de alta su usuario correcatmente.\n";
    cout << "Hora de conexión:" << ultCon.getHora() <<":"<< ultCon.getMin();

    return cs;
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


/*
set<DtUsuario> listarContactos(int numTel){
    Usuario *u; 
    ControllerUsuario* cu = ControllerUsuario::getinstancia();
    map<int, Usuario*>::iterator it;
    for (it = u->contacto .begin(); it != u->contacto.end(); ++it) 
  {
    cout << u->contacto.at(it).getNombre<<endl;
    cout << u->contacto.at(it).getImagen<<endl;
    cout << u->contacto.at(it).getDescripcion<<endl;
    it++;
  }
 
 
}

DtUsuario agregarContacto( int numTel){

   ControllerUsuario* cu = ControllerUsuario::getinstancia();
   
    Usuario *u;
    int contactonuevo;
    bool existe;
    bool salir= false;
    while(!salir){//mientras quiera agregar contactos;
       //  u->mostrarDatos();
       listarContactos(u->getNumTel);
         cout<<"Ingrese el numero del contacto a agregar:"<<endl;
         cin>> contactonuevo;
        existe=ingresarNumero(contactonuevo);
         if(existe){
            u->getContacto(contactonuevo);
            cout<<"Se encontro el contacto"<<endl;
            u->contacto.insert(make_pair(auto,u->getContacto(contactonuevo) ))
            

         }
        else{
            cout<<"El contacto ingresado no existe"<<endl;
        }
         


    }
   



}*/

/* void salir(){}
void cancelar(){} */
