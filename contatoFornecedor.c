#include "consumidor.h"
#include "xml.h"

int enviaJogo(char nome_jogo[50]){
    // envia a solicitação em XML para o fornecedor
    int enviar;

    enviar = gravarXMLJogo(nome_jogo);

    if(enviar == 0){
        return SUCESS;
    } 
    else{
        // tratar casos de erro
    }
}

int recebeJogo(char nome_arq[55]){
    // recebe o preço do jogo

    // chama a funcao da locadora de comprar jogo do modulo locadora

}

