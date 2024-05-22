//
//  amostra.h
//  PostoSaude
//
//  Created by Patricia Dockhorn Costa on 14/07/22.
//

#ifndef fila_h
#define fila_h

typedef struct Fila tFila;

#include <stdio.h>
#include "amostra.h"

tFila* criaFila();
void insereFila(tFila*, Amostra*);
void insereComecoFila(tFila*, Amostra* );
void retiraFila(tFila*, Amostra*);
void imprimeFila(tFila*);
void desalocaFila(tFila*);

#endif
