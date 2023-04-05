#ifndef PRODUCTO_H
#define PRODUCTO_H

typedef struct {
    int id;
    char nombre[50];
    float precio;
} Producto;

Producto* crearProducto(int id, char* nombre, float precio);
void liberarProducto(Producto* producto);
void imprimirProducto(Producto* producto);
void anyadirProducto(Producto producto);
void eliminarProducto(int id);
int modificarProducto(int id, Producto producto);
int obtenerID(Producto* producto);

#endif // PRODUCTO_H