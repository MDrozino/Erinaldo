#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rotas.h"

No* criarNo(int id, const char* nomeLinha, const char* tipo, const char* regiao) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    
    novoNo->id = id;
    strcpy(novoNo->nomeLinha, nomeLinha);
    strcpy(novoNo->tipo, tipo);
    strcpy(novoNo->regiao, regiao);
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    
    return novoNo;
}

void inserirNaListaDupla(No** lista, int id, const char* nomeLinha, const char* tipo, const char* regiao) {
    No* novoNo = criarNo(id, nomeLinha, tipo, regiao);
    
    if (*lista == NULL) {
        *lista = novoNo;
        return;
    }
    
    No* atual = *lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
    atual->proximo = novoNo;
    novoNo->anterior = atual;
}

void carregarRotasDeArquivo(No** lista, const char* nomeArquivo, const char* filtro) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        int id;
        char nomeLinha[100], tipo[20], regiao[50];
        
        sscanf(linha, "%d;%[^;];%[^;];%[^\n]", &id, nomeLinha, tipo, regiao);
        
        if (strstr(tipo, filtro) != NULL || strstr(regiao, filtro) != NULL) {
            inserirNaListaDupla(lista, id, nomeLinha, tipo, regiao);
        }
    }
    
    fclose(arquivo);
}

void exibirListaEmOrdem(No* lista) {
    if (lista == NULL) {
        printf("Nenhuma rota encontrada!\n");
        return;
    }
    
    printf("\nRotas em ordem normal:\n");
    No* atual = lista;
    while (atual != NULL) {
        printf("ID: %d | Linha: %s | Tipo: %s | Região: %s\n",
               atual->id, atual->nomeLinha, atual->tipo, atual->regiao);
        atual = atual->proximo;
    }
}

void exibirListaEmOrdemInversa(No* lista) {
    if (lista == NULL) {
        printf("Nenhuma rota encontrada!\n");
        return;
    }
    
    No* atual = lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
    printf("\nRotas em ordem inversa:\n");
    while (atual != NULL) {
        printf("ID: %d | Linha: %s | Tipo: %s | Região: %s\n",
               atual->id, atual->nomeLinha, atual->tipo, atual->regiao);
        atual = atual->anterior;
    }
}

void liberarLista(No** lista) {
    No* atual = *lista;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
}

void incluirNovaRota(No** lista) {
    int id;
    char nomeLinha[100], tipo[20], regiao[50];
    
    printf("\n=== Incluir Nova Rota ===\n");
    printf("Digite o ID da rota: ");
    scanf("%d", &id);
    getchar(); // Limpar o buffer

    printf("Digite o nome da linha: ");
    scanf("%[^\n]", nomeLinha);
    getchar();

    printf("Digite o tipo de transporte: ");
    scanf("%[^\n]", tipo);
    getchar();

    printf("Digite a região: ");
    scanf("%[^\n]", regiao);
    getchar();

    inserirNaListaDupla(lista, id, nomeLinha, tipo, regiao);
    
    // Salvar no arquivo
    FILE* arquivo = fopen("rotas_de_transportes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    
    fprintf(arquivo, "%d;%s;%s;%s\n", id, nomeLinha, tipo, regiao);
    fclose(arquivo);
    
    printf("\nRota incluída com sucesso!\n");
}

