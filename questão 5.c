#include <stdio.h>

void bubbleSortOrdem(int v[], int n, int ordem) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ordem == 1 && v[j] > v[j + 1]) || 
                (ordem == -1 && v[j] < v[j + 1])) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void imprimirArray(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    // Teste 1: n = 0
    int v1[] = {};
    printf("n=0: ");
    imprimirArray(v1, 0);

    // Teste 2: n = 1
    int v2[] = {5};
    printf("n=1: ");
    imprimirArray(v2, 1);

    // Teste 3: Elementos repetidos (crescente)
    int v3[] = {3, 1, 3, 1, 3};
    bubbleSortOrdem(v3, 5, 1);
    printf("Repetidos crescente: ");
    imprimirArray(v3, 5);

    // Teste 4: Elementos repetidos (decrescente)
    int v4[] = {3, 1, 3, 1, 3};
    bubbleSortOrdem(v4, 5, -1);
    printf("Repetidos decrescente: ");
    imprimirArray(v4, 5);

    // Teste 5: Positivos e negativos (crescente)
    int v5[] = {-5, 3, -1, 0, 8, -10};
    bubbleSortOrdem(v5, 6, 1);
    printf("Posit/Negat crescente: ");
    imprimirArray(v5, 6);

    // Teste 6: Positivos e negativos (decrescente)
    int v6[] = {-5, 3, -1, 0, 8, -10};
    bubbleSortOrdem(v6, 6, -1);
    printf("Posit/Negat decrescente: ");
    imprimirArray(v6, 6);

    return 0;
}