#ifndef Lista_h
#define Lista_h

#include <stdio.h>

typedef struct Lista tLista;

tLista* criaLista();
int retornaAnimal(void* celula);
void* obtemPrimeiroLista(tLista* lista);
void* obtemUltimoLista(tLista* lista);
void* obtemProximoLista(tLista* lista, void* dado);
void* retornaInfo(void* c);
void imprimeLista(tLista* lista, void (*imprimirItem)(void *));
void insereLista(tLista* lista, void* dado, int animal);
int varreLista(tLista* lista1, tLista* lista2, void* dado);
void primeiroNULL(tLista* lista);
void desalocaLista(tLista* lista);

#endif
