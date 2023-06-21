#include <stdio.h>
#include "dinheiro.h"
#include "retornos.h"

//int avaliaCompra(int preco, char nome_arq[55])
//int atualizaSaldo(int valor, char nome_arq[55])

int main(void){
    float preco;
    int resultado;
    char* nome_arq;

    printf("Testando a funcao avaliaCompra:\n");

    nome_arq = "erro.xml";
    preco = 70;
    resultado = avaliaCompra(preco,nome_arq);

    if(resultado == ERROR_LEITURA){
        printf("Retorno ERROR_LEITURA OK.\n");
    } else {
        printf("Retorno ERROR_LEITURA NOT OK.\n");
    }


    nome_arq = "dinheiro_teste.xml";
    resultado = avaliaCompra(preco, nome_arq);

    if(resultado == SUCESS){
        printf("Retorno SUCESS OK.\n");
    } else {
        printf("Retorno SUCESS NOT OK.\n");
    }

    preco = 999.99;
    resultado = avaliaCompra(preco, nome_arq);

    if(resultado == ERROR_COMPRA){
        printf("Retorno ERROR_COMPRA OK.\n");
    } else{
        printf("Retorno ERROR_COMPRA NOT OK.\n");
    }
    printf("Fim dos testes da avaliaCompra.\n");

    printf("Testando a funcao atualizaSaldo:\n");

    

}