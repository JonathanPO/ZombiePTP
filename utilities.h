/*
Arquivo responsável por ser o header do arquivo utilities.c
Autores: Arthur Cohen e Jonathan Gabriel
*/

int autenticar(char usuario[10], char senha[10]);

int criarUsuario(char usuario[10], char senha[10]);

void jogar();

char* traduzirItens(int cod);

void usarItem(Player *player, int cod);

void ocorrerEvento();