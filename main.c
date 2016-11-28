#include <stdio.h>
#include <string.h>
#include "utilities.h"

int main(void){
	char *login;
	char *senha;

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
		jogar();
	} else{
		criarUsuario(login, senha);

		printf("Olá, %s!\n", login);
		jogar();
	}

	return 0;
}