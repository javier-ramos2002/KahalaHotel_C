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


