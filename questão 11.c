#include <stdio.h>

void insertionSort(int *V, int n) {
    for (int i = 1; i < n; i++) {
        int chave = V[i];
        int j = i;
        
        while (j > 0 && chave < V[j - 1]) {
            V[j] = V[j - 1];
            j--;
        }
        
        V[j] = chave;
    }
}

int main() {
    int V[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    insertionSort(V, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    
    return 0;
}