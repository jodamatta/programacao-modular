#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

int main(void){
    No* lst = NULL;

    int* info = (int*) malloc(sizeof(int));
    if( info == NULL){
        //printf("Nao foi possivel alocar memoria para novo item.\n");
        return ERROR_MALLOC;
    }
    *info = 15;
    char identificador[20] = "Gustavo";
    int* info2 = (int*) malloc(sizeof(int));
    if( info2 == NULL){
        //printf("Nao foi possivel alocar memoria para novo item.\n");
        return ERROR_MALLOC;
    }
    *info2 = 18;
    char identificador2[20] = "Eduardo";
    int* info3 = (int*) malloc(sizeof(int));
    if( info3 == NULL){
        //printf("Nao foi possivel alocar memoria para novo item.\n");
        return ERROR_MALLOC;
    }
    *info3 = 20;
    char identificador3[20] = "Felipe";
    inclui(&lst, info3, identificador3);
    inclui(&lst, info2, identificador2);
    printf("\nTestando funcao inclui :\n\n");
    int resultado = inclui(&lst, info, identificador);
    if(resultado == SUCCESS_INCLUI){
        printf("Retorno SUCESS_INCLUI OK.\n");
    } else {
        printf("Retorno SUCESS_INCLUI NOT OK.\n");
    }
    resultado = inclui(&lst, info, identificador);
    if(resultado == ERROR_ITEMJAEXISTE){
        printf("Retorno ERROR_ITEMJAEXISTE OK.\n");
    } else {
        printf("Retorno ERROR_ITEMJAEXISTE NOT OK.\n");
    }
    printf("\nFim dos testes da funcao inclui.\n");

    printf("\nTestando funcao busca :\n\n");
    No* item_um;
    No* lst_nova = NULL;
    resultado = busca(lst_nova, "Gustavo", &item_um);
    if (resultado == ERROR_LISTAVAZIA){
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = busca(lst, "Gustavoo", &item_um);
    if (resultado == ERROR_NAOENCONTRADO){
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    resultado = busca(lst, "Gustavo", &item_um);
    if (resultado == SUCCESS_ENCONTRADO){
        printf("Retorno SUCESS_ENCONTRADO OK.\n");
    } else {
        printf("Retorno SUCESS_ENCONTRADO NOT OK.\n");
    }
    printf("\nFim dos testes da funcao busca.\n");

    printf("\nTestando funcao atualiza :\n\n");
    int* info_nova = (int*) malloc(sizeof(int));
    if( info_nova == NULL){
        //printf("Nao foi possivel alocar memoria para novo item.\n");
        return ERROR_MALLOC;
    }
    *info_nova = 8;
    resultado = atualiza(&lst_nova,info_nova, "Gustavo");
    if (resultado == ERROR_LISTAVAZIA){
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = atualiza(&lst,info_nova, "Gustavoo");
    if (resultado == ERROR_NAOENCONTRADO){
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }  
    resultado = atualiza(&lst,info_nova, "Gustavo");
    if (resultado == SUCCESS_ATUALIZA){
        printf("Retorno SUCESS_ATUALIZA OK.\n");
    } else {
        printf("Retorno SUCESS_ATUALIZA NOT OK.\n");
    }
    printf("\nFim dos testes da funcao atualiza.\n");

    printf("\nTestando funcao percorre_lista_em_ordem :\n\n");
    No* lst_teste = lst;
    char nome[20];
    resultado = percorre_lista_em_ordem(nome, &lst_teste);
    printf("%s\n",nome);
    percorre_lista_em_ordem(nome, &lst_teste);
    percorre_lista_em_ordem(nome,&lst_teste);
    if (resultado == SUCCESS){
        printf("Retorno SUCESS OK.\n");
    } else {
        printf("Retorno SUCESS NOT OK.\n");
    }
    resultado = percorre_lista_em_ordem(nome, &lst_teste);
    if (resultado == ERROR_LISTAVAZIA){
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    printf("\nFim dos testes da funcao percorre_lista_em_ordem.\n");

    printf("\nTestando funcao deleta :\n\n");
    resultado = deleta(&lst_nova,"Gustavo");
    if (resultado == ERROR_LISTAVAZIA){
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = deleta(&lst,"Gustavoo");
    if (resultado == ERROR_NAOENCONTRADO){
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    } 
    resultado = deleta(&lst,"Felipe");
    if (resultado == SUCCESS_DELETE){
        printf("Retorno SUCESS_DELETE OK.\n");
    } else {
        printf("Retorno SUCESS_DELETE NOT OK.\n");
    }
    resultado = deleta(&lst,"Gustavo");
    if (resultado == SUCCESS_DELETE){
        printf("Retorno SUCESS_DELETE OK.\n");
    } else {
        printf("Retorno SUCESS_DELETE NOT OK.\n");
    }   
    printf("\nFim dos testes da funcao deleta.\n");


    return 0;
}