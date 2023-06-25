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

    InfoJogo jogo2;
    jogo2.preco1Dia = 18;
    jogo2.preco7Dias = 27;
    jogo2.qtd_estoque = 8;
    jogo2.qtd_alugada1 = 0;
    jogo2.qtd_alugada7 = 0;

    InfoJogo jogo3;
    jogo3.preco1Dia = 12;
    jogo3.preco7Dias = 50;
    jogo3.qtd_estoque = 1;
    jogo3.qtd_alugada1 = 0;
    jogo3.qtd_alugada7 = 0;

    printf("\nTestando funcao inclui jogo:\n\n");
    int resultado = incluirJogo(lst, "Assassinos", jogo1);
    incluirJogo(lst, "Tartarugas Ninjas I", jogo3);
    incluirJogo(lst, "Tartarugas Ninjas V", jogo3);
    incluirJogo(lst, "Justiceiros", jogo1);
    if (resultado == SUCCESS_INCLUI) {
        printf("Retorno SUCCESS_INCLUI OK.\n");
    } else {
        printf("Retorno SUCCESS_INCLUI NOT OK.\n");
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
    if (resultado == SUCCESS_ENCONTRADO) {
        printf("Retorno SUCCESS_ENCONTRADO OK.\n");
    } else {
        printf("Retorno SUCCESS_ENCONTRADO NOT OK.\n");
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
    resultado = atualizacaoJogo("Assassinos", lst, jogo2);
    //buscarJogoExibe("Assassinos", lst);
    if (resultado == SUCCESS_ATUALIZA) {
        printf("Retorno SUCCESS_ATUALIZA OK.\n");
    } else {
        printf("Retorno SUCCESS_ATUALIZA NOT OK.\n");
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

    printf("\nTestando funcao aluga jogo 7 dias:\n\n");
    float preco;
    resultado = atualizacaoJogoAlugado7("Tartarugas Ninjas I", lst, &preco);
    if (resultado == SUCCESS_ALUGADO) {
        printf("Retorno SUCCESS_ALUGADO OK.\n");
    } else {
        printf("Retorno SUCCESS_ALUGADO NOT OK.\n");
    }
    resultado = atualizacaoJogoAlugado7("Assassinoso", lst, &preco);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    resultado = atualizacaoJogoAlugado7("Assassinos", lst_nova, &preco);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = atualizacaoJogoAlugado7("Tartarugas Ninjas I", lst, &preco);
    if (resultado == ERROR_SEMESTOQUE) {
        printf("Retorno ERROR_SEMESTOQUE OK.\n");
    } else {
        printf("Retorno ERROR_SEMESTOQUE NOT OK.\n");
    }
    atualizacaoJogoAlugado7("Tartarugas Ninjas I", lst, &preco);
    resultado = atualizacaoJogoAlugado7("Tartarugas Ninjas I", lst, &preco);
    if (resultado == ERROR_SOLICITARCOMPRA) {
        printf("Retorno ERROR_SOLICITARCOMPRA OK.\n");
    } else {
        printf("Retorno ERROR_SOLICITARCOMPRA NOT OK.\n");
    }
    printf("\nFim dos testes da funcao aluga jogo 7 dias.\n");

    printf("\nTestando funcao aluga jogo 1 dias:\n\n");
    resultado = atualizacaoJogoAlugado1("Tartarugas Ninjas V", lst, &preco);
    if (resultado == SUCCESS_ALUGADO) {
        printf("Retorno SUCCESS_ALUGADO OK.\n");
    } else {
        printf("Retorno SUCCESS_ALUGADO NOT OK.\n");
    }
    resultado = atualizacaoJogoAlugado1("Assassinoso", lst, &preco);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    resultado = atualizacaoJogoAlugado1("Assassinos", lst_nova, &preco);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = atualizacaoJogoAlugado1("Tartarugas Ninjas V", lst, &preco);
    if (resultado == ERROR_SEMESTOQUE) {
        printf("Retorno ERROR_SEMESTOQUE OK.\n");
    } else {
        printf("Retorno ERROR_SEMESTOQUE NOT OK.\n");
    }
    atualizacaoJogoAlugado1("Tartarugas Ninjas V", lst, &preco);
    resultado = atualizacaoJogoAlugado1("Tartarugas Ninjas V", lst, &preco);
    if (resultado == ERROR_SOLICITARCOMPRA) {
        printf("Retorno ERROR_SOLICITARCOMPRA OK.\n");
    } else {
        printf("Retorno ERROR_SOLICITARCOMPRA NOT OK.\n");
    }
    printf("\nFim dos testes da funcao aluga jogo 1 dias.\n");
    
    printf("\nTestando funcao devolve jogo alugado por 7 dias:\n\n");
    resultado = atualizacaoJogoDevolvido7("Tartarugas Ninjas I", lst);
    if (resultado == SUCCESS_DEVOLUCAO) {
        printf("Retorno SUCCESS_DEVOLUCAO OK.\n");
    } else {
        printf("Retorno SUCCESS_DEVOLUCAO NOT OK.\n");
    }
    resultado = atualizacaoJogoDevolvido7("Assassinoso", lst);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    resultado = atualizacaoJogoDevolvido7("Assassinos", lst_nova);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = atualizacaoJogoDevolvido7("Tartarugas Ninjas I", lst);
    if (resultado == ERROR_NAOALUGADO) {
        printf("Retorno ERROR_NAOALUGADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOALUGADO NOT OK.\n");
    }
    printf("\nFim dos testes da funcao devolve jogo alugado por 7 dias.\n");

    printf("\nTestando funcao devolve jogo alugado por 1 dias:\n\n");
    resultado = atualizacaoJogoDevolvido1("Tartarugas Ninjas V", lst);
    if (resultado == SUCCESS_DEVOLUCAO) {
        printf("Retorno SUCCESS_DEVOLUCAO OK.\n");
    } else {
        printf("Retorno SUCCESS_DEVOLUCAO NOT OK.\n");
    }
    resultado = atualizacaoJogoDevolvido1("Assassinoso", lst);
    if (resultado == ERROR_NAOENCONTRADO) {
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    resultado = atualizacaoJogoDevolvido1("Assassinos", lst_nova);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = atualizacaoJogoDevolvido1("Tartarugas Ninjas V", lst);
    if (resultado == ERROR_NAOALUGADO) {
        printf("Retorno ERROR_NAOALUGADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOALUGADO NOT OK.\n");
    }
    printf("\nFim dos testes da funcao devolve jogo alugado por 1 dias.\n");

    printf("\nTestando funcao grava xml:\n\n");
    resultado = rotinaJogoEscritaXML(lst);
    if (resultado == SUCCESS_ESCRITA) {
        printf("Retorno SUCCESS_ESCRITA OK.\n");
    } else {
        printf("Retorno SUCCESS_ESCRITA NOT OK.\n");
    }
    resultado = rotinaJogoEscritaXML(lst_nova);
    if (resultado == ERROR_LISTAVAZIA) {
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    printf("\nFim dos testes da funcao grava xml.\n");

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
    if (resultado == SUCCESS_DELETE) {
        printf("Retorno SUCCESS_DELETE OK.\n");
    } else {
        printf("Retorno SUCCESS_DELETE NOT OK.\n");
    }
    printf("\nFim dos testes da funcao deleta dados do jogo.\n");

    return 0;
}
