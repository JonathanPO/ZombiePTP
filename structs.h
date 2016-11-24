/*
Arquivo responsável por definir as estruturas dos componentes presentes no jogo
Autores: Arthur Cohen e Jonathan Gabriel
*/

#include <string.h>

typedef struct {
	char location[];
	int size;
	char theft[];
	char enemy;
} Building;

typedef struct {
	char name[];
	int hp;
	int xp;
	int bag[20];
	int stamina;
} Player;

typedef struct {
	char type[];
	int hp;
	int xp;
	char theft[];
} Zombie;

typedef struct{
	char tipo[];
	int bag[20];
	int swap[20];
} NPC;