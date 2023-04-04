#include <stdlib.h>
#include <string.h>
#include "producto.h"

Producto* crearProducto(int id, char* nombre, float precio) {
    Producto* producto = malloc(sizeof(Producto));
    producto->id = id;
    strcpy(producto->nombre, nombre);
    producto->precio = precio;
    return producto;
}

void liberarProducto(Producto* producto) {
    free(producto);
}