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
int autenticar(char *usuario, char *senha){
	if(buscarUsuario(usuario, senha) = 0){
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

// Método responsável por manter o estado de jogo e definir as ações possíveis
void jogar(char *login){
	char acao[10] = "inicio";

	Player player = buscarJogador(login);

	while(acao != "sair"){
		printf("Comando:\n")
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

	*player.stamina += 10;
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

void ocorrerEvento(Player *player){
	int codEvento, tipoDoItem;
	char acao[4];

	srand(time(NULL));

	codEvento = (rand() % 4) + 1;

	switch (codEvento){
		case 1:
			printf("A wild zombie appears!\n");
			lutar(player);
			break;

		case 2:
			printf("A wild NPC appears!\n");
			printf("Deseja interagir com ele? (sim ou não)\n");
			if(strcmp(acao, "sim") == 0){
				char *npc = gerarNPC(player);
				agir(player, npc);
			} else if(strcmp(acao, "nao") == 0){
				printf("O NPC foi embora\n");
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

void gerarItem(Player *player){
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

	for(i=0; i < *player.bag.size(); i++){
		if(*player.bag[i] == 0){
				*player.bag[i] == tipoDoItem;
				i = *player.bag.size();
		}
	}

}

char* gerarNPC(Player *player){
	char *tipoDoNPC;

	srand(time(NULL));
	if(*player.xp < 100){
		tipoDoNPC = "Viajante";
	} else if(*player.xp > 100){
		tipoDoNPC = "Comerciante";
	}

	return tipoDoNPC;
}
