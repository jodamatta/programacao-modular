#ifndef XML_H
#define XML_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retornos.h"

int lerDado(FILE* fp,char* dado,int tam_tag);
int gravaString(FILE* fp,char *string,char *tag);
int gravaInt(FILE* fp, int valor,char *tag);
int gravaFloat(FILE* fp,float valor,char *tag);
//int gravaConsumidor(No* lista);


#endif