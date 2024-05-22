#include <stdlib.h>
#include "Lista.h"

typedef struct Celula tCelula;

struct Celula{
    int animal;
    void* info;
    tCelula* prox;
};

struct Lista{
    tCelula* prim;
    tCelula* ult;
    int tamanho;
};

tLista* criaLista()
{
    tLista* lista = (tLista*) calloc (1, sizeof(tLista));
    lista -> tamanho = 0;
    return lista;
}

int retornaAnimal(void* celula)
{
    tCelula* c = (tCelula*) celula;
    return c -> animal;
}

void* obtemPrimeiroLista(tLista* lista)
{   
    return lista -> prim;
}

void* obtemUltimoLista(tLista* lista)
{   
    return lista -> ult;
}

void* obtemProximoLista(tLista* lista, void* dado)
{
    tCelula* aux = (tCelula*) dado;
    return aux -> prox;
        
}

void primeiroNULL(tLista* lista)
{
    free(lista -> prim);
    lista -> prim = NULL;
    free(lista -> ult);
    lista -> ult = NULL;
}

int varreLista(tLista* lista1, tLista* lista2, void* dado)
{
    if(lista1 == NULL)
    {
        printf("Lista 1 vazia\n");
        return -1;
    }

    tCelula* aux = obtemPrimeiroLista(lista1);
    tCelula* anterior = NULL;

    while(aux != NULL)
    {
        if(aux->info == dado)
        {
            if(aux->prox != NULL)
            {
                if(anterior == NULL)
                {
                    aux = obtemPrimeiroLista(lista1); 
                    lista1->prim = aux->prox;
                    free(aux);
                }
                else
                {
                    anterior->prox = aux->prox;
                    free(aux);
                }
            }
            else
            {
                if(anterior != NULL)
                {
                    anterior->prox = NULL;
                    free(aux);
                }
                else
                {
                    primeiroNULL(lista1);
                    free(aux);
                }
            }
            return 0;
        }
        anterior = aux;
        aux = aux->prox;
    }

    if(lista2 == NULL)
    {
        return -1;
    }

    aux = obtemPrimeiroLista(lista2);
    anterior = NULL;
    
    while(aux != NULL)
    {
        if(aux->info == dado)
        {
            if(aux->prox != NULL)
            {
                if(anterior == NULL)
                {
                    lista2->prim = aux->prox;
                    free(aux);
                }
                else
                {
                    anterior->prox = aux->prox;
                    free(aux);
                }
            }
            else
            {
                if(anterior != NULL)
                {
                    anterior->prox = NULL;
                    free(aux);
                }
                else
                {
                    primeiroNULL(lista2);
                    free(aux);
                }
            }
            return 1;
        }
        anterior = aux;
        aux = aux->prox;
    }
    return -1;
}


void insereLista(tLista* lista, void* dado, int animal)
{
    tCelula* novo = (tCelula*) calloc (1, sizeof(tCelula));
    if (novo == NULL)
    {
        printf("Bug no novo\n");
        exit(1);
    }
    novo->info = dado;
    novo->animal = animal;
    novo->prox = NULL;

    if (lista->ult == NULL) {
        lista->prim = lista->ult = novo;
    } else {
        lista->ult->prox = novo;
        lista->ult = novo;
    }

    lista->tamanho++;
}


void imprimeLista(tLista* lista, void (*imprimirItem)(void *))
{
    tCelula* aux = lista -> prim;
    while (aux != NULL)
    {
        imprimirItem(aux -> info);
        aux = aux -> prox;
    }
}

void* retornaInfo(void* c)
{
    tCelula* celula = (tCelula*) c;
    return celula -> info;
}

void desalocaLista(tLista* lista)
{
    tCelula* atual = lista->prim;
    while (atual != NULL)
    {
        tCelula* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    free(lista);
}