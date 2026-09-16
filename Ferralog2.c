#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
===========================================================
              SISTEMA FERRALOG - INVENTARIO
===========================================================

Neste programa vamos trabalhar com:

- Variaveis
- Arrays (vetores)
- printf()
- scanf()
- if / else
- switch / case
- do / while
- for
- operador &&
- Sleep()
- fflush()
- system("cls")

O sistema permite:

[1] Cadastrar ferramentas
[2] Consultar ferramentas cadastradas
[3] Verificar garantia
[4] Sair

As ferramentas ficam armazenadas na memoria enquanto
o programa estiver aberto.
===========================================================
*/


/*
-----------------------------------------------------------
QUANTIDADE MAXIMA DE FERRAMENTAS
-----------------------------------------------------------

Aqui definimos que o sistema poderá armazenar
ate 100 ferramentas.

Se quiser aumentar, basta mudar o numero.
*/

#define MAX_FERRAMENTAS 100


int main() {

    /*
    -------------------------------------------------------
    VARIAVEIS
    -------------------------------------------------------
    */

    int opcao_menu;

    /*
    Quantidade de ferramentas cadastradas.

    Comeca com 0 porque ainda nao temos nenhuma.
    */
    int quantidade_ferramentas = 0;


    /*
    -------------------------------------------------------
    ARRAYS PARA ARMAZENAR AS FERRAMENTAS
    -------------------------------------------------------

    Cada posicao representa uma ferramenta.

    Exemplo:

    nome[0] = primeira ferramenta
    nome[1] = segunda ferramenta
    nome[2] = terceira ferramenta

    E assim por diante.
    */

    char nome[MAX_FERRAMENTAS][100];

    float valor_compra[MAX_FERRAMENTAS];

    int codigo_qr[MAX_FERRAMENTAS];

    int possui_garantia[MAX_FERRAMENTAS];


    /*
    Variavel usada para percorrer as ferramentas
    usando o for.
    */

    int i;


    /*
    -------------------------------------------------------
    TELA DE CARREGAMENTO
    -------------------------------------------------------
    */

    printf("Iniciando o sistema FerraLog...\n\n");

    Sleep(1000);

    printf("[*] Conectando ao banco de dados de inventario...\n");

    Sleep(1500);

    printf("[*] Carregando modulo de leitura de QR Code...\n");

    Sleep(1500);

    printf("[*] Verificando status e validade das garantias...\n");

    Sleep(2000);

    printf("[*] Sincronizando dados...\n\n");

    Sleep(1000);


    /*
    -------------------------------------------------------
    BARRA DE PROGRESSO
    -------------------------------------------------------

    O for vai repetir 20 vezes.

    A cada repeticao:
    - aparece um #
    - o programa atualiza a tela
    - espera 100 milissegundos
    */

    printf("Carregando: ");

    for (i = 0; i < 20; i++) {

        printf("#");

        /*
        Forca o computador a mostrar o # imediatamente.
        */
        fflush(stdout);

        Sleep(100);
    }

    printf(" 100%%\n\n");

    Sleep(500);

    system("cls");


    /*
    =======================================================
                    MENU PRINCIPAL
    =======================================================

    O do-while faz o menu continuar aparecendo.

    O programa somente termina quando:
    
    opcao_menu == 4
    */

    do {

        printf("========================================\n");
        printf("         SISTEMA FERRALOG\n");
        printf("            INVENTARIO\n");
        printf("========================================\n\n");

        printf("Ferramentas cadastradas: %d\n\n",
               quantidade_ferramentas);

        printf("[1] Cadastrar nova ferramenta\n");

        printf("[2] Consultar ferramentas cadastradas\n");

        printf("[3] Verificar status de garantia\n");

        printf("[4] Sair do sistema\n");

        printf("========================================\n");

        printf("Digite a opcao desejada: ");

        scanf("%d", &opcao_menu);


        /*
        ===================================================
                         SWITCH / CASE
        ===================================================
        */

        switch (opcao_menu) {


            /*
            =================================================
                         CASE 1
                 CADASTRAR NOVA FERRAMENTA
            =================================================
            */

            case 1:

                system("cls");


                /*
                ------------------------------------------------
                VERIFICAR SE O SISTEMA ESTA CHEIO
                ------------------------------------------------

                Se a quantidade chegar a 100,
                nao sera possivel cadastrar outra.
                */

                if (quantidade_ferramentas >= MAX_FERRAMENTAS) {

                    printf("========================================\n");

                    printf("ERRO: Limite de ferramentas atingido!\n");

                    printf("========================================\n");

                    printf("\nPressione ENTER para continuar...");

                    getchar();
                    getchar();

                    break;
                }


                printf("========================================\n");
                printf("       CADASTRO DE FERRAMENTA\n");
                printf("========================================\n\n");


                /*
                ------------------------------------------------
                NOME
                ------------------------------------------------
                */

                printf("Digite o nome da ferramenta: ");

                scanf(" %99[^\n]",
                      nome[quantidade_ferramentas]);


                /*
                ------------------------------------------------
                VALOR
                ------------------------------------------------
                */

                printf("Digite o valor da compra: R$ ");

                scanf("%f",
                      &valor_compra[quantidade_ferramentas]);


                /*
                ------------------------------------------------
                CODIGO QR
                ------------------------------------------------
                */

                printf("Digite o codigo QR: ");

                scanf("%d",
                      &codigo_qr[quantidade_ferramentas]);


                /*
                ------------------------------------------------
                GARANTIA
                ------------------------------------------------

                1 = Sim
                2 = Nao
                */

                do {

                    printf("\nA ferramenta possui garantia?\n");

                    printf("[1] Sim\n");

                    printf("[2] Nao\n");

                    printf("Digite uma opcao: ");

                    scanf("%d",
                          &possui_garantia[quantidade_ferramentas]);


                    /*
                    Se for diferente de 1 E diferente de 2,
                    a opcao e invalida.
                    */

                    if (possui_garantia[quantidade_ferramentas] != 1 &&
                        possui_garantia[quantidade_ferramentas] != 2) {

                        printf("\nERRO: Opcao invalida!\n");

                    }

                } while (
                    possui_garantia[quantidade_ferramentas] != 1 &&
                    possui_garantia[quantidade_ferramentas] != 2
                );


                /*
                ------------------------------------------------
                VALIDACAO DO VALOR
                ------------------------------------------------

                O valor precisa ser maior que zero.
                */

                system("cls");


                if (valor_compra[quantidade_ferramentas] > 0) {


                    /*
                    --------------------------------------------
                    RECIBO
                    --------------------------------------------
                    */

                    printf("========================================\n");
                    printf("          RECIBO DE CADASTRO\n");
                    printf("========================================\n\n");


                    printf("Nome: %s\n",
                           nome[quantidade_ferramentas]);


                    printf("Valor: R$ %.2f\n",
                           valor_compra[quantidade_ferramentas]);


                    printf("Codigo QR: %d\n",
                           codigo_qr[quantidade_ferramentas]);


                    if (possui_garantia[quantidade_ferramentas] == 1) {

                        printf("Garantia: SIM\n");

                    } else {

                        printf("Garantia: NAO\n");

                    }


                    /*
                    --------------------------------------------
                    ALERTA DE ALTO RISCO
                    --------------------------------------------

                    Regra:

                    Valor maior que R$ 1.000
                    E
                    Sem garantia.
                    */

                    if (
                        valor_compra[quantidade_ferramentas] > 1000 &&
                        possui_garantia[quantidade_ferramentas] == 2
                    ) {

                        printf("\n");
                        printf("!!! ALERTA DE ALTO RISCO !!!\n");

                        printf("Ferramenta acima de R$ 1.000,00 ");

                        printf("sem garantia.\n");

                    } else {

                        printf("\nStatus de risco: Normal\n");

                    }


                    /*
                    ------------------------------------------------
                    AUMENTAR A QUANTIDADE DE FERRAMENTAS
                    ------------------------------------------------

                    Somente depois que o cadastro foi validado,
                    aumentamos a quantidade.

                    Exemplo:

                    Antes:
                    quantidade = 0

                    Depois do cadastro:
                    quantidade = 1
                    */

                    quantidade_ferramentas++;


                    printf("\n========================================\n");

                    printf("Ferramenta cadastrada com sucesso!\n");

                    printf("========================================\n");


                } else {

                    /*
                    Se o valor for 0 ou negativo,
                    a ferramenta nao sera cadastrada.
                    */

                    printf("========================================\n");

                    printf("ERRO: Valor Invalido!\n");

                    printf("O valor deve ser maior que zero.\n");

                    printf("========================================\n");

                }


                printf("\nPressione ENTER para voltar ao menu...");

                getchar();
                getchar();

                break;


            /*
            =================================================
                    CASE 2
               CONSULTAR FERRAMENTAS
            =================================================
            */

            case 2:

                system("cls");


                /*
                Verifica se existe pelo menos uma ferramenta.
                */

                if (quantidade_ferramentas == 0) {

                    printf("========================================\n");

                    printf("     NENHUMA FERRAMENTA CADASTRADA\n");

                    printf("========================================\n");

                } else {


                    printf("========================================\n");

                    printf("       FERRAMENTAS CADASTRADAS\n");

                    printf("========================================\n\n");


                    /*
                    ------------------------------------------------
                    LISTA DAS FERRAMENTAS
                    ------------------------------------------------

                    O for percorre todas as ferramentas.

                    i = 0
                    i = 1
                    i = 2
                    etc.
                    */

                    for (i = 0;
                         i < quantidade_ferramentas;
                         i++) {


                        printf("[%d] %s\n",
                               i + 1,
                               nome[i]);

                    }


                    printf("\n========================================\n");

                    printf("Digite o numero da ferramenta que deseja ver: ");


                    /*
                    Criamos uma variavel para guardar
                    a escolha do usuario.
                    */

                    int escolha_ferramenta;

                    scanf("%d", &escolha_ferramenta);


                    /*
                    ------------------------------------------------
                    VALIDACAO DA ESCOLHA
                    ------------------------------------------------

                    Se o usuario escolher 1, acessamos:

                    vetor[0]

                    Se escolher 2:

                    vetor[1]

                    Por isso usamos:

                    escolha_ferramenta - 1
                    */

                    if (
                        escolha_ferramenta >= 1 &&
                        escolha_ferramenta <= quantidade_ferramentas
                    ) {


                        int posicao;

                        posicao = escolha_ferramenta - 1;


                        system("cls");


                        printf("========================================\n");

                        printf("        DADOS DA FERRAMENTA\n");

                        printf("========================================\n\n");


                        printf("Nome: %s\n",
                               nome[posicao]);


                        printf("Valor: R$ %.2f\n",
                               valor_compra[posicao]);


                        printf("Codigo QR: %d\n",
                               codigo_qr[posicao]);


                        if (possui_garantia[posicao] == 1) {

                            printf("Garantia: SIM\n");

                        } else {

                            printf("Garantia: NAO\n");

                        }


                        /*
                        Verifica novamente o risco da ferramenta.
                        */

                        if (
                            valor_compra[posicao] > 1000 &&
                            possui_garantia[posicao] == 2
                        ) {

                            printf("\nALERTA: ALTO RISCO!\n");

                        } else {

                            printf("\nStatus de risco: Normal\n");

                        }


                        printf("\n========================================\n");


                    } else {

                        printf("\nERRO: Ferramenta nao encontrada!\n");

                    }

                }


                printf("\nPressione ENTER para voltar ao menu...");

                getchar();
                getchar();

                break;


            /*
            =================================================
                    CASE 3
              VERIFICAR GARANTIA
            =================================================
            */

            case 3:

                system("cls");


                if (quantidade_ferramentas == 0) {

                    printf("========================================\n");

                    printf("     NENHUMA FERRAMENTA CADASTRADA\n");

                    printf("========================================\n");

                } else {


                    printf("========================================\n");

                    printf("       STATUS DE GARANTIA\n");

                    printf("========================================\n\n");


                    /*
                    Mostra todas as ferramentas e
                    seus respectivos status de garantia.
                    */

                    for (i = 0;
                         i < quantidade_ferramentas;
                         i++) {


                        printf("[%d] %s - ",
                               i + 1,
                               nome[i]);


                        if (possui_garantia[i] == 1) {

                            printf("COM GARANTIA\n");

                        } else {

                            printf("SEM GARANTIA\n");

                        }

                    }

                }


                printf("\nPressione ENTER para voltar ao menu...");

                getchar();
                getchar();

                break;


            /*
            =================================================
                         CASE 4
                          SAIR
            =================================================
            */

            case 4:

                system("cls");

                printf("========================================\n");

                printf("          SAINDO DO SISTEMA\n");

                printf("========================================\n\n");

                printf("Obrigado por utilizar o FerraLog!\n");

                Sleep(1000);

                break;


            /*
            =================================================
                         DEFAULT
            =================================================
            */

            default:

                system("cls");

                printf("========================================\n");

                printf("           OPCAO INVALIDA!\n");

                printf("========================================\n\n");

                printf("Digite uma opcao entre 1 e 4.\n");

                printf("\nPressione ENTER para continuar...");

                getchar();
                getchar();

                break;

        }


    /*
    -------------------------------------------------------
    FINAL DO DO-WHILE
    -------------------------------------------------------

    O menu continua enquanto a opcao for diferente de 4.

    Quando o usuario escolher 4, o programa encerra.
    */

    } while (opcao_menu != 4);


    /*
    -------------------------------------------------------
    FINAL DO PROGRAMA
    -------------------------------------------------------
    */

    return 0;
} 