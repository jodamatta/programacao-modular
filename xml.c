#include "xml.h"

int lerDado(FILE* fp,char* dado,int tam_tag){
  char linha[100];
  fgets(linha,sizeof(linha),fp);
  linha[strlen(linha)-tam_tag]='\0';
  strcpy(dado,linha+tam_tag);
  return SUCESS_LEITURA;
}

int gravaString(FILE* fp,char *string,char *tag){
  int check;
  check = fprintf(fp,"  <%s>%s</%s>\n",tag,string,tag);
  if(check<0){
    return ERROR_ESCRITA;
  }
  return SUCCESS;
}
int gravaInt(FILE* fp, int valor,char *tag){
  int check;
  check = fprintf(fp,"  <%s>%d</%s>\n",tag,valor,tag);
  if(check<0){
    return ERROR_ESCRITA;
  }
  return SUCCESS;
}
int gravaFloat(FILE* fp,float valor,char *tag){
  int check;
  check = fprintf(fp,"  <%s>%f</%s>\n",tag,valor,tag);
  if(check<0){
    return ERROR_ESCRITA;
  }
  return SUCCESS;
}

int gravaConsumidor(No* lista){
  char* tag;
  No* aux = lista;
  int check;
  InfoConsumidor* info =(InfoConsumidor*)malloc(sizeof(InfoConsumidor));
  
  FILE *fp = fopen("consumidor.xml", "w");
  if (fp == NULL) {
    printf("Could not open file.\n");
    return 1;
  }
  fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  
  while(aux != NULL){
    info = aux->info;
    fprintf(fp, "<consumidor>\n");
    tag = "nome";
    gravaString(fp,info->nome,tag);
    tag = "sobrenome";
    gravaString(fp,info->sobrenome,tag);
    tag = "celular";
    gravaString(fp,info->celular,tag);
    tag = "endereco";
    gravaString(fp,info->endereco,tag);
    tag = "cpf";
    gravaString(fp, aux->identificador,tag);
    aux = aux->prox;
    fprintf(fp, "</consumidor>\n");
  }
}
