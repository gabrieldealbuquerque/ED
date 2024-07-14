
#include "aluno.h"

struct aluno
{
    char* nome;
    char* matricula;
    int idade;
};

tAluno* criaAluno (char* nome, char* matricula, int idade)
{
    tAluno* aluno = (tAluno*) calloc (1, sizeof(tAluno));
    aluno -> nome = strdup(nome);
    aluno -> matricula = strdup(matricula);
    aluno -> idade = idade;
}

void liberaAluno (tAluno* a)
{
    free(a -> nome);
    free(a -> matricula);
    free(a);
}

char* retornaMatricula(tAluno* aluno)
{
    return aluno -> matricula;
}

int retornaIdade(tAluno* aluno)
{
    return aluno -> idade;
}

char* retornaNome(tAluno* aluno)
{
    return aluno -> nome;
}

void imprimeAluno (tAluno* a)
{
    printf("Nome do aluno: %s\n", a -> nome);
    printf("\tIdade: %d\n", a -> idade);
    printf("\tMatricula: %s\n", a -> matricula);
}