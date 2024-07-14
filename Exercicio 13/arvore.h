//
//  arvore.h
//


#ifndef arvore_h
#define arvore_h

#include "aluno.h"

typedef struct arv Arv;
//Cria uma árvore vazia
Arv* arv_criavazia ();
//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (tAluno* aluno, Arv* sae, Arv* sad);
//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a);
//retorna true se a árvore estiver vazia e false
//caso contrário
int arv_vazia (Arv* a);
//indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence (Arv* a, tAluno* c);
Arv* insereArvore (Arv* a, tAluno* aluno);
Arv* arvB_busca(Arv* raiz, char* chave);
Arv* abb_retira (Arv* raiz, char* chave);
//imprime as informações dos nós da árvore
int folhas (Arv* a); //retorna o número de folhas da árvore
int ocorrencias (Arv* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore
int altura (Arv* a); //retorna a altura da árvore
char* retornaNomedoNo(Arv* arvore);
char* retornaMatriculadoNo(Arv* arvore);
void arv_imprime (Arv* a);

#endif
