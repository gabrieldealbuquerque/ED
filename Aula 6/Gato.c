#include <stdlib.h>
#include <string.h>
#include "Gato.h"

struct _Gato
{
    char* nome;
    int agressividade;
};

Gato* inicGato(char* nome, int agressividade)
{
    Gato* gato = (Gato*) calloc (1, sizeof(Gato));
    gato -> nome = strdup(nome);
    gato -> agressividade = agressividade;
    return gato;
}
void atribuiNivelAgressividadeGato(void* g, int nivel)
{
    Gato* gato = (Gato*) g;
    gato -> agressividade = nivel;
}

int obtemNivelAgressividadeGato(void* g)
{
    Gato* gato = (Gato*) g;
    return gato -> agressividade;
}

void imprimirGato(void* g)
{
    Gato* gato = (Gato*) g;
    printf("Gato: %s ", gato -> nome);
    if (gato -> agressividade == 0)
    {
        printf("Agressivo: Não\n");
    }
    else
        printf("Agressivo: Sim\n");
}

void liberaGato(void* g)
{
    Gato* gato = (Gato*) g;
    free(gato -> nome);
    free(gato);
}
