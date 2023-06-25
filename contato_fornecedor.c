#include "contato_fornecedor.h"
#include "xml.h"
#include <stdio.h>
#include <stdlib.h>

//int gravaString(FILE* fp,char *string,char *tag)

int envia_jogo(char* nome_jogo, int qtd){
    int resultado;
    FILE* fp = "solicitacao.xml";

    // gravar nome do jogo
    resultado = gravaString(fp, nome_jogo, "nome");
    if(resultado == ERROR_ESCRITA){
        return ERROR_ESCRITA;
    }
    else{
        // gravar a quantidade que queremos
        resultado = gravaInt(fp,qtd,"quantidade");

    } if (resultado == ERROR_ESCRITA){
        return ERROR_ESCRITA;
    } else {
        // gravar o verificador
        resultado = gravaInt(fp, 0, "verificador"); 
    } if (resultado == ERROR_ESCRITA){
        return ERROR_ESCRITA;
    
    } else {
        return SUCCESS;
    }
}

int recebe_jogo(){

}