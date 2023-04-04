#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "producto.h"
#include "sqlite3.h"



// crea un nuevo producto
Producto* crearProducto(int id, char* nombre, float precio) {
    Producto* producto = malloc(sizeof(Producto));
    producto->id = id;
    strcpy(producto->nombre, nombre);
    producto->precio = precio;
    return producto;
}
//Libera la memoria asignada a un producto
void liberarProducto(Producto* producto) {
    free(producto);
}

//Imprime por pantalla el producto
void imprimirProducto(Producto* producto) {
    printf("ID: %d\n", producto->id);
    printf("Nombre: %s\n", producto->nombre);
    printf("Precio: %.2f\n", producto->precio);
}

//Añade un producto en la base de datos
void anyadirProducto(Producto producto) {
    sqlite3 *db;
    char *err_msg = NULL;
    char *sql = NULL;

    int rc = sqlite3_open("bd.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    asprintf(&sql, "INSERT INTO productos (id, nombre, precio) VALUES (%d, '%s', %f);",
             producto.id, producto.nombre, producto.precio);


    rc = sqlite3_exec(db, sql, NULL, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al insertar el producto: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        exit(1);
    }

    sqlite3_free(sql);
    sqlite3_close(db);
}
