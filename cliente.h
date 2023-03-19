#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>

typedef struct{
	char *dni;
    char *nombre;
    char *apellido;
    int edad;
    int telefono;
    int numeroTarjeta;
    char *contrasena;
}Cliente;

void registrarCliente(Cliente **clientes, int *numClientes);

#endif