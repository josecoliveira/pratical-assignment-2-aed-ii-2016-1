#ifndef ARVORESBB_H_INCLUDED
#define ARVORESBB_H_INCLUDED

#define SBB_VERTICAL 0
#define SBB_HORIZONTAL 1

typedef Aluno Elemento;

typedef struct ArvoreSBB {
    Elemento *reg;
    struct ArvoreSBB *esq;
    struct ArvoreSBB *dir;
    int esqtipo;
    int dirtipo;
} ArvoreSBB;

ArvoreSBB *criaArvoreSBB(Elemento *r);  //cria uma árvore com o elemento r sendo raíz

Elemento *pesquisaSBB(ArvoreSBB *t, Chave x);  //pesquisa na árvore o elemento com chave x

void ee(ArvoreSBB **ptr);  //transformação esquerda-esquerda para manter propriedadas da árvore SBB

void dd(ArvoreSBB **ptr);  //transformação direita-direita para manter propriedadas da árvore SBB

void ed(ArvoreSBB **ptr);  //transformação esquerda-direita para manter propriedadas da árvore SBB

void de(ArvoreSBB **ptr);  //transformação direita-esquerda para manter propriedadas da árvore SBB

void iInsere(Elemento *r, ArvoreSBB **ptr, int *incli, int *fim);  //usada pela insereElemento (ver slides do professor)

void iInsereAqui(Elemento *r, ArvoreSBB **ptr, int *incli, int *fim);   //usada pela iInsere (ver slides do professor)

void insereElementoSBB(ArvoreSBB **t, Elemento *n);  //insere elemento n na árvore t

void inicializa(ArvoreSBB **raiz);  //inicializa a raiz da árvore com NULL

void imprimeArvoreSBB(ArvoreSBB *t);  //imprime a ávore (pré-ordem, in-ordem ou /pós-ordem)

void apagaArvoreSBB(ArvoreSBB *t); //desaloca arvore t

#endif // ARVORESBB_H_INCLUDED
