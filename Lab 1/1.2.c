#include <stdio.h>
#include <stdlib.h>

void GetSet(int a[], int *x) {
    int box;
    scanf("%d", &box);

    int *storage = (int *)malloc(box * sizeof(int));
    for (int slot = 0; slot < box; slot++) {
        scanf("%d", &storage[slot]);
    }

    *(int **)a = storage;
    *x = box;
}

int main() {
    int *data, num;
    GetSet((int *)&data, &num);
    return 0;
}
