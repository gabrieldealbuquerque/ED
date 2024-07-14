//
//  taluno.h
//

#ifndef taluno_h
#define taluno_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno tAluno;
tAluno* criaAluno (char* nome, char* matricula, int idade);
char* retornaMatricula(tAluno* aluno);
void liberaAluno (tAluno* a);
void imprimeAluno (tAluno* a);
int retornaIdade(tAluno* aluno);
char* retornaNome(tAluno* aluno);

#endif
