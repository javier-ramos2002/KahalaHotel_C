#ifndef MINIBAR_H
#define MINIBAR_H

#include "producto.h"

typedef struct {
    Producto** productos;
    int numProductos;
    float precioTotal;
} Minibar;

Minibar* crearMinibar();
void liberarMinibar(Minibar* minibar);
// void anyadirProductoMinibar(Minibar* minibar, Producto* producto);
// void quitarProductoMinibar(Minibar* minibar, int idProducto);
void calcularPrecioTotalMinibar(Minibar* minibar);
void imprimirMinibar(Minibar* minibar);


#endif