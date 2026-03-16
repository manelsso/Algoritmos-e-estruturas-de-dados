void selectionSort(int *V, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Encontra o índice do menor elemento
        for (int j = i + 1; j < n; j++) {
            if (V[j] < V[minIndex]) {
                minIndex = j;
            }
        }
        
        // Troca o menor elemento com a posição correta
        int temp = V[i];
        V[i] = V[minIndex];
        V[minIndex] = temp;
    }
}