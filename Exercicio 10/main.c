#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "arvore.h"

int main()
{
    tAluno* aluno1 = criaAluno("gabriel", "2023101581", 19);
    tAluno* aluno2 = criaAluno("gandalf", "1", 99999);
    tAluno* aluno3 = criaAluno("vladimir", "1975102495kgb1", 71);
    Arv* arvore = arv_criavazia();
    printf("Escolha o teste:\n");
    printf("\tTeste 1 - Digite 1\n");
    printf("\tTeste 2 - Digite 2\n");
    printf("\tTeste 3 - Digite 3\n");
    printf("\tTeste 4 - Digite 4\n");
    printf("\tTeste 5 - Digite 5\n");
    int teste = 0;
    while (1)
    {
        scanf(" %d", &teste);
        if (teste >= 1 && teste <= 5)
        {
            if (teste == 1)
            {
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno2);
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno2);
            }
            if (teste == 2)
            {
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno2);
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno2);           
            }
            if (teste == 3)
            {
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno2);
                arvore = insereArvore(arvore, aluno2);
                arvore = insereArvore(arvore, aluno1);
            }
            if (teste == 4)
            {
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno2);
                arvore = insereArvore(arvore, aluno2);
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno2);
            }
            if (teste == 5)
            {
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno2);
            }
            break;
        }
        printf("\n\nNumero escolhido invalido\n\n");
    }
    arv_imprime(arvore);
    int contador = ocorrencias(arvore, "gandalf");
    printf("gandalf apareceu %d vezes\n", contador);
    int folhasArvore = folhas(arvore);
    printf("A arvore possui %d folhas\n", folhasArvore);
    int alturaArvore = altura(arvore);
    printf("A arvore possui altura %d de altura\n", alturaArvore);
    return 0;
}