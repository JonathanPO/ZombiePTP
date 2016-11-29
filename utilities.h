/*
Arquivo responsável por ser o header do arquivo utilities.c
Autores: Arthur Cohen e Jonathan Gabriel
*/
#ifndef UTILITIES_H_
#define UTILITIES_H_
#include "structs.h"

int autenticar(char *usuario, char *senha);

int criarUsuario(char *usuario, char *senha);

char* traduzirItens(int cod);

void usarItem(Player *player, int cod);

void ocorrerEvento(Player *player);

int gerarZumbi(Player *player);

void gerarItem(Player *player);

char* gerarNPC(Player *player);

int randomizarAcao();

void jogar();

#endif