#include <stdio.h>    // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>   // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>   // Biblioteca de aloca��es de texto por regi�o
#include <string.h>   // Biblioteca para manipula��o de strings

// Fun��o respons�vel por cadastrar os usu�rios no sistema
int registro() {
    // Cria��o de vari�veis/strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: "); // Coletando CPF
    scanf("%s", cpf); // L� o CPF
    
    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo
    
    // Cria��o do arquivo com o CPF como nome
    FILE *file = fopen(arquivo, "w"); // Cria o arquivo em modo de escrita
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    
    // Solicitar dados adicionais do usu�rio
    printf("Digite o nome: ");
    scanf("%s", nome);
    
    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);
    
    printf("Digite o cargo: ");
    scanf("%s", cargo);
    
    // Salva as informa��es no arquivo
    printf(file, "CPF: %s\nNome:  %s\nCargo: %s\n", cpf, nome, sobrenome, cargo);
    
    fclose(file); // Fecha o arquivo
    printf("Usu�rio cadastrado com sucesso!\n");
    return 0;
}

// Fun��o para consultar os dados de um usu�rio
int consulta() {
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file = fopen(cpf, "r"); // Abre o arquivo em modo de leitura
    
    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo. Usu�rio n�o encontrado!\n");
        return 1;
    }
    
    // Exibe as informa��es do usu�rio
    printf("\nEssas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }
    
    fclose(file); // Fecha o arquivo
    return 0;
}

// Fun��o para deletar o usu�rio
int deletar() {
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar o usu�rio. CPF n�o encontrado!\n");
    }
    
    return 0;
}

int main() {
    int opcao = 0; // Vari�vel para armazenar a op��o do menu
    int laco = 1;
    
    while (laco == 1) { // La�o para o menu ficar ativo
        system("cls"); // Limpa a tela
        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
        
        // Exibe o menu
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada:\n\n"); 
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Op��o: ");
        
        scanf("%d", &opcao); // Armazena a escolha do usu�rio
        system("cls"); // Limpa a tela
        
        // Sele��o do menu
        switch (opcao) {
            case 1:
                registro(); // Chama a fun��o de registro
                break;
                
            case 2:
                consulta(); // Chama a fun��o de consulta
                break;
                
            case 3:
                deletar(); // Chama a fun��o de deletar
                break;
                
            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }
    }
    
    return 0;
}
