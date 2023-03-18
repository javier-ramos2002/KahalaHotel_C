#include "utilities.h"
#include <stdio.h>
#include<stdlib.h>

int menuPrincipal() {
    int opcion;
    do {
        printf("Bienvenido al programa\n");
        printf("1. Acceder como cliente\n");
        printf("2. Acceder como administrador\n");
        printf("3. Salir del programa\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Accediendo como cliente...\n");
                menuCliente();
                break;
            case 2:
                printf("Accediendo como administrador...\n");
                menuAdministrador();
                break;
            case 3:
                printf("Saliendo...\n");
                exit(0);
            default:
                printf("Opcion invalida, intentelo de nuevo\n");
                break;
        }
    } while (opcion != 3);
    return opcion;
}

int menuCliente() {
    int opcion;
    do {
        printf("Menu de acceso como cliente\n");
        printf("1. Registrarse\n");
        printf("2. Iniciar sesion\n");
        printf("3. Volver al menu principal\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Registrando nueva cuenta...\n");
                break;
            case 2:
                printf("Iniciando sesion...\n");
                break;
            case 3:
                printf("Volviendo al menu principal...\n");
                menuPrincipal();
                break;
            default:
                printf("Opcion invalida, intentelo de nuevo\n");
                break;
        }
    } while (opcion != 3);
    return opcion;
}


int menuAdministrador(){
int opcion;
    do {
        printf("Menu de acceso como administrador\n");
        printf("1. Iniciar sesion\n");
        printf("2. Volver al menu principal\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Iniciando sesion...\n");
                break;
            case 2:
                printf("Volviendo al menu principal...\n");
                menuPrincipal();
                break;
            default:
                printf("Opcion invalida, intentelo de nuevo\n");
                break;
        }
    } while (opcion != 2);
    return opcion;
}
