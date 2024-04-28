#include "matriz.h"

int main()
{
    //criacao da primeira matriz
    int linha, coluna, linha2, coluna2;
    printf("Tamanho da matriz:\n");
    scanf("%d %d", &linha, &coluna);
    Matriz* matriz = inicializaMatriz(linha, coluna);
    int l,c,elemento, elemento1, elemento2;
    printf("Adicionar quantos valores?\n");
    int qtd;
    scanf(" %d", &qtd);
    for(int i = 0; i < qtd; i++)
    {
        scanf("%d %d %d", &l, &c, &elemento);
        modificaElemento(matriz, l, c, elemento);
    }
    imprimeMatriz(matriz);
    printf("\n");
    //transposta
    Matriz* tranposta;
    tranposta = transposta (matriz);
    if (tranposta != NULL)
        imprimeMatriz(tranposta); 

    //adicao da segunda matriz e multiplicacao entre elas
    printf("Tamanho da matriz 2 pra multiplicacao\n");
    scanf("%d %d", &linha2, &coluna2);
    Matriz* mat2 = inicializaMatriz(linha2, coluna2);
    printf("Adicionar quantos valores?\n");
    int qtd2;
    scanf(" %d", &qtd2);
    for(int i = 0; i < qtd2; i++)
    {
        scanf("%d %d %d", &l, &c, &elemento2);
        modificaElemento(mat2, l, c, elemento2);
    }
    Matriz* resultadoMult = multiplicacao(matriz, mat2);

    //impressao das matrizes
    if (matriz != NULL)
    {
        printf("\nMatriz 1:\n");
        imprimeMatriz(matriz);
    }
    if (mat2 != NULL)
    {
        printf("\nMatriz 2:\n");
        imprimeMatriz(mat2); 
    }
    if (resultadoMult != NULL)
    {
        printf("\nResultado da multiplicacao:\n");
        imprimeMatriz(resultadoMult);
    }

    //desalocacao das matrizes
    if (matriz != NULL)
        destroiMatriz(matriz);
    if (tranposta != NULL)
        destroiMatriz(tranposta);
    if (mat2 != NULL)
        destroiMatriz(mat2);
    if (resultadoMult != NULL)
        destroiMatriz(resultadoMult);

    return 0;
}