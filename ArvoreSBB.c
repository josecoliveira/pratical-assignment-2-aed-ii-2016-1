#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "ArvoreSBB.h"

/*------------------------------------------------
  Protótipo: ArvoreSBB *criaArvoreSBB(Elemento *r)
  Função: Cria árvore SBB com um elemento.
  Entrada: Ponteiro para elemento.
  Saída: Ponteiro para árvore.
--------------------------------------------------*/
ArvoreSBB *criaArvoreSBB(Elemento *r) {
    ArvoreSBB *novaArvore = malloc(sizeof(ArvoreSBB));
    novaArvore->reg = r;
    novaArvore->esq = NULL;
    novaArvore->dir = NULL;
    novaArvore->esqtipo = SBB_VERTICAL;
    novaArvore->dirtipo = SBB_VERTICAL;
    return novaArvore;
}

/*--------------------------------------------------------------------
  Protótipo: Elemento *pesquisaSBB(ArvoreSBB *t, Chave x)
  Função: Pesquisa um elemento na árvore binária.
  Entrada: Ponteiro para a árvore da pesquisa e chave a ser pesquisada
  Saída: Ponteiro para o elemento encontrado.
  --------------------------------------------------------------------*/
Elemento *pesquisaSBB(ArvoreSBB *t, Chave x) {
    if (t == NULL) {
        printf("Registro não esta presente na árvore\n");
    } else if (x < t->reg->matricula) {
        return pesquisaSBB(t->esq, x);
    } else if (x < t->reg->matricula) {
        return pesquisaSBB(t->dir, x);
    } else {
        return t->reg;
    }
    return NULL;
}

/*--------------------------------------------------------------------
  Protótipo: void ee(ArvoreSBB **ptr)
  Função: Trata ocorrência de ponteiros horizontais esquerda-esquerda.
  Entrada: Duplo ponteiro para árvore.
  Saída: Nenhuma.
  --------------------------------------------------------------------*/
void ee(ArvoreSBB **ptr) {
    ArvoreSBB *novaArvore = *ptr;
    ArvoreSBB *esq = novaArvore->esq;
    novaArvore->esq = esq->dir;
    esq->dir = novaArvore;
    esq->esqtipo = SBB_VERTICAL;
    novaArvore->esqtipo = SBB_VERTICAL;
    *ptr = esq;
}

/*------------------------------------------------------------------
  Protótipo: void dd(ArvoreSBB **ptr)
  Função: Trata ocorrência de ponteiros horizontais direita-direita.
  Entrada: Duplo ponteiro para árvore.
  Saída: Nenhuma.
  ------------------------------------------------------------------*/
void dd(ArvoreSBB **ptr) {
    ArvoreSBB *novaArvore = *ptr;
    ArvoreSBB *dir = novaArvore->dir;
    novaArvore->dir = dir->esq;
    dir->esq = novaArvore;
    dir->dirtipo = SBB_VERTICAL;
    novaArvore->dirtipo = SBB_VERTICAL;
    *ptr = dir;
}

/*-------------------------------------------------------------------
  Protótipo: void ed(ArvoreSBB **ptr)
  Função: Trata ocorrência de ponteiros horizontais esquerda-direita.
  Entrada: Duplo ponteiro para árvore.
  Saída: Nenhuma.
  -------------------------------------------------------------------*/
void ed(ArvoreSBB **ptr) {
    ArvoreSBB *novaArvore = *ptr;
    ArvoreSBB *esq = novaArvore->esq;
    ArvoreSBB *dir = esq->dir;
    esq->dir = dir->esq;
    dir->esq = esq;
    novaArvore->esq = dir->dir;
    dir->dir = novaArvore;
    esq->dirtipo = SBB_VERTICAL;
    novaArvore->esqtipo = SBB_VERTICAL;
    *ptr = dir;
}

/*-------------------------------------------------------------------
  Protótipo: void de(ArvoreSBB **ptr)
  Função: Trata ocorrência de ponteiros horizontais direita-esquerda.
  Entrada: Duplo ponteiro para árvore.
  Saída: Nenhuma.
  -------------------------------------------------------------------*/
void de(ArvoreSBB **ptr) {
    ArvoreSBB *novaArvore = *ptr;
    ArvoreSBB *dir = novaArvore->dir;
    ArvoreSBB *esq = dir->esq;
    dir->esq = esq->dir;
    esq->dir = dir;
    novaArvore->dir = esq->esq;
    esq->esq = novaArvore;
    dir->esqtipo = SBB_VERTICAL;
    novaArvore->dirtipo = SBB_VERTICAL;
    *ptr = dir;
}

