/*
Arquivo responsável por definir os métodos de utilidade do programa
Autores: Arthur Cohen e Jonathan Gabriel
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "utilities.h"
#include "crud.h"
#include "acoes.h"
#include "structs.h"

// Método responsável por definir se existe um usuário no banco de dados a partir do seu login e senha
int autenticar(char *usuario, char *senha){
	if(autenticarUsuario(usuario, senha) == 0){
		return 0;
	} else{
		return 1;
	}
}

// Método responsável por requisitar a criação de um novo usuário no banco de dados
int criarUsuario(char *usuario, char *senha){
	if(criarUsuario(usuario, senha) == 0){
		return 0;
	} else{
		return 1;
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
			(*player).hp += 10;
			break;

		case 2:
			(*player).hp += 20;
			break;

		case 3:
			(*player).hp += 5;
			break;

		case 4:
			(*player).stamina += 10;
			break;
	}
}

void ocorrerEvento(Player *player){
	int codEvento, tipoDoItem;
	char *acao;

	srand(time(NULL));

	codEvento = (rand() % 4) + 1;

	switch (codEvento){
		case 1:
			printf("A wild zombie appears!\n");
			lutar(player);
			break;

		case 2:
			printf("A wild NPC appears!\n");
			printf("Deseja interagir com ele? (sim ou nao)\n");
			if(strcmp(acao, "sim") == 0){
				char *npc = gerarNPC(player);
				agir(player, npc);
			} else if(strcmp(acao, "nao") == 0){
				printf("O NPC foi embora!\n");
			}

			break;

		case 3:
			printf("A wild item appears!\n");
			gerarItem(player);
			break;

	}
}

int gerarZumbi(Player *player){
	int tipoDoZumbi;

	srand(time(NULL));
	if((*player).xp < 100){
		tipoDoZumbi = 1;
	} else if((*player).xp > 100){
		tipoDoZumbi = (rand() % 2) + 1;
	} else if((*player).xp > 200){
		tipoDoZumbi = (rand() % 3) + 1;
	} else if((*player).xp > 300){
		tipoDoZumbi = (rand() % 4) + 1;
	}

	switch(tipoDoZumbi){
		case 1:
			printf("Você foi atacado por um zumbi comum!\n");
		case 2:
			printf("Você foi atacado por um zumbi protegido!\n");
		case 3:
			printf("Você foi atacado por um cachorro zumbi!\n");
		case 4:
			printf("Você foi atacado por um zumbi tank!\n");
	}

	return tipoDoZumbi;
}

void gerarItem(Player *player){
	int i=0, tipoDoItem;
	int bagLength = (int) sizeof((*player).bag) / sizeof((*player).bag[0]);

	srand(time(NULL));
	if((*player).xp < 100){
		tipoDoItem = 1;
	} else if((*player).xp > 100){
		tipoDoItem = (rand() % 2) + 1;
	} else if((*player).xp > 200){
		tipoDoItem = (rand() % 3) + 1;
	} else if((*player).xp > 300){
		tipoDoItem = (rand() % 4) + 1;
	}

	for(i=0; i < bagLength; i++){
		if((*player).bag[i] == 0){
				(*player).bag[i] == tipoDoItem;
				i = bagLength;
		}
	}

}

char* gerarNPC(Player *player){
	char *tipoDoNPC;

	srand(time(NULL));
	if((*player).xp < 100){
		tipoDoNPC = "Viajante\0";
	} else if((*player).xp > 100){
		tipoDoNPC = "Comerciante\0";
	}

	return tipoDoNPC;
}

int randomizarAcao(){
	srand(time(NULL));

	return ((rand() % 10) + 1); 
}

// Método responsável por manter o estado de jogo e definir as ações possíveis
void jogar(char *login){
	char *acao = "inicio\0";

	Player player = buscarJogador(login);
	player.stamina = 20;

	while(acao != "sair"){
		printf("Comando:\n");
		scanf("%s", acao);
		printf("\n\n\n");

		if(strcmp(acao, "mover") == 0){
			mover(&player);
		} else if(strcmp(acao, "itens") == 0){
			itens(&player);
		} else{
			printf("Esse comando não existe.");
		}

		ocorrerEvento(&player);
	}

	player.stamina += 5;
}
