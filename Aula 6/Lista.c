    #include <stdio.h>
    #include <stdlib.h>
    #include "Lista.h"

    struct celula_str{
        int tipo;
        void* Item;
        struct celula_str* Prox;
    };

    tLista* insereCachorroNaLista (Cachorro* c)
    {
        tLista* p;
        p->tipo = 0; //0 é pra cachorrros
        p->Item = c;
        p->Prox = NULL;
        return p;
    }

    tLista* insereGatoNaLista (Gato* g)
    {
        tLista* p;
        p->tipo = 1; //0 é pra gatos
        p->Item = g;
        p->Prox = NULL;
        return p;
    }

    void desalocaLista (tLista* lista)
    {
        if(lista == NULL)
        {
            printf("Lista vazia\n");
            return;
        }

        tLista* aux = lista;
        while (aux)
        {
            lista = aux -> Prox;
            if (aux -> tipo == CACHORRO)
                liberaCachorro(lista -> Item);
            if (aux -> tipo == GATO)
                liberaGato(lista -> Item);
            free(aux);
            aux = lista;
        }
    }