#include "Prestamo.h"

Prestamo::Prestamo()
{
    numeroPrestamo = 0;
    montoAprobado = 0;
    saldoPendiente = 0;
    contadorPagos = 0;
}

Prestamo::Prestamo(int nP, Cliente* cl, Fecha* fP, float mA)
{
    numeroPrestamo = nP;
    cliente = cl;
    fechaAprobacion = fP;
    montoAprobado = mA;
    saldoPendiente = mA;
    contadorPagos = 0;
}
int Prestamo::getNumeroPrestamo()
{
    return numeroPrestamo;
}
void Prestamo::setNumeroPrestamo(int numPrest)
{
    numeroPrestamo = numPrest;
}
Cliente* Prestamo::getCliente()
{
    return cliente;
}
void Prestamo::setCliente(Cliente* client)
{
    cliente = client;
}
void Prestamo::setFechaAprobacion(Fecha* fA)
{
    fechaAprobacion = fA;
}
Fecha* Prestamo::getFechaAprobacion()
{
    return fechaAprobacion;
}
void Prestamo::setMontoAprobado(float mA)
{
    montoAprobado = mA;
}
float Prestamo::getMontoAprobado()
{
    return montoAprobado;
}
bool Prestamo::hacerPago(Pago* pag)
{
    bool hecho = false;
    if(contadorPagos < TAM){
        lstPagos[contadorPagos] = pag;
        contadorPagos ++;
        saldoPendiente -= pag->getMontoPago();
        hecho = true;
    }
    return hecho;
}
Pago** Prestamo::getLstPagos()
{
    return lstPagos;
}
float Prestamo::getSaldoPendiente()
{
    return saldoPendiente;
}
int Prestamo::getContadorPagos()
{
    return contadorPagos;
}
