#include"cliente.h"
#include<stdlib.h>
#include <string.h>

void registrarCliente(Cliente **clientes, int *numClientes) {
    printf("Ingrese los datos del cliente:\n");
    Cliente cliente;
    cliente.dni = (char *) malloc(50 * sizeof(char));
    printf("DNI: ");
    scanf("%s", cliente.dni);

    FILE *f = fopen("clientes.txt", "r");
    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

   char line[256];
    while (fgets(line, sizeof(line), f)) {
        char *posicionComa = strchr(line, ',');
        if (posicionComa != NULL) {
            *posicionComa = '\0';
            if (strcmp(line + 5, cliente.dni) == 0) {
                printf("Ya existe un cliente registrado con ese DNI.\n");
                fclose(f);
                return;
            }
        }
    }


    fclose(f);

    *clientes = (Cliente *) realloc(*clientes, (*numClientes + 1) * sizeof(Cliente));
    
    cliente.nombre = (char *) malloc(50 * sizeof(char));
    printf("Nombre: ");
    scanf("%s", cliente.nombre);
    cliente.apellido = (char *) malloc(50 * sizeof(char));
    printf("Apellido: ");
    scanf("%s", cliente.apellido);
    printf("Edad: ");
    scanf("%d", &cliente.edad);
    printf("Telefono: ");
    scanf("%d", &cliente.telefono);
    printf("Numero de tarjeta: ");
    scanf("%d", &cliente.numeroTarjeta);
    cliente.contrasena = (char *) malloc(50 * sizeof(char));
    printf("Contrasena: ");
    scanf("%s", cliente.contrasena);

    (*clientes)[*numClientes] = cliente;
    (*numClientes)++;
    printf("Cliente registrado correctamente.\n");

    f = fopen("clientes.txt", "a");
    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(f, "DNI: %s, Nombre: %s, Apellido: %s, Edad: %d, Telefono: %d, Numero de tarjeta: %d, Contrasena: %s\n", cliente.dni, cliente.nombre, cliente.apellido, cliente.edad, cliente.telefono, cliente.numeroTarjeta, cliente.contrasena);
    fclose(f);
}