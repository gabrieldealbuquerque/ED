#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


typedef struct celula tCelula;

struct celula
{
    tProduto produto;
    tCelula* proximo;
};

struct lista
{
    tCelula* primeiro;
    tCelula* ultimo;
    int tamanho;
};

tLista* criarLista()
{
    tLista* lista = (tLista*) calloc (1, sizeof(tLista));
    lista -> primeiro = NULL;
    lista -> ultimo = NULL;
    lista -> tamanho = 0;
    return lista;
}

void insereLista(tProduto* produto, tLista* lista)
{
    tCelula* novo = (tCelula*) calloc (1, sizeof(tCelula));
    if (lista -> ultimo == NULL) 
        lista -> primeiro = lista -> ultimo = novo;
    else
    {
        lista -> ultimo -> proximo = novo;
        lista -> ultimo = novo;
    }
    lista -> ultimo -> produto = *produto;
    lista -> ultimo -> proximo = NULL;
    lista -> tamanho++;
}

void retirarLista(tLista* lista, int codigo)
{
    tCelula* anterior = NULL;
    tCelula* p = lista->primeiro;
    
    while (p != NULL && obtemCodigo(p->produto) != codigo)
    { 
        anterior = p;
        p = p->proximo;
    }
    
    if (p == NULL)
        return;
    
    if (p == lista->primeiro && p == lista->ultimo)
    {
        lista->primeiro = lista->ultimo = NULL;
        desalocaNomeProduto(p -> produto);
        free(p);
        lista->tamanho--;
        return; 
    }

    if (p == lista->ultimo)
    {
        lista->ultimo = anterior; 
        anterior->proximo = NULL; 
        desalocaNomeProduto(p -> produto);
        free(p);
        lista->tamanho--;
        return;
    }
    
    if (p == lista->primeiro)
        lista->primeiro = p->proximo;
    else
        anterior->proximo = p->proximo;
    desalocaNomeProduto(p -> produto);
    free(p);
    lista->tamanho--;
}

void imprimeLista (tLista* Lista)
{
    tCelula* Aux;
    Aux = Lista -> primeiro;
    printf("\nformato da lista atual:\n");
    while (Aux != NULL)
    {
        printf ("%d\n", obtemCodigo(Aux -> produto));
        printf ("%s\n", obtemNome(Aux -> produto));
        printf ("%d\n", obtemPreco(Aux -> produto));
        Aux = Aux -> proximo;
        printf("\n");
    }
}

void liberaLista(tLista* lista)
{
      if (lista == NULL) {
        printf("Lista é nula\n");
        return;
    }

    if (lista->ultimo == NULL) {
        printf("Lista está vazia\n");
        free(lista);
        return;
    }
    tCelula* atual = lista->ultimo;
    while (atual != NULL)
    {
        tCelula* temp = atual;
        desalocaNomeProduto(temp -> produto);
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}