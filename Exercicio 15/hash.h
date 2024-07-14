#ifndef hash_h
#define hash_h

#include <stdio.h>
#include "palavra.h"

typedef struct hash tHash;

tHash* inicHash(int tamanho);
tPalavra* acessa(tHash*, char*);
int contaPalavras(tHash*);
void imprimeHash(tHash*);
void liberaHash(tHash*);



#endif
