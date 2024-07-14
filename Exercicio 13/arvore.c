#include "arvore.h"
#include "aluno.h"

struct arv {
    tAluno* info;
    struct arv* esq;
    struct arv* dir;
};


Arv* arv_criavazia ()
{
    return NULL;
}

Arv* arv_cria (tAluno* aluno, Arv* sae, Arv* sad)
{
    Arv* p = (Arv*) calloc (1, sizeof(Arv));
    p->info = aluno;
    p->esq = sae;
    p->dir = sad;

    return p;
}

char* retornaNomedoNo(Arv* arvore)
{
    return retornaNome(arvore -> info);
}

char* retornaMatriculadoNo(Arv* arvore)
{
    return retornaMatricula(arvore -> info);
}

Arv* insereArvore (Arv* a, tAluno* aluno)
{

    if (a==NULL) 
    {
        a = (Arv*)calloc (1, sizeof(Arv));
        a->info = aluno;
        a->esq = a->dir = NULL;  
    }
    else if (retornaIdade(aluno) < retornaIdade(a->info))
        a->esq = insereArvore(a->esq,aluno);
    else /* v < a->info */
        a->dir = insereArvore(a->dir,aluno);

    return a;
}

Arv* arv_libera (Arv* a)
{
    if (!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

int arv_vazia (Arv* a)
{
    return a == NULL;
}

int arv_pertence (Arv* a, tAluno* c)
{
    if (arv_vazia(a))
        return 0; /* árvore vazia: não encontrou */
    else
        return (strcmp(retornaMatricula(a -> info), retornaMatricula(c)) == 0 ||
                arv_pertence(a->esq, c) ||
                arv_pertence(a->dir, c));
}//função recursiva que retorna 1 se estiver e 0 se não.

Arv* arvB_busca(Arv* raiz, char* chave)
{
    if (arv_vazia(raiz))
        return NULL;

    if (strcmp(retornaMatricula(raiz -> info), chave) < 0)
        return arvB_busca(raiz -> esq, chave);
    else if (strcmp(retornaMatricula(raiz -> info), chave) > 0)
        return arvB_busca(raiz -> dir, chave);
    else
    {
        return raiz;
    }
}

Arv* abb_retira (Arv* raiz, char* chave)
{
    if (raiz == NULL)
        return NULL;
    if (strcmp(retornaMatricula(raiz -> info), chave) < 0)
    {
        raiz -> esq = abb_retira(raiz -> esq, chave);
    }
    else if (strcmp(retornaMatricula(raiz -> info), chave) > 0)
    {
        raiz -> dir = abb_retira(raiz -> dir, chave);
    }
    
    else
    {
        
        if (raiz -> esq == NULL && raiz -> dir == NULL)
        {
            free(raiz);
            raiz = NULL;
        }
        else if (raiz -> esq == NULL)
        {
            Arv* t = raiz;
            raiz = raiz -> dir;
            free(t);
        }
        else if (raiz -> dir == NULL)
        {
            Arv* t = raiz;
            raiz = raiz -> esq;
            free(t);
        }
        else
        {
            Arv* f = raiz -> esq;
            while (f -> dir != NULL)
                f = f -> dir;
            tAluno* t = raiz -> info;
            raiz -> info = f -> info;
            f -> info = t;

            raiz -> esq = abb_retira(raiz -> esq, chave);
        }
    }
    return raiz;
}

int folhas (Arv* a) //retorna o número de folhas da árvore
{
    if (a == NULL)
        return 0;
    
    if (arv_vazia(a->esq) && arv_vazia(a->dir))
        return 1;
    
    return folhas(a->esq) + folhas(a->dir);
}

int ocorrencias (Arv* a , char* nome) //retorna o número de vezes que o aluno aparece na árvore
{
    if (arv_vazia(a))
        return 0;

    return (strcmp(retornaNome(a->info), nome) == 0 ? 1 : 0) +
           ocorrencias(a->esq, nome) +
           ocorrencias(a->dir, nome);
}

int altura (Arv* a) //retorna a altura da árvore
{
    if (arv_vazia(a))
        return -1; // se a árvore estiver vazia, a altura é -1 (ou 0, dependendo da convenção usada)
    else
    {
        int altura_esq = altura(a->esq);
        int altura_dir = altura(a->dir);
        return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
    }
}

void arv_imprime (Arv* a)
{
    if (a != NULL){
        imprimeAluno(a -> info); /* mostra raiz */
        arv_imprime(a->esq); /* mostra sae */
        arv_imprime(a->dir); /* mostra sad */
    }
}
