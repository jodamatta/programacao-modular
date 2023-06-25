#include <stdio.h>
#include "dinheiro.h"
#include "retornos.h"

int main(void){
    float preco;
    int resultado;

    printf("Testando a funcao avaliaCompra:\n");

    preco = 70;
    resultado = avaliaCompra(preco);

    if(resultado == ERROR_LEITURA){
        printf("Houve um erro na leitura do arquivo.\n");
    }
    if(resultado == SUCCESS){
        printf("Retorno SUCESS OK.\n");
    } else {
        printf("Retorno SUCESS NOT OK.\n");
    }

    preco = 999.99;
    resultado = avaliaCompra(preco);

    if(resultado == ERROR_LEITURA){
        printf("Houve um erro na leitura do arquivo.\n");
    }
    if(resultado == ERROR_COMPRA){
        printf("Retorno ERROR_COMPRA OK.\n");
    } else {
        printf("Retorno ERROR_COMPRA NOT OK.\n");
    }
    printf("Fim dos testes da avaliaCompra.\n");

    printf("Testando a funcao atualizaSaldo:\n");

    preco = -9999;
    resultado = atualizaSaldo(preco);

    if(resultado == ERROR_SALDONEG){
        printf("Retorno ERROR_SALDONEG OK\n");
    } else {
        printf("Retorno ERROR_SALDONEG NOT OK.\n");
    }

    preco = 10;
    resultado = atualizaSaldo(preco);

    if(resultado == ERROR_ESCRITA){
        printf("Houve um erro na escrita do arquivo.\n");
    }
    if(resultado == SUCCESS){
        printf("Retorno SUCESS OK\n");
    } else {
        printf("Retorno SUCESS NOT OK.\n");
    }
}