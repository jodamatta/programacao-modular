#include "consumidor.h"
//#include "xml.h"

int enviaJogo(char nome_jogo[50], char nome_arq[55]){
    // envia a solicitação em XML para o fornecedor
    int enviar;

    enviar = gravaXMLJogo(nome_jogo, nome_arq);

    if(enviar == 0){
        return SUCESS;
    } 
    else if(enviar == -1){
        return ERROR_ARQUIVONENCONTRADO;
    } 
}

int recebeJogo(char nome_arq[55]){
    int preco;
    // como vou pegar o nome do jogo?
    char* nomeJogo;

    preco = leXMLJogo(nome_arq);

    if(preco < 0){
        return ERROR_LEITURA;
    } else {
        compraJogo(nomeJogo, preco);
        return SUCESS;
    }
}

