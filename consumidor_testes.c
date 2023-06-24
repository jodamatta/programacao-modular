#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consumidor.h"

int main(void) {
    Lista_consumidor* lst = cria_lista_consumidor();

    InfoConsumidor consumidor1;
    strcpy(consumidor1.nome,"Gustavo");
    strcpy(consumidor1.sobrenome,"Arcary Passos");
    strcpy(consumidor1.celular,"94593-1320");
    strcpy(consumidor1.endereco,"Rua Cosme Velho");

    InfoConsumidor consumidor2;
    strcpy(consumidor2.nome,"Gustavo");
    strcpy(consumidor2.sobrenome,"Arcary Passos");
    strcpy(consumidor2.celular,"98393-3317");
    strcpy(consumidor2.endereco,"Rua Cosme Velho, 415");

    InfoConsumidor consumidor3;
    strcpy(consumidor3.nome,"Jorge");
    strcpy(consumidor3.sobrenome,"Alcalino Terra");
    strcpy(consumidor3.celular,"94593-1820");
    strcpy(consumidor3.endereco,"Rua Laranjeiras");

    printf("\nTestando funcao valida cpf:\n\n");
    int resultado = valida_cpf("199-293-317-74");
    if (resultado == SUCESS_CPF) {
        printf("Retorno SUCESS_CPF OK.\n");
    } else {
        printf("Retorno SUCESS_CPF NOT OK.\n");
    }
    resultado = valida_cpf("a99-293-317-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("1b9-293-317-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("19c-293-317-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199+293-317-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-d93-317-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-2e3-317-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-29f-317-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-293[317-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-293-g17-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-293-3h7-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-293-31i-74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-293-3h7]74");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-293-317-j4");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-293-317-7k");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    resultado = valida_cpf("199-293-317-742");
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    printf("\nFim dos testes da funcao valida cpf.\n");

    printf("\nTestando funcao inclui consumidor:\n\n");
    resultado =  incluirConsumidor(lst, "199-293-317-74", consumidor1);
    incluirConsumidor(lst, "199-223-317-74", consumidor3);
    if (resultado == SUCESS_INCLUI) {
        printf("Retorno SUCESS_INCLUI OK.\n");
    } else {
        printf("Retorno SUCESS_INCLUI NOT OK.\n");
    }
    resultado = incluirConsumidor(lst, "199-293-317-74", consumidor1);
    if (resultado == ERROR_ITEMJAEXISTE) {
        printf("Retorno ERROR_ITEMJAEXISTE OK.\n");
    } else {
        printf("Retorno ERROR_ITEMJAEXISTE NOT OK.\n");
    }
    resultado = incluirConsumidor(lst, "192-993-317-788", consumidor1);
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    printf("\nFim dos testes da funcao inclui consumidor.\n");

    printf("\nTestando funcao busca e exibe dados do consumidor:\n\n");
    resultado = buscarConsumidorExibe("199-293-317-74", lst);
    if (resultado == SUCESS_ENCONTRADO) {
        printf("Retorno SUCESS_ENCONTRADO OK.\n");
    } else {
        printf("Retorno SUCESS_ENCONTRADO NOT OK.\n");
    }
    resultado = buscarConsumidorExibe("192-993-317-78", lst);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    Lista_consumidor* lst_nova = cria_lista_consumidor();
    resultado = buscarConsumidorExibe("199-293-317-74", lst_nova);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = buscarConsumidorExibe("199-293-3c7-74", lst);
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    printf("\nFim dos testes da funcao busca e exibe dados do jogo.\n");
    
    printf("\nTestando funcao atualiza dados do consumidor:\n\n");
    resultado = atualizacaoConsumidor("199-293-317-74", lst, consumidor2);
    buscarConsumidorExibe("199-293-317-74", lst);
    if (resultado == SUCESS_ATUALIZA) {
        printf("Retorno SUCESS_ATUALIZA OK.\n");
    } else {
        printf("Retorno SUCESS_ATUALIZA NOT OK.\n");
    }
    resultado = atualizacaoConsumidor("199-293-317-74", lst_nova, consumidor2);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = atualizacaoConsumidor("199-283-317-74", lst, consumidor2);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    resultado = atualizacaoConsumidor("199-2g3-317-74", lst, consumidor2);
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    printf("\nFim dos testes da funcao atualiza dados do consumidor.\n");

    printf("\nTestando funcao grava xml:\n\n");
    resultado = rotinaConsumidorEscritaXML(lst);
    if (resultado == SUCESS_ESCRITA) {
        printf("Retorno SUCESS_ESCRITA OK.\n");
    } else {
        printf("Retorno SUCESS_ESCRITA NOT OK.\n");
    }
    resultado = rotinaConsumidorEscritaXML(lst_nova);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    printf("\nFim dos testes da funcao grava xml.\n");
    
    printf("\nTestando funcao deleta dados do consumidor:\n\n");
    resultado = excluirConsumidor("199-293-317-74", lst_nova);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = excluirConsumidor("192-983-317-73", lst);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    resultado = excluirConsumidor("199-293-317-74", lst);
    if (resultado == SUCESS_DELETE) {
        printf("Retorno SUCESS_DELETE OK.\n");
    } else {
        printf("Retorno SUCESS_DELETE NOT OK.\n");
    }
    resultado = excluirConsumidor("1r2-9g3-317-74", lst);
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    printf("\nFim dos testes da funcao deleta dados do consumidor.\n");

    return 0;   
}
