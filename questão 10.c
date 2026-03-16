#include <stdio.h>

void selectionSort(int arr[], int n, int ordem) {
    for (int i = 0; i < n - 1; i++) {
        int extremo = i;
        for (int j = i + 1; j < n; j++) {
            if (ordem == 1) {
                // Crescente
                if (arr[j] < arr[extremo]) {
                    extremo = j;
                }
            } else {
                // Decrescente
                if (arr[j] > arr[extremo]) {
                    extremo = j;
                }
            }
        }
        // Troca
        int temp = arr[i];
        arr[i] = arr[extremo];
        arr[extremo] = temp;
    }
}

void exibirVetor(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    // Teste 1: Ordem Crescente (1)
    int vetor1[7];
    for (int i = 0; i < n; i++) {
        vetor1[i] = vetor[i];
    }
    printf("Vetor original: ");
    exibirVetor(vetor1, n);
    
    selectionSort(vetor1, n, 1);
    printf("Ordem Crescente: ");
    exibirVetor(vetor1, n);

    // Teste 2: Ordem Decrescente (-1)
    int vetor2[7];
    for (int i = 0; i < n; i++) {
        vetor2[i] = vetor[i];
    }
    selectionSort(vetor2, n, -1);
    printf("Ordem Decrescente: ");
    exibirVetor(vetor2, n);

    return 0;
}