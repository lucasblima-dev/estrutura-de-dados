#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void printList(No *lista) {
    No *atual = lista;
    if (!atual) {
        printf("Lista vazia! Nada para mostrar.\n");
        return;
    }
    
    printf("\n=== ALUNOS CADASTRADOS ===\n");
    while (atual) {
        printf("Nome: %s\nMatrícula: %d\n", atual->name, atual->matricula);
        printf("\n");
        atual = atual->next;
    }
    printf("---------------------------\n");
    printf("Total de alunos: %d\n", showSize(lista));
}

int main() {
    No *lista = makeList();

    int option, mat;
    char nome[50];

    do {
        printf("\n===== MENU DE OPÇÕES =====\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Buscar aluno por matrícula\n");
        printf("4 - Buscar aluno por nome\n");
        printf("5 - Mostrar lista\n");
        printf("0 - Sair do programa\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                printf("\nDigite o nome do aluno: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &mat);
                getchar();

                lista = insert(lista, mat, nome);
                printf("\nAluno adicionado com sucesso!\n");
                break;

            case 2:
                printf("\nDigite a matrícula do aluno que deseja remover: ");
                scanf("%d", &mat);
                getchar();

                lista = removeMat(lista, mat);
                break;

            case 3:
                printf("\nDigite a matrícula do aluno para buscar: ");
                scanf("%d", &mat);
                getchar();

                No *resultadoMat = findMat(lista, mat);
                if (resultadoMat) {
                    printf("\nAluno encontrado: %s \nMatrícula: %d\n", resultadoMat->name, resultadoMat->matricula);
                } else {
                    printf("Nenhum aluno com essa matrícula foi encontrado!\n");
                }
                break;

            case 4:
                printf("\nDigite o nome do aluno para buscar: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                No *resultadoNome = findName(lista, nome);
                if (resultadoNome) {
                    printf("\nAluno encontrado: %s \nMatrícula: %d\n", resultadoNome->name, resultadoNome->matricula);
                } else {
                    printf("Nenhum aluno com esse nome foi encontrado!\n");
                }
                break;

            case 5:
                printList(lista);
                break;

            case 0:
                printf("Até a próxima! ;)\n");
                break;

            default:
                printf("Essa opção não existe :/ \nTente novamente!\n"); 
        }
    } while (option != 0);
    
    return 0;
}