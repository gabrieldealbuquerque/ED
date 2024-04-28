#ifndef lista_h
#define lista_h

#include "produto.h"

typedef struct lista tLista;

tLista* criarLista();
void insereLista(tProduto* produto, tLista* lista);
void retirarLista(tLista* lista, int codigo);
void imprimeLista(tLista* lista);
void liberaLista(tLista* lista);

#endif

