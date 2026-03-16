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
    // osso
}