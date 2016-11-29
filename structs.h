/*
Arquivo responsável por definir as estruturas dos componentes presentes no jogo
Autores: Arthur Cohen e Jonathan Gabriel
*/
#ifndef STRUCTS_H_
#define STRUCTS_H_
#include <string.h>

typedef struct {
	int idBuild;
	char *name;
	int location;
	int size;
	int theft;
	char *description;
} Building;

typedef struct {
	int idPlayer;
	char *name;
	char *password;
	int hp;
	int xp;
	int stamina;
	int bag[20];
} Player;

typedef struct {
	int idEnemy;
	char *name;
	int hp;
	int xpGain;
} Enemy;

#endif