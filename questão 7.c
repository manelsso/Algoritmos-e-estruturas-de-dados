#include <stdio.h>

void selectionSort(int arr[], int n) {
    // Iterações do laço externo
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        
        // Encontrar o índice do menor elemento
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        // Trocar elementos
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
        
        // Exibir estado do vetor após cada iteração
        printf("i = %d: [", i);
        for (int k = 0; k < n; k++) {
            printf("%d", arr[k]);
            if (k < n - 1) printf(", ");
        }
        printf("]\n");
    }
}

int main() {
    int vetor[] = {64, 25, 12, 22, 11};
    int n = 5;
    
    printf("Vetor original: [64, 25, 12, 22, 11]\n\n");
    selectionSort(vetor, n);
    
    return 0;
}