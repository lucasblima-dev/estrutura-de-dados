#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>

struct No {
  char *name;
  int matricula;
  struct No *prev;
  struct No *next;
} No;

No* makeList();
No* insert(No *lista, int mat, char *nome); 
No* remove(No *lista, int mat);
No* findMat(No *lista, int mat);
No* findName(No *lista, char *nome); 
int showSize(No *lista);

#endif