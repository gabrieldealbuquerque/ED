#include <stdlib.h>
#include "fila.h"

typedef struct lista tLista;

struct lista{
    Amostra* info;
    tLista* prox;
    tLista* ant;
};

struct Fila
{
    tLista* inicio;
    tLista* fim;
};


#include <stdlib.h>
#include "fila.h"

tFila* criaFila()
{
    tFila* fila = (tFila*) calloc (1, sizeof(tFila));
    fila -> fim = fila -> inicio = NULL;
    return fila;
}

void insereFila(tFila* fila, Amostra* dado)
{
    //fila sempre se insere no final
    tLista* lista = (tLista*) calloc(1, sizeof(tLista));
    
    lista -> info = dado;
    if (fila -> fim == NULL)
    {
        fila -> inicio = fila -> fim = lista;
        return;
    }
    lista -> prox = NULL;
    lista -> ant = fila -> fim;
    fila -> fim -> prox = lista;
    fila -> fim = lista;
}

void insereComecoFila(tFila* fila, Amostra* dado)
{
    //fila com prioridade se insere no inicio
    tLista* lista = (tLista*) calloc(1, sizeof(tLista));
    
    lista -> info = dado;
    if (fila -> fim == NULL)
    {
        fila -> inicio = fila -> fim = lista;
        return;
    }
    lista -> prox = fila -> inicio;
    fila -> inicio -> ant = lista;
    lista -> ant = NULL;
    fila -> inicio = lista;
}

void retiraFila(tFila* fila, Amostra* dado)
{

}
void imprimeFila(tFila* fila)
{
    tLista* lista = fila -> inicio;
    while (lista)
    {
        imprimeAmostra(lista -> info);
        lista = lista -> prox;
    }
}
void desalocaFila(tFila* fila)
{
    if (fila == NULL)
        return;
    tLista* lista = fila -> inicio;
    tLista* aux = lista;
    while (lista)
    {
        aux = lista;
        lista = lista -> prox;
        liberaAmostra(aux -> info);
        free(aux);

    }

    free(fila);
}