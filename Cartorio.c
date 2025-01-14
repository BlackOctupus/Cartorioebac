#include <stdio.h>    // Biblioteca de comunicação com o usuário
#include <stdlib.h>   // Biblioteca de alocação de espaço em memória
#include <locale.h>   // Biblioteca de alocações de texto por região
#include <string.h>   // Biblioteca para manipulação de strings

// Função responsável por cadastrar os usuários no sistema
int registro() {
    // Criação de variáveis/strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: "); // Coletando CPF
    scanf("%s", cpf); // Lê o CPF
    
    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo
    
    // Criação do arquivo com o CPF como nome
    FILE *file = fopen(arquivo, "w"); // Cria o arquivo em modo de escrita
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    
    // Solicitar dados adicionais do usuário
    printf("Digite o nome: ");
    scanf("%s", nome);
    
    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);
    
    printf("Digite o cargo: ");
    scanf("%s", cargo);
    
    // Salva as informações no arquivo
    printf(file, "CPF: %s\nNome:  %s\nCargo: %s\n", cpf, nome, sobrenome, cargo);
    
    fclose(file); // Fecha o arquivo
    printf("Usuário cadastrado com sucesso!\n");
    return 0;
}

// Função para consultar os dados de um usuário
int consulta() {
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file = fopen(cpf, "r"); // Abre o arquivo em modo de leitura
    
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo. Usuário não encontrado!\n");
        return 1;
    }
    
    // Exibe as informações do usuário
    printf("\nEssas são as informações do usuário:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }
    
    fclose(file); // Fecha o arquivo
    return 0;
}

// Função para deletar o usuário
int deletar() {
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar o usuário. CPF não encontrado!\n");
    }
    
    return 0;
}

int main() {
    int opcao = 0; // Variável para armazenar a opção do menu
    int laco = 1;
    
    while (laco == 1) { // Laço para o menu ficar ativo
        system("cls"); // Limpa a tela
        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
        
        // Exibe o menu
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada:\n\n"); 
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Opção: ");
        
        scanf("%d", &opcao); // Armazena a escolha do usuário
        system("cls"); // Limpa a tela
        
        // Seleção do menu
        switch (opcao) {
            case 1:
                registro(); // Chama a função de registro
                break;
                
            case 2:
                consulta(); // Chama a função de consulta
                break;
                
            case 3:
                deletar(); // Chama a função de deletar
                break;
                
            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        }
    }
    
    return 0;
}
