#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


// Função para criar um novo nó
struct No* criar(int mat, char *nome) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->mat = mat;
    novo->nome = strdup(nome);
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

// Inserir de forma ordenada pelo nome
struct No* inserir(struct No *lista, int mat, char *nome) {
    struct No *novo = criar(mat, nome);
    if (!lista) return novo;
    
    struct No *atual = lista, *anterior = NULL;
    while (atual && strcmp(atual->nome, nome) < 0) {
        anterior = atual;
        atual = atual->prox;
    }
    
    novo->prox = atual;
    novo->ant = anterior;
    if (atual) atual->ant = novo;
    if (anterior) {
        anterior->prox = novo;
        return lista;
    }
    return novo;
}

// Remover um nó pela matrícula
struct No* remover(struct No *lista, int mat) {
    struct No *atual = lista;
    while (atual && atual->mat != mat)
        atual = atual->prox;
    
    if (!atual) return lista;
    
    if (atual->ant)
        atual->ant->prox = atual->prox;
    if (atual->prox)
        atual->prox->ant = atual->ant;
    
    struct No *novaLista = (atual == lista) ? atual->prox : lista;
    free(atual->nome);
    free(atual);
    return novaLista;
}

// // Buscar por matrícula
// struct No* buscarMatricula(struct No *lista, int mat) {
//     while (lista) {
//         if (lista->mat == mat)
//             return lista;
//         lista = lista->prox;
//     }
//     return NULL;
// }

// Buscar por nome
struct No* buscar(struct No *lista, char *nome) {
    while (lista) {
        if (strcmp(lista->nome, nome) == 0)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

// Retornar o tamanho da lista
int tamanho(struct No *lista) {
    int count = 0;
    while (lista) {
        count++;
        lista = lista->prox;
    }
    return count;
}
// Função para imprimir a lista
void imprimir(struct No *lista) {
    while (lista) {
        printf("Matricula: %d, Nome: %s\n", lista->mat, lista->nome);
        lista = lista->prox;
    }
}