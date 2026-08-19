#include <stdio.h>
#include <windows.h>

  int main() {
      
    printf("Inializando sistema animado...\n");
    sleep(1000);
    printf("Sistema inicializado com sucesso!\n");
    sleep(1000);
    printf("[*] Conectando Banco de dados...\n");
    sleep(1000);
    printf("[*]Carregando modulo de leitura do QRcode\n");
    sleep(1000);
    printf("[*]Sincronizando dados...\n"); 
    sleep(1000);

    system("cls");
    
    printf("=======================================\n");
    printf(" SISTEMA FERRALOG - INVENTÁRIO\n");
    printf("=======================================\n");
    printf(" Sistema Inicializado com sucesso!\n");
    printf("Selecione uma opção;\n");
    printf("1 - Cadastrar Ferramenta\n");
    printf("2 - Consultar ferramenta por QR code\n");
    printf("3 - Verificar o status de garantia\n");
    printf("4 - Sair do sistema\n");

  }