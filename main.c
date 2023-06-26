#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo_de_tabuleiro.h"
#include "consumidor.h"
#include "dinheiro.h"
#include "contato_fornecedor.h

void rotinaDevolucao(Lista_jogo* lst_jogo);
void rotinaAluguel(Lista_jogo* lst_jogo, Lista_consumidor* lst_consumidor);
void rotinaInserirNovoJogo(Lista_jogo* lst_jogo);


int main(void) {
    // definicao das variaveis
    Lista_jogo* lst_jogo = cria_lista_jogo();
    Lista_consumidor* lst_consumidor = cria_lista_consumidor();
    float saldo;
    int resultado;
    // fazer leitura do xml relacionada com o dinheiro
    resultado = lerXMLDinheiro(&saldo);
    if(resultado == ERROR_ARQUIVONEXISTE){
        saldo = 0;
    }
    // fazer leitura do xml dos consumidores
    lerXMLConsumidor(lst_consumidor);
    // fazer leitura do xml dos jogos de tabuleiros
    lerXMLJogo(lst_jogo);
    // verificar atualizacao nas solicitacoes de compras de jogos
    lerFornecedor(lst_jogo);
    // loop de rotinas
    while( 0 == 0 ){
        char controleRotina;
        printf("\n\n");
        printf("Aperte (1) para fazer a devolucao de um jogo (2) para fazer o aluguel de um jogo (3) para incluir novo jogo (4) para encerrar o programa: ");
        scanf(" %c", &controleRotina);
        printf("\n\n");
        if(controleRotina == '1'){
            // rotina de devolucao
            rotinaDevolucao(lst_jogo);
        } else if (controleRotina == '2'){
            // rotina de aluguel
            rotinaAluguel(lst_jogo,lst_consumidor);
        } else if (controleRotina == '3'){
            // rotina de insercao de novo jogo
            rotinaInserirNovoJogo(lst_jogo);
        } else if (controleRotina == '4'){
            break;
        } else {
            printf("\nCaractere inserido invalido.\n");
        }
    }

    
    // salva em xml dados da lista de jogo
    rotinaJogoEscritaXML(lst_jogo);
    // salva em xml dados da lista de consumidores
    rotinaConsumidorEscritaXML(lst_consumidor);
    // libera memoria de lista de jogo
    limpa_lista_jogo(lst_jogo);
    // libera memoria de lista de consumidor
    limpa_lista_consumidor(lst_consumidor);
    return 0;
}

void rotinaDevolucao(Lista_jogo* lst_jogo){
    while(0 == 0 ){
        int resultado;
        char nome_jogo[20];
        char controleRotina;
        printf("\n\n");
        printf("Coloque o nome do jogo a ser devolvido: ");
        scanf(" %[^\n]", nome_jogo);
        printf("\n\n");
        resultado = atualizacaoJogoDevolvido7( nome_jogo, lst_jogo);
        if(resultado == ERROR_LISTAVAZIA){
            printf("O sistema ainda nao possui nenhum jogo nos dados.\n");
            break;
        } else if(resultado == ERROR_NAOENCONTRADO){
            printf("O jogo em questao nao foi encontrado nos dados do sistema.\n");
            printf("Se quiser fazer uma nova tentativa digite (1): ");
            scanf(" %c",&controleRotina);
            if(controleRotina != '1'){
                break;
            }
        } else if(resultado == ERROR_NAOALUGADO){
            printf("O jogo em questao foi encontrado, porem nao tinha sido alugado.\n");
            break;
        } else if(resultado == SUCCESS_DEVOLUCAO){
            printf("Devolucao realizada com SUCCESSo, para ver dados sobre o jogo devolvido digite (1) para voltar a tela inicial digite (2): ");
            scanf(" %c",&controleRotina);
            if (controleRotina == '2'){
                break;
            } else if (controleRotina == '1'){
                printf("\n\n");
                buscarJogoExibe( nome_jogo, lst_jogo);
                break;
            }
        }
    }
    printf("\n\n");
}

