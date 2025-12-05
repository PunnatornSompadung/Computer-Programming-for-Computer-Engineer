#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *row, int *col) {
    int r, c;
    scanf("%d %d", &r, &c); // input

    int fixed = r * c;
    int *str = (int *)malloc(fixed * sizeof(int));

    for (int x = 0; x < fixed; x++) {
        scanf("%d", &str[x]);
    }

    *row = r;
    *col = c;

    return str;
}

int main() {
    int *data, m, n;
    data = GetMatrix(&m, &n);
    return 0;
}