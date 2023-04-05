#include <stdio.h>
#include <stdlib.h>
#include "minibar.h"

#define TAM_INICIAL 10 // define la capacidad inicial de los productos


//Inicializa el minbar
Minibar* crearMinibar() {
    Minibar* minibar = (Minibar*) malloc(sizeof(Minibar));
    if (minibar == NULL) {
        printf("Error: no se ha podido reservar memoria para el minibar.\n");
        return NULL;
    }

    minibar->productos = (Producto**) malloc(sizeof(Producto*) * TAM_INICIAL);
    if (minibar->productos == NULL) {
        printf("Error: no se ha podido reservar memoria para los productos del minibar.\n");
        free(minibar);
        return NULL;
    }

    minibar->numProductos = 0;
    minibar->precioTotal = 0.0;

    return minibar;
}

//Libera la memoria asignada a el minibar
void liberarMinibar(Minibar* minibar) {
    for (int i = 0; i < minibar->numProductos; i++) {
        liberarProducto(minibar->productos[i]);
    }

    free(minibar->productos);
    free(minibar);
}

// // Añade un producto al minibar (y actualiza el precio total y num de productos)
// void anyadirProductoMinibar(Minibar* minibar, Producto* producto) {
//     if (minibar->numProductos % TAM_INICIAL == 0) {
//         minibar->productos = (Producto**) realloc(minibar->productos, sizeof(Producto*) * (minibar->numProductos + TAM_INICIAL));
//         if (minibar->productos == NULL) {
//             printf("Error: no se pudo reservar memoria para los productos del minibar.\n");
//             return;
//         }
//     }

//     minibar->productos[minibar->numProductos++] = producto;
//     minibar->precioTotal += producto->precio;
// }

// //elimina un producto del minibar (e actualiza el precio total)
// void eiminarProductoMinibar(Minibar* minibar, int idProducto) {
//     for (int i = 0; i < minibar->numProductos; i++) {
//         if (minibar->productos[i]->id == idProducto) {
//             liberarProducto(minibar->productos[i]);
//             for (int j = i; j < minibar->numProductos - 1; j++) {
//                 minibar->productos[j] = minibar->productos[j+1];
//             }
//             minibar->numProductos--;
//             minibar->precioTotal -= minibar->productos[i]->precio;
//             break;
//         }
//     }
// }

// Calcula el precio total del minibar
void calcularPrecioTotalMinibar(Minibar* minibar) {
    float precioTotal = 0.0;
    for (int i = 0; i < minibar->numProductos; i++) {
        precioTotal += minibar->productos[i]->precio;
    }
    minibar->precioTotal = precioTotal;
}

//imprime el precio total del minibar y sus productos(con el precio de cada producto)
void imprimirMinibar(Minibar* minibar) {
    printf("Precio: %.2f\n", minibar->precioTotal);
    printf("Precio: %.2f\n", minibar->precioTotal);
    printf("Productos:\n");
    for (int i = 0; i < minibar->numProductos; i++) {
      //  printf("- %s (Precio: %.2f)\n", minibar->productos[i].nombre, minibar->productos[i].precio);
    }
}