void rotinaAluguel(Lista_jogo* lst_jogo, Lista_consumidor* lst_consumidor){
    while (0 == 0) {
        int resultado;
        float valor;
        char nome_jogo[20];
        char controleRotina;
        char cidadao_cpf[20];

        printf("\n\n");
        printf("Coloque o nome do jogo a ser alugado: ");
        scanf(" %[^\n]", nome_jogo);
        getchar(); // Limpar o caractere de nova linha residual no buffer

        printf("\n\n");
        printf("Digite (1) para alugar por 1 dia e (2) para 7 dias: ");
        scanf(" %c%*c", &controleRotina);

        if (controleRotina == '2') {
            resultado = atualizacaoJogoAlugado7(nome_jogo, lst_jogo, &valor);
        } else if (controleRotina == '1') {
            resultado = atualizacaoJogoAlugado1(nome_jogo, lst_jogo, &valor);
        } else {
            break;
        }

        if (resultado == ERROR_LISTAVAZIA) {
            printf("O sistema ainda nao possui nenhum jogo nos dados.\n");
            break;
        } else if (resultado == ERROR_NAOENCONTRADO) {
            printf("O jogo em questao nao foi encontrado nos dados do sistema.\n");
            printf("Se quiser fazer uma nova tentativa digite (1): ");
            scanf(" %c%*c", &controleRotina);
            if (controleRotina != '1') {
                break;
            }
        } else if (resultado == ERROR_SEMESTOQUE) {
            printf("Jogo indisponivel no momento.\n");
            break;
        } else if (resultado == ERROR_SOLICITARCOMPRA) {
            // função do fornecedor para solicitar jogo
            break;
        } else if (resultado == SUCCESS_ALUGADO) {
            // função de somar dinheiro da locadora
            atualizaSaldo(valor,0);
            printf("Aperte (1) para registrar o consumidor que realizou a compra ou qualquer outra tecla para nao registrar: ");
            scanf(" %c%*c", &controleRotina);

            while (0 == 0) {
                if (controleRotina == '1') {
                    printf("\n\n");
                    printf("Coloque o cpf do consumidor: ");
                    fgets(cidadao_cpf, sizeof(cidadao_cpf), stdin);
                    cidadao_cpf[strcspn(cidadao_cpf, "\n")] = '\0'; // Remover o caractere de nova linha

                    printf("\n\n");
                    resultado = buscarConsumidorExibe(cidadao_cpf, lst_consumidor);

                    if (resultado == ERROR_INVALIDOCPF) {
                        printf("Aperte (1) se quiser tentar inserir com o cpf certo ou qualquer outra tecla para nao registrar: ");
                        scanf(" %c%*c", &controleRotina);
                    } else if (resultado == ERROR_LISTAVAZIA || resultado == ERROR_NAOENCONTRADO) {
                        InfoConsumidor consumidor;
                        printf("Digite o nome: ");
                        fgets(consumidor.nome, sizeof(consumidor.nome), stdin);
                        consumidor.nome[strcspn(consumidor.nome, "\n")] = '\0'; // Remover o caractere de nova linha

                        printf("Digite o sobrenome: ");
                        fgets(consumidor.sobrenome, sizeof(consumidor.sobrenome), stdin);
                        consumidor.sobrenome[strcspn(consumidor.sobrenome, "\n")] = '\0'; // Remover o caractere de nova linha

                        printf("Digite o número de celular: ");
                        fgets(consumidor.celular, sizeof(consumidor.celular), stdin);
                        consumidor.celular[strcspn(consumidor.celular, "\n")] = '\0'; // Remover o caractere de nova linha

                        printf("Digite o endereço: ");
                        fgets(consumidor.endereco, sizeof(consumidor.endereco), stdin);
                        consumidor.endereco[strcspn(consumidor.endereco, "\n")] = '\0'; // Remover o caractere de nova linha

                        incluirConsumidor(lst_consumidor, cidadao_cpf, consumidor);
                        break;
                    } else if (resultado == SUCCESS_ENCONTRADO) {
                        break;
                    }
                } else {
                    break;
                }
            }

            break;
        }
    }
}

void rotinaInserirNovoJogo(Lista_jogo* lst_jogo){
    int resultado;
    char nome_jogo[20];
    char controleRotina;
    printf("\n\n");
    printf("Coloque o nome do jogo a ser incluido: ");
    scanf(" %[^\n]", nome_jogo);
    printf("\n\n");

    resultado = buscarJogoExibe(nome_jogo,lst_jogo);
    if (resultado == ERROR_LISTAVAZIA || resultado == ERROR_NAOENCONTRADO){
        InfoJogo jogo;

        printf("Digite o preço para 1 dia de aluguel: ");
        scanf("%f", &jogo.preco1Dia);
        
        printf("Digite o preço para 7 dias de aluguel: ");
        scanf("%f", &jogo.preco7Dias);
        
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &jogo.qtd_estoque);
        
        jogo.qtd_alugada1 = 0;
        jogo.qtd_alugada7 = 0;
        jogo.solicitacoes = 0;

        incluirJogo(lst_jogo, nome_jogo,jogo);
    } else {
        printf("\n\n");
        printf("Aperte (1) para atualizar ou qualquer outra tecla para nao alterar: ");
        scanf(" %c", &controleRotina);
        if (controleRotina == '1'){
            InfoJogo jogo;

            printf("Digite o preço para 1 dia de aluguel: ");
            scanf("%f", &jogo.preco1Dia);
            
            printf("Digite o preço para 7 dias de aluguel: ");
            scanf("%f", &jogo.preco7Dias);
            
            printf("Digite a quantidade em estoque: ");
            scanf("%d", &jogo.qtd_estoque);
            
            jogo.qtd_alugada1 = 0;
            jogo.qtd_alugada7 = 0;
            jogo.solicitacoes = 0;

            atualizacaoJogo(nome_jogo,lst_jogo,jogo);

        }
    }
}
