#include "bd.h"
#include <stdio.h>
#include <string.h>

sqlite3 *db;
sqlite3_stmt *stmt;
int init_database() {
	int result;
	char sql[100];
	char dni[10];
	int edad,telefono,numeroTarjeta;
	char nom[20],ape[20],con[20];

	result = sqlite3_open("bd.db", &db);
	if (result != SQLITE_OK) {
		printf("Error al abrir la BBDD\n");
		return result;
	}

	sprintf(sql, "create table if not exists Cliente(dni varchar2(10), nombre varchar2(20), apellido varchar2(20), edad int, telefono int, numeroTarjeta int, contrasena varchar2(20))");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

    sprintf(sql, "INSERT INTO Cliente(dni, nombre, apellido, edad, telefono, numeroTarjeta, contrasena) VALUES ('%s', '%s', '%s', %d, %d, %d, '%s')", dni, nom, ape, edad, telefono, numeroTarjeta, con);
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    result = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

   	sprintf(sql, "SELECT * FROM Cliente");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("%s|", sqlite3_column_text(stmt, 0));
        printf("%s|", sqlite3_column_text(stmt, 1));
        printf("%s|", sqlite3_column_text(stmt, 2));
        printf("%d|", sqlite3_column_int(stmt, 3));
        printf("%d|", sqlite3_column_int(stmt, 4));
        printf("%d|", sqlite3_column_int(stmt, 5));
        printf("%s\n", sqlite3_column_text(stmt, 6));
    }

    sqlite3_finalize(stmt);

	sprintf(sql, "delete from Cliente where dni = ?");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    return SQLITE_OK;
	
}

int close_database() {
    sqlite3_close(db);
    return 0;
}