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
        printf("Credenciales invalidas, intentalo de nuevo\n");
        return;
    }
}