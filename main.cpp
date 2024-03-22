#include <iostream>
#include "Prestamo.h"
#include <string>
#define MAXIMO 3
#include <stdlib.h>

using namespace std;
int menu()
{
    int opc;
    cout <<"1. Agregar clientes a la lista" <<endl;
    cout <<"2. Agregar prestamo a la lista" <<endl;
    cout <<"3. Hacer pagos de pr�stamos" <<endl;
    cout <<"4. Mostrar lista de clientes" <<endl;
    cout <<"5. Mostrar lista de prestamos" <<endl;
    cout <<"6. Mostrar detalles del prestamo" <<endl;
    cout <<"7. Salir" <<endl;
    cout <<"Digite la opcion: ";
    cin >> opc;
    return opc;
}
Cliente *agregarCliente()
{
    int id;
    string nombre;
    string apellido;
    Cliente *cli = NULL;
    cout <<"INFORMACION DE CLIENTE" <<endl;
    cout <<"Digite el id: ";
    cin >> id;
    cout <<"Digite el nombre: ";
    cin >> nombre;
    cout <<"Digite el apellido: ";
    cin >> apellido;
    cli = new Cliente(id, nombre, apellido);
    return cli;
}
Cliente *buscarCliente(int contCliente, Cliente *lstCliente[], int idCliente)
{
    Cliente *cli = NULL;
    for(int i = 0; i < contCliente; i++){
        if(lstCliente[i]->getIdCliente() == idCliente){
            cli = lstCliente[i];
        }
    }
    return cli;
}
Prestamo *agregarPrestamo(Cliente *cli)
{
    float montoAprobado;
    int dia, mes, anio, idPrestamo;
    Fecha *fe = NULL;
    Prestamo *prest = NULL;
    ///solicitud de datos
    cout <<"Digite el id del prestamo: ";
    cin >> idPrestamo;
    cout <<"Digite la fecha de aprobacion (dd/mm/aa)" <<endl;
    cin >> dia;
    cin >> mes;
    cin >> anio;

    ///si lo es se crea un objeto tipo fecha
    fe = new Fecha(dia, mes, anio);
    cout <<"Digite el monto aprobado: ";
    cin >> montoAprobado;

    //se crea un nuevo objeto tipo prestamo
    prest = new Prestamo(idPrestamo, cli, fe, montoAprobado);

    ///se retorna el objeto prest
    return prest;
}
Prestamo *buscarPrestamo(int contPrestamo, Prestamo *lstPrestamo[], int idPrestamo)
{
    Prestamo *prest = NULL;
    for(int i = 0; i < contPrestamo; i++){
        if(lstPrestamo[i]->getNumeroPrestamo() == idPrestamo){
            prest = lstPrestamo[i];
        }
    }

    return prest;
}
void agregarPago(Prestamo *prest)
{
    int dia, mes, anio;
    float monto;
    Pago *pag;
    Fecha *fe;

    ///se solicitan los datos
    cout <<"Digite la fecha del pago en formato dd//mm/aa" <<endl;
    cin >> dia;
    cin >> mes;
    cin >> anio;
    cout <<"Digite el monto del pago: ";
    cin >> monto;

    ///se crea un objeto tipo fecha con la fecha del pago
    fe = new Fecha(dia, mes, anio);

    ///se crea un objeto tipo pago
    pag = new Pago(fe, monto);

    prest->hacerPago(pag);
}
void mostrarClientes(int contCliente, Cliente *lstCliente[])
{
    if(contCliente == 0){
        cout <<"La lista esta vacia" <<endl;
    }else{
        cout <<"ID\tNombre\tApellido" <<endl;
        for(int i = 0; i < contCliente; i++){
            cout <<lstCliente[i]->getIdCliente() <<"\t";
            cout <<lstCliente[i]->getNombre() <<"\t";
            cout <<lstCliente[i]->getApellido() <<endl;
        }
    }
}
void mostrarPrestamos(int contPrestamo, Prestamo *lstPrestamo[]) {
    if (contPrestamo == 0) {
        cout << "La lista de prestamos esta vacia" << endl;
    } else {
        cout << "No prestamo\tCliente\t\tFecha de aprobacion\tMonto aprobado\tSaldo pendiente" << endl;
        for (int i = 0; i < contPrestamo; i++) {
            cout << lstPrestamo[i]->getNumeroPrestamo() << "\t\t";
            cout << lstPrestamo[i]->getCliente()->getNombre() << " ";
            cout << lstPrestamo[i]->getCliente()->getApellido() << "\t";
            lstPrestamo[i]->getFechaAprobacion()->mostrarFecha();
            cout << "\t\t" << lstPrestamo[i]->getMontoAprobado() << "\t\t";
            cout << lstPrestamo[i]->getSaldoPendiente() << endl;
        }
    }
}


