#ifndef Cachorro_h
#define Cachorro_h

#define CACHORRO 0

typedef struct Cachorro Cachorro;

Cachorro* inicCachorro(char* nome, int nivel);
void atribuiNivelAgressividadeCachorro(Cachorro* c, int nivel);
void liberaCachorro(Cachorro* cachorro);


#endif