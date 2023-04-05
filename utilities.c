#include "utilities.h"
#include "cliente.h"
#include "administrador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd.h"
void menuPrincipal() {
    init_database();
    char input[50];
    int opcion;
    do {
        printf("************\nKAHALA HOTEL\n************\n");
        printf("1. Acceder como cliente\n");
        printf("2. Acceder como administrador\n");
        printf("3. Salir del programa\n");
        printf("Ingrese una opcion: ");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &opcion);

        switch (opcion) {
            int numClientes;
            Cliente *clientes;
            case 1:
                printf("Accediendo como cliente...\n");
                menuCliente();
                break;
            case 2:
                printf("Accediendo como administrador...\n");
                if(menuAdministradorLogin()){
                    menuAdministrador();
                }
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
    close_database();
}

void menuCliente() {
    char input[50];
    int opcion;
    do {
        printf("***************************\nMenu de acceso como cliente\n***************************\n");
        printf("1. Registrarse\n");
        printf("2. Iniciar sesion\n");
        printf("3. Configurar mi perfil\n");
        printf("4. Volver al menu principal\n");
        printf("Ingrese una opcion: ");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &opcion);

        switch (opcion) {
            int numClientes;
            Cliente *clientes;
            case 1:
                numClientes = 0;
                clientes = NULL;
                registrarCliente(&clientes, &numClientes);
                break;
            case 2:
                if(iniciarSesion("clientes.txt")==2)
                    menuReserva();
                break;
            case 3:
                printf("Configurando mi perfil...\n");
                break;
            case 4:
                printf("Volviendo al menu principal...\n");
                break;
            default:
                printf("Opcion invalida, intentelo de nuevo\n");
                break;
        }
    } while (opcion != 4);
}


int menuAdministradorLogin(){
    char input[50];
    int opcion,a;
    char usuario[50];
    char contrasena[50];
    
    do {
        printf("*********************************\nMenu de acceso como administrador\n*********************************\n");
        printf("1. Iniciar sesion\n");
        printf("2. Volver al menu principal\n");
        printf("Ingrese una opcion: ");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &opcion);

        switch (opcion) {
            case 1:
                a=loginAdministrador(usuario, contrasena);
                break;
            case 2:
                printf("Volviendo al menu principal...\n");
                break;
            default:
                printf("Opcion invalida, intentelo de nuevo\n");
                break;
        }
    } while (opcion != 2);
    return a;
}

void menuReserva(){
    char input[50];
    int opcion;
    do {
        printf("*******\nReserva\n*******\n");
        printf("1. Hacer reserva\n");
        printf("2. Ver mis reservas\n");
        printf("3. Volver al menu principal\n");
        printf("Ingrese una opcion: ");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Haciendo reserva...\n");
                break;
            case 2:
                printf("Accediendo a mis reservas...\n");
                break;
            case 3:
                printf("Volviendo al menu principal...\n");
                break;
            default:
                printf("Opcion invalida, intentelo de nuevo\n");
                break;
        }
    } while (opcion != 3);
}

void menuAdministrador(){
    char input[50];
    int opcion;
    do {
        printf("\n*************\nAdministrador\n*************\n");
        printf("1. Ver lista de clientes\n");
        printf("2. Volver al menu principal\n");
        printf("Ingrese una opcion: ");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarClientes();
                break;
            case 2:
                printf("Volviendo al menu principal...\n");
                break;
            default:
                printf("Opcion invalida, intentelo de nuevo\n");
                break;
        }
    } while (opcion != 2);
}