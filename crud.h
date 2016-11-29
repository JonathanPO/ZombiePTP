/*
Arquivo responsável por ser o header do arquivo utilitesBanco.c
Autores: Arthur Cohen e Jonathan Gabriel
*/
#ifndef CRUD_H_
#define CRUD_H_
//#include <mysql.h>
#include "structs.h"

int autenticarUsuario(char *usuario, char *senha);

int adicionarUsuario(char *usuario, char *senha);

Player buscarJogador(char *login);

Building buscarLocal(Building *building);

Enemy buscarZumbi(int idEnemy);

#endif