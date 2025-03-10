#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main() {
    struct No *lista = NULL;
    int opcao, mat;
    char nome[100];
    
    do {
        printf("\nMenu:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Buscar por nome\n");
        printf("4 - Imprimir lista\n");
        printf("5 - Mostrar tamanho da lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matrícula: ");
                scanf("%d", &mat);
                printf("Digite o nome: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = 0;  
                lista = inserir(lista, mat, nome);
                break;
            case 2:
                printf("Digite a matrícula a ser removida: ");
                scanf("%d", &mat);
                lista = remover(lista, mat);
                break;
            case 3:
                printf("Digite o nome a ser buscado: ");
                getchar();
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = 0;
                struct No *busca = buscar(lista, nome);
                if (buscar)
                    printf("Nome encontrado: %d, Nome: %s\n", busca->mat, busca->nome);
                else
                    printf("Nome não encontrado.\n");
                break;
            case 4:
                printf("Lista de alunos:\n");
                imprimir(lista);
                break;
            case 5:
                printf("Tamanho da lista: %d\n", tamanho(lista));
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
} 