#ifndef produto_h
#define produto_h

typedef struct produto {
    int codigo;
    char* nome;
    int preco;
} tProduto;

void ImprimeProduto(tProduto* produto);
tProduto* criaProduto(int codigo, char* nome, int preco);
int obtemCodigo(tProduto* produto);
int obtemPreco(tProduto* produto);
char* obtemNome(tProduto* produto);
void desalocaProduto(tProduto* produto);

#endif

