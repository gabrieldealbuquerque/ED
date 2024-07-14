#include "hash.h"
#include "palavra.h"
#include <stdlib.h>
#include <string.h>

struct hash{
    tPalavra** vetor;
    int tamanho;
};

static int hash (char* s , int tamanho)
{
    int i;
    int total = 0;
    for (i = 0; s[i] != '\0'; i++)
        total += s[i];
    return (total % tamanho);
}

tHash* inicHash(int tamanho)
{
    int i;
    tHash* h = (tHash*) calloc (1, sizeof(tHash));
    h -> tamanho = tamanho;
    h -> vetor = (tPalavra**) calloc (tamanho, sizeof(tPalavra*));
    for (i = 0; i < tamanho; i++)
        h -> vetor[i] = NULL;
    return h;
}
tPalavra* acessa(tHash* h, char* palavra)
{
    tPalavra* p;
    int indice = hash (palavra, h -> tamanho);
    
    p = buscaPalavra(h -> vetor[indice], palavra);
    if (p)
        return p;

    p = inicPalavra(palavra);
    h -> vetor[indice] = inserePalavraLista(h -> vetor[indice], p);

    return p;
}
int contaPalavras(tHash* h)
{
    int soma = 0;
    for (int i = 0; i < h -> tamanho; i++)
    {
        soma = soma + contaPalavrasLista (h -> vetor[i]);
    }
    return soma;
}
void imprimeHash(tHash* h)
{
    for (int i = 0; i < h -> tamanho; i++)
    {
        if (h -> vetor[i] != NULL)
        {
            printf("\nPosição Vetor[%d]: \n", i);
            imprimeLista(h -> vetor[i]);
    }
    }
}
void liberaHash(tHash* h)
{
    for (int i = 0; i < h -> tamanho; i++)
        liberaListaPalavra(h -> vetor[i]);
    
    free(h -> vetor);
    free(h);
}