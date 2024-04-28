#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "produto.h"

int main()
{
    tLista* lista = NULL;
    while (1)
    {
        int codigo, preco;
        char nome[50];
        printf("codigo:\n");
        scanf(" %d", &codigo);
        printf("nome:\n");
        scanf(" %[^\n]", nome);
        printf("preco:\n");
        scanf(" %d", &preco);
        tProduto* produto = criaProduto(codigo, nome, preco);
        lista = insereLista(produto, lista);
        int opcao;
        printf("opcao: (1 para encerrar e 0 para adicionar outro produto)\n");
        scanf("%d", &opcao);
        if (opcao)
        {
            break;
        }
    }
    imprimeLista(lista);
    printf("retirar da lista codigo:\n");
    int a;
    scanf(" %d", &a);
    lista = retirarLista(lista, a);
    imprimeLista(lista);
    liberaLista(lista);
    return 0;
}