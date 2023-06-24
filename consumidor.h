#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include "retornos.h"

typedef struct info_consumidor{
    char nome[15];
    char sobrenome[50];
    char celular[20];
    char endereco[50];
} InfoConsumidor;

typedef struct lista_consumidor{
    No* inicio;
    No* corrente;
} Lista_consumidor;

Lista_consumidor* cria_lista_consumidor();

int valida_cpf(char cpf[]);

int incluirConsumidor(Lista_consumidor* lista_consumidor, char cpf[], InfoConsumidor info);

int buscarConsumidorExibe(char cpf[],Lista_consumidor* lista_consumidor);

int atualizacaoConsumidor( char cpf[], Lista_consumidor* lista_consumidor, InfoConsumidor info_nova);

int excluirConsumidor(char cpf[], Lista_consumidor* lista_consumidor);

void limpa_lista_consumidor(Lista_consumidor* lista_consumidor);

#endif
