#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"

struct Cachorro{
   int nivel;
   char* nome; 
};

Cachorro* inicCachorro(char* nome, int nivel)
{
    Cachorro* cachorro = calloc(1, sizeof(Cachorro));
    cachorro -> nivel = nivel;
    cachorro -> nome = strdup(nome);

    return cachorro;
}

void atribuiNivelAgressividadeCachorro(Cachorro* c, int nivel)
{
    c -> nivel = nivel;
}

void liberaCachorro(Cachorro* cachorro)
{
   free(cachorro);
}