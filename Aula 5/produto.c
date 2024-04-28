#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

tProduto* criaProduto(int codigo, char* nome, int preco)
{
    tProduto* produto = calloc(1, sizeof(tProduto));
    produto -> codigo = codigo;
    produto -> nome = strdup(nome);
    produto -> preco = preco;
    return produto;
}

void ImprimeProduto(tProduto* produto)
{
    printf("Nome do Produto[%d]: %s\n", produto -> codigo, produto -> nome);
    printf("Preco: %d\n", produto -> preco);
    printf("\n");
}

int obtemCodigo(tProduto* produto)
{
    return produto -> codigo;
}

int obtemPreco(tProduto* produto)
{
    return produto -> preco;
}

char* obtemNome(tProduto* produto)
{
    return produto -> nome;
}

void desalocaProduto(tProduto* produto)
{
    if (produto != NULL)
    {
        free(produto -> nome);
        free(produto);
    }
    return;
}