#include "listas.h"
//#include "xml.h"

int avaliaCompra(float preco, char nome_arq[55]){
    float saldo;
    float diferenca;
    saldo = leXML(nome_arq);

    if(saldo < 0){
        return ERROR_LEITURA;
    } 

    else {
        diferenca = saldo - preco;
        if(diferenca < 0){
            return ERROR_COMPRA;
        } 
        else {
            return SUCESS;
        }
    }
}

int atualizaSaldo(float valor, char nome_arq[55]){
    float saldo;
    int novoSaldo;
    int resultado;

    saldo = leXML(nome_arq);

    novoSaldo = saldo + valor;

    if(novoSaldo < 0){
        return ERROR_SALDONEG;
    }

    resultado = gravaXML(nome_arq, novoSaldo);

    if(resultado == SUCESS){
        return SUCESS;
    }
    else {
        return ERROR_ESCRITA;
    }
}