#include "contatoFornecedor.h"

int enviaJogo(char nome_jogo[50], char nome_arq[55]);

int main(void){
    char* nome_jogo = "War";
    char* nome_arq1 = "teste.xml";
    char* nome_arq2 = "solicito.xml";
    int resultado;

    printf("Iniciando testes de envio de jogo:\n");

    resultado = enviaJogo(nome_jogo,nome_arq1);
    if(resultado == ERROR_ARQUIVONENCONTRADO){
        printf("Retorno ERROR_ARQUIVONEXISTE OK.\n");
    } 
    else{
        printf("Retorno ERROR_ARQUIVONEXISTE NOT OK.\n");
    }
    resultado = enviaJogo(nome_jogo,nome_arq2);
    if(resultado == SUCESS){
        printf("Retorno SUCESSO OK.\n");
    } else{
        printf("RETORNO SUCESS NOT OK.\n");
    }

    printf("Fim dos testes de envio de jogo.\n");

    printf("Iniciando testes de recebimento de jogo:\n");

}