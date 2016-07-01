#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
#include "ArvoreSBB.h"
#include "Hash.h"

/*-------------------------------------------------------------------
  Protótipo: Hash *criaHashPadrao()
  Função: Cria tabela hash com 10 posições e cria árvore em cada uma.
  Entrada: Nenhuma.
  Saída: Ponteiro para a estrutura hash.
  -------------------------------------------------------------------*/
Hash *criaHashPadrao() {
    Hash *novaHash = malloc(sizeof(Hash));

    int i;

    ArvoreBinaria **hash = malloc(sizeof(ArvoreBinaria) * 10);
    for (i = 0; i < 10; i++) {
        hash[i] = criaArvore(NULL);
    }

    ArvoreSBB **hashSBB = malloc(sizeof(ArvoreSBB) * 10);
    for (i = 0; i < 10; i++) {
        hashSBB[i] = criaArvoreSBB(NULL);
    }

    novaHash->hash = hash;
    novaHash->hashSBB = hashSBB;
    novaHash->nElem = 0;
    novaHash->tam = 10;

    return novaHash;
}

/*---------------------------------------------------
  Protótipo: Hash *criaHash(int t)
  Função: Cria tabela hash e cria árvore em cada uma.
  Entrada: Numero de posições na tabela.
  Saída: Ponteiro para a estrutura hash.
  ---------------------------------------------------*/
Hash *criaHash(int t) {
    Hash *novaHash = malloc(sizeof(Hash));

    int i;

    ArvoreBinaria **hash = malloc(sizeof(ArvoreBinaria) * t);
    for (i = 0; i < t; i++) {
        hash[i] = criaArvore(NULL);
    }

    ArvoreSBB **hashSBB = malloc(sizeof(ArvoreSBB) * t);
    for (i = 0; i < t; i++) {
        hashSBB[i] = criaArvoreSBB(NULL);
    }

    novaHash->hash = hash;
    novaHash->hashSBB = hashSBB;
    novaHash->nElem = 0;
    novaHash->tam = t;

    return novaHash;
}

/*-------------------------------------
  Protótipo: void apagaHash(Hash *h)
  Função: Desaloca hash e suas árvores.
  Entrada: Ponteiro para o hash.
  Saída: Nenhuma.
  -------------------------------------*/
void apagaHash(Hash *h) {
    int i;
    for (i = 0; i < h->tam; i++) {
        apagaArvoreBinaria(h->hash[i]);
        apagaArvoreSBB(h->hashSBB[i]);
    }
    free(h);
}

/*-----------------------------------------------------
  Protótipo: void insereNaHash(Hash *h, Elemento *x)
  Função: Insere elemento na tabela Hash.
  Entrada: Ponteiro para hash e ponteiro para elemento.
  Saída: Nenhuma.
  -----------------------------------------------------*/
void insereNaHash(Hash *h, Elemento *x) {
    int c = x->matricula % 10;
    insereElemento(h->hash[c], x);
    insereElementoSBB(&h->hashSBB[c], x);
}



/*--------------------------------
  Protótipo: imprime(Hash *h)
  Função: Imprime as tabelas hash.
  Entrada: Ponteiro para hash.
  Saída: Nenhuma.
  --------------------------------*/
void imprime(Hash *h) {
    int i;
    printf("Hash Arvore Binaria.\n");
    for (i = 0; i < h->tam; i++) {
        if (h->hash[i] == NULL) {
            continue;
        }
        printf("%i:\n", i);
        imprimeArvoreBinaria(h->hash[i]);
    }
    printf("\n");
    printf("Hash ArvoreSBB.\n");
    for (i = 0; i < h->tam; i++) {
        if (h->hashSBB[i] == NULL) {
            continue;
        }
        printf("%i:\n", i);
        imprimeArvoreSBB(h->hashSBB[i]);
    }
}

/*---------------------------------------------------
  Protótipo: int obtemNumElem(Hash *h)
  Função: Obtem o número de elementos na tabela hash.
  Entrada: Ponteiro para hash.
  Saída: Saída número de elemento na tabela.
  ---------------------------------------------------*/
int obtemNumElem(Hash *h) {
    return h->nElem;
}
