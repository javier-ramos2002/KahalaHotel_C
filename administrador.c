#include "administrador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loginAdministrador(char* usuario, char* contrasena) {
    char* admin_username = "admin";
    char* admin_password = "admin";
    
    printf("Ingrese su nombre de usuario: ");
    char input[50];
    fgets(input, 50, stdin);
    sscanf(input, "%s", usuario);
    
    printf("Ingrese su contrasena: ");
    fgets(input, 50, stdin);
    sscanf(input, "%s", contrasena);
    
    if (strcmp(usuario, admin_username) == 0
        && strcmp(contrasena, admin_password) == 0) {
        printf("Inicio de sesion completado\n");
        return 1;
    } else {
        printf("Credenciales invalidas, intentelo de nuevo\n");
        return 0;
    }
}

void mostrarClientes() {
    FILE *file;
    char line[256];

    file = fopen("clientes.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("*****************\nLista de clientes\n*****************\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}