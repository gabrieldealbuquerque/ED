#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"

#define NPAL 64
#define NTAB 127

int le_palavra (FILE* fp, char* s)
{
    int i = 0;
    int c;
    if (fscanf(fp, " %s", s) != EOF)
        return strlen(s);
    return 0;

    return i;
}

int main(int argc, char** argv)
{
    FILE* fp;
    tHash* tabela;
    char s[NPAL];

    if (argc != 2)
    {
        printf("Arquivo nao encontrado!\n");
        return 0;
    }

    fp = fopen (argv[1], "rt");

    if (fp == NULL)
    {
        printf("Arquivo nao abriu\n");
        return 0;
    }

    tabela = inicHash(NTAB);

    while (le_palavra(fp, s))
    {
        tPalavra* p = acessa(tabela, s);
        
        atualizaOcorrencias(p);
    }

    imprimeHash(tabela);
}