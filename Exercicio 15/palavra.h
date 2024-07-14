
#ifndef palavra_h
#define palavra_h

#include <stdio.h>

typedef struct palavra tPalavra;

tPalavra* inicPalavra(char* palavra);
char* retornaPalavra(tPalavra* palavra);
void atualizaOcorrencias(tPalavra* palavra);
int retornaOcorrencias(tPalavra* palavra);
tPalavra* buscaPalavra(tPalavra* pal, char* palavra);
tPalavra* inserePalavraLista(tPalavra* lista, tPalavra* palavra);
int contaPalavrasLista(tPalavra* palavra);
void imprimeLista(tPalavra* lista);
void liberaListaPalavra(tPalavra* lista);



#endif
