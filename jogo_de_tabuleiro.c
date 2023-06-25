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
    novo_info->solicitacoes = info.solicitacoes;
    int resultado = inclui(&lista_jogo->inicio, novo_info, codigo);
    if (resultado == ERROR_ITEMJAEXISTE) {
        free(novo_info);
        return ERROR_ITEMJAEXISTE;
    }
    return SUCCESS_INCLUI;
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
    printf("\n%s: \nPreco 1 dia: %.2f\nPreco 7 dias: %.2f\nQuantidade em estoque: %d\nQuantidade alugada 1 dia: %d\nQuantidade alugada 7 dias: %d\n\n", codigo,aux->preco1Dia,aux->preco7Dias,aux->qtd_estoque,aux->qtd_alugada1,aux->qtd_alugada7);
    return SUCCESS_ENCONTRADO;
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
    novo_info->solicitacoes = info_nova.solicitacoes;
    int resultado = atualiza(&lista_jogo->inicio, novo_info, codigo);
    if (resultado == ERROR_LISTAVAZIA){
        free(novo_info);
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        free(novo_info);
        return ERROR_NAOENCONTRADO;
    }
    return SUCCESS_ATUALIZA;
}

int atualizacaoJogoDevolvido7(char codigo[], Lista_jogo* lista_jogo){
    int resultado = busca(lista_jogo->inicio, codigo, &lista_jogo->corrente);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        return ERROR_NAOENCONTRADO;
    }
    InfoJogo* aux;
    resultado = retorna_info(lista_jogo->corrente,&aux);
    if (aux->qtd_alugada7 == 0) {
        return ERROR_NAOALUGADO;
    }
    aux->qtd_estoque = aux->qtd_estoque + 1;
    aux->qtd_alugada7 = aux->qtd_alugada7 - 1;
    return SUCCESS_DEVOLUCAO;
}

int atualizacaoJogoDevolvido1(char codigo[], Lista_jogo* lista_jogo){
    int resultado = busca(lista_jogo->inicio, codigo, &lista_jogo->corrente);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        return ERROR_NAOENCONTRADO;
    }
    InfoJogo* aux;
    resultado = retorna_info(lista_jogo->corrente,&aux);
    if (aux->qtd_alugada1 == 0) {
        return ERROR_NAOALUGADO;
    }
    aux->qtd_estoque = aux->qtd_estoque + 1;
    aux->qtd_alugada1 = aux->qtd_alugada1 - 1;
    return SUCCESS_DEVOLUCAO;
}

int atualizacaoJogoAlugado7(char codigo[], Lista_jogo* lista_jogo,float* preco){
    int resultado = busca(lista_jogo->inicio, codigo, &lista_jogo->corrente);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        return ERROR_NAOENCONTRADO;
    }
    InfoJogo* aux;
    resultado = retorna_info(lista_jogo->corrente,&aux);
    if (aux->qtd_estoque == 0){
        aux->solicitacoes = aux->solicitacoes + 1; 
        if (aux->solicitacoes == 3) {
            // caso de fornecedor
            return ERROR_SOLICITARCOMPRA;
        }
        return ERROR_SEMESTOQUE;
    }
    aux->qtd_estoque = aux->qtd_estoque - 1;
    aux->qtd_alugada7 = aux->qtd_alugada7 + 1;
    aux->solicitacoes = 0;
    *preco = aux->preco7Dias;
    return SUCCESS_ALUGADO;
}

int atualizacaoJogoAlugado1(char codigo[], Lista_jogo* lista_jogo,float* preco){
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
    if (aux->qtd_estoque == 0){
        aux->solicitacoes = aux->solicitacoes + 1;
        if (aux->solicitacoes == 3) {
            // caso de fornecedor
            return ERROR_SOLICITARCOMPRA;
        }
        return ERROR_SEMESTOQUE;
    }
    aux->qtd_estoque = aux->qtd_estoque - 1;
    aux->qtd_alugada1 = aux->qtd_alugada1 + 1;
    aux->solicitacoes = 0;
    *preco = aux->preco1Dia;
    return SUCCESS_ALUGADO;
}

int lerXMLJogo(Lista_jogo *lista){
  InfoJogo dados;
  char linha[100];
  char *aux;
  char nome[100];
  FILE *fp = fopen("jogos.xml", "r");
  if (fp == NULL) {
    printf("Could not open file.\n");
    return ERROR_ARQUIVONEXISTE;
  }
  while (fgets(linha, sizeof(linha), fp)) {
    aux = strstr(linha, "<jogo>");
    if (aux != NULL) {
      lerDado(fp,linha,8);
      strcpy(nome,linha);
      
      lerDado(fp,linha,13);
      dados.preco1Dia = atof(linha);
      
      lerDado(fp,linha,14);
      dados.preco7Dias = atof(linha);
      
      lerDado(fp,linha,11);
      dados.qtd_estoque = atoi(linha);
      
      lerDado(fp,linha,15);
      dados.qtd_alugada1 = atoi(linha);

      lerDado(fp,linha,15);
      dados.qtd_alugada7 = atoi(linha);

      lerDado(fp,linha,16);
      
      dados.solicitacoes = atoi(linha);
      
      incluirJogo(lista,nome,dados);
    }
  }
  return SUCCESS_LEITURA;
}

int rotinaJogoEscritaXML(Lista_jogo* lista_jogo){
    int resultado;
    char nome[20];
    lista_jogo->corrente = lista_jogo->inicio;
    char *tag;
    float copy;
    if(lista_jogo->inicio == NULL){
        return ERROR_LISTAVAZIA;
    }
    FILE *fp = fopen("jogos.xml", "w");
    if (fp == NULL) {
      printf("Could not open file.\n");
      return ERROR_ARQUIVONEXISTE;
    }
    fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    while(0 == 0 ){
        InfoJogo* aux;
        resultado = retorna_info(lista_jogo->corrente,&aux);
        if (resultado == ERROR_LISTAVAZIA){
            break;
        }
        resultado = percorre_lista_em_ordem(nome,&lista_jogo->corrente);
        fprintf(fp, "<jogo>\n");
        tag = "nome";
        gravaString(fp,nome,tag);
        tag = "preco1Dia";
        printf("%f",aux->preco1Dia);
        gravaFloat(fp,copy,tag);
        tag = "preco7Dias";
        gravaFloat(fp,aux->preco7Dias,tag);
        tag = "estoque";
        gravaInt(fp,aux->qtd_estoque,tag);
        tag = "qtdAlugada1";
        gravaInt(fp, aux->qtd_alugada1,tag);
        tag = "qtdAlugada7";
        gravaInt(fp, aux->qtd_alugada7,tag);
        tag = "solicitacoes";
        gravaInt(fp,aux->solicitacoes,tag);
        fprintf(fp, "</jogo>\n");
        //printf("\n%s: \nPreco 1 dia: %.2f\nPreco 7 dias: %.2f\nQuantidade em estoque: %d\nQuantidade alugada 1 dia: %d\nQuantidade alugada 7 dias: %d\n\n", nome,aux->preco1Dia,aux->preco7Dias,aux->qtd_estoque,aux->qtd_alugada1,aux->qtd_alugada7);
    }
    return SUCCESS_ESCRITA;
}

void limpa_lista_jogo(Lista_jogo* lista_jogo){
    libera(lista_jogo->inicio);
    free(lista_jogo);
}
