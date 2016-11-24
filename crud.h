/*
Arquivo responsável por ser o header do arquivo utilitesBanco.c
Autores: Arthur Cohen e Jonathan Gabriel
*/

#include <mysql.h>
#include "structs.h"

int buscarUsuario(char usuario[], char senha[]);

int adicionarUsuario(char usuario[], char senha[]);

int buscarLocal(Building *building);

int buscarNPC(char type[]);

int buscarZumbi(char type[]);