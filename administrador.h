#ifndef ADMINISTRASOR_H_
#define ADMINISTRASOR_H_

typedef struct{
	char *usuario;
    char *contrasena;
}Administrador;

void loginAdministrador(char *usuario, char *contrasena);
void mostrarCliente();
#endif