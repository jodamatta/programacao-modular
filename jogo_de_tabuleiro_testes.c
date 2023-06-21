#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo_de_tabuleiro.h"

int main(void) {
    Lista_jogo* lst = cria_lista_jogo();

    InfoJogo jogo1;
    jogo1.preco1Dia = 10;
    jogo1.preco7Dias = 25;
    jogo1.qtd_estoque = 5;
    jogo1.qtd_alugada1 = 0;
    jogo1.qtd_alugada7 = 0;

    printf("\nTestando funcao inclui jogo:\n\n");
    int resultado = incluirJogo(lst, "Assassinos", jogo1);
    incluirJogo(lst, "Justiceiros", jogo1);
    if (resultado == SUCESS_INCLUI) {
        printf("Retorno SUCESS_INCLUI OK.\n");
    } else {
        printf("Retorno SUCESS_INCLUI NOT OK.\n");
    }
    resultado = incluirJogo(lst, "Assassinos", jogo1);
    if (resultado == ERROR_ITEMJAEXISTE) {
        printf("Retorno ERROR_ITEMJAEXISTE OK.\n");
    } else {
        printf("Retorno ERROR_ITEMJAEXISTE NOT OK.\n");
    }
    printf("\nFim dos testes da funcao inclui jogo.\n");

    printf("\nTestando funcao busca e exibe dados do jogo:\n\n");
    resultado = buscarJogoExibe("Assassinos", lst);
    if (resultado == SUCESS_ENCONTRADO) {
        printf("Retorno SUCESS_ENCONTRADO OK.\n");
    } else {
        printf("Retorno SUCESS_ENCONTRADO NOT OK.\n");
    }
    resultado = buscarJogoExibe("Assassinoso", lst);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    Lista_jogo* lst_nova = cria_lista_jogo();
    resultado = buscarJogoExibe("Assassinos", lst_nova);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    printf("\nFim dos testes da funcao busca e exibe dados do jogo.\n");

    printf("\nTestando funcao atualiza dados do jogo:\n\n");
    InfoJogo jogo2;
    jogo2.preco1Dia = 18;
    jogo2.preco7Dias = 27;
    jogo2.qtd_estoque = 8;
    jogo2.qtd_alugada1 = 0;
    jogo2.qtd_alugada7 = 0;
    resultado = atualizacaoJogo("Assassinos", lst, jogo2);
    //buscarJogoExibe("Assassinos", lst);
    if (resultado == SUCESS_ATUALIZA) {
        printf("Retorno SUCESS_ATUALIZA OK.\n");
    } else {
        printf("Retorno SUCESS_ATUALIZA NOT OK.\n");
    }
    resultado = atualizacaoJogo("Assassinos", lst_nova, jogo2);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = atualizacaoJogo("Assassinoso", lst, jogo2);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    printf("\nFim dos testes da funcao atualiza dados do jogo.\n");

    printf("\nTestando funcao deleta dados do jogo:\n\n");
    resultado = excluirJogo("Assassinos", lst_nova);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = excluirJogo("Assassinoso", lst);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    resultado = excluirJogo("Assassinos", lst);
    if (resultado == SUCESS_DELETE) {
        printf("Retorno SUCESS_DELETE OK.\n");
    } else {
        printf("Retorno SUCESS_DELETE NOT OK.\n");
    }
    printf("\nFim dos testes da funcao deleta dados do jogo.\n");

    return 0;
}
