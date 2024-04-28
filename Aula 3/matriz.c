#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    int nLinhas;
    int nColunas;
    int** matrix;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    Matriz* matriz; 
    matriz = calloc(1, sizeof(Matriz));
    matriz -> nLinhas = nlinhas;
    matriz -> nColunas = ncolunas;
    matriz -> matrix = calloc (1, (sizeof(int*) * nlinhas));
    for (int i = 0; i < nlinhas; i++)
    {
        matriz -> matrix[i] = calloc(1, (sizeof(int) * ncolunas));
    }


    for(int i = 0; i < nlinhas; i++)
    {
        for (int j = 0; j < ncolunas; j++)
        {
            matriz -> matrix[i][j] = 0;
        }
    }
    return matriz;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    if (linha > mat -> nLinhas || linha < 0 || coluna > mat -> nColunas || coluna < 0)
    {
        printf("A posicao informa nao faz parte da matriz.\n");
        return;
    }
    mat -> matrix[linha-1][coluna-1] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    return mat -> matrix[linha][coluna];
}

int recuperaNColunas (Matriz* mat)
{
    return mat -> nColunas;
}

int recuperaNLinhas (Matriz* mat)
{
    return mat -> nLinhas;
}

Matriz* transposta (Matriz* mat)
{
    Matriz* transposta = inicializaMatriz(mat -> nColunas, mat -> nLinhas);
    for (int i = 0; i < transposta -> nLinhas; i++)
    {
        for (int j = 0; j < transposta -> nColunas; j++)
        {
            transposta -> matrix[i][j] = mat -> matrix[j][i];
        }
    }
    return transposta;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
    if (mat1 -> nColunas != mat2 -> nLinhas)
    {
        printf("Nao e possivel efetuar a multiplicacao\n");
        return NULL;
    }
    Matriz* resultado = inicializaMatriz(mat1 -> nLinhas, mat2 -> nColunas);
    for (int i = 0; i < mat1 -> nLinhas; i++)
    {
        for (int j = 0; j < mat2 -> nColunas; j++)
        {
            for (int c = 0; c < mat1 -> nColunas; c++)
            {
                for(int k = 0; k < mat2 -> nLinhas; k++)
                {
                    resultado -> matrix[i][j] += (mat1 -> matrix[i][c] * mat2 -> matrix[k][j]);
                    c++;
                }
            }
        }
    }
    return resultado;
}

void imprimeMatriz(Matriz* mat)
{
    int temMaiorq10 = 0;
    for(int i = 0; i < mat -> nLinhas; i++)
    {
        if (mat -> matrix[i][mat -> nColunas-1] > 9)
        {
            temMaiorq10++;
        }
    }
    for(int i = 0; i < mat -> nLinhas; i++)
    {
        printf("|");
        for (int j = 0; j < mat -> nColunas; j++)
        {
            printf("%d", mat -> matrix[i][j]);
            if (j != mat -> nColunas-1)
            {
                printf(" ");
                if (mat -> matrix[i][j] < 10)
                printf(" ");
            }
            else
            {
                if (temMaiorq10 > 0 && mat -> matrix[i][j] < 10)
                {
                    printf(" ");
                }
            }
        }
        printf("|\n");
    }
}

void imprimeLinhas (Matriz* mat, int indice)
{
    for (int j = 0; j < mat -> nColunas; j++)
    {
        printf("%d ", mat -> matrix[indice][j]);
    }
    printf("\n");
}

void destroiMatriz (Matriz* mat)
{
    for (int i = 0; i < mat -> nLinhas; i++)
    {
        free(mat -> matrix[i]);
    }
    free(mat -> matrix);
    free(mat);
}
