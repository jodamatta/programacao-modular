#include "listas.h"
#include "xml.h"

int avaliaCompra(float preco){
    float saldo;
    float diferenca;
    
    //saldo = leXML("saldo.xml");

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

int atualizaSaldo(float valor){
    float saldo;
    int novoSaldo;
    int resultado;
    FILE* saldoXML;

    // ler o saldo da file saldo.xml

    novoSaldo = saldo + valor;

    if(novoSaldo < 0){
        return ERROR_SALDONEG;
    }

    resultado = gravaFloat(saldoXML, novoSaldo, "saldo");

    if(resultado == SUCCESS){
        return SUCCESS;
    }
    else {
        return ERROR_ESCRITA;
    }
}