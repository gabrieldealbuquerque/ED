#include <stdio.h>
#include "Lista.h"


#define MANSO 0
#define AGRESSIVO 1

struct celula_str{
    int tipo;
    void* Item;
    struct celula_str* Prox;
}

typedef Celula TipoListaHet;

TipoListaHet* criaCachorro (int tipo, char* nome)
{
    Cachorro* c = (Cachorro*) malloc(sizeof(Cachorro));
    c->tipo = tipo;
    c->nome = nome;
    TipoListaHet* p = (Cachorro*) malloc(sizeof(Cachorro));
    p->tipo = 0; //0 é pra cachorrros
    p->Item = c;
    p->Prox = NULL;
    return p;
}

TipoListaHet* criaGato (int tipo, char* nome)
{
    Gato* g = (Gato*) malloc(sizeof(Gato));
    c->tipo = tipo;
    c->nome = nome;
    TipoListaHet* p = (Gato*) malloc(sizeof(Gato));
    p->tipo = 1; //0 é pra gatos
    p->Item = g;
    p->Prox = NULL;
    return p;
}

void desalocaCachorro (char* nome)
{

}

void desalocaGato (char * nome)
{
    
}