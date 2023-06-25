#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consumidor.h"
#include "listas.h"
#include "retornos.h"
#include "jogo_de_tabuleiro.h"

int lerDado(FILE* fp,char* dado,int tam_tag);
int gravaString(FILE* fp,char *string,char *tag);
int gravaInt(FILE* fp, int valor,char *tag);
int gravaFloat(FILE* fp,float valor,char *tag);
int gravaConsumidor(No* lista);
