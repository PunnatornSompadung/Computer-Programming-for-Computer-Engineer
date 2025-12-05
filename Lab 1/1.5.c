#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int rawPtr[], int *rows, int *cols) {
    int r, c;
    scanf("%d %d", &r, &c);

    int total = r * c;
    int *matrixBox = (int*)malloc(total * sizeof(int));

    for (int i = 0; i < total; i++) {
        scanf("%d", &matrixBox[i]);
    }

    *((int **)rawPtr) = matrixBox;
    *rows = r;
    *cols = c;
}

int main() {
    int *data, m, n;
    GetMatrix((int *)&data, &m, &n);
    return 0;
}
