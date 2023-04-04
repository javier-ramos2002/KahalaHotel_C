#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "habitacion.h"

// Crea una nueva habitación
Habitacion* crear_habitacion(char nombre[], int precio, int id, char tipo[]) {
    Habitacion* habitacion = (Habitacion*) malloc(sizeof(Habitacion));
    if (habitacion == NULL) {
        printf("Error: no se pudo crear la habitacion\n");
        return NULL;
    }

    strcpy(habitacion->nombre, nombre);
    habitacion->precio = precio;
    habitacion->id = id;
    strcpy(habitacion->tipo, tipo);

    return habitacion;
}

//Libera la memoria asignada a una habitación
void liberar_habitacion(Habitacion* habitacion) {
    free(habitacion);
}

//Imprime la información de una habitación
void imprimir_habitacion(Habitacion* habitacion) {
    printf("Habitación %d - %s\n", habitacion->id, habitacion->nombre);
    printf("Tipo: %s\n", habitacion->tipo);
    printf("Precio: %d\n", habitacion->precio);
}