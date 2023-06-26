#ifndef XML_H
#define XML_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retornos.h"

int lerDado(FILE* fp,char* dado,int tam_tag1,int tam_tag2);
int gravaString(FILE* fp,char *string,char *tag);
int gravaInt(FILE* fp, int valor,char *tag);
int gravaFloat(FILE* fp,float valor,char *tag);


#endif
