#include "administrador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loginAdministrador(char* usuario, char* contrasena) {
    char* admin_username = "admin";
    char* admin_password = "admin";
    
    printf("Ingrese su nombre de usuario: ");
    scanf("%s", usuario);
    
    printf("Ingrese su contrasena: ");
    scanf("%s", contrasena);
    
    if (strcmp(usuario, admin_username) == 0
        && strcmp(contrasena, admin_password) == 0) {
        printf("Inicio de sesion completado\n");
        menuAdministrador();
    } else {
        printf("Credenciales invalidas, intentelo de nuevo\n");
        return;
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