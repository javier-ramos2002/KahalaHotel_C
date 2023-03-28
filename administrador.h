#ifndef ADMINISTRASOR_H_
#define ADMINISTRASOR_H_

typedef struct{
	char *usuario;
    char *contrasena;
}Administrador;

int loginAdministrador(char *usuario, char *contrasena);
void mostrarClientes();
#endif