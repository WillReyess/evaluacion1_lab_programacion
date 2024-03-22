#include "Cliente.h"

Cliente::Cliente(int iC, string n, string a)
{
    idCliente = iC;
    nombre = n;
    apellido = a;
}

Cliente::~Cliente()
{
    //dtor
}
int Cliente::getIdCliente()
{
    return idCliente;
}
string Cliente::getNombre()
{
    return nombre;
}
string Cliente::getApellido()
{
    return apellido;
}
