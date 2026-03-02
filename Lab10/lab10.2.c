#include <stdio.h>

void TowerHanoi(int m, int from, int to);

int main() {
    int n = 3;
    TowerHanoi(n, 1, 3);
    return 0;
}

void TowerHanoi(int m, int from, int to) {
    if (m <= 0)
        return;

    if (m == 1) {
        printf("Disc 1 from %d to %d\n", from, to);
        return;
    }

    int aux = 6 - from - to;

    TowerHanoi(m - 1, from, aux);
    printf("Disc %d from %d to %d\n", m, from, to);
    TowerHanoi(m - 1, aux, to);
}