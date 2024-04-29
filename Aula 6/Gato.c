#include <stdlib.h>
#include <string.h>
#include "Gato.h"

struct Gato{
   int nivel;
   char* nome; 
};

Gato* inicGato(char* nome, int nivel)
{
    Gato* gato = calloc(1, sizeof(Gato));
    gato -> nivel = nivel;
    gato -> nome = strdup(nome);

    return gato;
}

void atribuiNivelAgressividadeGato(Gato* c, int nivel)
{
    c -> nivel = nivel;
}

void liberaGato(Gato* gato)
{
    free(gato);
}
