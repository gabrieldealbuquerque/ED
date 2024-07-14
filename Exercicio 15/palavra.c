#include "palavra.h"
#include <stdlib.h>
#include <string.h>

struct palavra{
    char* palavra;
    int ocorrencias;
    tPalavra* prox;
};

tPalavra* inicPalavra(char* palavra)
{
    tPalavra* p = (tPalavra*) calloc (1, sizeof(tPalavra));
    p -> palavra = strdup(palavra);
    p -> ocorrencias = 0;
    p -> prox = NULL;
    return p;
}
char* retornaPalavra(tPalavra* palavra)
{
    return palavra -> palavra;
}
void atualizaOcorrencias(tPalavra* palavra)
{
    palavra -> ocorrencias++;
}
int retornaOcorrencias(tPalavra* palavra)
{
    return palavra -> ocorrencias;
}
tPalavra* buscaPalavra(tPalavra* pal, char* palavra)
{
    tPalavra* p;

    for(p = pal; p != NULL; p = p -> prox)
    {
        if (strcmp(palavra, p -> palavra) == 0)
            return p;
    }
    return NULL;
}
tPalavra* inserePalavraLista(tPalavra* lista, tPalavra* palavra)
{
    palavra -> prox = lista;

    return palavra;
}
int contaPalavrasLista(tPalavra* palavra)
{
    tPalavra* p;
    int i = 0;

    for (p = palavra; p != NULL; p = p -> prox)
    {
        i++;
    }
    return i;
}
void imprimeLista(tPalavra* lista)
{
    tPalavra* p;
    for(p = lista; p != NULL; p = p -> prox)
    {

            printf("Palavra: %s\n\tOcorrencias: %d\n", p -> palavra,
            p -> ocorrencias);
    }
}
void liberaListaPalavra(tPalavra* lista)
{
    tPalavra* aux = lista;
    tPalavra* t;

    while (aux != NULL)
    {
        t = aux -> prox;
        free(aux -> palavra);
        free(aux);
        aux = t;
    }
}