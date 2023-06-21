#include "retornos.h"

int inclui(No** lst, void* info, char identificador[]);

int mostra_conteudo(No* lst);

int mostra_todo_conteudo(No* lst);

int busca(No* lst, char identificador[], No** buscado);

int atualiza(No** lst,void* info_atualizada, char identificador[]);

int retorna_info(No* lst,void** info);

int deleta(No** lst, char identificador[]);