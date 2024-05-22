//
//  pedido.h
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 02/10/19.
//  Copyright © 2019 Patricia Dockhorn Costa. All rights reserved.
//

/* TAD Pedido. Um Pedido consiste de uma lista de Produtos!!!! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

/* Define o tipo TPedido (tipo opaco). Estrutura interna deste tipo eh definida na implementacao do TAD.
 * Trata-se da sentinela da lista e deve conter as seguintes informacoes:
 * Dono do pedido (char*) e os campos prim e ult da sentinela
 */

typedef struct _tCelula tCelula;

struct pedido{
    char* donoDoPedido;
    tCelula* prim;
    tCelula* ult;
};

struct _tCelula{
    TProduto* info;
    tCelula* prox;
    tCelula* ant;
};


/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono)
{
    TPedido* pedido = (TPedido*) calloc (1, sizeof(TPedido));
    pedido -> donoDoPedido = strdup(dono);
    return pedido;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido (TPedido* pedido, TProduto* prod)
{
    tCelula* novoProduto = (tCelula*) calloc (1, sizeof(tCelula));
    if (pedido -> ult == NULL)
    {
        pedido -> prim = pedido -> ult = novoProduto;
    }
    else
    {
        tCelula* celulaAnterior = pedido -> ult; 
        pedido -> ult -> prox = novoProduto;
        pedido -> ult = novoProduto;
        pedido -> ult -> ant = celulaAnterior;
    }
    pedido -> ult -> info = prod;
    pedido -> ult -> prox = NULL;
}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido (TPedido* pedido)
{
    if (pedido -> ult == NULL)
    {
        printf("Nao ha produtos neste pedido!\n");
        return;
    }
    tCelula* atual = pedido->prim;
    while (atual != NULL)
    {
        tCelula* temp = atual;
        atual = atual->prox;
        ImprimeIngredientes(temp -> info);
    }
}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod)
{
    if (pedido == NULL)
    {
        return;
    }
    if (pedido -> ult == NULL)
    {
        printf("Nao ha produtos neste pedido!\n");
        return;
    }
    tCelula* atual = pedido->prim;
    while (atual != NULL)
    {
        tCelula* temp = atual;
        if (!strcmp(RetornaNome(atual -> info), prod))
        {           
            if (temp -> ant != NULL) 
                temp -> ant -> prox = temp -> prox;
            else
                pedido -> prim = temp -> prox;
            if (temp -> prox != NULL)
                temp -> prox -> ant = temp -> ant;
            else
                pedido -> ult = temp -> ant;
            temp -> prox = NULL;
            temp -> ant = NULL;
            free(temp);
            return;
        }
        atual = atual->prox;
    }
}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: Pedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar)
{
    if(pedido == NULL)
    {
        return 0;
    }
    int caloriaTotal = 0;
    int temRestricaoAlimentar = 0;
    
    tCelula* atual = pedido->prim;
    
    while (atual != NULL)
    {
        caloriaTotal += Calorias(atual -> info);
        atual = atual->prox;
    }

    if (caloriaTotal > restricao_calorica)
    {
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }
    atual = pedido -> prim;
    while (atual != NULL)
    {
        tCelula* temp = atual;
        temRestricaoAlimentar = VerificaIngrediente(temp -> info, restricao_alimentar);
        if (temRestricaoAlimentar)
        {
            printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome((TProduto*)atual -> info));
            return 0;
        }
        atual = atual->prox;
    }
    if (pedido -> prim != NULL)
    {   
        tCelula* a = pedido->prim;
        while (a != NULL)
        {
            tCelula* temp = a;
            a = a->prox;
            if (temp != NULL)
                free(temp);
        }
    }
    else
        {
            printf("sdgsdfopghksdfopghkspdfogh");
            exit(1);
        }
    free(pedido -> donoDoPedido);
    free(pedido);
    return 1;
}
