void selectionSort(int *V, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        

        for (int j = i + 1; j < n; j++) {
            if (V[j] < V[minIndex]) {
                minIndex = j;
            }
        }
        
        
        int temp = V[i];
        V[i] = V[minIndex];
        V[minIndex] = temp;
    }
}