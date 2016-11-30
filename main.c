/*
Arquivo principal do jogo
Autores: Arthur Cohen e Jonathan Gabriel
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utilities.h"

int main(void){
	char *login = malloc(sizeof(char) * 128);
	char *senha = malloc(sizeof(char) * 128);

	printf("Bem vindo ao Zombie Text!\n\n\n");
	printf("---------------------------------\n");
	printf("Digite o seu login:\n");
	scanf("%s", login);
	printf("\n");
	printf("Digite sua senha:\n");
	scanf("%s", senha);
	printf("\n");

	if(autenticar(login, senha) == 0){
		printf("Olá, %s!\n", login);
		jogar(login);
	} else{
		criarUsuario(login, senha);

		printf("Olá, %s!\n", login);
		jogar(login);
	}

	return 0;
}