#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

void calc_esfera (float r, float* area, float* volume)
{
    /*area = 4pir²
    volume = 4pir³/3*/

    *area = 4*PI*pow(r, 2);
    *volume = (4*PI*pow(r, 3))/3;
}

int raizes (float a, float b, float c, float* x1, float* x2)
{
    /*ax²+bx+c = 0
    b²-4ac
    -b+-sqrtdelta/2a*/

    float delta;
    delta = (pow(b, 2) - (4*a*c));
    if (delta < 0)
    {
        return 0;
    }
    *x1 = ((-b + sqrt(delta))/(2*a));
    *x2 = ((-b - sqrt(delta))/(2*a));
    if (*x1 == *x2)
    {
        return 1;
    }
    return 2;
}

int pares (int n, int* vet)
{
    int i, a = 0;
    for(i = 0; i < n; i++)
    {
        if (!(vet[i]%2))
        {
            a++;
        }
    }
    return a;
}

void inverte (int n, int* vet)
{
    int temp;
    int i, j;
    for(i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }
}

double avalia (double* poli, int grau, double x)
{
    int i;
    double resultado = 0;
    for(i = grau+1; i--; i > -1)
    {
        if (i != 0)
        {
            resultado += (poli[i]*pow(x, i));
        }
        else
        {
            resultado += poli[i];
        }
    }
    return resultado;
}

/*main calc_esfera*/
int main()
{
    float raio;
    printf("valor do raio:\n");
    scanf("%f", &raio);
    float* area = calloc(1, sizeof(float));
    float* volume = calloc(1, sizeof(float));
    calc_esfera(raio, area, volume);
    printf("area:%.3f\n", *area);
    printf("volume:%.3f\n", *volume);
    free(area);
    free(volume);
    return 0;
}

/*main raizes*/
/*
int main()
{
    float a, b, c;
    printf("digite o valor de a:\n");
    scanf("%f", &a);
    printf("digite o valor de b:\n");
    scanf("%f", &b);
    printf("digite o valor de c:\n");
    scanf("%f", &c);
    float* x1 = calloc(1, sizeof(float));
    float* x2 = calloc(1, sizeof(float));
    int nRaizes;
    nRaizes = raizes(a, b, c, x1, x2);
    printf("Numero de raizes:%d\n", nRaizes);
    if (nRaizes == 0)
    {
        printf("Nao existem raizes reais para a equacao\n");
    }
    else if (nRaizes == 1)
    {
        printf("Raiz = %f\n", *x1);
    }
    else if (nRaizes == 2)
    {
        printf("Raiz 1 = %f\n", *x1);
        printf("Raiz 2 = %f\n", *x2);
    }
    free(x1);
    free(x2);
}*/

/*main pares*/
/*
int main()
{
    int tVetor;
    printf("digite o tamanho do vetor:\n");
    scanf("%d", &tVetor);
    int* vetor = calloc(tVetor, sizeof(int));
    for (int i = 0; i < tVetor; i++)
    {
        printf("digite o elemento %d do vetor:\n", i);
        scanf("%d", &vetor[i]);
    }
    int qtdPar;
    qtdPar = pares(tVetor, vetor);
    free(vetor);
    printf("Quantidade de pares: %d", qtdPar);
}*/

/*main inverte*/
/*
int main()
{
    int tVetor;
    printf("digite o tamanho do vetor:\n");
    scanf("%d", &tVetor);
    int* vetor = calloc(tVetor, sizeof(int));
    for (int i = 0; i < tVetor; i++)
    {
        printf("digite o elemento %d do vetor:\n", i);
        scanf("%d", &vetor[i]);
    }
    inverte(tVetor, vetor);
    for(int i = 0; i < tVetor; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
}*/

/*main avalia*/
/*
int main()
{
    int grau;
    printf("digite o grau da equacao:\n");
    scanf("%d", &grau);
    double* vetor = calloc(grau+1, sizeof(double));
    for (int i = 0; i < grau+1; i++)
    {
        printf("digite o coeficiente de grau %d:\n", i);
        scanf("%lf", &vetor[i]);
    }
    double resultado, x;
    printf("digite o valor de x:\n");
    scanf("%lf", &x);
    resultado = avalia(vetor, grau, x);
    printf("O resultado da equacao e: %.3lf\n", resultado);
    free(vetor);
    return 0;
}*/