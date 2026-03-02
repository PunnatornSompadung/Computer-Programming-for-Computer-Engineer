#include <stdio.h>

long SumLoop(int n);
long SumRecur(int n);

int main() {
    int n = 10;

    printf("SumLoop(%d) = %ld\n", n, SumLoop(n));
    printf("SumRecur(%d) = %ld\n", n, SumRecur(n));

    return 0;
}

long SumLoop(int n) {
    if (n <= 0)
        return 0;

    long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;

    return sum;
}

long SumRecur(int n) {
    if (n <= 0)
        return 0;

    return n + SumRecur(n - 1);
}