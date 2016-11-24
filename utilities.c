/*
Arquivo responsável por definir os métodos de utilidade do programa
Autores: Arthur Cohen e Jonathan Gabriel
*/

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "crud.h"
#include "acoes.h"
#include "structs.h"

// Método responsável por definir se existe um usuário no banco de dados a partir do seu login e senha
int autenticar(char usuario[10], char senha[10]){
	if(buscarUsuario(usuario, senha) = 0){
		return 0;
	} else{
		return 1;
	}
}

// Método responsável por requisitar a criação de um novo usuário no banco de dados
int criarUsuario(char usuario[10], char senha[10]){
	if(criarUsuario(usuario, senha) == 0){
		return 0;
	} else{
		return 1;
	}
}

// Método responsável por manter o estado de jogo e definir as ações possíveis
void jogar(){
	char acao[10] = "inicio";

	while(acao != "sair"){
		printf("Comando:\n")
		scanf("%s", acao);
		printf("\n\n\n");

		//Adicionar as chamadas dos métodos
		if(strcmp(acao, "mover") == 0){
			mover();
		} else if(strcmp(acao, "agir") == 0){
			agir();
		} else if(strcmp(acao, "itens") == 0){
			itens();
		} else{
			printf("Esse comando não existe.");
		}

		ocorrerEvento();
	}
}

char* traduzirItens(int cod){
	switch (cod){
		case 1:
			return "first-aid\0";
			break;

		case 2:
			return "antídoto\0";
			break;

		case 3:
			return "curativo\0";
			break;

		case 4:
			return "comida\0";
			break;
	}
}

void usarItem(Player *player, int cod){
	switch (cod){
		case 1:
			*player.hp = *player.hp + 10;
			break;

		case 2:
			*player.hp = *player.hp + 20;
			break;

		case 3:
			*player.hp = *player.hp + 5;
			break;

		case 4:
			*player.stamina = *player.stamina + 10;
			break;
	}
}

void ocorrerEvento(){
	int codEvento;

	srand(time(NULL));

	codEvento = (rand() % 3) + 1;

	switch (codEvento){
		case 1:
			// Adicionar o evento de aparição de zumbi
			printf("A wild zombie appears!\n");
			lutar();
			break;

		case 2:
			// Adicionar o evento de interação com um NPC
			printf("A wild NPC appears!\n");
			printf("Deseja interagir com ele?\n");
			break;

		case 3:
			// Adicionar o evento de descoberta de item
			printf("A wild item appears!\n");
			break;
	}
}

int gerarZumbi(Player *player){
	int tipoDoZumbi;

	srand(time(NULL));
	if(*player.xp < 100){
		tipoDoZumbi = 1;
	} else if(*player.xp > 100){
		tipoDoZumbi = (rand() % 2) + 1;
	} else if(*player.xp > 200){
		tipoDoZumbi = (rand() % 3) + 1;
	} else if(*player.xp > 300){
		tipoDoZumbi = (rand() % 4) + 1;
	}

	return tipoDoZumbi;
}

int gerarItem(Player *player){
	int tipoDoItem;

	srand(time(NULL));
	if(*player.xp < 100){
		tipoDoItem = 1;
	} else if(*player.xp > 100){
		tipoDoItem = (rand() % 2) + 1;
	} else if(*player.xp > 200){
		tipoDoItem = (rand() % 3) + 1;
	} else if(*player.xp > 300){
		tipoDoItem = (rand() % 4) + 1;
	}

	return tipoDoItem;
}
