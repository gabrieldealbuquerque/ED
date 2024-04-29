#ifndef Gato_h
#define Gato_h

#define GATO 1

typedef struct Gato Gato;

Gato* inicGato(char* nome, int nivel);
void atribuiNivelAgressividadeGato(Gato* c, int nivel);
void liberaGato(Gato* gato);

#endif