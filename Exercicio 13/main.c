#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "arvore.h"

int main()
{
    tAluno* aluno1 = criaAluno("gabriel", "2023101581", 19);
    tAluno* aluno2 = criaAluno("gandalf", "1", 99999);
    tAluno* aluno3 = criaAluno("vladimir", "1975102495kgb1", 71);
    tAluno* aluno4 = criaAluno("aragorn", "2023202255", 87);
    tAluno* aluno5 = criaAluno("frodo", "2023401234", 33);
    tAluno* aluno6 = criaAluno("legolas", "2023105678", 2931);
    tAluno* aluno7 = criaAluno("samwise", "2023112234", 38);
    tAluno* aluno8 = criaAluno("bilbo", "2023604321", 111);
    tAluno* aluno9 = criaAluno("sauron", "2023785678", 545);
    tAluno* aluno10 = criaAluno("galadriel", "2023908765", 8395);
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
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno4);
                arvore = insereArvore(arvore, aluno5);
                arvore = insereArvore(arvore, aluno6);
                arvore = insereArvore(arvore, aluno7);
                arvore = insereArvore(arvore, aluno8);
                arvore = insereArvore(arvore, aluno9);
                arvore = insereArvore(arvore, aluno10);
            }
            if (teste == 2)
            {
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno7);
                arvore = insereArvore(arvore, aluno5);
                arvore = insereArvore(arvore, aluno9);
                arvore = insereArvore(arvore, aluno10);
                arvore = insereArvore(arvore, aluno1);
            }
            if (teste == 3)
            {
                arvore = insereArvore(arvore, aluno2);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno4);
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno5);
            }
            if (teste == 4)
            {
                arvore = insereArvore(arvore, aluno5);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno2);
            }
            if (teste == 5)
            {
                arvore = insereArvore(arvore, aluno8);
                arvore = insereArvore(arvore, aluno9);
                arvore = insereArvore(arvore, aluno1);
                arvore = insereArvore(arvore, aluno2);
                arvore = insereArvore(arvore, aluno3);
                arvore = insereArvore(arvore, aluno5);
                arvore = insereArvore(arvore, aluno10);
                arvore = insereArvore(arvore, aluno4);
                arvore = insereArvore(arvore, aluno6);
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

    int resposta;
    char chave[200];
    Arv* resultadoBusca;
    while(1)
    {
        printf("Buscar?\n1 para confirmar ou 0 para negar\n");
        scanf(" %d", &resposta);
        if (resposta == 1)
        {
            printf("Digite a matricula do aluno:\n");
                scanf(" %[^\n]", chave);
            resultadoBusca = arvB_busca(arvore, chave);
            if (resultadoBusca)
                printf("A Matricula %s está na árvore\n Nome:%s\n", retornaMatriculadoNo(resultadoBusca), retornaNomedoNo(resultadoBusca));
            else
                printf("%s não está na árvore\n", chave);
            break;
        }
        if (resposta == 0)
        {
            break;
        }
        printf("Essa opção não existe\n");
    }
    resposta = 0;
    Arv* resultadoRetirada;
        while(1)
    {
        printf("Retirar?\n1 para confirmar ou 0 para negar\n");
        scanf(" %d", &resposta);
        if (resposta == 1)
        {
            printf("Digite a matricula do aluno:\n");
                scanf(" %[^\n]", chave);
            resultadoRetirada = abb_retira(arvore, chave);
            if (!resultadoRetirada)
                printf("Aluno foi retirado com sucesso\n");
            else
                printf("Aluno nao encontrado na árvore\n");

            printf("Formato atual da árvore:\n");
            arv_imprime(arvore);
            break;
        }
        if (resposta == 0)
        {
            break;
        }
        printf("Essa opção não existe\n");
    }
    
    return 0;
}