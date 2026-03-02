#include <stdio.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx);

int main() {
    int n = 5, wx = 11;
    
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    
    int *x = KnapsackGreedy(w, v, n, wx);
    
    for(int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    
    return 0;
}

int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    int *x = new int[n];
    float *ratio = new float[n];
    int *index = new int[n];
    
    for (int i = 0; i < n; i++) {
        x[i] = 0;
        ratio[i] = (float)v[i] / w[i];
        index[i] = i;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                float tempRatio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempRatio;
                
                int tempIndex = index[i];
                index[i] = index[j];
                index[j] = tempIndex;
            }
        }
    }
    
    int currentWeight = 0;
    
    for (int i = 0; i < n; i++) {
        int idx = index[i];
        
        if (currentWeight + w[idx] <= wx) {
            x[idx] = 1;
            currentWeight += w[idx];
        }
    }
    
    return x;
}