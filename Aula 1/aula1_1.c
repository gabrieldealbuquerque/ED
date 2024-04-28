#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void digiteValor()
{
    printf("Digite o valor:\n");
}

int main()
{
    int a = 1, b = 2, c = 3, d = 4;
    int* p;
    int* s;
    int* t;
    int* q;

    p = &a;
    s = &b;
    t = &c;
    q = &d;

    printf("a:%d b:%d c:%d d:%d\n", a, b, c, d);
    printf("p:%d s:%d t:%d q:%d\n", *p, *s, *t, *q);

    while (1)
    {
        printf("--------------------------------------\n");
        printf("Mudar valor de qual variavel?\n");
        int op;
        scanf("%d", &op);
        int l = 0;
        int valor;
        if (op == 1)
        {
            digiteValor();
            scanf("%d", &valor); 
            *p = valor;
            l++;
        }
        else if(op == 2)
        {
            digiteValor();
            scanf("%d", &valor); 
            *s = valor;
            l++;
        }
        else if(op == 3)
        {
            digiteValor();
            scanf("%d", &valor);
            *t = valor;
            l++; 
        }
        else if(op == 4)
        {
            digiteValor();
            scanf("%d", &valor);
            *q = valor;
            l++; 
        }
        else
        {
            printf("Variavel nao existe\n");
            printf("--------------------------------------\n");
        }
        printf("a:%d b:%d c:%d d:%d\n", a, b, c, d);
        printf("p:%d s:%d t:%d q:%d\n", *p, *s, *t, *q);
        if (l > 0)
        {
            while(1)
            {
                int opca;
                printf("--------------------------------------\n");
                printf("Alterar outra variavel? S = 1| N = 0\n");
                printf("--------------------------------------\n");
                scanf("%d", &opca);
                if (opca == 0)
                {
                    exit(0);
                }
                else if (opca != 1)
                {
                    printf("Opcao escolhida nao existe\n");   
                }
                if (opca == 1)
                {
                    break;
                }
            }
        }
    }
    return 0;
}