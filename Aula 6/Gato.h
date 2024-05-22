#ifndef Gato_h
#define Gato_h

#include <stdio.h>

typedef struct _Gato Gato;

Gato* inicGato();
void atribuiNivelAgressividadeGato(void* , int );
int obtemNivelAgressividadeGato(void* g);
void imprimirGato(void* g);
void liberaGato(void* );

#endif
