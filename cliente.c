#include"cliente.h"
#include<stdlib.h>
#include <string.h>

void registrarCliente(Cliente **clientes, int *numClientes) {
    printf("Ingrese los datos del cliente:\n");
    Cliente cliente;
    cliente.dni = (char *) malloc(50 * sizeof(char));
    printf("DNI: ");
    char input[256];
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", cliente.dni);

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
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", cliente.nombre);

    cliente.apellido = (char *) malloc(50 * sizeof(char));
    printf("Apellido: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", cliente.apellido);

    printf("Edad: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &cliente.edad);

    printf("Telefono: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &cliente.telefono);

    printf("Numero de tarjeta: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &cliente.numeroTarjeta);

    cliente.contrasena = (char *) malloc(50 * sizeof(char));
    printf("Contrasena: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", cliente.contrasena);

    (*clientes)[*numClientes] = cliente;
    (*numClientes)++;
    printf("Cliente registrado correctamente.\n");

    f = fopen("clientes.txt", "a");
    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(f, "DNI: %s, Nombre: %s, Apellido: %s, Edad: %d, Telefono: %d, Numero de tarjeta: %d, Contrasena: %s\r\n", cliente.dni, cliente.nombre, cliente.apellido, cliente.edad, cliente.telefono, cliente.numeroTarjeta, cliente.contrasena);
    fclose(f);
}

int iniciarSesion(const char *filename) {
    char dni[10], contrasena[50];
    FILE *file;

    printf("Introduzca su DNI: ");
    fgets(dni, sizeof(dni), stdin);
    sscanf(dni, "%9s", dni);

    printf("Introduzca su contrasena: ");
    fgets(contrasena, sizeof(contrasena), stdin);
    sscanf(contrasena, "%49s", contrasena);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char dni_file[10], contrasena_file[50];
        sscanf(line, "DNI: %9[^,], Nombre: %*[^,], Apellido: %*[^,], Edad: %*d, Telefono: %*d, Numero de tarjeta: %*d, Contrasena: %49[^,\n]", dni_file, contrasena_file);

        if (strcmp(dni, dni_file) == 0 && strcmp(contrasena, contrasena_file) == 0) {
            fclose(file);
            printf("Bienvenido %s.\n", dni);
            return 2;
        }
    }

    fclose(file);
    printf("Credenciales invalidas, intentelo de nuevo.\n");
    return 1;
}

void liberarCliente(Cliente *cliente) {
    free(cliente->dni);
    free(cliente->nombre);
    free(cliente->apellido);
    free(cliente->contrasena);
    cliente->edad = 0;
    cliente->telefono = 0;
    cliente->numeroTarjeta = 0;
}
