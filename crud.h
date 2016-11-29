/*
Arquivo responsável por ser o header do arquivo crud.c
Autores: Arthur Cohen e Jonathan Gabriel
*/
#ifndef CRUD_H_
#define CRUD_H_
#include <mysql/mysql.h>
#include "structs.h"

MYSQL conectar();

void fecharConexao(MYSQL *conexao);

int autenticarUsuario(char *usuario, char *senha);

int adicionarUsuario(char *usuario, char *senha);

Player buscarJogador(char *login);

Building buscarLocal(int location);

Enemy buscarZumbi(int idEnemy);

void salvarJogo(Player *player, Building *building, Enemy *enemy){

}

#endif