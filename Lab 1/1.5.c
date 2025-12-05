#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int value[], int *row, int *col) {
    int r, c;
    scanf("%d %d", &r, &c); //รับค่า

    int compile = r * c;
    int *matrixBox = (int*)malloc(compile * sizeof(int));

    for (int i = 0; i < compile; i++) {
        scanf("%d", &matrixBox[i]);
    }

    *((int **)value) = matrixBox;
    *row = r;
    *col = c;
}

int main() {
    int *data, m, n;
    GetMatrix((int *)&data, &m, &n);
    return 0;
}