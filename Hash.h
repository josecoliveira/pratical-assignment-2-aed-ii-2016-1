#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

typedef struct Hash {
    ArvoreBinaria **hash;
    ArvoreSBB **hashSBB;
    int tam;
    int nElem;
} Hash;

//int funcaoHash(...); //função Hash (deve criar como desejar, com a passagem de parâmetros que julgar necessária)

Hash *criaHashPadrao(); //inicializacao padrao

Hash *criaHash(int t); //inicializa com tamanho passado (aloca)

void apagaHash(Hash *h); //desaloca Hash h

void insereNaHash(Hash *h, Elemento *x); //insere um Elemento na Hash

//Elemento *obtemDaHash(Hash *h, Chave c);  //obtem um Elemento da Hash dada sua chave

void imprime(Hash *h); //imprime a tabela Hash h

int obtemNumElem(Hash *h); //retorna o número de elementos inseridos até o momento

#endif // HASH_H_INCLUDED
