/*
Arquivo responsável por implementar os métodos do header acoes.h
Autores: Arthur Cohen e Jonathan Gabriel
*/

#include <string.h>
#include "acoes.h"
#include "structs.h"
#include "crud.h"
#include "utiilities.h"

// Método responsável por realizar a ação de mover o personagem para um building
void mover(Player *player){
	char location[];
	Building building; 

	printf("Para onde deseja se mover?\n");
	scanf("%s", location);
	printf("\n");

	building.location = location;

	*player.stamina = *player.stamina - building.size;

	printf("Você chegou na localidade\n");

}

// Método responsável por realizar a ação de permitir o personagem interagir com um NPC
void agir(Player *player, NPC *npc){
	int i = 0, j = 0, cod = -1;

	if(strcmp(*npc.type, "vendedor") == 0){
		printf("---------------------------Bem vindo à loja---------------------------\n");

		for(i=0; i < *npc.bag.size(); i++){
			printf("%i - %s \n", i+1, traduzirItens(*npc.bag(i)));
		}
		i = 0;

		while(cod != 0){
			printf("Digite o número do item que deseja (digite 0 para sair):\n")/
			scanf("%i", &cod);
			printf("\n");

			if(cod > 0 && cod < 5){
				*npc.swap[i] = cod;
				i++;
			} else if(cod == 0){
				printf("Obrigado pela compra!\n");
			} else{
				printf("Item inexistente na loja\n");
			}
		}

		i=0;

		for(i=0; i < *player.bag.size(); i++){
			if(*player.bag[i] == 0){
				if(j < *npc.swap.size()){
					*player.bag[i] == *npc.swap[j];
					j++;
				}
			}
		}

	} else if(strcmp(*npc.type, "evento") == 0){
		for(i=0; i < *player.bag.size(); i++){
			if(*player.bag[i] == 0){
				if(j < *npc.swap.size()){
					*player.bag[i] == *npc.swap[j];
					j++;
				}
			}
		}
	}
	
}

// Método responsável por realizar a ação de mostrar os itens que o personagem possui
void itens(Player *player){
	int i = 0, cod = 0;

	printf("-----------------------Itens-----------------------\n");

	for(i=0; i < *player.bag.size(); i++){
			printf("%i - %s \n", i+1, traduzirItens(*player.bag(i)));
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

}

// Método responsável por realizar a ação de luta contra um zumbi
void lutar(Player *player){
	int tipoDoZumbi = gerarZumbi();

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

	return 0;

}
