#include <stdlib.h>
#include <string.h>
#include "BanhoTosa.h"
#include "Lista.h"

struct banhotosa{
    char* nome;
    tLista* mansos;
    tLista* agressivos;
};

#define GATO 0
#define CACHORRO 1

/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome)
{
    BanhoTosa* loja = (BanhoTosa*) malloc (sizeof(BanhoTosa));
    loja -> nome = strdup(nome);
    loja -> mansos = criaLista();
    loja -> agressivos = criaLista();
    return loja;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, Cachorro* dog)
{
    if (dog != NULL)
    {
        if (obtemNivelAgressividadeCachorro(dog) == 0)
        {
            
            insereLista(loja -> mansos, dog, CACHORRO);
        }
        else
        {
            insereLista(loja -> agressivos, dog, CACHORRO);
        }
    }
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, Gato* cat)
{
    if (cat != NULL)
    {
        if (obtemNivelAgressividadeGato(cat) == 0)
        {
            printf("AGRESSIVIDADE:%d\n\n", obtemNivelAgressividadeGato(cat));
            insereLista(loja -> mansos, cat, GATO);
        }
        else
        {
            printf("AGRESSIVIDADE:%d\n\n", obtemNivelAgressividadeGato(cat));
            insereLista(loja -> agressivos, cat, GATO);
        }
    }
}


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat)
{
    int nivelNovo = varreLista(loja -> mansos, loja -> agressivos, cat);
    cadastraGato(loja, cat);
    /*if (!(varreLista(loja -> mansos, loja -> agressivos, cat)))
    {
        cadastraGato(loja, cat);
    }
    else if (varreLista(loja -> mansos, loja -> agressivos, cat) == 1)
    {
        cadastraGato(loja, cat);
    }*/

}

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog)
{
    int nivelNovo = varreLista(loja -> mansos, loja -> agressivos, dog);
    if (nivelNovo != -1) 
        cadastraCachorro(loja, dog);
    /*if (!(varreLista(loja -> mansos, loja -> agressivos, cat)))
    {
        cadastraGato(loja, cat);
    }
    else if (varreLista(loja -> mansos, loja -> agressivos, cat) == 1)
    {
        cadastraGato(loja, cat);
    }*/
}


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa* loja)
{
    int animal;
    printf("\t - %s -\n", loja -> nome);

    printf("Mansos:\n");
    void* aux = obtemPrimeiroLista(loja -> mansos);
    while (aux)
    {
        animal = retornaAnimal(aux);
        if (animal == GATO)
        {
            imprimirGato(retornaInfo(aux));
        }
        else if (animal == CACHORRO)
        {
            imprimirCachorro(retornaInfo(aux));
        }
        aux = obtemProximoLista(loja -> mansos, aux);
    }

    printf("Agressivos:\n");
    aux = obtemPrimeiroLista(loja -> agressivos);
    while (aux)
    {
        animal = retornaAnimal(aux);
        if (animal == GATO)
        {
            imprimirGato(retornaInfo(aux));
        }
        else if (animal == CACHORRO)
        {
            imprimirCachorro(retornaInfo(aux));
        }
        aux = obtemProximoLista(loja -> agressivos, aux);
    }
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja)
{
    int receita = 0;
    int animal;

    void* aux = obtemPrimeiroLista(loja -> mansos);
    while (aux)
    {
        animal = retornaAnimal(aux);
        if (animal == GATO)
        {
            receita += 30;
        }
        else if (animal == CACHORRO)
        {
            receita += 40;
        }
        aux = obtemProximoLista(loja -> mansos, aux);
    }

    aux = obtemPrimeiroLista(loja -> agressivos);
    while (aux)
    {
        animal = retornaAnimal(aux);
        if (animal == GATO)
        {
            receita += 35;
        }
        else if (animal == CACHORRO)
        {
            receita += 45;
        }
        aux = obtemProximoLista(loja -> agressivos, aux);
    }
    return receita;
}


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja)
{
    free(loja -> nome);
    desalocaLista(loja -> mansos);
    desalocaLista(loja -> agressivos);
    free(loja);
}