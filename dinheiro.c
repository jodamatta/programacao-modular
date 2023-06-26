#include "xml.h"
#include "dinheiro.h"

int avaliaCompra(float preco){
    float saldo;
    float* ptrSaldo = &saldo;
    float diferenca;
    
    lerXMLDinheiro(ptrSaldo);

    if(saldo < 0){
        return ERROR_LEITURA;
    } 

    else {
        diferenca = saldo - preco;
        if(diferenca < 0){
            return ERROR_COMPRA;
        } 
        else {
            return SUCCESS;
        }
    }
}

int atualizaSaldo(float valor,int modo){// 0 para soma e 1 para subtração
    float saldo;
    float* ptrSaldo = &saldo;
    float novoSaldo;
    int resultado;

    lerXMLDinheiro(ptrSaldo);
    if(modo == 0){
      novoSaldo = saldo + valor;
    }
    else if(modo == 1){
      novoSaldo = saldo - valor;
    }
    else{
      return ERROR_MODOINVALIDO;
    }


    if(novoSaldo < 0){
        return ERROR_SALDONEG;
    }
    FILE* saldoXML = fopen("saldo.xml", "w");
    fprintf(saldoXML, "<dinheiro>\n");
    resultado = gravaFloat(saldoXML, novoSaldo, "saldo");
    fprintf(saldoXML, "</dinheiro>\n");
    fclose(saldoXML);
    if(resultado == SUCCESS){
        return SUCCESS;
    }
    else {
        return ERROR_ESCRITA;
    }
}

int lerXMLDinheiro(float* saldo){
  char linha[100];
  char *aux;
  FILE *fp = fopen("saldo.xml", "r");
  if (fp == NULL) {
    printf("Could not open file.\n");
    return ERROR_ARQUIVONEXISTE;
  }
  while (fgets(linha, sizeof(linha), fp)) {
    aux = strstr(linha, "<dinheiro>");
    if (aux != NULL) {
      lerDado(fp,linha,9,9);
      *saldo = atof(linha);
      fclose(fp);
      return SUCCESS_LEITURA;
    }
  }
  fclose(fp);
  return ERROR_LEITURA;
}
