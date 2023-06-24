#ifndef JOGO_DE_TABULEIRO_H
#define JOGO_DE_TABULEIRO_H

#include "retornos.h"

typedef struct info_jogo{
    float preco1Dia;
    float preco7Dias;
    int qtd_estoque;
    int qtd_alugada1;
    int qtd_alugada7;
    int solicitacoes;
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

int atualizacaoJogoDevolvido7(char codigo[], Lista_jogo* lista_jogo);

int atualizacaoJogoDevolvido1(char codigo[], Lista_jogo* lista_jogo);

int atualizacaoJogoAlugado7(char codigo[], Lista_jogo* lista_jogo,float* preco);

int atualizacaoJogoAlugado1(char codigo[], Lista_jogo* lista_jogo,float* preco);

int rotinaJogoEscritaXML(Lista_jogo* lista_jogo);

void limpa_lista_jogo(Lista_jogo* lista_jogo);

#endif
