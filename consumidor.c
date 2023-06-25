#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consumidor.h"
#include "listas.h"

Lista_consumidor* cria_lista_consumidor(){
    Lista_consumidor* lista_consumidor = (Lista_consumidor*) malloc(sizeof(Lista_consumidor));
    if (lista_consumidor == NULL) {
        return NULL;
    }
    lista_consumidor->inicio = NULL;
    lista_consumidor->corrente = NULL;
    return lista_consumidor;
}

int valida_cpf(char cpf[]){
    if(cpf[3] != '-' || cpf[7] != '-' || cpf[11] != '-' || cpf[14] != '\0'){
        return ERROR_INVALIDOCPF;
    }
    for(int i = 0;i < 3;i++){
        if(cpf[i] < '0' ||  cpf[i] > '9'){
            return ERROR_INVALIDOCPF;
        }
    }
    for(int i = 4;i < 7;i++){
        if(cpf[i] < '0' ||  cpf[i] > '9'){
            return ERROR_INVALIDOCPF;
        }
    }
    for(int i = 8;i < 11;i++){
        if(cpf[i] < '0' ||  cpf[i] > '9'){
            return ERROR_INVALIDOCPF;
        }
    }
    for(int i = 12;i < 14;i++){
        if(cpf[i] < '0' ||  cpf[i] > '9'){
            return ERROR_INVALIDOCPF;
        }
    }
    return SUCCESS_CPF;
}

int incluirConsumidor(Lista_consumidor* lista_consumidor, char cpf[], InfoConsumidor info) {
    int resultado = valida_cpf(cpf);
    if(resultado == ERROR_INVALIDOCPF){
        return ERROR_INVALIDOCPF;
    }
    InfoConsumidor* novo_info = (InfoConsumidor*) malloc(sizeof(InfoConsumidor));
    if (novo_info == NULL) {
        return ERROR_MALLOC;
    }
    strcpy(novo_info->nome,info.nome);
    strcpy(novo_info->sobrenome,info.sobrenome);
    strcpy(novo_info->celular,info.celular);
    strcpy(novo_info->endereco,info.endereco);
    resultado = inclui(&lista_consumidor->inicio, novo_info, cpf);
    if (resultado == ERROR_ITEMJAEXISTE) {
        free(novo_info);
        return ERROR_ITEMJAEXISTE;
    }
    return SUCCESS_INCLUI;
}

int buscarConsumidorExibe(char cpf[],Lista_consumidor* lista_consumidor) {
    int resultado = valida_cpf(cpf);
    if(resultado == ERROR_INVALIDOCPF){
        return ERROR_INVALIDOCPF;
    }
    resultado = busca(lista_consumidor->inicio, cpf, &lista_consumidor->corrente);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        return ERROR_NAOENCONTRADO;
    }
    InfoConsumidor* aux;
    resultado = retorna_info(lista_consumidor->corrente,&aux);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_INFO;
    }
    printf("\nCPF: %s\nNome: %s\nSobrenome: %s\nCelular: %s\nEndereco: %s\n\n",cpf,aux->nome,aux->sobrenome,aux->celular,aux->endereco);
    return SUCCESS_ENCONTRADO;
}

int atualizacaoConsumidor( char cpf[], Lista_consumidor* lista_consumidor, InfoConsumidor info_nova) {
    int resultado = valida_cpf(cpf);
    if(resultado == ERROR_INVALIDOCPF){
        return ERROR_INVALIDOCPF;
    }
    InfoConsumidor* novo_info = (InfoConsumidor*) malloc(sizeof(InfoConsumidor));
    if (novo_info == NULL) {
        return ERROR_MALLOC;
    }
    strcpy(novo_info->nome,info_nova.nome);
    strcpy(novo_info->sobrenome,info_nova.sobrenome);
    strcpy(novo_info->celular,info_nova.celular);
    strcpy(novo_info->endereco,info_nova.endereco);
    resultado = atualiza(&lista_consumidor->inicio, novo_info, cpf);
    if (resultado == ERROR_LISTAVAZIA){
        free(novo_info);
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        free(novo_info);
        return ERROR_NAOENCONTRADO;
    }
    return SUCCESS_ATUALIZA;
}

int excluirConsumidor(char cpf[], Lista_consumidor* lista_consumidor){
    int resultado = valida_cpf(cpf);
    if(resultado == ERROR_INVALIDOCPF){
        return ERROR_INVALIDOCPF;
    }
    resultado = deleta(&lista_consumidor->inicio,cpf);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        return ERROR_NAOENCONTRADO;
    }
    return SUCCESS_DELETE;
}

int lerXMLConsumidor(Lista_consumidor *lista){
  InfoConsumidor dados;
  char linha[100];
  char *aux;
  char cpf[100];
  FILE *fp = fopen("consumidor.xml", "r");
  if (fp == NULL) {
    printf("Could not open file.\n");
    return ERROR_ARQUIVONEXISTE;
  }
  while (fgets(linha, sizeof(linha), fp)) {
    aux = strstr(linha, "<consumidor>");
    if (aux != NULL) {
      lerDado(fp,linha,8);
      strcpy(dados.nome,linha);
      
      lerDado(fp,linha,13);
      strcpy(dados.sobrenome, linha);
      
      lerDado(fp,linha,11);
      strcpy(dados.celular,linha);
      
      lerDado(fp,linha,12);
      strcpy(dados.endereco,linha);
      
      lerDado(fp,linha,7);
      strcpy(cpf,linha);
      
      incluirConsumidor(lista,cpf,dados);
    }
  }
  return SUCCESS_LEITURA;
}
int rotinaConsumidorEscritaXML(Lista_consumidor* lista_consumidor){
    int resultado;
    char cpf[20];
    char* tag;
    lista_consumidor->corrente = lista_consumidor->inicio;
    FILE *fp = fopen("consumidor.xml", "w");
    if (fp == NULL) {
      printf("Could not open file.\n");
      return ERROR_ARQUIVONEXISTE;
    }
    if(lista_consumidor->inicio == NULL){
        return ERROR_LISTAVAZIA;
    }
    fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    while(0 == 0 ){
        InfoConsumidor* aux;
        resultado = retorna_info(lista_consumidor->corrente,&aux);
        if (resultado == ERROR_LISTAVAZIA){
            break;
        }
        resultado = percorre_lista_em_ordem(cpf,&lista_consumidor->corrente);
        fprintf(fp, "<consumidor>\n");
        tag = "nome";
        gravaString(fp,aux->nome,tag);
        tag = "sobrenome";
        gravaString(fp,aux->sobrenome,tag);
        tag = "celular";
        gravaString(fp,aux->celular,tag);
        tag = "endereco";
        gravaString(fp,aux->endereco,tag);
        tag = "cpf";
        gravaString(fp, cpf,tag);
        fprintf(fp, "</consumidor>\n");
        printf("\nCPF: %s\nNome: %s\nSobrenome: %s\nCelular: %s\nEndereco: %s\n\n",cpf,aux->nome,aux->sobrenome,aux->celular,aux->endereco);
    }
    return SUCCESS_ESCRITA;
}
void limpa_lista_consumidor(Lista_consumidor* lista_consumidor){
    libera(lista_consumidor->inicio);
    free(lista_consumidor);
}
