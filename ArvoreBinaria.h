#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

#include "Aluno.h"

typedef Aluno Elemento;

typedef struct ArvoreBinaria {
    struct ArvoreBinaria* esq;
    struct ArvoreBinaria* dir;
    Elemento* reg;
} ArvoreBinaria;

ArvoreBinaria* criaArvore(Elemento* r); //cria uma árvore com o elemento r sendo raíz

Elemento* pesquisaBinaria(ArvoreBinaria *t, Chave x); //pesquisa na árvore o elemento com chave x

void insereElemento(ArvoreBinaria* t, Elemento *n); //insere elemento n na árvore t

ArvoreBinaria* removeDaArvore(ArvoreBinaria* t, Chave c); //remove o elemento de chave c da árvore t

ArvoreBinaria* achaMenor(ArvoreBinaria* t); //encontra o menor elemento da árvore t

void imprimeArvoreBinaria(ArvoreBinaria *t); //imprime a ávore (pré-ordem, in-ordem ou pós-ordem)

void apagaArvoreBinaria(ArvoreBinaria *t); // desaloca arvore t

#endif // ARVOREBINARIA_H_INCLUDED
