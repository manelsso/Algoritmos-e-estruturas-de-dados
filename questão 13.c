#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long comparacoes;
    long movimentacoes;
} Estatisticas;

Estatisticas insertionSortInstrumentado(int V[], int n) {
    Estatisticas stats = {0, 0};
    
    for (int i = 1; i < n; i++) {
        int chave = V[i];
        stats.movimentacoes++;
        
        int j = i - 1;
        while (j >= 0) {
            stats.comparacoes++; 
            if (chave < V[j]) {
                V[j + 1] = V[j];
                stats.movimentacoes++;
                j--;
            } else {
                break;
            }
        }
        
        V[j + 1] = chave;
        stats.movimentacoes++;
    }
    
    return stats;
}

void imprimirVetor(int V[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void testarCenario(const char *nome, int V[], int n) {
    printf("\n=== Cenário: %s ===\n", nome);
    printf("Vetor original: ");
    imprimirVetor(V, n);
    
    Estatisticas stats = insertionSortInstrumentado(V, n);
    
    printf("Vetor ordenado: ");
    imprimirVetor(V, n);
    printf("Comparações: %ld\n", stats.comparacoes);
    printf("Movimentações: %ld\n", stats.movimentacoes);
    printf("Total operações: %ld\n", stats.comparacoes + stats.movimentacoes);
}

int main() {
    int n = 20;
    
    // Teste 1: Vetor já ordenado
    int ordenado[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    testarCenario("ORDENADO", ordenado, n);
    
    // Teste 2: Vetor reverso
    int reverso[20] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    testarCenario("REVERSO", reverso, n);
    
    // Teste 3: Vetor aleatório
    int aleatorio[20] = {15, 3, 19, 7, 11, 2, 18, 5, 14, 9, 1, 20, 8, 4, 16, 12, 6, 17, 10, 13};
    testarCenario("ALEATÓRIO", aleatorio, n);
    
    // Teste 4: Vetor quase ordenado (com poucas trocas)
    int quaseOrdenado[20] = {1, 2, 3, 4, 5, 6, 7, 8, 20, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    testarCenario("QUASE ORDENADO", quaseOrdenado, n);
    

    return 0;
}