void mostrarDetalle(Prestamo *prest)
{
    cout <<"Numero del prestamo: " <<prest->getNumeroPrestamo() <<endl;
    cout <<"Cliente: " <<prest->getCliente()->getNombre() <<" " <<prest->getCliente()->getApellido() <<endl;
    cout <<"FECHA DE APROBACION" <<endl;
    prest->getFechaAprobacion()->mostrarFecha();
    cout <<"\n" <<"Monto aprobado: " <<prest->getMontoAprobado() <<endl;

    ///se recorre el arreglo para buscar los pagos realizados
    if(prest->getContadorPagos() == 0){
        cout <<"No tiene pagos registrados" <<endl;
    }else{
        cout <<"LISTAS DE PAGO" <<endl;
        Pago **lista = prest->getLstPagos();
        cout <<"No\tFecha\t\tMonto pagado" <<endl;
        for(int i=0; i < prest->getContadorPagos(); i++){
            cout <<(i+1) <<"\t";
            lista[i]->getFechaPago()->mostrarFecha();
            cout <<"\t" <<lista[i]->getMontoPago() <<endl;
        }
    }
}
int main()
{
    int opc;
    Cliente *lstCliente[MAXIMO];
    Cliente *cli = NULL;
    Prestamo *lstPrestamo[MAXIMO];
    Prestamo *pres = NULL;
    int contClientes = 0, contPrestamo = 0, idClietne, idPrestamo;
    do{
        system("cls");
        opc = menu();
        switch(opc){
            case 1:
                ///agregar cliente
                if(contClientes < MAXIMO){
                    lstCliente[contClientes] = agregarCliente();
                    contClientes ++;
                    cout <<"El cliente se agrego con exito" <<endl;
                }else{
                    cout <<"La lista esta llena" <<endl;
                }
                break;
            case 2:
                ///agregar prestamo
                if(contPrestamo < MAXIMO){
                    cout <<"Digite el id del cliente: ";
                    cin >> idClietne;
                    cli = buscarCliente(contClientes, lstCliente, idClietne);
                    if(cli){
                        lstPrestamo[contPrestamo] = agregarPrestamo(cli);
                        contPrestamo ++;
                        cout <<"El prestamo fue registrado con exito" <<endl;
                    }
                    else{
                        cout <<"El cliente no existe no se puede agregar" <<endl;
                    }
                }
                else{
                    cout <<"La lista esta llena" <<endl;
                }
                break;
            case 3:
                ///Hacer pagos de prestamos
                cout <<"Digite el id del prestamo: ";
                cin >> idPrestamo;
                pres = buscarPrestamo(contPrestamo, lstPrestamo, idPrestamo);
                if(pres){
                    agregarPago(pres);
                    cout <<"El pago ha sido registrado" <<endl;
                }
                else{
                    cout <<"EL prestamo no existe, no se puede registrar" <<endl;
                }
                break;
            case 4:
                ///Mostrar lista de clientes
                mostrarClientes(contClientes, lstCliente);
                break;
            case 5:
                ///Mostrar lista de prestamos
                mostrarPrestamos(contPrestamo, lstPrestamo);
                break;
            case 6:
                ///Mostrar detalles del prestamo
                cout <<"Digite el id del prestamo" <<endl;
                cin >> idPrestamo;

                pres = buscarPrestamo(contPrestamo, lstPrestamo, idPrestamo);
                if(pres){
                    mostrarDetalle(pres);
                }
                else{
                    cout <<"El prestamo no existe, no se puede mostrar los detalles" <<endl;
                }
                break;
            case 7:
                ///salir
                cout <<"saliendo del programa" <<endl;
                break;
            default:
                cout <<"Opcion no valida" <<endl;
                break;
        }

        system("pause");
    }while(opc != 7);

    return 0;
}
