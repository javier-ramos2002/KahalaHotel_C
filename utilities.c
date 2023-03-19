#include "utilities.h"
#include "cliente.c"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int menuPrincipal() {
    int opcion;
    do {
        printf("************\nKAHALA HOTEL\n************\n");
        printf("1. Acceder como cliente\n");
        printf("2. Acceder como administrador\n");
        printf("3. Salir del programa\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            int numClientes;
            Cliente *clientes;
            case 1:
                printf("Accediendo como cliente...\n");
                menuCliente();
                break;
            case 2:
                printf("Accediendo como administrador...\n");
                menuAdministrador();
                break;
            case 3:
                numClientes = 0;
                clientes = NULL;
                printf("Saliendo...\n");
                 for (int i = 0; i < numClientes; i++) {
                    free(clientes[i].dni);
                    free(clientes[i].nombre);
                    free(clientes[i].apellido);
                    free(clientes[i].contrasena);
                }
                free(clientes);
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
        printf("***************************\nMenu de acceso como cliente\n***************************\n");
        printf("1. Registrarse\n");
        printf("2. Iniciar sesion\n");
        printf("3. Configurar mi perfil\n");
        printf("4. Volver al menu principal\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            int numClientes;
            Cliente *clientes;
            case 1:
                numClientes = 0;
                clientes = NULL;
                registrarCliente(&clientes, &numClientes);
                break;
            case 2:
                printf("Iniciando sesion...\n");
                break;
            case 3:
                printf("Configurando mi perfil...\n");
                break;
            case 4:
                printf("Volviendo al menu principal...\n");
                menuPrincipal();
                break;
            default:
                printf("Opcion invalida, intentelo de nuevo\n");
                break;
        }
    } while (opcion != 4);
    return opcion;
}


int menuAdministrador(){
int opcion;
    do {
        printf("*********************************\nMenu de acceso como administrador\n*********************************\n");
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

int menuReserva(){
int opcion;
    do {
        printf("*******\nReserva\n*******\n");
        printf("1. Hacer reserva\n");
        printf("2. Ver mis reservas\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Haciendo reserva...\n");
                break;
            case 2:
                printf("Accediendo a mis reservas...\n");
                break;
            default:
                printf("Opcion invalida, intentelo de nuevo\n");
                break;
        }
    } while (opcion != 2);
    return opcion;
}