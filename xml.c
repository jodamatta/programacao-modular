#include "xml.h"

int lerDado(FILE* fp,char* dado,int tam_tag1,int tam_tag2){
  char linha[100];
  fgets(linha,sizeof(linha),fp);
  linha[strlen(linha)-tam_tag2]='\0';
  strcpy(dado,linha+tam_tag1);
  return SUCCESS_LEITURA;
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
