#include "contato_fornecedor.h"
#include "xml.h"
#include <stdio.h>
#include <stdlib.h>

int envia_jogo(char* nome_jogo, int qtd){
    int resultado;
    FILE *fp = fopen("solicitacao.xml", "w");
    fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf("<solicitacao>\n");
    // gravar nome do jogo
    resultado = gravaString(fp, nome_jogo, "nome");
    if(resultado == ERROR_ESCRITA){
        return ERROR_ESCRITA;
    }
    else{
        // gravar a quantidade que queremos
        resultado = gravaInt(fp,qtd,"qtd");
        fprintf("</solicitacao>\n");
        if (resultado == ERROR_ESCRITA){
            return ERROR_ESCRITA;
        } else {
            return SUCCESS;
        } 
    }
}
