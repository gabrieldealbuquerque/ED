#ifndef Cachorro_h
#define Cachorro_h

#include <stdio.h>

#define MANSO 0
#define BRAVO 1

typedef struct _Cachorro Cachorro;

Cachorro* inicCachorro();
void atribuiNivelAgressividadeCachorro(void* , int );
int obtemNivelAgressividadeCachorro(void* c);
void imprimirCachorro(void* c);
void liberaCachorro(void* );

#endif
