#include <stdio.h>
#include <stdlib.h>

int *GetSet(int size[]) {
    int most;
    scanf("%d", &most);

    int *box = (int*)malloc(most * sizeof(int));
    for (int i = 0; i < most; i++) {
        scanf("%d", &box[i]);
    }

    *size = most;
    return box;
}

int main() {
    int *data, num;
    data = GetSet(&num);
    return 0;
}