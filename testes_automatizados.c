#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consumidor.h"
#include "jogo_de_tabuleiro.h"

int main(void) {

    // TESTES DO MODULO CONSUMIDOR //
    printf("Iniciando testes do modulo Consumidor.\n");
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
    if (resultado == SUCCESS_CPF) {
        printf("Retorno SUCCESS_CPF OK.\n");
    } else {
        printf("Retorno SUCCESS_CPF NOT OK.\n");
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
    if (resultado == SUCCESS_INCLUI) {
        printf("Retorno SUCCESS_INCLUI OK.\n");
    } else {
        printf("Retorno SUCCESS_INCLUI NOT OK.\n");
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
    if (resultado == SUCCESS_ENCONTRADO) {
        printf("Retorno SUCCESS_ENCONTRADO OK.\n");
    } else {
        printf("Retorno SUCCESS_ENCONTRADO NOT OK.\n");
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
    if (resultado == SUCCESS_ATUALIZA) {
        printf("Retorno SUCCESS_ATUALIZA OK.\n");
    } else {
        printf("Retorno SUCCESS_ATUALIZA NOT OK.\n");
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
    if (resultado == SUCCESS_ESCRITA) {
        printf("Retorno SUCCESS_ESCRITA OK.\n");
    } else {
        printf("Retorno SUCCESS_ESCRITA NOT OK.\n");
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
    if (resultado == SUCCESS_DELETE) {
        printf("Retorno SUCCESS_DELETE OK.\n");
    } else {
        printf("Retorno SUCCESS_DELETE NOT OK.\n");
    }
    resultado = excluirConsumidor("1r2-9g3-317-74", lst);
    if (resultado == ERROR_INVALIDOCPF) {
        printf("Retorno ERROR_INVALIDOCPF OK.\n");
    } else {
        printf("Retorno ERROR_INVALIDOCPF NOT OK.\n");
    }
    printf("\nFim dos testes da funcao deleta dados do consumidor.\n");
    printf("Fim dos testes do modulo Consumidor.\n");

    // TESTES DO MODULO FORNECEDOR //
    printf("Inicio dos testes do modulo Fornecedor.\n");
    int resultado;

    printf("Testando a funcao envia_jogo:\n");

    resultado = envia_jogo("Jogo da Vida", 1);
    if(resultado == SUCCESS){
        printf("retorno SUCCESS OK\n");
    } else if(resultado == ERROR_ESCRITA){
        printf("Houve um erro na escrita.\n");
    }
    else {
        printf("retorno SUCCESS NOT OK\n");
    }

    printf("Fim dos testes da funcao envia_jogo\n");
    printf("Fim dos testes do modulo Fornecedor.\n");

    // TESTES DO MODULO DINHEIRO
    printf("Inicio dos testes do modulo Dinheiro.\n");

    float preco;
    int resultado;

    printf("Testando a funcao avaliaCompra:\n");

    preco = 70;
    resultado = avaliaCompra(preco);

    if(resultado == ERROR_LEITURA){
        printf("Houve um erro na leitura do arquivo.\n");
    }
    if(resultado == SUCCESS){
        printf("Retorno SUCESS OK.\n");
    } else {
        printf("Retorno SUCESS NOT OK.\n");
    }

    preco = 999.99;
    resultado = avaliaCompra(preco);

    if(resultado == ERROR_LEITURA){
        printf("Houve um erro na leitura do arquivo.\n");
    }
    if(resultado == ERROR_COMPRA){
        printf("Retorno ERROR_COMPRA OK.\n");
    } else {
        printf("Retorno ERROR_COMPRA NOT OK.\n");
    }
    printf("Fim dos testes da avaliaCompra.\n");

    printf("Testando a funcao atualizaSaldo:\n");

    preco = -9999;
    resultado = atualizaSaldo(preco);

    if(resultado == ERROR_SALDONEG){
        printf("Retorno ERROR_SALDONEG OK\n");
    } else {
        printf("Retorno ERROR_SALDONEG NOT OK.\n");
    }

    preco = 10;
    resultado = atualizaSaldo(preco);

    if(resultado == ERROR_ESCRITA){
        printf("Houve um erro na escrita do arquivo.\n");
    }
    if(resultado == SUCCESS){
        printf("Retorno SUCESS OK\n");
    } else {
        printf("Retorno SUCESS NOT OK.\n");
    }
    printf("Fim dos testes da atualizaSaldo.\n");
    printf("Fim dos testes do modulo Dinheiro\n.");

    // TESTES DO MODULO JOGO DE TABULEIRO //

    printf("Inicio dos testes do modulo Jogo de Tabuleiro.\n");
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
    printf("Fim dos testes do modulo Jogo de Tabuleiro.\n");

    // TESTE DO MODULO LISTAS //
    printf("Inicio dos testes do modulo Listas.\n");
    No* lst = NULL;

    int* info = (int*) malloc(sizeof(int));
    if( info == NULL){
        //printf("Nao foi possivel alocar memoria para novo item.\n");
        return ERROR_MALLOC;
    }
    *info = 15;
    char identificador[20] = "Gustavo";
    int* info2 = (int*) malloc(sizeof(int));
    if( info2 == NULL){
        //printf("Nao foi possivel alocar memoria para novo item.\n");
        return ERROR_MALLOC;
    }
    *info2 = 18;
    char identificador2[20] = "Eduardo";
    int* info3 = (int*) malloc(sizeof(int));
    if( info3 == NULL){
        //printf("Nao foi possivel alocar memoria para novo item.\n");
        return ERROR_MALLOC;
    }
    *info3 = 20;
    char identificador3[20] = "Felipe";
    inclui(&lst, info3, identificador3);
    inclui(&lst, info2, identificador2);
    printf("\nTestando funcao inclui :\n\n");
    int resultado = inclui(&lst, info, identificador);
    if(resultado == SUCCESS_INCLUI){
        printf("Retorno SUCCESS_INCLUI OK.\n");
    } else {
        printf("Retorno SUCCESS_INCLUI NOT OK.\n");
    }
    resultado = inclui(&lst, info, identificador);
    if(resultado == ERROR_ITEMJAEXISTE){
        printf("Retorno ERROR_ITEMJAEXISTE OK.\n");
    } else {
        printf("Retorno ERROR_ITEMJAEXISTE NOT OK.\n");
    }
    printf("\nFim dos testes da funcao inclui.\n");

    printf("\nTestando funcao busca :\n\n");
    No* item_um;
    No* lst_nova = NULL;
    resultado = busca(lst_nova, "Gustavo", &item_um);
    if (resultado == ERROR_LISTAVAZIA){
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = busca(lst, "Gustavoo", &item_um);
    if (resultado == ERROR_NAOENCONTRADO){
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }
    resultado = busca(lst, "Gustavo", &item_um);
    if (resultado == SUCCESS_ENCONTRADO){
        printf("Retorno SUCCESS_ENCONTRADO OK.\n");
    } else {
        printf("Retorno SUCCESS_ENCONTRADO NOT OK.\n");
    }
    printf("\nFim dos testes da funcao busca.\n");

    printf("\nTestando funcao atualiza :\n\n");
    int* info_nova = (int*) malloc(sizeof(int));
    if( info_nova == NULL){
        //printf("Nao foi possivel alocar memoria para novo item.\n");
        return ERROR_MALLOC;
    }
    *info_nova = 8;
    resultado = atualiza(&lst_nova,info_nova, "Gustavo");
    if (resultado == ERROR_LISTAVAZIA){
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = atualiza(&lst,info_nova, "Gustavoo");
    if (resultado == ERROR_NAOENCONTRADO){
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    }  
    resultado = atualiza(&lst,info_nova, "Gustavo");
    if (resultado == SUCCESS_ATUALIZA){
        printf("Retorno SUCCESS_ATUALIZA OK.\n");
    } else {
        printf("Retorno SUCCESS_ATUALIZA NOT OK.\n");
    }
    printf("\nFim dos testes da funcao atualiza.\n");

    printf("\nTestando funcao percorre_lista_em_ordem :\n\n");
    No* lst_teste = lst;
    char nome[20];
    resultado = percorre_lista_em_ordem(nome, &lst_teste);
    printf("%s\n",nome);
    percorre_lista_em_ordem(nome, &lst_teste);
    percorre_lista_em_ordem(nome,&lst_teste);
    if (resultado == SUCCESS){
        printf("Retorno SUCCESS OK.\n");
    } else {
        printf("Retorno SUCCESS NOT OK.\n");
    }
    resultado = percorre_lista_em_ordem(nome, &lst_teste);
    if (resultado == ERROR_LISTAVAZIA){
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    printf("\nFim dos testes da funcao percorre_lista_em_ordem.\n");

    printf("\nTestando funcao deleta :\n\n");
    resultado = deleta(&lst_nova,"Gustavo");
    if (resultado == ERROR_LISTAVAZIA){
        printf("Retorno ERROR_LISTAVAZIA OK.\n");
    } else {
        printf("Retorno ERROR_LISTAVAZIA NOT OK.\n");
    }
    resultado = deleta(&lst,"Gustavoo");
    if (resultado == ERROR_NAOENCONTRADO){
        printf("Retorno ERROR_NAOENCONTRADO OK.\n");
    } else {
        printf("Retorno ERROR_NAOENCONTRADO NOT OK.\n");
    } 
    resultado = deleta(&lst,"Felipe");
    if (resultado == SUCCESS_DELETE){
        printf("Retorno SUCCESS_DELETE OK.\n");
    } else {
        printf("Retorno SUCCESS_DELETE NOT OK.\n");
    }
    resultado = deleta(&lst,"Gustavo");
    if (resultado == SUCCESS_DELETE){
        printf("Retorno SUCCESS_DELETE OK.\n");
    } else {
        printf("Retorno SUCCESS_DELETE NOT OK.\n");
    }   
    printf("\nFim dos testes da funcao deleta.\n");
    printf("Fim dos testes do modulo Listas.\n");

    printf("FIM DOS TESTES AUTOMATIZADOS");
    return 0;   
}
