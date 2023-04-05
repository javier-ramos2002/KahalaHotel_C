#include <stdlib.h>
#include <string.h>
#include "reserva.h"

//Inicializa una reserva
void inicializarReserva(Reserva* reserva, int id, char* fechaEntrada, char* fechaSalida, Cliente* cliente, Habitacion* habitacion, Minibar* minibar) {
    reserva->id = id;

    reserva->fechaEntrada = (char*) malloc(sizeof(char) * (strlen(fechaEntrada) + 1));
    strcpy(reserva->fechaEntrada, fechaEntrada);

    reserva->fechaSalida = (char*) malloc(sizeof(char) * (strlen(fechaSalida) + 1));
    strcpy(reserva->fechaSalida, fechaSalida);
    
    reserva->cliente = cliente;
    reserva->habitacion = habitacion;
    reserva->minibar = minibar;
}

//Libera la memoria asignada a una reserva
void liberarReserva(Reserva* reserva) {
    free((void *) reserva->id);
    free(reserva->fechaEntrada);
    free(reserva->fechaSalida);
    //liberarCliente(reserva->cliente); por hacer
    liberarHabitacion(reserva->habitacion);
    liberarMinibar(reserva->minibar);
    free(reserva);
}
