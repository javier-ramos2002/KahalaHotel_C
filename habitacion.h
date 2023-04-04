#ifndef HABITACION_H_
#define HABITACION_H_
#include <stdio.h>

typedef struct{
	char id;
    char nombre[50];
    float precio;
    char tipo[20];
}Habitacion;

Habitacion* crearHabitacion(char nombre[], int precio, int id, char tipo[]);
void liberarHabitacion(Habitacion* habitacion);
void imprimirHabitacion(Habitacion* habitacion);
void anyadirHabitacion(Habitacion habitacion);
void modificarHabitacion(int id, Habitacion *habitacion);


#endif