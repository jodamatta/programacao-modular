#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo_de_tabuleiro.h"
#include "listas.h"

Lista_jogo* cria_lista_jogo() {
    Lista_jogo* lista_jogo = (Lista_jogo*) malloc(sizeof(Lista_jogo));
    if (lista_jogo == NULL) {
        return NULL;
    }
    lista_jogo->inicio = NULL;
    lista_jogo->corrente = NULL;
    return lista_jogo;
}

int incluirJogo(Lista_jogo* lista_jogo, char codigo[], InfoJogo info) {
    InfoJogo* novo_info = (InfoJogo*) malloc(sizeof(InfoJogo));
    if (novo_info == NULL) {
        return ERROR_MALLOC;
    }
    novo_info->preco1Dia = info.preco1Dia;
    novo_info->preco7Dias = info.preco7Dias;
    novo_info->qtd_estoque = info.qtd_estoque;
    novo_info->qtd_alugada1 = info.qtd_alugada1;
    novo_info->qtd_alugada7 = info.qtd_alugada7;
    int resultado = inclui(&lista_jogo->inicio, novo_info, codigo);
    if (resultado == ERROR_ITEMJAEXISTE) {
        free(novo_info);
        return ERROR_ITEMJAEXISTE;
    }
    return SUCESS_INCLUI;
}

int buscarJogoExibe(char codigo[], Lista_jogo* lista_jogo) {
    int resultado = busca(lista_jogo->inicio, codigo, &lista_jogo->corrente);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        return ERROR_NAOENCONTRADO;
    }
    InfoJogo* aux;
    resultado = retorna_info(lista_jogo->corrente,&aux);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_INFO;
    }
    printf("\n%s: \nPreco 1 dia: %d\nPreco 7 dias: %d\nQuantidade em estoque: %d\nQuantidade alugada 1 dia: %d\nQuantidade alugada 7 dias: %d\n\n", codigo,aux->preco1Dia,aux->preco7Dias,aux->qtd_estoque,aux->qtd_alugada1,aux->qtd_alugada7);
    return SUCESS_ENCONTRADO;
}

int atualizacaoJogo(char codigo[], Lista_jogo* lista_jogo, InfoJogo info_nova) {
    InfoJogo* novo_info = (InfoJogo*) malloc(sizeof(InfoJogo));
    if (novo_info == NULL) {
        return ERROR_MALLOC;
    }
    novo_info->preco1Dia = info_nova.preco1Dia;
    novo_info->preco7Dias = info_nova.preco7Dias;
    novo_info->qtd_estoque = info_nova.qtd_estoque;
    novo_info->qtd_alugada1 = info_nova.qtd_alugada1;
    novo_info->qtd_alugada7 = info_nova.qtd_alugada7;
    int resultado = atualiza(&lista_jogo->inicio, novo_info, codigo);
    if (resultado == ERROR_LISTAVAZIA){
        free(novo_info);
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        free(novo_info);
        return ERROR_NAOENCONTRADO;
    }
    return SUCESS_ATUALIZA;
}

int excluirJogo(char codigo[], Lista_jogo* lista_jogo){
    int resultado = deleta(&lista_jogo->inicio,codigo);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        return ERROR_NAOENCONTRADO;
    }
    return SUCESS_DELETE;
}
