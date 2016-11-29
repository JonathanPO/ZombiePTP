/*
Arquivo responsável por implementar os métodos do header acoes.h
Autores: Arthur Cohen e Jonathan Gabriel
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "acoes.h"
#include "structs.h"
#include "crud.h"
#include "utilities.h"

// Método responsável por realizar a ação de mover o personagem para um building
void mover(Player *player){
	int location;
	Building building; 

	printf("Para onde deseja se mover?\n");
	scanf("%i", &location);
	printf("\n");

	building.location = location;

	building = buscarLocal(location);

	(*player).stamina -= building.size;

	printf("Você chegou na localidade %i\n", building.location);
	printf("%s\n", building.description);

}

// Método responsável por realizar a ação de permitir o personagem interagir com um NPC
void agir(Player *player, char *npc){
	int i = 0, j = 0, cod = -1;
	int tempBag[20];
	int bagLength = (int) sizeof((*player).bag) / sizeof((*player).bag[0]);
	int tempBagLength = (int) sizeof(tempBag) / sizeof(tempBag[0]);

	if(strcmp(npc, "vendedor") == 0){
		printf("---------------------------Bem vindo à loja---------------------------\n");

		/*for(i=0; i < tamanhoArray(*npc.bag); i++){
			printf("%i - %s \n", i+1, traduzirItens(*npc.bag(i)));
		}*/
		i = 0;

		while(cod != 0){
			printf("Digite o número do item que deseja (digite 0 para sair):\n")/
			scanf("%i", &cod);
			printf("\n");

			if(cod > 0 && cod < 5){
				tempBag[i] = cod;
				i++;
			} else if(cod == 0){
				printf("Obrigado pela compra!\n");
			} else{
				printf("Item inexistente na loja\n");
			}
		}

		i=0;

		for(i=0; i < bagLength; i++){
			if((*player).bag[i] == 0){
				if(j < tempBagLength){
					(*player).bag[i] == tempBag[j];
					j++;
				}
			}
		}

	} else if(strcmp(npc, "evento") == 0){
		for(i=0; i < bagLength; i++){
			if((*player).bag[i] == 0){
				if(j < tempBagLength){
					(*player).bag[i] == tempBag[j];
					j++;
				}
			}
		}
	}
	
}

// Método responsável por realizar a ação de mostrar os itens que o personagem possui
void itens(Player *player){
	int i = 0, cod = 0;
	int bagLength = (int) sizeof((*player).bag) / sizeof((*player).bag[0]);

	printf("-----------------------Itens-----------------------\n");

	for(i=0; i < bagLength; i++){
			printf("%i - %s \n", i+1, traduzirItens((*player).bag[i]));
	}

	while(cod != 0){
			printf("Digite o número do item que usar (digite 0 para sair):\n")/
			scanf("%i", &cod);
			printf("\n");

			if(cod > 0 && cod < 5){
				usarItem(player, cod);
			} else{
				printf("Item inexistente na sua mochila\n");
			}
	}

	printf("Mochila fechada!\n");

}

// Método responsável por realizar a ação de luta contra um zumbi
void lutar(Player *player){
	int tipoDoZumbi = gerarZumbi(player);
	Enemy zumbi = buscarZumbi(tipoDoZumbi);
	char *acao = malloc(sizeof(char) * 128);

	printf("|||||||||||||||||||||FIGHT MODE|||||||||||||||||||||\n");
	while(zumbi.hp > 0 && (*player).hp > 0){
		printf("Zombie HP: %i\n", zumbi.hp);
		printf("Player HP: %i\n", (*player).hp);
		printf("Sua ação (atacar, itens, fugir):\n");
		scanf("%s", acao);
		printf("\n");

		if(strcmp(acao, "atacar") == 0){
			if(randomizarAcao() == 5){
				printf("O zumbi esquivou!\n");
			} else if(randomizarAcao() == 10){
				printf("Ataque crítico!\n");
				printf("%i de dano!\n", ((*player).xp) / 5);
				zumbi.hp -= (*player).xp / 5;
			} else{
				printf("O zumbi sofreu %i de dano!\n", (*player).xp / 10);
				zumbi.hp -= (*player).xp / 10;
			}

		} else if (strcmp(acao, "itens") == 0){
			itens(player);
		} else if (strcmp(acao, "fugir") == 0){
			if(randomizarAcao() > 5){
				printf("Fugiu!\n");
			} else{
				printf("Não conseguiu fugir!\n");
			}
		}

		if(strcmp(acao, "fugir") != 0){
			if(zumbi.hp > 0){
				printf("O zumbi atacou!\n");

				if(randomizarAcao() == 5){
					printf("Você esquivou do zumbi!\n");
				} else if(randomizarAcao() == 10){
					printf("Ataque crítico do zumbi!\n");
					printf("%i de dano!\n", zumbi.xpGain / 5);
					(*player).hp -= zumbi.xpGain / 5;
				} else{
					printf("Você sofreu %i de dano!\n", zumbi.xpGain / 10);
					(*player).hp -= zumbi.xpGain / 10;
				}
			} else{
				printf("O zumbi foi derrotado!\n");
				printf("Vcoê ganhou %i de XP!\n", zumbi.xpGain);
				(*player).xp += zumbi.xpGain;
			}

			if((*player).xp < 0){
				printf("O zumbi te derrotou!\n");
				printf("------------------------GAME OVER------------------------\n");
				exit(0);
			}
		}
	}

}
