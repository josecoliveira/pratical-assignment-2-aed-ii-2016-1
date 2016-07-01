#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

typedef int Chave;

typedef struct Aluno {
    char *nome;
    Chave matricula;
} Aluno;

Aluno *criaAluno(char *n, Chave mat);  // cria Aluno dado seu nome e sua matricula

void apagaAluno(Aluno *a); // desaloca ponteiro aluno (e seus dados)

void imprimeAluno(Aluno *a); // imprime dados de Aluno no formato: (matricula) nome

#endif // ALUNO_H_INCLUDED
