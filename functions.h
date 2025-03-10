#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>

struct No {
    int mat;
    char *nome;
    struct No *ant;
    struct No *prox;
} No;


struct No *criar(int mat, char *nome);
struct No *inserir(struct No *lista, int mat, char *nome);
struct No *buscar(struct No *lista, char *nome);
struct No *remover(struct No *lista, int mat);
int tamanho(struct No *lista);
void imprimir(struct No *lista);

#endif