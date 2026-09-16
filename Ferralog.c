#include <stdio.h>      // Biblioteca para entrada e saída de dados
#include <stdlib.h>     // Biblioteca que permite usar system("cls")
#include <windows.h>    // Biblioteca do Windows para usar Sleep()


/*
===========================================================
        SISTEMA FERRALOG - INVENTÁRIO DE FERRAMENTAS
===========================================================

Este programa simula um sistema de inventário.

Conceitos utilizados:
- Variáveis
- printf()
- scanf()
- if / else
- operador lógico &&
- switch / case
- do / while
- for
- Sleep()
- fflush()
- system("cls")

O programa permite:
1 - Cadastrar uma ferramenta
2 - Consultar ferramenta por QR Code
3 - Verificar garantia
4 - Sair
===========================================================
*/


int main() {

    /*
    -------------------------------------------------------
    PARTE 1 - TELA DE CARREGAMENTO
    -------------------------------------------------------
    
    printf() serve para mostrar mensagens na tela.

    \n significa "quebra de linha".

    Sleep(1000) faz o programa esperar 1000 milissegundos,
    ou seja, 1 segundo.
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
    PARTE 2 - BARRA DE PROGRESSO
    -------------------------------------------------------

    O for será executado 20 vezes.

    A cada repetição:
    - imprime um #
    - atualiza a tela com fflush(stdout)
    - espera um pouco com Sleep()

    O fflush(stdout) é importante porque força o
    computador a mostrar o # imediatamente na tela.
    */

    printf("Sincronizando sistema: ");

    int i;

    for (i = 0; i < 20; i++) {

        printf("#");

        // Força a impressão do caractere imediatamente
        fflush(stdout);

        // Pausa por 100 milissegundos
        Sleep(100);
    }

    printf(" 100%%\n\n");

    Sleep(500);


    /*
    -------------------------------------------------------
    PARTE 3 - LIMPAR A TELA
    -------------------------------------------------------

    system("cls") limpa o terminal no Windows.

    No Linux/Mac seria normalmente:
    system("clear");
    */

    system("cls");


    /*
    -------------------------------------------------------
    VARIÁVEIS DO SISTEMA
    -------------------------------------------------------

    int:
    Usado para números inteiros.

    float:
    Usado para números que podem possuir casas decimais.

    char:
    Pode ser usado para armazenar um único caractere.

    Aqui:
    opcao_menu = guarda a opção escolhida no menu.

    nome = guarda o nome da ferramenta.

    codigo_qr = guarda o código QR da ferramenta.

    valor_compra = guarda o valor da ferramenta.

    possui_garantia = guarda:
    1 = possui garantia
    2 = não possui garantia
    */

    int opcao_menu;

    int codigo_qr;

    float valor_compra;

    int possui_garantia;

    char nome[100];


    /*
    -------------------------------------------------------
    PARTE 4 - DO-WHILE
    -------------------------------------------------------

    O do-while permite executar o menu pelo menos uma vez.

    Depois que o usuário terminar uma operação, o menu
    aparecerá novamente.

    O programa só terminará quando opcao_menu for igual a 4.
    */

    do {


        /*
        ---------------------------------------------------
        MENU PRINCIPAL
        ---------------------------------------------------
        */

        printf("===============================\n");
        printf("     SISTEMA FERRALOG\n");
        printf("===============================\n\n");

        printf("Sistema carregado com sucesso!\n\n");

        printf("Selecione uma opcao no menu abaixo:\n\n");

        printf("[1] Cadastrar nova ferramenta\n");

        printf("[2] Consultar ferramenta por QR Code\n");

        printf("[3] Verificar status de garantia\n");

        printf("[4] Sair do sistema\n");

        printf("===============================\n");

        printf("Digite a opcao desejada: ");

        /*
        scanf("%d", &opcao_menu);

        %d significa que esperamos um número inteiro.

        O & informa ao scanf o endereço da variável onde
        o valor digitado será armazenado.
        */

        scanf("%d", &opcao_menu);


        /*
        ---------------------------------------------------
        SWITCH / CASE
        ---------------------------------------------------

        O switch verifica o valor de uma variável e executa
        um bloco correspondente.

        Exemplo:

        Se opcao_menu == 1
        executa case 1.

        Se opcao_menu == 2
        executa case 2.

        E assim por diante.
        */

        switch (opcao_menu) {


            /*
            =================================================
            CASE 1 - CADASTRAR NOVA FERRAMENTA
            =================================================
            */

            case 1:

                /*
                Limpa a tela antes de começar o cadastro.
                */

                system("cls");

                printf("========================================\n");
                printf("       CADASTRO DE FERRAMENTA\n");
                printf("========================================\n\n");


                /*
                ------------------------------------------------
                LEITURA DO NOME
                ------------------------------------------------

                %99[^\n] permite ler um nome com espaços.

                Exemplo:
                Furadeira Bosch

                O [^\n] significa:
                "leia até encontrar uma quebra de linha".

                O 99 evita ultrapassar o tamanho do vetor.
                */

                printf("Digite o nome da ferramenta: ");

                scanf(" %99[^\n]", nome);


                /*
                ------------------------------------------------
                LEITURA DO VALOR
                ------------------------------------------------

                %f é utilizado para ler uma variável float.
                */

                printf("Digite o valor da compra: R$ ");

                scanf("%f", &valor_compra);


                /*
                ------------------------------------------------
                LEITURA DO CODIGO QR
                ------------------------------------------------

                %d é usado para números inteiros.
                */

                printf("Digite o codigo QR: ");

                scanf("%d", &codigo_qr);


                /*
                ------------------------------------------------
                PERGUNTA SOBRE GARANTIA
                ------------------------------------------------

                O usuário deve informar:

                1 = Sim
                2 = Não

                O do-while garante que o usuário só poderá
                continuar quando digitar 1 ou 2.
                */

                do {

                    printf("\nA ferramenta possui garantia?\n");

                    printf("[1] Sim\n");

                    printf("[2] Nao\n");

                    printf("Digite uma opcao: ");

                    scanf("%d", &possui_garantia);


                    /*
                    ------------------------------------------------
                    IF PARA VALIDAR A GARANTIA
                    ------------------------------------------------

                    Se o usuário digitar algo diferente de 1 e 2,
                    mostramos uma mensagem de erro.

                    O operador || significa "OU".

                    Portanto:

                    se for diferente de 1 OU diferente de 2,
                    a opção será considerada inválida.
                    */

                    if (possui_garantia != 1 && possui_garantia != 2) {

                        printf("\nERRO: Opcao de garantia invalida!\n");

                    }

                } while (possui_garantia != 1 && possui_garantia != 2);


                /*
                ------------------------------------------------
                LIMPAR A TELA
                ------------------------------------------------
                */

                system("cls");


                /*
                =================================================
                VALIDAÇÃO DO VALOR
                =================================================

                A regra do trabalho diz:

                O recibo só deve ser mostrado se o valor
                for MAIOR que zero.

                Portanto:

                valor_compra > 0

                Se for menor ou igual a zero, mostramos erro.
                */

                if (valor_compra > 0) {


                    /*
                    ------------------------------------------------
                    RECIBO DE CADASTRO
                    ------------------------------------------------
                    */

                    printf("========================================\n");
                    printf("          RECIBO DE CADASTRO\n");
                    printf("========================================\n\n");


                    printf("Nome da ferramenta: %s\n", nome);

                    printf("Valor da compra: R$ %.2f\n", valor_compra);

                    printf("Codigo QR: %d\n", codigo_qr);


                    /*
                    ------------------------------------------------
                    STATUS DA GARANTIA
                    ------------------------------------------------

                    Se possui_garantia for igual a 1,
                    significa que possui garantia.

                    Caso contrário, não possui.
                    */

                    if (possui_garantia == 1) {

                        printf("Garantia: SIM\n");

                    } else {

                        printf("Garantia: NAO\n");

                    }


                    /*
                    =================================================
                    DESAFIO HACKER - CLASSIFICACAO DE RISCO
                    =================================================

                    Regra:

                    A ferramenta será considerada de ALTO RISCO
                    quando:

                    1 - O valor for maior que R$ 1.000,00
                    E
                    2 - A ferramenta NÃO possuir garantia.

                    Para representar "E" usamos:

                    &&

                    Então:

                    valor_compra > 1000
                    &&
                    possui_garantia == 2
                    */

                    if (valor_compra > 1000 && possui_garantia == 2) {

                        printf("\n");
                        printf("!!! ALERTA DE ALTO RISCO !!!\n");
                        printf("Ferramenta acima de R$ 1.000,00 ");
                        printf("sem garantia.\n");

                    } else {

                        /*
                        Caso a ferramenta não se enquadre
                        na regra de alto risco.
                        */

                        printf("\n");
                        printf("Status de risco: Normal\n");

                    }


                    /*
                    ------------------------------------------------
                    FINAL DO RECIBO
                    ------------------------------------------------
                    */

                    printf("\n========================================\n");

                    printf("Cadastro realizado com sucesso!\n");

                    printf("========================================\n");


                } else {


                    /*
                    =================================================
                    VALOR INVÁLIDO
                    =================================================

                    Se valor_compra não for maior que zero,
                    o recibo não será mostrado.

                    A mensagem solicitada pelo exercício é:

                    ERRO: Valor Invalido!
                    */

                    printf("========================================\n");

                    printf("ERRO: Valor Invalido!\n");

                    printf("O valor da ferramenta deve ser maior que zero.\n");

                    printf("========================================\n");

                }


                /*
                ------------------------------------------------
                PAUSA
                ------------------------------------------------

                getchar() normalmente captura um ENTER que
                ficou no teclado depois do scanf.

                Em seguida, outro getchar() espera o usuário
                pressionar ENTER.
                */

                printf("\nPressione ENTER para voltar ao menu...");

                getchar();

                getchar();

                break;


            /*
            =================================================
            CASE 2
            =================================================

            Ainda não existe a funcionalidade de consulta.
            */

            case 2:

                system("cls");

                printf("========================================\n");

                printf("     CONSULTAR FERRAMENTA POR QR CODE\n");

                printf("========================================\n\n");

                printf("Modulo em desenvolvimento.\n");

                printf("\nPressione ENTER para voltar ao menu...");

                getchar();

                getchar();

                break;


            /*
            =================================================
            CASE 3
            =================================================

            Ainda não existe a funcionalidade de consulta
            de garantia.
            */

            case 3:

                system("cls");

                printf("========================================\n");

                printf("       VERIFICAR STATUS DE GARANTIA\n");

                printf("========================================\n\n");

                printf("Modulo em desenvolvimento.\n");

                printf("\nPressione ENTER para voltar ao menu...");

                getchar();

                getchar();

                break;


            /*
            =================================================
            CASE 4 - SAIR
            =================================================
            */

            case 4:

                system("cls");

                printf("========================================\n");

                printf("          SAINDO DO SISTEMA...\n");

                printf("========================================\n\n");

                printf("Obrigado por utilizar o FerraLog!\n");

                Sleep(1000);

                break;


            /*
            =================================================
            DEFAULT
            =================================================

            O default é executado quando o usuário digita
            uma opção que não existe no menu.
            */

            default:

                system("cls");

                printf("========================================\n");

                printf("         OPCAO INVALIDA!\n");

                printf("========================================\n\n");

                printf("Digite uma opcao entre 1 e 4.\n");

                printf("\nPressione ENTER para voltar ao menu...");

                getchar();

                getchar();

                break;

        }


    /*
    -------------------------------------------------------
    FINAL DO DO-WHILE
    -------------------------------------------------------

    O menu continua aparecendo enquanto:

    opcao_menu != 4

    != significa "diferente de".

    Portanto:

    enquanto a opção for diferente de 4,
    o sistema continua funcionando.

    Quando o usuário escolher 4,
    o programa encerra.
    */

    } while (opcao_menu != 4);


    
    /*-------------------------------------------------------
    RETURN 0
    -------------------------------------------------------

    Indica que o programa terminou normalmente
   
    O valor 0 normalmente representa sucesso.*/

    return 0;

}