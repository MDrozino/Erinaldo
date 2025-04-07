#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rotas.h"

int main() {
    No* lista = NULL;
    int opcao;
    char filtro[50];

    do {
        printf("\n=== Menu de Rotas ===\n");
        printf("1. Buscar rotas\n");
        printf("2. Incluir nova rota\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        switch(opcao) {
            case 1:
                printf("Digite o tipo de transporte ou região desejada: ");
                scanf("%[^\n]", filtro);
                getchar();
                
                carregarRotasDeArquivo(&lista, "rotas_de_transportes.txt", filtro);
                exibirListaEmOrdem(lista);
                exibirListaEmOrdemInversa(lista);
                liberarLista(&lista);
                break;
                
            case 2:
                incluirNovaRota(&lista);
                liberarLista(&lista);
                break;
                
            case 3:
                printf("Saindo do programa...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 3);
    
    return 0;
}

