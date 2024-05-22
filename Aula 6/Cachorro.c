#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"

struct _Cachorro
{
    char* nome;
    int agressividade;
};

Cachorro* inicCachorro(char* nome, int agressividade)
{
    Cachorro* cachorro = (Cachorro*) calloc (1, sizeof(Cachorro));
    cachorro -> nome = strdup(nome);
    cachorro -> agressividade = agressividade;
    return cachorro;
}
void atribuiNivelAgressividadeCachorro(void* c, int nivel)
{
    Cachorro* cachorro = (Cachorro*) c;
    cachorro -> agressividade = nivel;
}

int obtemNivelAgressividadeCachorro(void* c)
{
    Cachorro* cachorro = (Cachorro*) c;
    return(cachorro -> agressividade);
}

void imprimirCachorro(void* c)
{
    Cachorro* cachorro = (Cachorro*) c;
    printf("Cachorro: %s ", cachorro -> nome);
    if (cachorro -> agressividade == 0)
    {
        printf("Agressivo: Não\n");
    }
    else
        printf("Agressivo: Sim\n");
}

void liberaCachorro(void* c)
{
    Cachorro* cachorro = (Cachorro*) c;
    free(cachorro -> nome);
    free(cachorro);
}
