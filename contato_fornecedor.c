#include "contato_fornecedor.h"
#include "xml.h"
#include "listas.h"
#include "dinheiro.h"
#include <stdio.h>
#include <stdlib.h>

int envia_jogo(char* nome_jogo, int qtd){
    int resultado;
    FILE *fp = fopen("solicitacao.xml", "a");
    fprintf(fp,"<solicitacao>\n");
    // gravar nome do jogo
    resultado = gravaString(fp, nome_jogo, "nome");
    if(resultado == ERROR_ESCRITA){
        fclose(fp);
        return ERROR_ESCRITA;
    }
    else{
        // gravar a quantidade que queremos
        resultado = gravaInt(fp,qtd,"qtd");
        fprintf(fp,"</solicitacao>\n");
        fclose(fp);
        if (resultado == ERROR_ESCRITA){
            return ERROR_ESCRITA;
        } else {
            return SUCCESS;
        } 
    }
}

int lerFornecedor(Lista_jogo* lista){
  FILE* fp = fopen("arqFornecedor.xml","r");
  char linha[100];
  char nome[100];
  float preco;
  int qtd;
  int check;
  float transacao;
  InfoJogo * infonova;
  char *aux;
  if(fp == NULL){
    return ERROR_ARQUIVONEXISTE;
  }
  while (fgets(linha, sizeof(linha), fp)) {
    aux = strstr(linha, "  <row>");
    if (aux != NULL) {
      fgets(linha,sizeof(linha),fp); // ignora index
      
      lerDado(fp,linha,10,8);
      strcpy(nome,linha);
      
      lerDado(fp,linha,11,9);
      preco = atof(linha);
      
      lerDado(fp,linha,16,14);
      qtd = atoi(linha);
      
      transacao = preco*qtd;
      check = avaliaCompra(transacao);
      if(check != ERROR_COMPRA){
        atualizaSaldo(transacao,1);
        int resultado = busca(lista->inicio, nome, &lista->corrente);
        if(resultado == ERROR_NAOENCONTRADO){
          return ERROR_NAOENCONTRADO;
        }
        resultado = retorna_info(lista->corrente,&infonova);
        infonova->qtd_estoque += qtd;
        infonova->solicitacoes = 0;
        atualizacaoJogo(nome,lista,*infonova);
      } 
    }
  }
  return SUCCESS_LEITURA;
}
