// main.c
#include <stdio.h>
#include "rodizio.h"

int main() {
    ListaCircular* lista = inicializarLista();
    char criterio[15];
    
    printf("Digite o crit�rio de busca (dia da semana ou �ltimo d�gito da placa): ");
    scanf("%s", criterio);
    
    carregarArquivo(lista, criterio);
    
    int opcao;
    do {
        printf("\n1 - Exibir ve�culos\n");
        printf("2 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                exibirVeiculos(lista);
                break;
            case 2:
                liberarLista(lista);
                break;
            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 2);
    
    return 0;
}
