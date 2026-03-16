#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSortWithCounters(int v[], int n, int *comparacoes, int *trocas) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (v[j] > v[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                (*trocas)++;
            }
        }
    }
}

void bubbleSortOptimizadoWithCounters(int v[], int n, int *comparacoes, int *trocas) {
    // Se uma passada não fizer nenhuma troca, o vetor já está ordenado.
    // No melhor caso (vetor já ordenado), isso permite sair do loop externo
    // depois de apenas uma passada, reduzindo o custo para O(n).
    for (int i = 0; i < n - 1; i++) {
        int houveTroca = 0;
        for (int j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (v[j] > v[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                (*trocas)++;
                houveTroca = 1;
            }
        }
        if (!houveTroca) {
            break;
        }
    }
}

void fillAscending(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = i + 1;
}

void fillDescending(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = n - i;
}

void fillRandom(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = rand() % 100 + 1;
}

void copyArray(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int main(void) {
    const int n = 20;
    int base[n];
    int work[n];

    srand((unsigned)time(NULL));

    printf("Comparacao de Bubble Sort (n=%d)\n", n);

    // 1) vetor já ordenado
    fillAscending(base, n);
    copyArray(work, base, n);
    int c1 = 0, t1 = 0;
    bubbleSortWithCounters(work, n, &c1, &t1);

    int c2 = 0, t2 = 0;
    copyArray(work, base, n);
    bubbleSortOptimizadoWithCounters(work, n, &c2, &t2);

    printf("\nVetor ordenado:\n");
    printf("  bubbleSort:           comparacoes=%d, trocas=%d\n", c1, t1);
    printf("  bubbleSortOptimizado: comparacoes=%d, trocas=%d\n", c2, t2);

    // 2) vetor reverso
    fillDescending(base, n);
    copyArray(work, base, n);
    c1 = t1 = 0;
    bubbleSortWithCounters(work, n, &c1, &t1);

    c2 = t2 = 0;
    copyArray(work, base, n);
    bubbleSortOptimizadoWithCounters(work, n, &c2, &t2);

    printf("\nVetor reverso:\n");
    printf("  bubbleSort:           comparacoes=%d, trocas=%d\n", c1, t1);
    printf("  bubbleSortOptimizado: comparacoes=%d, trocas=%d\n", c2, t2);

    // 3) vetor aleatório
    fillRandom(base, n);
    copyArray(work, base, n);
    c1 = t1 = 0;
    bubbleSortWithCounters(work, n, &c1, &t1);

    c2 = t2 = 0;
    copyArray(work, base, n);
    bubbleSortOptimizadoWithCounters(work, n, &c2, &t2);

    printf("\nVetor aleatorio:\n");
    printf("  bubbleSort:           comparacoes=%d, trocas=%d\n", c1, t1);
    printf("  bubbleSortOptimizado: comparacoes=%d, trocas=%d\n", c2, t2);

    printf("\nObservacao: o caso que mais reduz operacoes com early stop eh o vetor ja ordenado\n");

    return 0;
}
