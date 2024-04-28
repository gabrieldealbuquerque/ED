#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
    tProduto* produto;
    tLista* anterior;
    tLista* proximo;
};

tLista* criarLista()
{
    tLista* lista = (tLista*) calloc (1, sizeof(tLista));
    lista -> proximo = NULL;
    lista -> produto = NULL;
    lista -> anterior = NULL;
    return lista;
}

tLista* insereLista(tProduto* produto, tLista* lista)
{
    if (!produto)
    {
        printf("Produto NULL");
        exit(1);
    }
    tLista* novaLista = criarLista();

    novaLista -> produto = produto;
    novaLista -> anterior = NULL;
    novaLista -> proximo = lista;
    if (lista) 
        lista -> anterior = novaLista;

    return novaLista;
}

tLista* retirarLista(tLista* lista, int codigo)
{
    if (lista == NULL) {
        printf("Lista vazia\n");
        return lista;
    }

    tLista* atual = lista;

    while (atual != NULL)
    {
        if (atual->produto != NULL && obtemCodigo(atual->produto) == codigo)
        {
            if (atual->anterior != NULL)
                atual->anterior->proximo = atual->proximo;
            if (atual->proximo != NULL)
                atual->proximo->anterior = atual->anterior;

            if (atual == lista)
                lista = atual->proximo;

            if(atual -> produto)
                desalocaProduto(atual->produto);
            free(atual);
            return lista;
        }
        atual = atual->proximo;
    }

    printf("Produto com código %d não encontrado na lista\n", codigo);
    return lista;
}

void imprimeLista (tLista* Lista)
{
    if(Lista == NULL)
    {
        printf("Lista vazia\n");
        return;
    }
    tLista* aux = Lista;
    while(aux)
    {
        if(aux -> produto)
            ImprimeProduto(aux -> produto);
        aux = aux -> proximo;
    }
}

void liberaLista(tLista* lista)
{
    if(lista == NULL)
    {
        printf("Lista vazia\n");
        return;
    }
    tLista* aux = lista;
    while(aux)
    {
        lista = aux -> proximo;
        desalocaProduto(aux -> produto);
        free(aux);
        aux = lista;
    }
}