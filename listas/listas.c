#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

struct no {
    void * info;
    char identificador[20];
    struct no* prox;
};

int inclui(No** lst, void* info, char identificador[]){
    No* buscado;
    int ja_existe = busca(*lst, identificador,&buscado);
    if(ja_existe == SUCESS_ENCONTRADO){
        //printf("Ja existe esse usuario.\n");
        return ERROR_ITEMJAEXISTE;
    }
    No* novo_item = (No*) malloc(sizeof(No));
    if( novo_item == NULL){
        //printf("Nao foi possivel alocar memoria para novo item.\n");
        return ERROR_MALLOC;
    }
    novo_item->info = info;
    strcpy(novo_item->identificador,identificador);
    novo_item->prox = *lst; 
    *lst = novo_item;
    return SUCESS_INCLUI;
}

int mostra_todo_conteudo(No* lst){
    if(lst == NULL){
       printf("Lista vazia\n");
       return ERROR_LISTAVAZIA; 
    }
    No* aux = lst;
    while(aux != NULL){
        printf("Item: %s\n",aux->identificador);
        aux = aux->prox;
    }
    return SUCESS;
}

int mostra_conteudo(No* lst){
    if(lst == NULL){
       printf("Lista vazia\n");
       return ERROR_LISTAVAZIA; 
    }
    No* aux = lst;
    printf("Item: %s\n",aux->identificador);
    printf("Valor: %p\n",aux->info);
    return SUCESS;
}

int busca(No* lst, char identificador[], No** buscado){
    if (lst == NULL){
        //printf("Lista vazia\n");
        *buscado = NULL;
        return ERROR_LISTAVAZIA;
    }
    No* aux = lst;

    while(aux != NULL){
        if(strcmp(aux->identificador, identificador) == 0){
            *buscado = aux;
            return SUCESS_ENCONTRADO;
        }
        aux = aux->prox;
    }
    *buscado = NULL;
    //printf("Item nao encontrado.\n");
    return ERROR_NAOENCONTRADO;
}

int atualiza(No** lst,void* info_atualizada, char identificador[]){
    No* buscado;
    int resultado = busca(*lst, identificador,&buscado);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        return ERROR_NAOENCONTRADO;
    }
    free(buscado->info);
    buscado->info = info_atualizada;
    return SUCESS_ATUALIZA;
}

int retorna_info(No* lst,void** info){
    if(lst == NULL){
        return ERROR_LISTAVAZIA;
    }
    *info = lst->info;
    return SUCESS; 
}

int deleta(No** lst, char identificador[]){
    No* buscado;
    int resultado = busca(*lst, identificador,&buscado);
    if (resultado == ERROR_LISTAVAZIA){
        return ERROR_LISTAVAZIA;
    } else if (resultado == ERROR_NAOENCONTRADO){
        return ERROR_NAOENCONTRADO;
    }
    No* aux = *lst;
    if(strcmp(aux->identificador, identificador) == 0){
        *lst = buscado->prox;
        free(buscado->info);
        free(buscado);
        return SUCESS_DELETE;
    }
    while(aux != NULL){
        if(strcmp(aux->prox->identificador, identificador) == 0){
            aux->prox = buscado->prox;
            free(buscado->info);
            free(buscado);
            break;
        }
        aux = aux->prox;
    }
    return SUCESS_DELETE;
}

void libera(No* lst) {
    No* aux = lst;
    while( aux != NULL){
        No* proximo = aux->prox;
        free(aux->info);
        free(aux);
        aux = proximo;
    }
}