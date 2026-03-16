#include <stdio.h>
#include <string.h>

int comparacoes = 0;

void selectionSort(int arr[], int n) {
    comparacoes = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        
        for (int j = i + 1; j < n; j++) {
            comparacoes++;  
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        // Troca
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void testarOrdenacao(int arr[], int n, char *descricao) {
    int copia[n];
    memcpy(copia, arr, n * sizeof(int));
    
    selectionSort(copia, n);
    printf("%s: %d comparações\n", descricao, comparacoes);
}

int main() {
    int n = 10;
    int crescente[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int decrescente[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int aleatorio[] = {5, 2, 8, 1, 9, 3, 7, 4, 6, 10};
    
    testarOrdenacao(crescente, n, "Ordem crescente");
    testarOrdenacao(decrescente, n, "Ordem decrescente");
    testarOrdenacao(aleatorio, n, "Ordem aleatória");
    

    return 0;
}