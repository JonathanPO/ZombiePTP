/*
Arquivo responsável por definir os métodos que acessam o banco de dados 
Autores: Arthur Cohen e Jonathan Gabriel
*/

#include <string.h>
//#include <mysql.h>
#include "crud.h"
#include "structs.h"

// Método responsável por buscar um usuário no banco de dados
int autenticarUsuario(char *usuario, char *senha){
	return 0;
}

// Método responsável por adicionar um usuário na base de dados
int adicionarUsuario(char *usuario, char *senha){
	return 0;
}

Player buscarJogador(char *login){
	Player player;

	return player;
}

Building buscarLocal(int location){
	Building building;

	return building;
}

Enemy buscarZumbi(int idEnemy){
	Enemy enemy;

	return enemy;
}
