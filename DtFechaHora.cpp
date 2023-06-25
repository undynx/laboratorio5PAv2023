#include "DtFechaHora.h"

DtFechaHora::DtFechaHora(){};

DtFechaHora::DtFechaHora(int dia, int mes, int anio, int hora, int min){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
    this->hora=hora;
    this->min=min;
}

//Gettes
int DtFechaHora::getDia(){
    return this->dia=dia;
}

int DtFechaHora::getMes(){
    return this->mes=mes;
}

int DtFechaHora::getAnio(){
    return this->anio=anio;
}

int DtFechaHora::getHora(){
    return this->hora=hora;
}

int DtFechaHora::getMin(){
    return this->min=min;
}

void DtFechaHora::mostrarFechayHora(){
    cout << endl;
    cout <<"Fecha: "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout << endl;
    cout <<"Hora: "<<getHora()<<":"<<getMin();
}

void DtFechaHora::mostrarFechayHoraConexion(){
    cout << endl;
    cout <<"Fecha de última conexión: "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout << endl;
    cout <<"Hora de última conexión: "<<getHora()<<":"<<getMin();
    cout << endl;
}

void DtFechaHora::mostrarFechayHoraRegistro(){
    cout << endl;
    cout <<"Fecha de registro: "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout << endl;
    cout <<"Hora de registro: "<<getHora()<<":"<<getMin();
    cout << endl;
}

void DtFechaHora::mostrarFechayHoraVisto(){
    cout << endl;
    cout <<"VISTO el "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout <<" a las "<<getHora()<<":"<<getMin();
}

void DtFechaHora::mostrarFechayHoraEnviado(){
    cout << endl;
    cout <<"ENVIADO el "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout <<" a las "<<getHora()<<":"<<getMin();
}

bool DtFechaHora::esMayorIgualQue(DtFechaHora* fechaHora)
{
    if(fechaHora==NULL)
    {
        return true;
    }

    if(this->getAnio()!=fechaHora->getAnio())
    {
        return (this->getAnio()>fechaHora->getAnio());
    }
    else
    {
        if(this->getMes()!=fechaHora->getMes())
        {
            return (this->getMes()>fechaHora->getMes());
        }
        else
        {
            if(this->getDia()!=fechaHora->getDia())
            {
                return (this->getDia()>fechaHora->getDia());
            }
            else
            {
                if(this->getHora()!=fechaHora->getHora())
                {
                    return (this->getHora()>fechaHora->getDia());
                }
                else
                {
                     if(this->getMin()!=fechaHora->getMin())
                    {
                        return (this->getHora()>fechaHora->getMin());
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
    }
}

bool DtFechaHora::esIgualQue(DtFechaHora* fechaHora){

    if(this->getAnio()!=fechaHora->getAnio())
    {
        return false;
    }
    else
    {
         if(this->getMes()!=fechaHora->getMes())
        {
            return false;
        }
        else
        {
            if(this->getDia()!=fechaHora->getDia())
            {
                return false;
            }
            else
            {
                if(this->getHora()!=fechaHora->getHora())
                {
                    return false;
                }
                else
                {
                    if(this->getMin()!=fechaHora->getMin())
                    {
                    return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }    
        }
    }
}

 DtFechaHora::~DtFechaHora() {};
