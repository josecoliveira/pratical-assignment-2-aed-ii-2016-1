#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
#include "Aluno.h"

/*-------------------------------------------------------------
  Protótipo: ArvoreBinaria *criaArvore(Elemento *r)
  Função: Cria uma árvore binária com um elemento.
  Entrada: Ponteiro para o elemento a ser adicionado na árvore.
  Saída: Ponteiro para a árvore criada.
  -------------------------------------------------------------*/
ArvoreBinaria *criaArvore(Elemento *r) {
    ArvoreBinaria *novaArvore = malloc(sizeof(ArvoreBinaria));
    novaArvore->esq = NULL;
    novaArvore->dir = NULL;
    novaArvore->reg = r;
    return novaArvore;
}

/*--------------------------------------------------------------------
  Protótipo: Elemento *pesquisaBinaria(ArvoreBinaria *t, Chave x)
  Função: Pesquisa um elemento na árvore binária.
  Entrada: Ponteiro para a árvore da pesquisa e chave a ser pesquisada
  Saída: Ponteiro para o elemento encontrado.
  --------------------------------------------------------------------*/
Elemento *pesquisaBinaria(ArvoreBinaria *t, Chave x) {
    if (t == NULL) {
        printf("Registro não esta presente na árvore\n");
        return NULL;
    } else if (x < t->reg->matricula) {
        return pesquisaBinaria(t->esq, x);
    } else if (x > t->reg->matricula) {
        return pesquisaBinaria(t->dir, x);
    } else {
        return t->reg; //Dúvida
    }
}

/*--------------------------------------------------------------------------
  Protótipo: void insereElemento(ArvoreBinaria *t, Elemento *n)
  Função: Intere elemento na árvore binária.
  Entrada: Ponteiro para a árvore e ponteiro para o elemento a ser inserido.
  Saída: Nenhuma.
  --------------------------------------------------------------------------*/
void insereElemento(ArvoreBinaria *t, Elemento *n) {
    if (n->matricula < t->reg->matricula) {
        if (t->esq) {
            insereElemento(t->esq, n);
        } else {
            ArvoreBinaria *novaArvore = criaArvore(n);
            t->esq = novaArvore;
        }
    } else {
        if (t->dir) {
            insereElemento(t->dir, n);
        } else {
            ArvoreBinaria *novaArvore = criaArvore(n);
            t->dir = novaArvore;
        }
    }
}

/*-------------------------------------------------------------------
  Protótipo: ArvoreBinaria *removeDaArvore(ArvoreBinaria *t, Chave c)
  Função: Remove um elemento da árvore pela chave.
  Entrada: Ponteiro para a árvore e chave do elemento a ser removido.
  Saída: Ponteiro para a árvore com elemento retirado
  -------------------------------------------------------------------*/
ArvoreBinaria *removeDaArvore(ArvoreBinaria *t, Chave c) {
    ArvoreBinaria *aux;
    if (t == NULL) {
        printf("Elemento ausente.\n");
    } else if (c < t->reg->matricula) {
        t->esq = removeDaArvore(t->esq, c);
    } else if (c > t->reg->matricula) {
        t->dir = removeDaArvore(t->dir, c);
    } else if (t->esq == NULL && t->dir == NULL) {
        free(t);
        return NULL;
    } else if (t->esq == NULL) {
        aux = t->dir;
        free(t);
        return aux;
    } else if (t->dir == NULL) {
        aux = t->esq;
        free(t);
        return aux;
    }  else {
        ArvoreBinaria *suc = achaMenor(t->dir);
        t->reg = suc->reg;
        t->dir = removeDaArvore(t->dir, suc->reg->matricula);
        return t;
    }
    return t;
}

/*-----------------------------------------------------
  Protótipo: ArvoreBinaria *achaMenor(ArvoreBinaria *t)
  Função: Encontra menor valor em uma árvore.
  Entrada: Ponteiro para a árvore.
  Saída: Ponteiro para a árvore com o menor valor.
  -----------------------------------------------------*/
ArvoreBinaria *achaMenor(ArvoreBinaria *t) {
    if (t->esq == NULL) {
        return t;
    }
    return achaMenor(t->esq);
}

/*------------------------------------------------------
  Protótipo: void imprimeArvoreBinaria(ArvoreBinaria *t)
  Função: Imprime árvore em caminhamento central.
  Entrada: Ponteiro para a árvore.
  Saída: Nenhuma.
  ------------------------------------------------------*/
void imprimeArvoreBinaria(ArvoreBinaria *t) {
    imprimeArvoreBinaria(t->esq);
    printf("(%i) %s\n", t->reg->matricula, t->reg->nome);
    imprimeArvoreBinaria(t->dir);
}

/*---------------------------------------------------------
  Protótipo: void apagaArvoreBinaria(ArvoreBinaria *t)
  Função: Desaloca todas os nós da árvore e seus elementos.
  Entrada: Ponteiro para a árvore.
  Sada: Nenhuma
  ---------------------------------------------------------*/
void apagaArvoreBinaria(ArvoreBinaria *t) {
    if (t->esq != NULL) {
        apagaArvoreBinaria(t->esq);
    }
    if (t->dir != NULL) {
        apagaArvoreBinaria(t->dir);
    }
    free(t->reg);
    free(t);
}
