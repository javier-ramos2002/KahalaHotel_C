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
	
}

int close_database() {
    sqlite3_close(db);
    return 0;
}