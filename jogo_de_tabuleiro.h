#ifndef JOGO_DE_TABULEIRO_H
#define JOGO_DE_TABULEIRO_H

#include "retornos.h"

typedef struct info_jogo{
    int preco1Dia;
    int preco7Dias;
    int qtd_estoque;
    int qtd_alugada1;
    int qtd_alugada7;
} InfoJogo;

typedef struct lista_jogo_cabeca{
    No* inicio;
    No* corrente;
} Lista_jogo;

Lista_jogo* cria_lista_jogo();

int incluirJogo(Lista_jogo* lista_jogo, char codigo[], InfoJogo info);

int buscarJogoExibe(char codigo[], Lista_jogo* lista_jogo);

int atualizacaoJogo(char codigo[], Lista_jogo* lista_jogo, InfoJogo info_nova);

int excluirJogo(char codigo[], Lista_jogo* lista_jogo);

#endif