/*---------------------------------------------------------------------------------------------------
  Protótipo: void iInsere(Elemento *r, ArvoreSBB **ptr, int *incli, int *fim)
  Função: Usada pela função InsereElementoSBB, localiza a posição para árvore para inerir o elemento.
  Entrada: Ponteiro para elemento, duplo ponteiro para árvore, ponteiro para inteiro indicando a
           inclinação do ponteiro na árvore e ponteiro para inteiro indiciando o fim da função.
  Saída: Nenhuma
  ---------------------------------------------------------------------------------------------------*/
void iInsere(Elemento *r, ArvoreSBB **ptr, int *incli, int *fim) {
    if (*ptr == NULL) {
        iInsereAqui(r, ptr, incli, fim);
    } else if (r->matricula < (*ptr)->reg->matricula) {
        iInsere(r, &((*ptr)->esq), &((*ptr)->esqtipo), fim);
        if (*fim) {
            return;
        }
        if ((*ptr)->esqtipo == SBB_VERTICAL) {
            *fim = 1;
        } else if ((*ptr)->esq->esqtipo == SBB_HORIZONTAL) {
            ee(ptr);
            *incli = SBB_HORIZONTAL;
        } else if ((*ptr)->esq->dirtipo == SBB_HORIZONTAL) {
            ed(ptr);
            *incli = SBB_HORIZONTAL;
        }
    } else if (r->matricula > (*ptr)->reg->matricula) {
        iInsere(r, &((*ptr)->esq), &((*ptr)->esqtipo), fim);
        if (*fim) {
            return;
        }
        if ((*ptr)->dirtipo == SBB_VERTICAL) {
            *fim = 1;
        } else if ((*ptr)->dir->dirtipo == SBB_HORIZONTAL) {
            dd(ptr);
            *incli = SBB_HORIZONTAL;
        } else if ((*ptr)->dir->esqtipo == SBB_HORIZONTAL) {
            de(ptr);
            *incli = SBB_HORIZONTAL;
        }
    } else {
        printf("Erro: Chave já está na árvore.\n");
        *fim = 1;
    }
}

/*------------------------------------------------------------------------------------------------------
  Protótipo: void iInsereAqui(Elemento *r, ArvoreSBB **ptr, int *incli, int *fim)
  Função: Usada pela função iInsereAqui, aloca a árvore com o elemento após encontrar a posição correta.
  Entrada: Duplo ponteiro para árvore, ponteiro para inteiro indicando a inclinação e ponteiro
           para inteiro indicado o fim da função iInsere.
  Saída: Nenhuma.
  ------------------------------------------------------------------------------------------------------*/
void iInsereAqui(Elemento *r, ArvoreSBB **ptr, int *incli, int *fim) {
    ArvoreSBB *novaArvore = malloc(sizeof(ArvoreSBB));
    novaArvore->reg = r;
    novaArvore->esq = NULL;
    novaArvore->dir = NULL;
    novaArvore->esqtipo = SBB_VERTICAL;
    novaArvore->dirtipo = SBB_VERTICAL;
    *ptr = novaArvore;
    *incli = SBB_HORIZONTAL;
    *fim = 0;
}

/*-------------------------------------------------------------
  Protótipo: void insereElementoSBB(ArvoreSBB **t, Elemento *n)
  Função: Insere elemento em árvore.
  Entrada: Duplo ponteiro para árvore e ponteiro para elemento.
  Saída: Nenhuma.
  -------------------------------------------------------------*/
void insereElementoSBB(ArvoreSBB **t, Elemento *n) {
    int fim = 0;
    int inclinacao = SBB_VERTICAL;
    iInsere(n, t, &inclinacao, &fim);
}

/*--------------------------------------------
  Protótipo: void inicializa(ArvoreSBB **raiz)
  Função: Inicializa a raiz da árvore com NULL
  Entrada: Ponteiro para árvore.
  Saída: Nenhuma.
  --------------------------------------------*/
void inicializa(ArvoreSBB **raiz) {
    *raiz = NULL;
}

/*-----------------------------------------------
  Protótipo: void imprimeArvoreSBB(ArvoreSBB *t)
  Função: Imprime árvore em caminhamento central.
  Entrada: Ponteiro para a árvore.
  Saída: Nenhuma.
  -----------------------------------------------*/
void imprimeArvoreSBB(ArvoreSBB *t) {
    printf("(%i) %s\n", t->reg->matricula, t->reg->nome);
    imprimeArvoreSBB(t->esq);
    imprimeArvoreSBB(t->dir);
}

/*---------------------------------------------------------
  Protótipo: void apagaArvoreSBB(ArvoreSBB *t)
  Função: Desaloca todas os nós da árvore e seus elementos.
  Entrada: Ponteiro para a árvore.
  Sada: Nenhuma
  ---------------------------------------------------------*/
void apagaArvoreSBB(ArvoreSBB *t) {
    if (t->esq != NULL) {
        apagaArvoreSBB(t->esq);
    }
    if (t->dir != NULL) {
        apagaArvoreSBB(t->dir);
    }
    free(t->reg);
    free(t);
}
