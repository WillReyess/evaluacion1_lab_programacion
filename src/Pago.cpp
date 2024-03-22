#include "Pago.h"

Pago::Pago(Fecha* fP, float mP)
{
    fechaPago = fP;
    montoPago = mP;
}

Pago::~Pago()
{
    //dtor
}
Fecha* Pago::getFechaPago()
{
    return fechaPago;
}
float Pago::getMontoPago()
{
    return montoPago;
}
