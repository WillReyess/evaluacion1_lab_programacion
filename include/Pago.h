#ifndef PAGO_H
#define PAGO_H
#include "Fecha.h"

class Pago
{
    public:
        Pago(Fecha*, float);
        Fecha* getFechaPago();
        float getMontoPago();
        virtual ~Pago();

    protected:

    private:
        Fecha *fechaPago;
        float montoPago;
};

#endif // PAGO_H
