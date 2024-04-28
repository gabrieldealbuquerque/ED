#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

tProduto criaProduto(int codigo, char* nome, int preco)
{
    tProduto produto;
    produto.codigo = codigo;
    produto.nome = strdup(nome);
    produto.preco = preco;
    return produto;
}

int obtemCodigo(tProduto produto)
{
    return produto.codigo;
}

int obtemPreco(tProduto produto)
{
    return produto.preco;
}

char* obtemNome(tProduto produto)
{
    return produto.nome;
}

void desalocaNomeProduto(tProduto produto)
{
    free(produto.nome);
    return;
}