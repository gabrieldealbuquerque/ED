#ifndef produto_h
#define produto_h

typedef struct produto {
    int codigo;
    char* nome;
    int preco;
} tProduto;

tProduto criaProduto(int codigo, char* nome, int preco);
int obtemCodigo(tProduto produto);
int obtemPreco(tProduto produto);
char* obtemNome(tProduto produto);
void desalocaNomeProduto(tProduto produto);

#endif

