#ifndef ROTAS_H
#define ROTAS_H

// Estrutura do nó da lista
typedef struct No {
    int id;
    char nomeLinha[100];
    char tipo[20];
    char regiao[50];
    struct No* anterior;
    struct No* proximo;
} No;

// Funções para manipulação da lista
No* criarNo(int id, const char* nomeLinha, const char* tipo, const char* regiao);
void inserirNaListaDupla(No** lista, int id, const char* nomeLinha, const char* tipo, const char* regiao);
void carregarRotasDeArquivo(No** lista, const char* nomeArquivo, const char* filtro);
void exibirListaEmOrdem(No* lista);
void exibirListaEmOrdemInversa(No* lista);
void liberarLista(No** lista);
void incluirNovaRota(No** lista);

#endif

