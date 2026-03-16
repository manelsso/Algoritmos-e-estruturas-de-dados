#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n, long *comparacoes, long *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            (*trocas)++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void testSelectionSort(int arr[], int n, const char *tipo) {
    long comparacoes, trocas;
    int copia[n];
    
    for (int i = 0; i < n; i++) {
        copia[i] = arr[i];
    }
    
    selectionSort(copia, n, &comparacoes, &trocas);
    
    printf("Caso %s (n=%d):\n", tipo, n);
    printf("  Comparações: %ld\n", comparacoes);
    printf("  Trocas: %ld\n", trocas);
    printf("  Array: ");
    printArray(copia, n);
    printf("\n");
}

int main() {
    int n = 20;
    
    // (i) Array ordenado
    int ordenado[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    testSelectionSort(ordenado, n, "Ordenado");
    
    // (ii) Array reverso
    int reverso[20] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    testSelectionSort(reverso, n, "Reverso");
    
    // (iii) Array aleatório
    srand(time(NULL));
    int aleatorio[20];
    for (int i = 0; i < n; i++) {
        aleatorio[i] = rand() % 100 + 1;
    }
    testSelectionSort(aleatorio, n, "Aleatório");
    
    printf("Explicação:\n");
    printf("Selection Sort é mais constante que Bubble Sort porque:\n");
    printf("- Sempre faz n(n-1)/2 comparações, independente da entrada\n");
    printf("- No máximo n-1 trocas (sempre move o mínimo para posição correta)\n");
    printf("- Não beneficia de arrays já ordenados como Bubble Sort\n");
    
    return 0;
}