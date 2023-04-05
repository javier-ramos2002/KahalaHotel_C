#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "habitacion.h"
#include "sqlite3.h"

// Crea una nueva habitación
Habitacion* crearHabitacion(char nombre[], int precio, int id, char tipo[]) {
    Habitacion* habitacion = (Habitacion*) malloc(sizeof(Habitacion));
    if (habitacion == NULL) {
        printf("Error: no se pudo crear la habitacion\n");
        return NULL;
    }

    strcpy(habitacion->nombre, nombre);
    habitacion->precio = precio;
    habitacion->id = id;
    strcpy(habitacion->tipo, tipo);

    return habitacion;
}

//Libera la memoria asignada a una habitación
void liberarHabitacion(Habitacion* habitacion) {
    free(habitacion);
}

//Imprime la información de una habitación
void imprimirHabitacion(Habitacion* habitacion) {
    printf("Habitación %d - %s\n", habitacion->id, habitacion->nombre);
    printf("Tipo: %s\n", habitacion->tipo);
    printf("Precio: %d\n", habitacion->precio);
}

//Añade una habitacion en la base de datos
void anyadirHabitacion(Habitacion habitacion) {
    sqlite3 *db;
    char *error_message = 0;
    int result;
    char sql_query[200];
    sprintf(sql_query, "INSERT INTO habitaciones (nombre, precio, id, tipo) VALUES ('%s', %f, %d, '%s')",
            habitacion.nombre, habitacion.precio, habitacion.id, habitacion.tipo);
    result = sqlite3_open("bd.db", &db); 
    if (result != SQLITE_OK) {
        printf("Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    result = sqlite3_exec(db, sql_query, 0, 0, &error_message);
    if (result != SQLITE_OK) {
        printf("Error al insertar una nueva Habitacion: %s\n", error_message);
        sqlite3_free(error_message);
        sqlite3_close(db);
        return;
    }
    sqlite3_close(db);
    printf("Habitacion añadida exitosamente\n");
}

//Elimina una habitacion en la base de datos
void eliminarHabitacion(int id) {
    sqlite3 *db;
    char *error_message = 0;
    int result;
    char sql_query[200];
    sprintf(sql_query, "DELETE FROM habitaciones WHERE id=%d", id);
    result = sqlite3_open("bd.db", &db); 
    if (result != SQLITE_OK) {
        printf("Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    result = sqlite3_exec(db, sql_query, 0, 0, &error_message);
    if (result != SQLITE_OK) {
        printf("Error al eliminar la habitacion: %s\n", error_message);
        sqlite3_free(error_message);
        sqlite3_close(db);
        return;
    }
    sqlite3_close(db);
    printf("Habitacion eliminada exitosamente\n");
}

// Actualiza/modifica la información de una habitación en la tabla
void modificarHabitacion(int id, Habitacion *habitacion) {
    sqlite3 *db;
    int rc = sqlite3_open("bd.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql = "UPDATE habitaciones SET nombre=?, precio=?, tipo=? WHERE id=?;";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, habitacion->nombre, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 2, habitacion->precio);
    sqlite3_bind_text(stmt, 3, habitacion->tipo, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, id);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error de ejecucion %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}



//Optiene el Id de un a Habitacion (para realizar consultas en la BD)
int obtenerID(Habitacion* habitacion){
    return habitacion->id;
}
