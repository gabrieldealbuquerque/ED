/*Informações sobre o domínio do problema:

- Um Supermercado tem um nome, um vetor de filiais e um valor total do estoque;
- Uma filial tem um nome e um estoque;
- Um estoque tem um valor e um vetor de itens de estoque;
- Um item de estoque tem um quantidade e está relacionado ao um tipo de produto;
- Um tipo de produto tem um nome e um valor.


A dinâmica do programa se resume no seguinte:

- cadastrar tipos de produtos
- alocar um supermercado
- alocar filiais para este supermercado
- alocar itens de estoque para cada filial (associar o produto pré cadastrado a uma quantidade)
- calcular o estoque da filial
- calcular o estoque do supermercado
- imprimir todas as informações relativas ao supermercado, por exemplo:



Nome: Carone, Estoque Total: 184500
             Filial: Jardim Camburi
             Estoque: 23000
                 Item: Leite Integral Selita, valor unitário: 10, quantidade: 200
                 Item: Presunto de Parma, valor unitário: 50, quantidade: 300
                 Item: Queijo, valor unitário: 30, quantidade: 200
             Filial: Jardim da Penha
             Estoque: 161500
                 Item: Biscoito, valor unitário: 5, quantidade: 2000
                 Item: Presunto de Parma, valor unitário: 50, quantidade: 3000
                 Item: Carne de Sol, valor unitário: 30, quantidade: 50*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    char nome[45];
    int valor;
}tTipo;

typedef struct{
    tTipo* tipo;
    int quantidade;
}tItem;

typedef struct{
    int qtdProdutos;
    tItem** itens;
    int qtdItens;
}tEstoque;

typedef struct{
    char nome[45];
    tEstoque* estoque;
}tFilial;

typedef struct{
    char nome[45]; 
    tFilial** filiais; 
    int estoqueTotal;
    int nFiliais;
}tSM;


tSM* criaSM(tSM* mercado)
{
    mercado = calloc (1, sizeof(tSM));
    printf("Digite o nome do mercado:\n");
    scanf("%[^\n]", mercado -> nome);
    printf("Informe o estoqueTotal:\n");
    scanf("%d", &mercado -> estoqueTotal);
    mercado -> nFiliais = 0;
    return mercado;
}

void imprimeMercado(tSM* mercado)
{
    printf("Nome:%s\nEstoque Total:%d\n", mercado -> nome, mercado -> estoqueTotal);
        for (int i = 0; i < mercado->nFiliais; i++) {
        printf("    Filial: %s\n", mercado->filiais[i]->nome);
        printf("        Estoque: %d\n", mercado->filiais[i]->estoque->qtdProdutos);
        for (int j = 0; j < mercado->filiais[i]->estoque->qtdItens; j++) {
            printf("        Item: %s, valor unitário: %d, quantidade: %d\n",
                   mercado->filiais[i]->estoque->itens[j]->tipo->nome,
                   mercado->filiais[i]->estoque->itens[j]->tipo->valor,
                   mercado->filiais[i]->estoque->itens[j]->quantidade);
        }
    }
}


void menu(tSM* mercado)
{
    while (1)
    {
        printf("Adicionar filial?\nS ou N?\n");
        char escolha;
        scanf(" %c", &escolha);
        if (escolha == 'S' || escolha == 's')
        {
            mercado -> nFiliais++;
            mercado -> filiais = (tFilial**)realloc(mercado -> filiais, mercado -> nFiliais * sizeof(tFilial*));
            mercado -> filiais[mercado -> nFiliais-1] = calloc(1, sizeof(tFilial));  
            printf("Digite o nome da filial:\n");
            scanf("  %[^\n]", mercado -> filiais[mercado -> nFiliais-1] -> nome);
            printf("Nome da filial: %s\n", mercado -> filiais[mercado -> nFiliais-1] -> nome);
            mercado -> filiais[mercado -> nFiliais-1] -> estoque = calloc(1, sizeof(tEstoque));
            printf("Informe a quantidade de produtos no estoque:\n");
            scanf(" %d", &mercado -> filiais[mercado -> nFiliais-1] -> estoque -> qtdProdutos);
            mercado -> filiais[mercado -> nFiliais-1] -> estoque -> qtdItens = 0;
            while (1)
            {
                printf("Adicionar as informacoes de algum item do estoque?\nS ou N?\n");
                char escolha2;
                scanf(" %c", &escolha2);
                if (escolha2 == 'S' || escolha2 == 's')
                {
                    
                    mercado -> filiais[mercado -> nFiliais-1] -> estoque -> qtdItens++;
                    mercado -> filiais[mercado -> nFiliais-1] -> estoque -> itens = (tItem**)realloc(mercado -> filiais[mercado -> nFiliais-1] -> estoque -> itens, mercado -> filiais[mercado -> nFiliais-1] -> estoque -> qtdItens * sizeof(tItem*));
                    mercado->filiais[mercado->nFiliais-1]->estoque->itens[mercado->filiais[mercado->nFiliais-1]->estoque->qtdItens-1] = calloc(1, sizeof(tItem));
                    mercado -> filiais[mercado -> nFiliais-1] -> estoque -> itens[mercado -> filiais[mercado -> nFiliais-1] -> estoque -> qtdItens-1] -> tipo = calloc(1, sizeof(tTipo));
                    printf("Digite o nome do item:\n");
                    scanf(" %[^\n]", mercado -> filiais[mercado -> nFiliais-1] -> estoque -> itens[mercado -> filiais[mercado -> nFiliais-1] -> estoque -> qtdItens-1] -> tipo -> nome);
                    printf("Digite o valor unitário do item:\n");
                    scanf(" %d", &mercado -> filiais[mercado -> nFiliais-1] -> estoque -> itens[mercado -> filiais[mercado -> nFiliais-1] -> estoque -> qtdItens-1] -> tipo -> valor);
                    printf("Informe a quantidade de produtos desse tipo que estao disponiveis no estoque:\n");
                    scanf(" %d", &mercado -> filiais[mercado -> nFiliais-1] -> estoque -> itens[mercado -> filiais[mercado -> nFiliais-1] -> estoque -> qtdItens-1] -> quantidade);
                }
                else if (escolha2 == 'N' || escolha2 == 'n')
                {
                    break;
                }
                else
                {
                    printf("Essa alternativa não existe.\n");
                }
            }
        }
        else if (escolha == 'N' || escolha == 'n')
        {
            break;
        }
        else
        {
            printf("Essa alternativa não existe.\n");
        }
    }
}

void imprimeSM(tSM *mercado) {

    printf("Nome: %s, Estoque Total: %d\n", mercado->nome, mercado->estoqueTotal);
    
    for (int i = 0; i < mercado->nFiliais; i++) {
        printf("    Filial: %s\n", mercado->filiais[i]->nome);
        printf("        Estoque: %d\n", mercado->filiais[i]->estoque->qtdProdutos);
        for (int j = 0; j < mercado->filiais[i]->estoque->qtdItens; j++) {
            printf("        Item: %s, valor unitário: %d, quantidade: %d\n",
                   mercado->filiais[i]->estoque->itens[j]->tipo->nome,
                   mercado->filiais[i]->estoque->itens[j]->tipo->valor,
                   mercado->filiais[i]->estoque->itens[j]->quantidade);
        }
    }
}

void desalocaSM(tSM *mercado) {
    if (mercado) {
        for (int i = 0; i < mercado->nFiliais; i++) {
            for (int j = 0; j < mercado->filiais[i]->estoque->qtdItens; j++) {
                free(mercado->filiais[i]->estoque->itens[j]->tipo);
                free(mercado->filiais[i]->estoque->itens[j]);
            }
            free(mercado->filiais[i]->estoque->itens);
            free(mercado->filiais[i]->estoque);
            free(mercado->filiais[i]);
        }
        free(mercado->filiais);
        free(mercado);
    }
}

int main()
{
    tSM* mercado;
    mercado = criaSM(mercado);
    imprimeMercado(mercado);
    menu(mercado);
    imprimeSM(mercado);
    desalocaSM(mercado);
    return 0;
}
