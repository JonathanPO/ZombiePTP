/*
Arquivo responsável por definir os métodos que acessam o banco de dados 
Autores: Arthur Cohen e Jonathan Gabriel
*/

#include <string.h>
#include <mysql.h>
#include "crud.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Método responsável por fazer uma conexão com o banco de dados
MYSQL conectar(){
	MYSQL conexao;

	mysql_init(&conexao);

	if(mysql_real_connect(&conexao, "localhost", "root", "root", "zumbi", 0, NULL, 0)){
		return conexao;
	} else{
		printf("Conexão com o banco falhou");

		return conexao;
	}
}

// Método responsável por fechar uma conexão existente
void fecharConexao(MYSQL *conexao){
	mysql_close(conexao);
}

// Método responsável por buscar um usuário no banco de dados
int autenticarUsuario(char *usuario, char *senha){
	MYSQL conexao = conectar();
	MYSQL_RES *resp;
	MYSQL_ROW rows;
	char *query = malloc(sizeof(char) * 128);
	int i=0, rtn=1;

	sprintf(query, "SELECT password FROM player WHERE name='%s';", usuario);

	mysql_query(&conexao, query);
	resp = mysql_store_result(&conexao);

	while((rows = mysql_fetch_row(resp) != NULL)){
		if(strcmp(rows[0], senha) == 0){
			rtn = 0;
		}
	}

	fecharConexao(&conexao);

	return rtn;
}

// Método responsável por adicionar um usuário na base de dados
int adicionarUsuario(char *usuario, char *senha){
	MYSQL conexao = conectar();
	char *query = malloc(sizeof(char) * 128);

	sprintf(query, "INSERT INTO player(name, password, hp, xp) VALUES ('%s', '%s', 200, 50);", usuario, senha);

	mysql_query(&conexao, query);

	fecharConexao(&conexao);

	return 0;
}

Player buscarJogador(char *login){
	MYSQL conexao = conectar();
	Player player;
	MYSQL_RES *resp;
	MYSQL_ROW rows;
	char *query = malloc(sizeof(char) * 128);

	sprintf(query, "SELECT * FROM player WHERE name='%s';", login);

	mysql_query(&conexao, query);
	resp = mysql_store_result(&conexao);

	while((rows = mysql_fetch_row(resp) != NULL)){
		player.idPlayer = atoi(rows[0]);
		player.name = rows[1];
		player.password = rows[2];
		player.hp = atoi(rows[3]);
		player.xp = atoi(rows[4]);
	}

	fecharConexao(&conexao);

	return player;
}

Building buscarLocal(int location){
	MYSQL conexao = conectar();
	Building building;
	MYSQL_RES *resp;
	MYSQL_ROW rows;
	char *query = malloc(sizeof(char) * 128);

	sprintf(query, "SELECT * FROM building WHERE location = '%i';", location);

	mysql_query(&conexao, query);
	resp = mysql_store_result(&conexao);

	while((rows = mysql_fetch_row(resp) != NULL)){
		building.idBuild = atoi(rows[0]);
		building.name = rows[1];
		building.location = atoi(rows[2]);
		building.size = atoi(rows[3]);
		building.theft = atoi(rows[4]);
		building.description = rows[5];
	}

	fecharConexao(&conexao);

	return building;
}

Enemy buscarZumbi(int idEnemy){
	MYSQL conexao = conectar();
	Enemy enemy;
	MYSQL_RES *resp;
	MYSQL_ROW rows;
	char *query = malloc(sizeof(char) * 128);

	sprintf(query, "SELECT * FROM enemy WHERE idEnemy = '%i';", idEnemy);

	mysql_query(&conexao, query);
	resp = mysql_store_result(&conexao);

	while((rows = mysql_fetch_row(resp) != NULL)){
		enemy.idEnemy = atoi(rows[0]);
		enemy.name = rows[1];
		enemy.hp = atoi(rows[2]);
		enemy.xpGain = atoi(rows[3]);
	}

	fecharConexao(&conexao);

	return enemy;
}

void salvarJogo(Player *player, Building *building, Enemy *enemy){

}
