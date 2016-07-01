#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

/*-----------------------------------------------------
  Protótipo: Aluno *criaAluno(char *n, Chave mat)
  Função: Aloca e cria uma nova estrutura Aluno.
  Entrada: String com nome e Chave com matrícula Aluno.
  Saída: Ponteiro para a estrutura do novo Aluno.
  -----------------------------------------------------*/
Aluno *criaAluno(char *n, Chave mat) {
    Aluno *novoAluno = malloc(sizeof(Aluno));
    novoAluno->nome = n;
    novoAluno->matricula = mat;
    return novoAluno;
}
/*-------------------------------------
  Protótipo: void apagaAluno(Aluno *a)
  Função: Desaloca uma estrutura Aluno.
  Entrada: Ponteiro para a esturura.
  Saída: Nenhuma.
  -------------------------------------*/
void apagaAluno(Aluno *a) {
    free(a);
}

/*
  Protótipo: void imprimeAluno(Aluno *a)
  Função: Imprime matricula e nome da estrutura Aluno.
  Estrada: Ponteiro para a estrutura Aluno.
  Saída: Nenhuma.
*/
void imprimeAluno(Aluno *a) {
    printf("(%d) %s\n", a->matricula, a->nome);
}
