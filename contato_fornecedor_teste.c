#include "contato_fornecedor.h"
#include <stdio.h>

int main(void){
    int resultado;

    printf("Testando a funcao envia_jogo:\n");

    resultado = envia_jogo("Jogo da Vida", 1);
    if(resultado == SUCCESS){
        printf("retorno SUCCESS OK\n");
    } else if(resultado == ERROR_ESCRITA){
        printf("Houve um erro na escrita.\n");
    }
    else {
        printf("retorno SUCCESS NOT OK\n");
    }

    printf("Fim dos testes da funcao envia_jogo\n");
    return 0;
}