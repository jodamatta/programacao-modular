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
    return SUCESS_CPF;
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
    return SUCESS_INCLUI;
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
    return SUCESS_ENCONTRADO;
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
    return SUCESS_ATUALIZA;
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
    return SUCESS_DELETE;
}

void limpa_lista_consumidor(Lista_consumidor* lista_consumidor){
    libera(lista_consumidor->inicio);
    free(lista_consumidor);
}