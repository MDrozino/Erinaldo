// main.c
#include <stdio.h>
#include "rodizio.h"

int main() {
    ListaCircular* lista = inicializarLista();
    char criterio[15];
    
    printf("Digite o critério de busca (dia da semana ou último dígito da placa): ");
    scanf("%s", criterio);
    
    carregarArquivo(lista, criterio);
    
    int opcao;
    do {
        printf("\n1 - Exibir veículos\n");
        printf("2 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                exibirVeiculos(lista);
                break;
            case 2:
                liberarLista(lista);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 2);
    
    return 0;
}
