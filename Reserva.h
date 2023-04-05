#ifndef RESERVA_H
#define RESERVA_H

#include "cliente.h"
#include "habitacion.h"
#include "minibar.h"

typedef struct {
    int id;
    char* fechaEntrada;
    char* fechaSalida;
    Cliente* cliente;
    Habitacion* habitacion;
    Minibar* minibar;
} Reserva;

void inicializarReserva(Reserva* reserva, int id, char* fechaEntrada, char* fechaSalida, Cliente* cliente, Habitacion* habitacion, Minibar* minibar);
void liberarReserva(Reserva* reserva);
float calcularPrecioReserva(Reserva* reserva);
void imprimirReserva(Reserva* reserva);

#endif