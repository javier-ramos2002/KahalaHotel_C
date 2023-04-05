#include <stdlib.h>
#include <string.h>
#include "reserva.h"
#include <time.h>

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

//Calcula el precio de una resrva teniendo encuenta los dias que el cliente ha estado y el precio de la habitacion mas el minibar
float calcularPrecioReserva(Reserva* reserva) {
    float precioTotal = reserva->habitacion->precio + reserva->minibar->precioTotal;

    struct tm fechaEntrada;
    strptime(reserva->fechaEntrada, "%d/%m/%Y", &fechaEntrada);
    time_t tiempoEntrada = mktime(&fechaEntrada);

    struct tm fechaSalida;
    strptime(reserva->fechaSalida, "%d/%m/%Y", &fechaSalida);
    time_t tiempoSalida = mktime(&fechaSalida);

    double duracion = difftime(tiempoSalida, tiempoEntrada);
    int diasReserva = (int)(duracion / (24 * 3600)) + 1;

    precioTotal *= diasReserva;

    return precioTotal;
}

// Imprime la informacion de una resrva
void imprimirReserva(Reserva* reserva) {
    printf("Reserva #%d\n", reserva->id);
    printf("Cliente: %s %s (DNI: %s)\n", reserva->cliente->nombre, reserva->cliente->apellido, reserva->cliente->dni);
    printf("Fechas: %s - %s\n", reserva->fechaEntrada, reserva->fechaSalida);
    printf("Habitación: #%d\n", reserva->habitacion->nombre);
    printf("Minibar:\n");
    for (int i = 0; i < reserva->minibar->numProductos; i++) {
        printf("%s: %.2f euros\n", reserva->minibar->productos[i]->nombre, reserva->minibar->productos[i]->precio);
    }
    printf("Precio total: %.2f euros\n", calcularPrecioReserva(reserva));
}


