#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

No* makeList() {
  return NULL;
}

No* insert(No *lista, int mat, char *nome) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        return lista;
    }

    novo->matricula = mat;
    novo->name = strdup(nome);
    novo->prev = NULL;
    novo->next = NULL;

    if (!lista) {
        return novo; 
    }

    No *atual = lista;
    No *anterior = NULL;

    while (atual && strcmp(atual->name, nome) < 0) {
        anterior = atual;
        atual = atual->next;
    }

    if (!anterior) { 
        novo->next = lista;
        lista->prev = novo;
        return novo;
    } else {
        novo->next = atual;
        novo->prev = anterior;
        anterior->next = novo;
        if (atual) {
            atual->prev = novo;
        }
    }

    return lista;
}

No* removeMat(No *lista, int mat) {
    No *atual = lista;

    while (atual && atual->matricula != mat) {
        atual = atual->next;
    }

    if (!atual) {
        printf("Matrícula não encontrada.\n");
        return lista;
    }

    if (atual->prev) {
        atual->prev->next = atual->next;
    } else {
        lista = atual->next;
    }

    if (atual->next) {
        atual->next->prev = atual->prev;
    }

    free(atual->name);
    free(atual);
    return lista;
}

No* findMat(No *lista, int mat) {
    No *atual = lista;
    while (atual) {
        if (atual->matricula == mat) {
            return atual;
        }
        atual = atual->next;
    }
    return NULL;
}

No* findName(No *lista, char *nome) {
    No *atual = lista;
    while (atual) {
        if (strcmp(atual->name, nome) == 0) {
            return atual;
        }
        atual = atual->next;
    }
    return NULL;
}

int showSize(No *lista) {
    int cont = 0;
    No *atual = lista;
    while (atual) {
        cont++;
        atual = atual->next;
    }
    return cont;
}
