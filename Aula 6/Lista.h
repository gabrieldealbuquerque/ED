#ifndef Lista_h
#define Lista_h

typedef struct celula_str tCelula;
typedef tCelula tLista;

#include "Cachorro.h"
#include "Gato.h"

tLista* insereCachorroNaLista (Cachorro* c);
tLista* insereGatoNaLista (Gato* g);
void desalocaLista (tLista* lista);

#endif